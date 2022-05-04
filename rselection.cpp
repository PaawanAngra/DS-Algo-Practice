#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rselect (vector <int> &v, int i, int start, int end);
int partition (vector <int> & v, int p, int start, int end);

int main ()
{
    vector <int> v = {4,5,62,1,23,45,532,6,2};
    vector <int> vsort = {4,5,62,1,23,45,532,6,2};
    sort(vsort.begin(), vsort.end());
    for (auto x : vsort)
    cout << x << " ";
    cout << endl;
    cout << "Which element ";
    int i;
    cin >> i;
    rselect (v, i - 1, 0, v.size() - 1);
}

void rselect (vector <int> &v, int i, int start, int end)
{
    if (start == end)
    {
        cout << v [start];
        return;
    }
    int p = rand () % (end - start + 1) + start;
    p = partition (v, p, start, end);
    if (p == i)
    {
        cout << v [p];
        return;
    }
    else if (p > i)
        rselect (v, i, start, p - 1);
    else
        rselect (v, i, p + 1, end);
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