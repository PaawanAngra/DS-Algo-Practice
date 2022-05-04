#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void add_edge (int a, int b);
void bfs (vector <vector <int>> &graph, int start);
void dfs (vector <vector <int>> &graph, int start);
void dfs_stack (int start);

vector <vector <int>> graph (10);
vector <int> nodes (10);

int main()
{
    for (int i = 0; i < 10; i++)
    {
        nodes[i] = -1;
        graph[i] = vector <int> ();
    }
    add_edge (1,2);
    add_edge (1,4);
    add_edge (2,3);
    add_edge (2,5);
    add_edge (2,8);
    add_edge (3,4);
    add_edge (3,9);
    add_edge (3,10);
    add_edge (5,6);
    add_edge (5,7);
    add_edge (5,8);
    add_edge (7,8);
    dfs_stack (0);
    for (int i = 0; i < 10; i++)
    {
        cout << i+1 << " " << nodes [i] << endl;
    }
}

void add_edge (int x, int y)
{
    graph[x-1].push_back(y-1);
    graph[y-1].push_back(x-1);
}

void bfs (vector <vector <int>> &graph, int start)
{
    start = start - 1;
    queue <int> q;
    int temp;
    nodes [start] = 0;
    q.push(start);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int i = 0; i < graph[temp].size(); i++)
        {
            if (nodes[graph[temp][i]] == -1)
            {
                nodes [graph[temp][i]] = nodes[temp] + 1;
                q.push(graph[temp][i]);
            }
        }
    }
    cout << endl;
}

void dfs (vector <vector <int>> &graph, int start)
{
    nodes [start] = 0;
    for (int i = 0; i < graph[start].size(); i++)
    {
        if (nodes[graph[start][i]] == -1)
            dfs(graph, graph[start][i]);
    }
    return;
}

void dfs_stack (int start)
{
    stack <int> s;
    s.push(start);
    nodes [start] = 0;
    while (!s.empty())
    {
        int con = 0;
        for (int i = 0; i < graph[start].size(); i++)
        {
            if (nodes[graph[start][i]] == -1)
            {
                s.push(start);
                start = graph[start][i];
                nodes [start] = 0;
                con = 1;
                break;
            }
        }
        if (con == 0)
        {
            start = s.top();
            s.pop();
        }
    }
}