#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;


int n = 200;
map <int, vector <int>> graph;


void input_graph (string &s);
void output_graph ();
void removesl ();
int mincut (int seed);

int main ()
{
    string s = "graph.txt";
    int min, count;
    min = 9999;
    input_graph (s);
    removesl();
    count = mincut (1);
    cout << count << endl;
}


void input_graph (string &s)
{
    ifstream ifile (s);
    string line;
    int a,b;
    while(getline (ifile, line))
    {
        istringstream iss (line);
        iss >> a;
        while (iss >> b)
        {
            graph [a].push_back(b);
        }
    }
}


void output_graph ()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}


void removesl ()
{
    for (int i = 1; i<= n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][j] == i)
                graph[i][j] = 0;
        }
    }
}


int mincut (int seed)
{
    time_t current_time;
	current_time = time(NULL);
    srand (current_time);
    while (graph.size() > 2)
    {
        int seed = (rand() % 10000) + 1;
        // Picking a random edge.
        int node1 = (rand() % 200) + 1;
        if (graph.find(node1) == graph.end())
            continue;
        int size = graph [node1].size();
        int index = (rand() % size);
        int node2 = graph [node1][index];
        if (node2 == 0)
            continue;

        //Contracting the edge.
        for (int i = 0; i < graph[node2].size(); i++)
        {
            if (graph[node2][i] != 0 && graph[node2][i] != node1)
            {
                graph[node1].push_back (graph[node2][i]);
                graph[graph[node2][i]].push_back (node1);
            }
        }

        // Removing node2 from graph.
        graph.erase(node2);
        for (auto i = graph.begin(); i != graph.end(); i++)
        {
            for (int j = 0; j < i -> second.size(); j++)
            {
                if (i -> second [j] == node2)
                    i -> second [j] = 0;
            }
        }
    }

    //Calculating size of min cut.
    auto it = graph.begin();
    int count = 0;
    for (int i = 0; i < it -> second.size(); i++)
    {
        if (it -> second[i] != 0)
            count++;
    }
    return count;
}

