#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *pre;
    Node(int val)
    {
        data = val;
        next = NULL;
        pre = NULL;
    }
};

class DLL
{
private:
    Node *head;
    Node *tail;

public:
    DLL()
    {
        head = tail = NULL;
    }
    void insert_h(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
    }

    void insert_t(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }
    void delete_h()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            int d = head->data;
            cout << d << " is deleted \n";

            delete head;
            head = tail = NULL;
            return;
        }
        else
        {
            Node *p = head;
            head = head->next;

            head->pre = NULL;

            int d = p->data;
            cout << d << " is deleted \n";

            delete p;
        }
    }

    void delete_t()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            int d = head->data;
            cout << d << " is deleted \n";

            delete head;
            head = tail = NULL;
            return;
        }
        else
        {
            Node *p = tail;
            tail = tail->pre;
            tail->next = NULL;
            int d = p->data;
            cout << d << " is deleted \n";
            p->pre = NULL;
            delete p;
        }
    }

    void rev()
    {
        Node *p = head;
        Node *temp = NULL;

        while (p)
        {
            // Swap next and prev pointers
            temp = p->pre;
            p->pre = p->next;
            p->next = temp;

            // Move to the next node (which is now stored in p->pre)
            p = p->pre;
        }

        // Swap head and tail after the loop ends
        if (temp != NULL)
        {
            head = temp->pre; // New head is the last node processed
        }
    }

    void mid()
    {
        Node *p, *q;
        p = head;
        q = head;
        while (q != nullptr && q->next != nullptr)
        {

            q = q->next->next;

            p = p->next;
        }
        cout << p->data << "\n";
    }
    void dis()
    {
        if (head == NULL)
        {
            cout << "ll is empty \n";
            return;
        }
        Node *p = head;
        while (p)
        {
            cout << p->data << " <=> ";
            p = p->next;
        }
        cout << "NULL \n";
    }
};
int main()
{
    DLL l;
    l.insert_t(1);
    l.insert_t(2);
    l.insert_t(3);
    l.insert_t(4);
    l.insert_t(5);
    l.insert_t(6);
    // l.delete_h();
    // l.delete_h();
    // l.delete_h();
    l.dis();
    // l.rev();
    // l.delete_t();
    // l.delete_t();
    // l.delete_t();
    // l.dis();
    l.mid();

    return 0;
}