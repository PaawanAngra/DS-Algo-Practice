#include <iostream>
using namespace std;

void merge_sort(int *arr, int lb, int ub);
void merge (int *arr, int i, int m, int j);

int main()
{
    int a [] = {4, 1, 5, 3, 2, 6, 8, 7};
	merge_sort(a, 0, 7);
	cout << "The elements in sorted order are \n";
	for (int i = 0; i < 8; i++)
	{
	    cout << a [i] << " ";
	}
	cout << "\n";
	return 0;
}

void merge_sort(int *arr, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (ub + lb) / 2;
        merge_sort (arr, lb, mid);
        merge_sort (arr, mid+1, ub);
        merge (arr, lb, mid, ub);
    }
}

void merge (int *arr, int i, int m, int j)
{
    int n = j-i+1;
    int temp [n];
    int a = i;
    int b = m+1;
    for (int k = 0; k < n; k++)
    {
        if (a > m)
        {
            for (int l = b; l <= j; l++)
            {
                temp [k] = arr [l];
                k++;
            }
            break;
        }
        if (b > j)
        {
            for (int l = a; l <=m; l++)
            {
                temp [k] = arr [l];
                cout << temp [k];
                k++;
            }
            break;
        }
        if (arr[a] <= arr [b])
        {
            temp [k] = arr [a];
            a++;
        }
        else
        {
            temp [k] = arr [b];
            cout << temp [k];
            b++;
        }
    }
    for (int k = 0; k < n; k++)
    {
        arr [i] = temp [k];
        i++;
    }
}