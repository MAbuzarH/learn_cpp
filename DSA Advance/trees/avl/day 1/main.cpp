// in avl we control height using balance factor
// bf = height of leftsubtree - height of right subtree
// bf must be{-1 | 0 | 1}
// absolute value of balance factor is less than or equal to 1 or bf = | hl - hr| <= 1;
//  if bf = | hl - hr| > 1 node is imbalanced;
//  we balanced tree using rotations
//  if any nood is imbalanced tree is imbalanced
//  for finding balanced fector we count height not nodes
//  we do some rotation to balance tree
//  LL ,LR ,RR  , RL
//  we used left left rotation  to solve to left left imbalance this is also called right or clock wise rotation
//  we used right right rotation  to solve to right right imbalance this is also called left or anti clock wise rotation
//  we used left right rotation  to solve to left right imbalance this is also called double rotation
//  we used  right left rotation  to solve to  right left imbalance this is also called double rotation
#include <iostream>

using namespace std;
struct Node
{
    Node *lchild;
    int data;
    int height; // height of each node
    Node *rchild;
} *root = NULL;

struct Node *Rinsert(struct Node *p, int val)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = val;
        t->height = 0;
        t->lchild = t->rchild = NULL;
        p = t;
        return p;
    }
    if (val < p->data)
    {
        p->lchild = Rinsert(p->lchild, val);
    }
    else
    {
        p->rchild = Rinsert(p->rchild, val);
    }
    return p;
}
int main()
{

    return 0;
}