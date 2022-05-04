#include <bits/stdc++.h>

using namespace std;

unordered_set <int> numbers;

int main ()
{
    ifstream file ("data.txt");
    string line;
    int a;
    while (getline (file, line))
    {
        istringstream iss (line);
        iss >> a;
        numbers.insert (a);
    }

    int count = 0;
    for (int i = -10000; i <= 10000; i++)
    {
        for (auto x : numbers)
        {
            int y = i - x;
            if (y == x)
                continue;
            else
                if (numbers.find(y) != numbers.end())
                {
                    count++;
                    break;
                }
        }
    }
    cout << count;
}