#include <bits/stdc++.h>

using namespace std;

void input_graph (int weights []);
void mwisfun (int weights [], int mwis [], int &n);
void reconstruction (int mwis [], int weights [], int &n);

int main ()
{
    ifstream file ("data.txt");
    string s;
    getline (file, s);

    // Input number of nodes
    int n = stoi (s);

    // Array to store weight of each node
    int weights [n] = {0};

    // Array to store solutions of smaller subproblems
    int mwis [n+1] = {0};

    //Input weights
    input_graph (weights);

    //Compute mwis for the subrpoblems, thus leading to the solution for the final graph
    mwisfun (weights, mwis, n);

    //Output the nodes chosen in mwis for the whole problem
    reconstruction (mwis, weights, n);
}

void input_graph (int weights [])
{
    string s;
    ifstream file ("data.txt");
    getline (file, s);
    int c = 0;
    while (getline (file, s))
    {
        weights [c] = stoi (s);
        c++;
    }
}

void mwisfun (int weights [], int mwis [], int &n)
{
    mwis [1] = weights [0];
    for (int i = 2; i <= n; i++)
    {
        mwis [i] = max (mwis [i-1], mwis [i-2] + weights [i-1]);
    }
}

void reconstruction (int mwis [], int weights [], int &n)
{
    int i = n;
    int c = 0;

    while (i > 1)
    {
        if (mwis [i-2] + weights [i-1] > mwis [i-1])
        {
            if (i == 2)
                c = 1;
            cout << i << ", ";
            i -= 2;
        }
        else
            i--;
    }
    if (c == 0)
        cout << "1" << endl;
}