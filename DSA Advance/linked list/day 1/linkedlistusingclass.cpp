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
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position \n";
            return;
        }

        if (pos == 0)
        {
            push_front(val); // Insert at front
            return;          // Stop further execution
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL) // Position is out of bounds
            {
                cout << "Invalid position \n";
                return;
            }
            temp = temp->next;
        }

        if (temp == NULL) // If position is still out of bounds
        {
            cout << "Invalid position \n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        // If inserting at the last position, update tail
        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }

    int search(int key)
    {
        Node *temp = head;
        int i = 0;
        while (temp)
        {
            if (temp->data == key)
            {
                // cout<<i;
                // cout << "founded \n";
                return i;
            }
            i++;
            temp = temp->next;
        }
        return -1;
    }
    void pop_Front()
    {
        if (head == NULL)
        {
            cout << "LL is empty \n";
            return;
        }

        Node *temp = head;

        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "LL is empty \n";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL) //(temp->next == tail)
        {
            temp = temp->next;
        }

        delete temp->next; // Delete last node
        temp->next = NULL; // Update tail pointer
        tail = temp;
    }
    void push_tail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void Display()
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "NULL " << endl;
        }
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL \n";
    }
};

int main()
{
    List l1;

    l1.push_front(30);
    l1.push_front(40);
    l1.push_front(50);
    l1.push_tail(20);
    l1.push_tail(10);
    l1.push_front(70);
    l1.Display();

    // l1.pop_Front();
    // l1.pop_back();
    l1.insert(3, 3);
    l1.Display();
    cout << l1.search(40);

    return 0;
}
