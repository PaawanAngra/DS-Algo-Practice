// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize f infile outfile\n");
        return 1;
    }

    float f = atof (argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int pad = (4 - ((bi.biWidth*3)%4))%4;
    // Scaling up

    if (f >= 1)
    {
        int sf = round(f);
        BITMAPFILEHEADER bfo = bf;
        BITMAPINFOHEADER bio = bi;

        bio.biWidth *= sf;
        bio.biHeight *= sf;

        int pado = (4 -((bio.biWidth*3)%4))%4;

        bio.biSizeImage = (bio.biWidth*3 + pado)*abs(bio.biHeight);
        bfo.bfSize = bio.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

        // write outfile's BITMAPFILEHEADER
        fwrite(&bfo, sizeof(BITMAPFILEHEADER), 1, outptr);

        // write outfile's BITMAPINFOHEADER
        fwrite(&bio, sizeof(BITMAPINFOHEADER), 1, outptr);

        // scale horizontally and vertically

        BYTE temp[bio.biWidth*3 + pado];
        for (int i = 0; i < abs(bi.biHeight); i++)
        {
            int c = 0;
            for (int j = 0; j < bi.biWidth; j++)
            {
                RGBTRIPLE triple;
                fread (&triple, sizeof(RGBTRIPLE), 1, inptr);
                for (int k =1; k<=sf; k++)
                {
                    fwrite (&triple, sizeof(RGBTRIPLE), 1, outptr);
                    temp [c] = triple.rgbtBlue;
                    c++;
                    temp [c] = triple.rgbtGreen;
                    c++;
                    temp [c] = triple.rgbtRed;
                    c++;
                }
            }
            fseek(inptr, pad, SEEK_CUR);
            for (int l = 1; l<= pado; l++)
                {
                    fputc(0x00, outptr);
                    temp [c] = 0x00;
                    c++;
                }
            for (int m = 1; m < sf; m++)
            {
                fwrite(&temp, sizeof(temp), 1, outptr);
            }
        }
    }

    // Scaling Down
    if (f < 1.0)
    {

        int sf = round(1/f);
        BITMAPFILEHEADER bfo = bf;
        BITMAPINFOHEADER bio = bi;

        bio.biWidth /= sf;
        bio.biHeight /= sf;
        int rem = bi.biWidth % sf;

        int pado = (4 -((bio.biWidth*3)%4))%4;

        bio.biSizeImage = (bio.biWidth*3 + pado)*abs(bio.biHeight);
        bfo.bfSize = bio.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

        // write outfile's BITMAPFILEHEADER
        fwrite(&bfo, sizeof(BITMAPFILEHEADER), 1, outptr);

        // write outfile's BITMAPINFOHEADER
        fwrite(&bio, sizeof(BITMAPINFOHEADER), 1, outptr);

        fseek(inptr, (bi.biWidth*3 + pad)*(sf-1) , SEEK_CUR);

        // scale horizontally and vertically
        for (int i = sf; i <= abs(bi.biHeight); i+=sf)
        {
            for (int j = sf; j <= bi.biWidth; j+=sf)
            {
                fseek(inptr, 3*(sf-1), SEEK_CUR);
                RGBTRIPLE triple;
                fread (&triple, sizeof(RGBTRIPLE), 1, inptr);
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
            fseek(inptr, 3*rem + pad, SEEK_CUR);
            fseek(inptr, (bi.biWidth*3 + pad)*(sf-1) , SEEK_CUR);
            for (int k = 1; k <= pado; k++)
            fputc (0x00, outptr);
        }
    }
    return 0;
}




