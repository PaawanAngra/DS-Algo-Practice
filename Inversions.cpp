# include <iostream>
# include <bits/stdc++.h>

using namespace std;

int splitmerge (int arr[], int start, int mid, int end);
int countinv (int arr[], int start, int end);

int main ()
{
    int arr[] = {3, 1, 2};
    int inv;
    int n = sizeof(arr)/sizeof(arr[0]);
    if (n == 1)
       inv = 0;
    else
        inv = countinv (arr, 0, n-1);
    cout << inv << endl;
}

int countinv (int arr[], int start, int end)
{
    if (start == end)
     return 0;
    int mid = (start + end) / 2;
    int leftinv = countinv (arr, start, mid);
    int rightinv = countinv (arr, mid + 1, end);
    int splitinv = splitmerge (arr, start, mid, end);
    return leftinv + rightinv + splitinv;
}

int splitmerge (int arr[], int start, int mid, int end)
{
    int count = 0;
    int i = 0;
    int j = mid + 1;
    int k = 0;
    int temp [end - start + 1];
    for (int k = 0; k < end - start + 1; k++)
    {
        if (i > mid)
        {
            while (j <= end)
            {
                temp [k] = arr [j];
                k++;
                j++;
            }
            break;
        }
        if (j > end)
        {
            while (i <= mid)
            {
                temp [k] = arr [i];
                k++;
                i++;
            }
            break;
        }
        if (arr [i] <= arr [j])
        {
            temp [k] = arr [i];
            i++;
        }
        else if (arr [i] > arr [j])
        {
            temp [k] = arr[j];
            count = count + mid - i + 1;
            j++;
        }
        k = 0;
    }
    for (int i = start; i <= end; i++)
        {
            arr [i] = temp [k];
            k++;
        }
    return count;
}