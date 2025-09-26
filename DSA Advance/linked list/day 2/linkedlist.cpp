

#include <iostream>
using namespace std;
// struct Node{
//     int data;
//     Node *next;
// };
// struct Node *first;
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

    int count()
    {
        int l = 0;
        if (head == NULL)
        {
            return 0;
        }
        Node *temp = head;
        while (temp)
        {
            temp = temp->next;
            l++;
        }
        return l;
    }
    void insert_top(int val)
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

    void insert_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void insert(int pos, int val)
    {
        if (pos < 0)
        {
            cout << "invalid node \n";
            return;
        }

        if (pos == 0)
        {
            insert_top(val);
            return;
        }
        if (head == NULL) // If list is empty and pos > 0
        {
            cout << "Invalid position \n";
            return;
        }
        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL || temp->next == NULL)
            {
                cout << "invalid node \n";
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "invalid node \n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL)
        {
            tail = newNode;
            return;
        }
    }

    void Insert_sorted(int val)
    {
        Node *p = head;
        Node *q = NULL;
        while (p && p->data < val)
        {
            q = p;
            p = p->next;
        }
        if (q == NULL)
        {
            insert(0, val);
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = q->next;
        q->next = newNode;
        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }

    void Display()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "NULL \n";
        }
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL \n";
    }

    void pop_top()
    {
        if (head == NULL)
        {
            cout << "invalid link list \n";
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
            cout << "invalid link list \n";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        tail = temp;
    }

    void remove_p(int pos)
    {
        int i = 0;
        if (pos < 0 || pos > count())
        {
            cout << "INvalid node";
            return;
        }
        if (pos == 1)
        {
            pop_top();
            return;
        }
        if (pos == (count()))
        {
            pop_back();
            return;
        }
        Node *p = head;
        Node *q = NULL;
        for (; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
            if (p == NULL) // Prevent accessing NULL pointer
            {
                cout << "Invalid position\n";
                return;
            }
        }
        q->next = p->next;

        delete p;
    }

    bool isSorted()
    {
        int x = -32678;
        Node *p = head;
        while (p == NULL)
        {
            if (x > p->data)
            {
                return false;
            }
            else if (x < p->data)
            {
                x = p->data;
                p = p->next;
            }
        }
        return true;
    }

    void removeD()
    {
        Node *p = head;
        Node *q = head->next;
        while (q != NULL)
        {
            if (p->data != q->data)
            {
                p = q;
                q = q->next;
            }
            else
            {
                // if (q->next != NULL)
                p->next = q->next;
                delete q;
                // if (p->next != NULL)
                q = p->next;
            }
        }
    }

    // Node *revers()
    // {
    //     Node *next = NULL;
    //     Node *pre = NULL;
    //     Node *cur = head;
    //     while (cur != NULL)
    //     {

    //         next = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = next;
    //     }
    // }
    // reverse ll using array
    // void revers()
    // {
    //     Node *p = head;
    //     int i = 0;
    //     int *a = new int[count()];
    //     while (p)
    //     {
    //         a[i] = p->data;
    //         p = p->next;
    //         i++;
    //     }
    //     p = head;
    //     i--;
    //     while (p)
    //     {
    //         p->data = a[i--];
    //         p = p->next;
    //     }
    // delete []a;
    // }
    // using sliding pointers
    void reverse()
    {
        Node *prev_node = nullptr;     // Tracks the previous node (initially NULL)
        Node *current_node = head;     // Starts at the head of the list
        Node *reversed_next = nullptr; // Stores the reversed "next" pointer

        while (current_node != nullptr)
        {
            // Step 1: Save the reversed_next (previous node's next)
            reversed_next = prev_node;

            // Step 2: Move prev_node to the current node
            prev_node = current_node;

            // Step 3: Move current_node to the next node in the original list
            current_node = current_node->next;

            // Step 4: Link the current node to the reversed_next (reverse the pointer)
            prev_node->next = reversed_next;
        }

        // Update head to point to the new first node (prev_node)
        head = prev_node;
    }

    // using recursion
    // void Reverse()
    // {

    //     Node *q = NULL;
    //     Node *p = head;
    //     if (p != NULL)
    //     {
    //         Reverse(p, p->next);
    //     }
    //     else
    //     {
    //         head = q;
    //     }
    // }

    void concat(List &l2)
    {
        if (l2.head == nullptr)
        {
            return; // Nothing to add
        }
        if (head == nullptr)
        {
            head = l2.head; // giving ownership to 2nd array
        }
        else
        {
            Node *p = head; // current
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = l2.head;
        }
        l2.head = NULL;

        // Node *q = l2.head;
    }
    List *Merge(List &l2)
    {
        Node *p = head;
        Node *q = l2.head;
        Node *dumi = new Node(-1);
        Node *three = dumi;
        while (p != NULL && q != NULL)
        {
            if (p->data < q->data)
            {
                three->next = p;
                p = p->next;
            }
            else
            {
                three->next = q;
                q = q->next;
            }
            three = three->next;
        }
        //     while (p)
        //     {
        //         three->next = p;
        //         p = p->next;
        //         dumi = dumi->next;
        //     }
        //     while (q)
        //     {
        //         dumi->next = q;
        //         q = q->next;
        //         dumi = dumi->next;
        //     }
        // Attach remaining nodes from either list
        if (p != nullptr)
            three->next = p;
        else
            three->next = q;
        List *mergedList = new List();
        mergedList->head = dumi->next;

        // Cleanup: Delete dummy node and invalidate original lists
        delete dumi;
        head = nullptr; // Optional: Clear current list
        l2.head = nullptr;
        return mergedList;
    }
    // List *Merge(List &l2)
    // {
    //     Node *p = head;             // Head of current list
    //     Node *q = l2.head;          // Head of the other list
    //     Node *dummy = new Node(-1); // Dummy node for easier linking
    //     Node *tail = dummy;         // Tail to build the merged list

    //     while (p != nullptr && q != nullptr)
    //     {
    //         if (p->data < q->data)
    //         {
    //             tail->next = p;
    //             p = p->next;
    //         }
    //         else
    //         {
    //             tail->next = q;
    //             q = q->next;
    //         }
    //         tail = tail->next;
    //     }

    //     // Attach remaining nodes from either list
    //     if (p != nullptr)
    //         tail->next = p;
    //     else
    //         tail->next = q;

    //     // Create a new List to hold the merged result
    //     List *mergedList = new List();
    //     mergedList->head = dummy->next;

    //     // Cleanup: Delete dummy node and invalidate original lists
    //     delete dummy;
    //     head = nullptr;    // Optional: Clear current list
    //     l2.head = nullptr; // Optional: Clear the other list

    //     return mergedList;
    // }

    bool checkLoop()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }

    Node* Cyclenode()
    {
        bool isCycle = false;
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                isCycle = true;
                break;
            }
        }
        if (!isCycle)
        {
           return NULL; 
        }
        slow = head;
        Node *pre =NULL;
        while(slow != fast){
            slow = slow->next;
            pre = fast;
            fast = fast->next;
        }
        pre->next = NULL;//it removies the cycle; 
        return slow;
            
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

// Node *Marge(Node *&head1, Node *&head2)
// {
//     Node *p1 = head1;
//     Node *p2 = head2;
//     Node *dumi = new Node(-1);
//     Node *p3 = dumi;
//     while (p1 != NULL && p2 != NULL)
//     {
//         if (p1->data < p2->data)
//         {
//             p3->next = p1;
//             p1 = p1->next;
//         }
//         else
//         {
//             p3->next = p2;
//             p2 = p2->next;
//         }
//         p3 = p3->next;
//     }
//     while (p1)
//     {
//         p3->next = p1;
//         p1 = p1->next;
//         p3 = p3->next;
//     }
//     while (p2)
//     {
//         p3->next = p2;
//         p2 = p2->next;
//         p3 = p3->next;
//     }
//     return dumi->next;
// }

// Node *RMarge(Node *&head1, Node *&head2)
// {
//     Node *result;
//     if (head1 == NULL)
//     {
//         return head2;
//     }
//     if (head2 == NULL)
//     {
//         return head1;
//     }
//     if (head1->data < head2->data)
//     {
//         result = head1;
//         result->next = RMarge(head1->next, head2);
//     }
//     else
//     {
//         result = head2;
//         result->next = RMarge(head1, head2->next);
//     }
//     return result;
// }
int main()
{
    List l;
    List l2;
    // Node *head1 = NULL;
    // Node *head2 = NULL;

    l2.insert_back(16);
    l2.insert_back(17);
    l2.insert_back(18);
    l.insert_top(1);
    l.insert_back(3);
    l.insert_back(7);
    l.insert_back(7);
    l.insert_back(11);
    l.insert_back(15);
    // l.insert(4, 20);
    // l.Insert_sorted(0);
    // cout << l.isSorted() << endl;

    // l.Display();
    l.removeD();
    // l.pop_top();
    // l.pop_back();
    // l.remove_p(3);
    // l.reverse();
    // l.Reverse(NULL, NULL);
    // l.concat(l2);
    // l.Display();
    List *l3 = new List();
    l3 = l.Merge(l2);
    l3->Display();
    cout << l3->checkLoop();
    // l2.Display();
    // cout << l.count();
    return 0;
}

/* space for kacthra
 void inseart_insorted(int val)
    {
        Node *p = head;
        Node *q = NULL;
        int i = 0;
        while (p)
        {
            i++;
            if (p->data > val)
            {
                break;
            }
            p = p->next;
        }
        if (p == tail)
        {
            insert(i + 1, val);
            return;
        }
        insert(i - 1, val);
    }
*/