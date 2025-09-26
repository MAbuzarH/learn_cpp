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

public:
    // List(){

    // }

    void Rdisplay(Node *p)
    {
        static int flag = 0;
        if (p != head || flag == 0)
        {
            flag = 1;
            cout << p->data << " ";
            Rdisplay(p->next);
        }
        flag = 0;
    }
    void display()
    {
        Rdisplay(head);
        // Node *p = head;
        // if (p == NULL)
        // {
        //     cout << "LL is empty \n";
        //     return;
        // }
        // do
        // {
        //     cout << p->data << "->";
        //     p = p->next;
        // } while (p != head);
        // cout << "Head \n";
    }
};
int main()
{

    return 0;
}