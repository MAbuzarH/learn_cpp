#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int val)
    {
        data = val;
        lchild = rchild = NULL;
    }
};

// build tree by geting preorder array

Node *buildTree(vector<int> pre, int &index)
{
    index++;

    if (index >= pre.size() || pre[index] == -1)
    {
        return NULL;
    }

    Node *root = new Node(pre[index]);
    root->lchild = buildTree(pre, index); // LEFT
    root->rchild = buildTree(pre, index); // RIGHT
    return root;
}

void Preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Preorder(root->lchild);
    Preorder(root->rchild);
}

void Postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Postorder(root->lchild);
    Postorder(root->rchild);
    cout << root->data << " ";
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->lchild);
    cout << root->data << " ";
    Inorder(root->rchild);
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL); // marker for end of first level

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            cout << "\n"; // end of level
            if (!q.empty())
            {
                q.push(NULL); // marker for next level
            }
        }
        else
        {
            cout << curr->data << " ";

            if (curr->lchild != NULL)
            {
                q.push(curr->lchild);
            }
            if (curr->rchild != NULL)
            {
                q.push(curr->rchild);
            }
        }
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftH, rightH;
    leftH = height(root->lchild);
    rightH = height(root->rchild);

    return max(leftH, rightH) + 1;
}

int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftN, rightN;
    leftN = count(root->lchild);
    rightN = count(root->rchild);

    return (leftN + rightN) + 1;
}

int sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftS, rightS;
    leftS = sum(root->lchild);
    rightS = sum(root->rchild);

    return leftS + rightS + root->data;
}

bool identical(Node *p, Node *q)
{
    if (p == NULL || q == NULL)
    {
        return p == q;
    }
    bool isLeftS, isRightS;
    isLeftS = identical(p->lchild, q->lchild);
    isRightS = identical(p->rchild, q->rchild);
    return (isLeftS && isRightS && p->data == q->data);
}

// recursive search in Binary search tree
Node *rBsearch(Node *t, int key)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->data == key)
    {
        return t;
    }
    if (t->data < key)
    {
        return rBsearch(t->lchild, key);
    }
    if (t->data > key)
    {
        return rBsearch(t->rchild, key);
    }
}

// hear p is tree and q is sub tree;
bool isSubtree(Node *p, Node *q)
{
    if (p == NULL || q == NULL)
    {
        return p == q;
    }

    if (p->data == q->data && identical(p, q))
    {
        return true;
        // bool isr, isl;
        // isl = isSubtree(p->lchild, q->lchild);
        // isr = isSubtree(p->rchild, q->rchild);
        // return isl && isr ;
    }

    return isSubtree(p->lchild, q) || isSubtree(p->rchild, q);
    // return isr || isl;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1};
    vector<int> pret1 = {
        30,
        20,
        45,
    };
    // vector<int> preorder = {1, 2, 4, -1, -1, 5 - 1, -1, 3, 6, -1, 7, -1, };
    int index = -1;
    cout << "Starting Program! \n";
    Node *root = buildTree(preorder, index);

    cout << "\n Printed in pre Order \n";
    Preorder(root);

    cout << "\n Printed in post Order \n";
    Postorder(root);

    cout << "\n Printed in  InOrder \n";
    Inorder(root);

    cout << "\n Printed in  Level Order \n";
    levelOrder(root);

    cout << "Hight of Tree: " << height(root) << endl;
    cout << "Total node of Tree: " << count(root) << endl;
    return 0;
}