#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node* next;
};


void print (Node* head);
Node* rev (Node* head);

int main ()
{
    Node* n1 = new Node ();
    Node* n2 = new Node ();
    Node* n3 = new Node ();
    n1 -> data = 1;
    n2 -> data = 2;
    n3 -> data = 3;
    Node* head = n1;
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = NULL;
    print (head);
    cout << "\n";
    head = rev (head);
    print (head);
    free (n1);
    free (n2);
    free (n3);
}

void print (Node* head)
{
    Node* temp = head;
    while (temp!= NULL)
    {
        cout << temp -> data << "\n";
        temp = temp -> next;
    }
}

Node* rev (Node* head)
{
    stack <Node*> s;
    Node* temp = head;
    while (temp != NULL)
    {
        s.push (temp);
        temp = temp -> next;
    }
    temp = s.top ();
    head = temp;
    s.pop ();
    while (!s.empty())
    {
        temp = s.top ();
        temp -> next -> next = temp;
        temp -> next = NULL;
        s.pop();
    }
    return head;
}