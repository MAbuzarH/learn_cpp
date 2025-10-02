// 2_3 search tree they are also called multi way tree or m_way search tree in 2_3 trees ,2 keys and 3 children
// 2_3 are search tree with degree 3 and they are height balanced search trees so B_tress here B is degree
// two rules are applied to balance tree:
// all leaf nodes at same level
// every node must have atleast half of children seel(n/2)
// root can have minimum 2 children
// creation process is bottom up
// every node have 3 chiled left middel and right chiled
// we have 2 keys k1 < k2
// all the keys in Left child:   l < k1
// all the keys in right child:  n > k2
// all the keys in Middle child: k1 < m <k2
// keys must arrange in sorted ordered
// binary trees grows downword  but B-trees(Search tree) Grow upword
// while inserting we we split node
// while deletion we have 3 cases
// case 1: simple delete
// case 2:delete and marge
// case 3:Borrow
// on deleting first try to borrow and then marge
// height vs Node analises
// min n = 2(h+1)-1
// max n =3^(h+1) - 1 / 3 - 1
// max h = log(base 2)*(n)
// min h = log(base 3)*(n)
// we say min && max height is log n
// B->trees or B+->trees are used in DBMS (data base management system )
// 2_3 tree is type of B-Tree
// storing the data on Disk is all about DBMS
// processing data on main memory (RAM) is all about Data structure
// we need self managed multi level indexs to represent a block of data in main memory to reduce size of search so B && b+ trees are came into they create index and delete atomaticaly if more data come and remove from main memory
// we use these trees for multilevel indexs where each key in a node has a child pointer and a pointer to record
// in m_way search tree we have a problem we have not control on node creation some time there is avaliable space in parent node but it create new node example insertion(10,20,20) this create 3 node first for 10 then 20 then 30 to solve this problem we use B trees
// B trees are nothing but m_way tree with some rules
// in B+ trees we have record pointers only from leaf nodes
// and every key has its copy in leaf node and all leaf nodes
// are connected as a linkedlist;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    vector<int> keys;        // can hold 1 or 2 keys
    vector<Node *> children; // can hold 0, 2 or 3 children
    bool isLeaf;

    Node(bool leaf = true)
    {
        isLeaf = leaf;
    }
};

// Utility: print inorder
void inorder(Node *root)
{
    if (!root)
        return;

    if (root->isLeaf)
    {
        for (int k : root->keys)
            cout << k << " ";
    }
    else
    {
        for (int i = 0; i < root->keys.size(); i++)
        {
            inorder(root->children[i]);
            cout << root->keys[i] << " ";
        }
        inorder(root->children.back());
    }
}

// Split a full child (has 3 keys)
void splitChild(Node *parent, int i)
{
    Node *fullChild = parent->children[i];

    Node *left = new Node(fullChild->isLeaf);
    Node *right = new Node(fullChild->isLeaf);

    // Distribute keys
    left->keys.push_back(fullChild->keys[0]);
    right->keys.push_back(fullChild->keys[2]);

    // Middle key goes up
    int middle = fullChild->keys[1];

    // If not leaf, split children too
    if (!fullChild->isLeaf)
    {
        left->children.push_back(fullChild->children[0]);
        left->children.push_back(fullChild->children[1]);

        right->children.push_back(fullChild->children[2]);
        right->children.push_back(fullChild->children[3]);
    }

    // Insert into parent
    parent->keys.insert(parent->keys.begin() + i, middle);
    parent->children[i] = left;
    parent->children.insert(parent->children.begin() + i + 1, right);

    delete fullChild; // free old node
}

// Insert into non-full node
void insertNonFull(Node *node, int val)
{
    if (node->isLeaf)
    {
        // Insert in sorted order
        node->keys.push_back(val);
        sort(node->keys.begin(), node->keys.end());
    }
    else
    {
        int i = node->keys.size() - 1;
        while (i >= 0 && val < node->keys[i])
            i--;
        i++;

        // If child is full (3 keys), split it
        if (node->children[i]->keys.size() == 3)
        {
            splitChild(node, i);
            if (val > node->keys[i])
                i++;
        }
        insertNonFull(node->children[i], val);
    }
}

// Insert into 2-3 tree
void insert(Node *&root, int val)
{
    if (!root)
    {
        root = new Node();
        root->keys.push_back(val);
        return;
    }

    if (root->keys.size() == 3)
    {
        Node *newRoot = new Node(false);
        newRoot->children.push_back(root);
        splitChild(newRoot, 0);
        root = newRoot;
    }

    insertNonFull(root, val);
}

int main()
{
    Node *root = NULL;

    vector<int> values = {10, 20, 30, 40, 50, 60, 70};

    for (int v : values)
    {
        insert(root, v);
    }

    cout << "Inorder traversal of 2-3 tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
