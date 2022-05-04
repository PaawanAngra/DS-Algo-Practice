#include <iostream>
using namespace std;

int queue [10];
int first = -1;
int last = -1;

void enqueue (int n);
void dequeue ();
void print ();

int main ()
{
    enqueue (1);
    enqueue (2);
    enqueue (3);
    enqueue (4);
    enqueue (5);
    enqueue (6);
    enqueue (7);
    enqueue (8);
    enqueue (9);
    enqueue (10);
    enqueue (11);
    print ();
    dequeue();
    print ();
    enqueue (11);
    print ();
}

void enqueue (int n)
{
    if ((last + 1) % 10 == first)
    {
        cout << "The list is full" << endl;
        return;
    }
    else if (first == -1 && last == -1)
    {
        first = 0;
        last = 0;
    }
    else
    {
        last = (last + 1) % 10;
    }
    queue [last] = n;
}

void dequeue ()
{
    if (first == -1 && last == -1)
    {
        cout << "List is empty" << endl;
        return;
    }
    else if (first == last)
    {
        first = -1;
        last = -1;
    }
    else
    {
        first = (first + 1) % 10;
    }
}

void print ()
{
    int count = first;
    while (count != last)
    {
        cout << queue[count] <<endl;
        count = (count + 1) % 10;
    }
    cout << queue[count] << endl;
}