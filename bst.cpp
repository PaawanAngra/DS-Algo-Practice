#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left;
    int data;
    Node* right;
};

Node* root = NULL;

void insert (int data);
void insert (Node* curr, int data);
Node* insertr (Node* curr, int data);
void bfs (Node* root);
void dfs (Node* root);
void search (Node* root, int data);
void min (Node* root1);
int max (Node* root1);
int height (Node* root);
void preorder (Node* root);
Node* Delete (Node* root, int data);

int main ()
{
    insert (root, 20);
    insert (root, 15);
    insert (root, 10);
    insert (root, 5);
    insert (root, 25);
    insert (root, 17);
    insert (root, 27);
    insert (root, 24);
    insert (root, 26);
    insert (root, 23);
    insert (root, 29);
    bfs (root);
    cout << endl;
    root = Delete (root, 20);
    bfs (root);
}

void insert (Node* root1, int data)
{
    Node* n = new Node ();
    Node* temp;
    Node* curr = root1;
    n -> data = data;
    if (curr == NULL)
    {
        root = n;
        return;
    }
    while (curr != NULL)
    {
        temp = curr;
        if (curr -> data >= data)
            curr = curr-> left;
        else if (curr -> data < data)
            curr = curr -> right;
    }
    if (data <= temp -> data)
        temp -> left = n;
    else if (data > temp -> data)
        temp -> right = n;
}

Node* insertr (Node* curr, int data)
{
    if (curr == NULL)
    {
        Node* n = new Node ();
        n -> data = data;
        return n;
    }
    if (curr -> data >= data)
    {
        curr -> left = insertr (curr -> left, data);
        return curr;
    }
    else if (curr -> data < data)
    {
        curr -> right = insertr (curr-> right, data);
        return curr;
    }
}

void bfs (Node* root)
{
    Node* temp;
    queue <Node*> q;
    cout << root -> data << endl;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp -> left != NULL)
        {
            cout << temp -> left -> data << endl;
            q.push (temp -> left);
        }
        if (temp -> right != NULL)
        {
            cout << temp-> right -> data << endl;
            q.push (temp -> right);
        }
    }
}

void dfs (Node* root)
{
    cout << root -> data << endl;
    if (root -> left != NULL)
        dfs (root -> left);
    if (root -> right != NULL)
        dfs (root -> right);
}

void search (Node* root1, int data)
{
    if (root1 != NULL)
    {
        if (data < root1 -> data)
            search (root1 -> left, data);
        else if (data > root1-> data)
            search (root1 -> right, data);
        else if (data == root1 -> data)
            cout << data << " found." << endl;
        return;
    }
    else
    {
        cout << data << " not found" << endl;
    }
}

void min (Node* root1)
{
    if (root1 -> left == NULL)
        cout << root1 -> data << " is min." << endl;
    else
        min (root1 -> left);
}

int max (Node* root1)
{
    if (root1 -> right == NULL)
    {
        return (root1 -> data);
    }
    else
        return (max (root1 -> right));
}

int height (Node* root)
{
    if (root == NULL)
        return -1;
    int hl = height (root -> left);
    int hr = height (root -> right);
    return (max (hl, hr) + 1);
}

void preorder (Node* root)
{
    if (root == NULL)
        return;
    cout << root -> data << " ";
    preorder (root -> left);
    preorder (root -> right);
}

void inorder (Node* root)
{
    if (root == NULL)
        return;
    inorder (root -> left);
    cout << root -> data << " ";
    inorder (root -> right);
}

Node* Delete (Node* root, int data)
{
    if (root == NULL)
        return NULL;
    if (data > root -> data)
        root -> right = Delete (root -> right, data) ;
    else if (data < root -> data)
        root -> left = Delete (root -> left, data);
    else
    {
        // Case 1 No children
        if (root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2 1 Child

        else if (root -> left == NULL || root -> right == NULL)
        {
            Node* temp = root;
            if (root -> left == NULL)
            {
                root = root -> right;
                delete temp;
            }
            else
            {
                root = root -> left;
                delete temp;
            }
            return root;
        }

        // Case 3 2 children

        else
        {
            int n = max (root -> left);
            root -> data = n;
            root -> left = Delete (root -> left, n);
        }
    }
    return root;
}
