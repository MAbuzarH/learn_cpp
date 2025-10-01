#include <iostream>
#include "QueueCpp.h"
using namespace std;

class Tree
{
private:
    Node *root;

public:
    Tree() { root = NULL; }
    void createTree();
    void Preorder() { PreOrder(root); };
    void PreOrder(Node *p);
    void InOrder(Node *p);
    void PostOrder(Node *p);
    void LevelOrder(Node *p);

    int Height(Node *root);
    Node *generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
};

void Tree::createTree()
{
    Node *t, *p;
    int x;
    Queue q(100);
    // create(&q,100);

    cout << "Enter value of root:";
    cin >> x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;

    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("eneter left child of %d ", p->data);
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("enter value of right child of %d : ", p->data);
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::PreOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void Tree::PostOrder(Node *p)
{
    if (p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::InOrder(Node *p)
{
    if (p)
    {
        PostOrder(p->lchild);
        cout << p->data << " ";
        PostOrder(p->rchild);
    }
}

int Tree::Height(Node *root)
{

    int x = 0, y = 0;
    if (root == 0)
    {
        return 0;
    }
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

void Tree::LevelOrder(Node *root)
{

    Queue q(100);

    cout << root->data << " ";
    q.enqueue(root);

    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout << root->lchild->data;
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data;
            q.enqueue(root->rchild);
        }
    }
}

int searchInorder(int inArray[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inArray[i] == data)
        {
            return i;
        }
    }
    return -1;
}
Node *Tree::generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd)
{

    static int preIndex = 0;

    if (inStart > inEnd)
    {
        return NULL;
    }
    Node *node = new Node(preorder[preIndex++]);

    if (inStart == inEnd)
    {
        return node;
    }
    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd);

    return node;
}

// count total nodes in tree
int Count(Node *p)
{
    int x, y;

    if (p != NULL)
    {
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int sumOfnodeData(Node *p)
{
    int x, y;

    if (p != NULL)
    {
        x = sumOfnodeData(p->lchild);
        y = sumOfnodeData(p->rchild);
        return x + y + p->data;
    }
    return 0;
}

// height of tree
int heightOfTree(Node *p)
{
    int x, y;

    if (p != NULL)
    {
        x = heightOfTree(p->lchild);
        y = heightOfTree(p->rchild);
        if (x > 1)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    return 0;
}

// number of node have 2 childern
int numOfLeaves(Node *p)
{
    int x, y;

    if (p == NULL) return 0;
    
    if (p->lchild ==NULL && p->rchild == NULL)
    return 1;
        
    
    return numOfLeaves(p->lchild) + numOfLeaves(p->rchild);
}

int main()
{
    Tree bt;

    int preorder[] = {4, 7, 9, 6, 3, 2, 16, 15, 5, 8, 14, 13, 1, 11, 12};
    int inorder[] = {6, 9, 3, 7, 16, 2, 15, 4, 14, 8, 13, 5, 11, 1, 12};

    Node *T = bt.generateFromTraversal(inorder, preorder, 0, sizeof(inorder) / sizeof(inorder[0]) - 1);
    bt.PreOrder(T);

    cout << "\n Number of nodes in tree T: " << Count(T);

    cout << "\n Number of Leaf nodes in tree T: " << numOfLeaves(T);
    // Tree t;
    // t.createTree();

    // //    t.InOrder(t.root);
    // //    t.LevelOrder(t.root);
    // //    t.PostOrder(t.root);
    // //    t.Height(t.root);
    // cout << "PreOrder function \n";
    // t.Preorder();
    return 0;
}