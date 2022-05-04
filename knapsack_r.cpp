#include <bits/stdc++.h>

using namespace std;

struct item
{
    int value;
    int weight;
};


vector <item> items;
unordered_map <int, unordered_map <int,int>> sol1;

int knapsack (int x, int y);
int main ()
{
    ifstream file ("data.txt");
    string line;
    getline (file, line);
    istringstream iss (line);

    item item0 = {0, 0};
    items.push_back (item0);
    // Get knap size and number of items
    int knap_size, n_items;
    iss >> knap_size;
    iss >> n_items;

    // Get item values and weights
    int a;
    item temp;
    while (getline (file, line))
    {
        istringstream iss (line);
        iss >> a;
        temp.value = a;
        iss >> a;
        temp.weight = a;
        items.push_back (temp);
    }

    // Calling knapsack function
    cout << knapsack (n_items, knap_size);
}

int knapsack (int x, int y)
{
    // If x is 0 return 0
    if (x == 0)
        return 0;

    // Check if sol1ution exists
    if (sol1.find (x) != sol1.end ())
        if (sol1 [x].find (y) != sol1 [x].end())
            return sol1 [x][y];

    // If sol1ution doesn't exist make two recursive calls
    if (items [x].weight > y)
    {
        sol1 [x][y] = knapsack (x-1, y);
        return sol1 [x][y];
    }
    else
    {
        sol1 [x][y] = max (knapsack (x-1, y), (items [x].value + knapsack (x-1, y - items [x].weight)));
        return sol1 [x][y];
    }
}