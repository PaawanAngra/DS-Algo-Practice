#include <bits/stdc++.h>

using namespace std;

bool comp (vector <double> &a, vector <double> &b)
{
    return (a [0] > b [0]);
}

bool comp1 (vector <double> &a, vector <double> &b)
{
    return (a [1] > b [1]);
}

int main ()
{
    double a, b, c;
    int n;

    ifstream file ("data.txt");
    string line;
    getline (file, line);
    istringstream iss (line);
    iss >> n;
    vector <vector <double>> vec (n, vector <double> (3));

    for (int i = 0; i < n; i++)
    {
        getline (file , line);
        istringstream iss (line);
        iss >> a >> b;
        vec [i][1] = a;
        vec [i][2] = b;
    }

    for (int i = 0; i < n; i++)
    {
        vec [i][0] = vec [i][1] / vec[i][2];
    }

    sort (vec.begin(), vec.end(), comp);

    for (int i = 0; i < n - 1; i++)
    {
        if (vec [i][0] == vec [i+1][0])
        {
            int j = i;
            while (vec [i][0] == vec [i+1][0])
            {
                i++;
                if (i == n - 1)
                    break;
            }
        sort (vec.begin() + j, vec.begin() + i, comp1);
        }
    }

    for (auto x : vec)
    {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }

    long sum = 0;
    long ct = 0;
    for (auto x : vec)
    {
        ct = ct + x [2];
        sum = sum + x[1] * ct;
    }

    cout << sum;
}