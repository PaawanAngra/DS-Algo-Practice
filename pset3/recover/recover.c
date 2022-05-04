#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    FILE* inptr = fopen (argv [1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 2;
    }
    int name = 000;
    char* fname = malloc(sizeof(char)*8);
    BYTE buff[512];
    int count = 0;
    sprintf (fname, "%03d.jpg", name);
    FILE* outptr = fopen(fname, "w");
    while (fread(buff, 1, 512, inptr))
    {
        if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
        {
            if (count == 0)
            {
                count++;
            }
            else if (count != 0)
            {
            fclose (outptr);
            name++;
            sprintf (fname, "%03d.jpg", name);
            outptr = fopen(fname, "w");
            }
        }

        if (count)
        {
            fwrite(buff, 1, 512, outptr);
        }
    }
    fclose (outptr);
    return 0;
}
