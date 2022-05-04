#include <bits/stdc++.h>

using namespace std;

void input_graph (string s);
void output_graph ();
void dijkstra (int start);

typedef pair <int, int> pa;

const unsigned int n = 200;
vector <vector <pa>> graph (n + 1);
int d [n + 1];

int main ()
{
    string s = "graph.txt";
    input_graph (s);
    for (int i = 0; i <= n; i++)
        d [i] = 9999;
    int start = 1;
    dijkstra (start);
    cout << d [7] << ",";
    cout << d [37] << ",";
    cout << d [59] << ",";
    cout << d [82] << ",";
    cout << d [99] << ",";
    cout << d [115] << ",";
    cout << d [133] << ",";
    cout << d [165] << ",";
    cout << d [188] << ",";
    cout << d [197];
    cout << endl;
}


void input_graph (string s)
{
    ifstream file (s);
    string line;
    int a, b, c;
    while (getline (file, line))
    {
        istringstream iss (line);
        iss >> a;
        while (iss >> b)
        {
            iss.ignore (1);
            iss >> c;
            pair <int, int> p = make_pair (b,c);
            graph [a].push_back (p);
        }
    }
}


void output_graph ()
{
    for (int i = 1; i < graph.size (); i++)
    {
        cout << i << "\t";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j].first << " " << graph[i][j].second << "  ";
        }
        cout << "\n";
    }
}


void dijkstra (int start)
{
    // Set of elements with shortest distance known.
    unordered_set <int> s1;
    // Set of elements with shortest distance unknown.
    unordered_set <int> s2;

    int dgs, node1, node2;
    set <pa> key;

    // Populating key, index pairs in an ordered set.
    for (int i = 1; i <= n; i++)
    {
        if (i != start)
        {
            key.insert (make_pair (9999, i));
            d [i] = 9999;
        }
        else
        {
            key.insert (make_pair (0, i));
            d [i] = 0;
        }
    }

    // Populating set s2.
    for (int i = 1; i <=n; i++)
        s2.insert (i);

    // Main while loop.
    while (!s2.empty())
    {
        //Removing lowest key from set.
        auto it = key.begin ();
        pa temp = *it;
        key.erase (it);
        node1 = temp.second;
        s1.insert (node1);
        s2.erase (node1);

        //Updating key values.
        for (int i = 0; i < graph[node1].size(); i++)
        {
            if (s2.find(graph[node1][i].first) != s2.end() )
            {
                node2 = graph[node1][i].first;
                key.erase (make_pair(d[node2], node2));
                dgs = min (d[node1] + graph[node1][i].second, d[node2]);
                d [node2] = dgs;
                key.insert (make_pair(dgs, node2));
            }
        }
    }
}
