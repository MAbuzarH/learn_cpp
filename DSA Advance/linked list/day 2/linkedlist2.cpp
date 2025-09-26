#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class List
{
private:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    List(int A[], int n);

    void insertt(int val)
    {
        Node *temp = new Node(val);

        if (head == NULL)
        {
            head = tail = temp;
            return;
        }

        tail->next = temp;
        tail = temp;
    }
    void inserth(int val)
    {
        Node *temp = new Node(val);

        if (head == NULL)
        {
            head = tail = temp;
            return;
        }

        temp->next = head;
        head = temp;
    }

    void Display()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "ll is empty \n";
            return;
        }
        while (temp)
        {
            cout << temp->data << " ->";
            temp = temp->next;
        }
        cout << "NULL \n";
    }

    ~List()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};
List::List(int A[], int n)
{
    if (n <= 0) // Handle empty array case
        return;
    head = new Node(A[0]); // Create the first node
    tail = head;           // Initialize tail
    for (int i = 1; i < n; i++)
    {
        Node *t = new Node(A[i]);
        tail->next = t;
        tail = t;
    }
}
int main()
{
    List l;
    for (int i = 0; i < 5; i++)
        l.inserth(i);

    l.Display();
    int A[] = {7, 8, 9, 11, 22};
    List l2(A, 5);
    l2.Display();
}
