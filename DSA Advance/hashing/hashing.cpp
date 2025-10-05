// Hashing
//  hashing is useful for searching
// we use linear and binary search there time complexcity respictively O(n) and O(n log n ) but we need more fast
// if list is sorted then we perform binary search else we prform linear search
// the idea of hashing is we take an arry and on its index we store particular value which is equal to that index eg on index 3 place val 3 so when  we have to find 3 we go to index 3 and this is done in constant time
// drawback:
// we have to take key which size is equal to max value prsent main array so save our self from this much memory consumption we use some mathmatical models
// we use relational maping :
// one one ,many many
// one many, many one
// we map values on hash tables using this function and when we need that value we ask hash function it tells us about value
// the type of hashing is disceus above is one to one hashing and we call it ideal hashing and its drawback is it consume much space
// so to reduce space we modify hash function
// when you modify hash function from ideal to any other function then we face collision fg 5,95,195 try to save on index 5
// to solve this problem of collision we have 2 methord
// open hasing: (chaninig)
// close Hashing : (we have space givin we should only use that)
// we use  open adressing under close hashing here is are mathord used under close hashing
// linear probing ,Quadrating probing,Double hashing
// Now  start Open hashing
// channing
// here we have array of link list or array of chanes eg we have 2 element 5 and 335 so they stor on index 5 as i->5->335 so on
// if elements(n = 100) and size of hashtable is (size 10)
// so here is loading factor lamda = n/size
// analysis of hashing is always done on base of loading factor
// avrage search time = 1+lamda/2
// avrage unsucessful search t = 1+lamda
// select the hash function such that keys are uniformly distributed

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Insert value in sorted order into linked list
void SortedInsert(Node **H, int x) {
    Node *t = new Node;
    t->data = x;
    t->next = NULL;

    if (*H == NULL || (*H)->data >= x) {
        t->next = *H;
        *H = t;
    } else {
        Node *p = *H;
        while (p->next && p->next->data < x)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// Search for key in linked list
Node *Search(Node *p, int key) {
    while (p != NULL) {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// Hash function
int Hash(int key) {
    return key % 10;
}

// Insert into hash table using chaining
void Insert(Node *H[], int key) {
    int index = Hash(key);
    SortedInsert(&H[index], key);
}

// Display hash table
void Display(Node *H[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Bin[" << i << "]: ";
        Node *p = H[i];
        while (p) {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    Node *HT[10];
    for (int i = 0; i < 10; i++)
        HT[i] = NULL;

    Insert(HT, 122);
    Insert(HT, 22);
    Insert(HT, 3222);
    Insert(HT, 45);
    Insert(HT, 35);
    Insert(HT, 25);

    cout << "Hash Table (with Chaining):\n";
    Display(HT, 10);

    Node *s = Search(HT[2], 22);
    if (s)
        cout << "\nFound: " << s->data << endl;
    else
        cout << "\nNot Found!" << endl;

    return 0;
}