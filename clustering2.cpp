#include <bits/stdc++.h>

using namespace std;

#define M 24

void unionise (int element1, int element2, int parent [], int rank[]);
int find (int element, int parent []);

int main ()
{
    unordered_set <int> set1;
    unordered_map <int, int> graph;

    ifstream file ("data.txt");
    string s;
    getline (file, s);
    istringstream iss (s);
    int nodes;
    iss >> nodes;

    while(getline (file, s))
    {
        istringstream iss (s);
        string s1 = "";
        string s2;
        for (int i = 1; i <= M; i++)
        {
            iss >> s2;
            s1 = s1 + s2;
        }
        bitset <M> bits (s1);
        int l = (int) bits.to_ulong();
        set1.insert (l);
    }

    nodes = set1.size();

    int c = 0;
    for (auto x : set1)
    {
        graph [x] = c++;
    }

    int parent [nodes];
    int rank [nodes];

    for (int i = 0; i < nodes; i++)
    {
        parent [i] = i;
        rank [i] = 0;
    }

    int node1, node2, signature;
    for (auto x : graph)
    {

        // Checking all nodes at a distance 1
        node1 = x.second;
        for (int i = 0; i < M; i++)
        {
            bitset <M> bits (x.first);
            signature = (bits.flip(i)).to_ulong();
            if (graph.find(signature) != graph.end())
            {
                node2 = graph [signature];
                if (find (node2, parent) != find (node1, parent))
                {
                    unionise (node2, node1, parent, rank);
                    nodes --;
                }
            }
        }


        //Checking all nodes at a distance 2
        node1 = x.second;
        for (int i = 0; i < M - 1; i++)
        {
            for (int j = i+1; j < M; j++)
            {
                bitset <M> bits (x.first);
                signature = (bits.flip(i)).flip(j).to_ulong();
                if (graph.find(signature) != graph.end())
                {
                    node2 = graph [signature];
                    if (find (node2, parent) != find (node1, parent))
                    {
                        unionise (node2, node1, parent, rank);
                        nodes --;
                    }
                }
            }
        }
    }

    cout << nodes;
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

//Unionise function
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