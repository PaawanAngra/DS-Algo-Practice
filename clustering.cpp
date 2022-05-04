#include <bits/stdc++.h>

using namespace std;

struct edges
{
    int node1, node2, size;
};

bool compare (edges e1, edges e2);
int find (int element, int parent []);
void unionise (int element1, int element2, int parent [], int rank[]);


int main ()
{
    ifstream file ("data.txt");
    string line;
    getline (file, line);
    istringstream iss (line);
    int nodes;
    iss >> nodes;

    //Initialise parent and rank array for union-find

    int parent [nodes + 1];
    int rank [nodes + 1];
    for (int i = 0; i <= nodes; i++)
    {
        parent [i] = i;
        rank [i] = 0;
    }


    //Input graph
    vector <edges> graph;
    while (getline (file, line))
    {
        istringstream iss (line);
        int a, b, c;
        iss >> a >> b >> c;
        edges e;
        e.node1 = a;
        e.node2 = b;
        e.size = c;
        graph.push_back(e);
    }


    sort(graph.begin(), graph.end(), compare);

    int k = 4; //Final number of clusters
    int clusters = nodes;
    int temp;

    for (int i = 0; i < graph.size(); i++)
    {
        if (find (graph[i].node1, parent) != find (graph[i].node2, parent))
        {
            unionise (graph[i].node1, graph[i].node2, parent, rank);
            clusters --;
        }

        if (clusters == k)
        {
            temp = i++;
            break;
        }
    }
}


//Comparator function
bool compare (edges e1, edges e2)
{
    return (e1.size < e2.size);
}


//Find function
int find (int element, int parent [])
{
    if (parent [element] != element)
    {
        int root = find (parent [element], parent);
        parent [element] = root;
        return root;
    }
    else
    {
        return element;
    }

}

//Unionise
void unionise (int element1, int element2, int parent [], int rank[])
{
    int root1 = find (element1, parent);
    int root2 = find (element2, parent);
    if (rank [root1] < rank [root2])
    {
        parent [root1] = root2;
    }

    else if (rank [root1] > rank [root2])
    {
        parent [root2] = root1;
    }

    else
    {
        parent [root1] = root2;
        rank [root2] ++;
    }
}
