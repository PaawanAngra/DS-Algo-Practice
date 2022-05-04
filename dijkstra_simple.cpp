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

    for (int i = 1; i <= n; i++)
        s2.insert (i);

    d [start] = 0;
    s1.insert (start);
    s2.erase (start);

    int min, v, dgs;

    while (!s2.empty())
    {

        min = 9999;
        v = -1;

        for (auto x : s1)
        {

            for (int i = 0; i < graph [x].size(); i++)
            {
                if (s2.find(graph [x][i].first) != s2.end() )
                {
                    dgs = d [x] + graph [x][i].second;
                    if (dgs <= min)
                    {
                        min = dgs;
                        v = graph [x][i].first;
                    }
                }
            }

        }
        d [v] = min;
        s1.insert (v);
        s2.erase (v);
    }
}
