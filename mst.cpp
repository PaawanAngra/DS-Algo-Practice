#include <bits/stdc++.h>

using namespace std;

vector <vector <pair <int,int>>> graph;
int nodes, edges;

void input_graph ();
void output_graph ();
int mst ();

int main ()
{
    input_graph ();
    //output_graph ();
    int weight_sum = mst ();
    cout << weight_sum << endl;
}

void input_graph ()
{
    ifstream file ("data.txt");
    string line;
    getline (file, line);
    istringstream iss (line);
    iss >> nodes >> edges;
    graph.resize (nodes + 1);
    while (getline (file , line))
    {
        istringstream iss (line);
        int a, b, c;
        iss >> a >> b >> c;
        graph [a].push_back (make_pair (b, c));
        graph [b].push_back (make_pair (a, c));
    }
}

void output_graph ()
{
    for (int i = 1; i <= nodes; i++)
    {
        cout << i << "\t";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j].first << " " << graph[i][j].second << "  ";
        }
        cout << endl;
    }
}

int mst ()
{
    int nodes_left [nodes + 1];
    set <pair <int, int>> keys;

    int node1, node2, new_key, edge_l;
    int sum = 0;
    pair <int, int> temp;

    // Nodes_left keeps track of key values and -1 signifies that a node has been moved to the mst
    nodes_left [1] = -1;
    for (int i = 2; i <= nodes; i++)
        nodes_left [i] = 9999;

    // Initialise key, node pairs with infinite value for all nodes except first
    keys.insert (make_pair (0, 1));
    for (int i = 2; i <= nodes; i++)
        keys.insert (make_pair (9999, i));

    // MST algorithm

    for (int i = 1; i <= nodes; i++)
    {
        // Evaluate lowest key, node pair with lowest key value
        temp = *keys.begin();

        // Delete the respective pair from heap
        keys.erase (temp);

        // Add respective edge length to sum of weights of mst
        sum = sum + temp.first;

        node1 = temp.second;

        // Mark the respective node as moved to mst
        nodes_left [node1] = -1;

        // Scan through all edges of node1
        for (int i = 0; i < graph[node1].size(); i++)
        {
            node2 = graph [node1][i].first;
            edge_l = graph [node1][i].second;

            // If node2 doesn't exist in mst then update it's key value
            if (nodes_left [node2] != -1)
            {
                keys.erase (make_pair (nodes_left [node2], node2));
                new_key = min (nodes_left [node2], edge_l);
                keys.insert (make_pair (new_key, node2));
                nodes_left [node2] = new_key;
            }
        }
    }
    return sum;
}