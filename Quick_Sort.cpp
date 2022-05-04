#include <iostream>
#include <vector>

using namespace std;
void quicksort (vector <int> & v, int start, int end);
int partition (vector <int> & v, int p, int start, int end);

int main ()
{
    vector <int> v;
    cout << "Enter the length of array \n";
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    cout << "The unsorted array is ";
    for (int i:v)
    {
        cout << i << " ";
    }
    cout << "\n";
    quicksort (v, 0, v.size() - 1);
    cout << "The sorted array is ";
    for (int i:v)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void quicksort (vector <int> & v, int start, int end)
{
    if (start == end)
        return;
    int p = rand () % (end - start + 1) + start;
    p = partition (v, p, start, end);
    if (p > start)
        quicksort (v, start, p-1);
    if (end > p)
        quicksort (v, p+1, end);
}

int partition (vector <int> & v, int p, int start, int end)
{
    int temp;
    temp = v [start];
    v [start] = v [p];
    v [p] = temp;
    int boundary = start + 1;
    for (int i = start + 1; i <= end; i++)
    {
        if (v [i] <= v [start])
        {
            temp = v [i];
            v [i] = v [boundary];
            v [boundary] = temp;
            boundary ++;
        }
    }
    temp = v [start];
    v [start] = v [boundary - 1];
    v [boundary - 1] = temp;
    return boundary - 1;
}