#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ifstream file ("data.txt");
    string line;
    getline (file, line);

    int knap_size, n_items;
    istringstream iss (line);
    iss >> knap_size;
    iss >> n_items;
    int sol [knap_size + 1][n_items + 1];
    for (int i = 0; i <= knap_size; i++)
        sol [i][0] = 0;
    int obj [2][n_items + 1];
    obj [0][0] = 0;
    obj [1][0] = 0;
    int a, b, c;
    c = 1;
    while (getline (file, line))
    {
        istringstream iss (line);
        iss >> a;
        iss >> b;
        obj [0][c] = a;
        obj [1][c] = b;
        c++;
    }

    for (int i  = 1; i <= n_items; i++)
    {
        for (int j = 0; j <= knap_size; j++)
        {
            if (obj [1][i] > j)
                sol [j][i] = sol [j][i-1];
            else
            {
                sol [j][i] = max (sol [j][i-1], (obj[0][i] + sol [j - obj [1][i]][i-1]));
            }
        }
    }
    cout << sol [knap_size][n_items];
}