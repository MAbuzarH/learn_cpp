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
// for deletion we use diffrent rotation
// if we preform deleting from right side so:
// L1 rotation -> it means that  the nodes which height is 1 and imbalance.
// L(-1) rotation -> it means that  the nodes which height is -1 and imbalance.
// L0 rotation -> it means that  the nodes which height is 0 and imbalance we proform either L1 or L(-1) rotations to balance.
// if we preform deleting from left side so:
// R1 rotation -> it means that  the nodes which height is 1 and imbalance.
// R(-1) rotation -> it means that  the nodes which height is -1 and imbalance.
// R0 rotation -> it means that  the nodes which height is 0 and imbalance we proform either R1 or R(-1) rotations to balance
// height vs node analysis
// if height is given so:
// min Nodes n = > N(h) = { 0   0, 1  1, N(h-2)+N(h-1)+1;
// max Nodes n =2^(h)-1;

//  h =  1 | 2 | 3 | 4 | 5 | 6 | 7  //height
// N(h)= 1 | 2 | 4 | 7 | 12| 20| 33 //max node
// so we abserve  from above table

// if n Nodes are given
// min h = log(base 2) *(n + 1)
// max h = see in table
// the formula is fabonachi sereies and this formula is called
// balanced series  its ratio is 1.6

// avl tree's height is alwase logrithamatic

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    Node *lchild;
    int data;
    int height; // height of each node
    Node *rchild;
} *root = NULL;

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalancedFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

struct Node *LLrotation(struct Node *p)
{
    Node *pl = p->lchild;   // 1) pl = left child of p
    Node *plr = pl->rchild; // 2) plr = right child of pl

    pl->rchild = p;  // 3) make p the right child of pl (rotate)
    p->lchild = plr; // 4) attach plr as left child of p

    p->height = NodeHeight(p);   // 5) recompute height of p (now lower)
    pl->height = NodeHeight(pl); // 6) recompute height of pl (new root of subtree)

    if (root == p) // 7) if p was the overall tree root, update it
        root = pl;

    return pl; // 8) return new root of this subtree (pl)
}

struct Node *LRrotation(struct Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;
    return plr;
}
struct Node *RLrotation(struct Node *p)
{
    return NULL;
}
struct Node *RRrotation(struct Node *p)
{
    return NULL;
}

void inorder(Node *p)
{
    if (p == NULL)
        return;
    inorder(p->lchild);
    printf("ND: %d , NH: %d  > ", p->data, p->height);
    inorder(p->rchild);
}

struct Node *Rinsert(struct Node *p, int val)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = val;
        t->height = 1;
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
    p->height = NodeHeight(p);
    if (BalancedFactor(p) == 2 && BalancedFactor(p->lchild) == 1)
        return LLrotation(p);
    else if (BalancedFactor(p) == 2 && BalancedFactor(p->lchild) == -1)
        return LRrotation(p);
    else if (BalancedFactor(p) == -2 && BalancedFactor(p->rchild) == 1)
        return RLrotation(p);
    return p;
}
int main()
{
    root = Rinsert(root, 50);
    Rinsert(root, 15);
    Rinsert(root, 20);
    cout << "Inorder view of AVL Tree \n";
    inorder(root);
    return 0;
}