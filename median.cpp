#include <bits/stdc++.h>

using namespace std;

int median (vector <int> input);

int main ()
{
    vector <int> input;
    input.push_back (0);
    //Creating input vector
    ifstream file ("test.txt");
    string line;
    while (getline (file, line))
    {
        istringstream iss (line);
        int a;
        iss >> a;
        input.push_back (a);
    }

    //Calling the function
    int ans = median (input);
    cout << ans % 10000 << endl;
}

int median (vector <int> input)
{
    priority_queue <int> lower;
    priority_queue <int, vector<int>, greater<int> > upper;
    int sum = 0;

    // Push first element in lower queue
    lower.push (input [1]);
    sum = input [1];

    // Median for second element onwards.
    for (int i = 2; i < input.size(); i++)
    {
        // Pushing element in the desired heap
        if (input [i] >= lower.top())
            upper.push (input [i]);
        else
            lower.push (input [i]);

        // Rebalancing if required
        if ((upper.size() - lower.size()) == 2)
        {
            lower.push (upper.top());
            upper.pop();
        }
        else if ((lower.size () - upper.size()) == 2)
        {
            upper.push (lower.top());
            lower.pop();
        }

        // Adding median for odd and even cases
        if (i % 2 == 0)
            sum = sum + lower.top();

        else
        {
            if (upper.size() > lower.size())
                sum = sum + upper.top();
            else
                sum = sum + lower.top();
        }
    }
    return sum;
}