# include <bits/stdc++.h>

using namespace std;

struct sub_tree
{
    vector <int> nodes;
    int weight;
};

bool comp (sub_tree a, sub_tree b);
void huffman (int &c);

set <sub_tree, decltype (comp)*> s(comp);

int main ()
{
    string f = "data.txt";
    ifstream file (f);

    string line;

    //Input number of nodes
    getline (file, line);
    istringstream iss (line);
    int n;
    iss >> n;

    //Input weights along with node number to a set
    int c = 0;
    while (getline (file, line))
    {
        sub_tree st;
        istringstream iss (line);
        iss >> st.weight;
        st.nodes.push_back(c);
        s.insert (st);
        c++;
    }

    huffman (c);
}

//Comparator function for the set
bool comp (sub_tree a, sub_tree b)
{
    return (a.weight <= b.weight);
}


void huffman (int &c)
{
    int merges [c] = {};
    while (s.size() > 1)
    {
        auto it = s.begin();
        auto it1 = it++;
        sub_tree new_s;
        new_s.weight = it -> weight + it1 -> weight;
        new_s.nodes = it -> nodes;
        new_s.nodes.insert (new_s.nodes.end(), it1 -> nodes.begin(), it1 -> nodes.end());
        for (int x : new_s.nodes)
            merges [x]++;
        s.erase (it);
        s.erase (it1);
        s.insert(new_s);
    }
    for (auto x : merges)
       cout << x << endl;
}