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
class Clist
{
private:
    Node *head;
    Node *tail;

public:
    Clist()
    {
        head = tail = NULL;
    }
    void inserth(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void insertt(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
            // tail->next = head;
        }
    }

    void removeh()
    {
        int deleted;
        if (head == NULL)
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        else
        {
            Node *p = head;
            head = head->next;
            tail->next = head;
            deleted = p->data;
            cout << deleted << ": is deleted from head of CL \n";
            p->next = NULL;

            delete p;
        }
    }
    void removet()
    {
        int deleted;
        if (tail == NULL)
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        else
        {
            Node *p = tail;
            Node *pre = head;
            while (pre->next != tail)
            {
                pre = pre->next;
            }
            tail = pre;
            tail->next = head;
            deleted = p->data;
            cout << deleted << ": is deleted from tail of CL \n";
            p->next = NULL;
            delete p;
        }
    }

    // display
    void dis()
    {
        if (head == NULL)
        {
            cout << "lL is empty \n";
            return;
        }
        Node *p = head;
        do
        {
            cout << p->data << " -> ";
            p = p->next;

        } while (p != head);
        cout << "Head \n";
        // cout << tail->next->data;
    }
};

int main()
{
    Clist l;
    l.insertt(1);
    l.insertt(2);
    l.insertt(3);
    l.dis();
    l.removet();
    l.dis();
}