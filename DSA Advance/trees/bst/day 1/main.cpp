// all nodes in BST must be unique
// left child value is smaller than root value
// right child value grater than root value
//  left < parent < rifgt
// inorder triversal is alwase sorted
// if you want to delete a node
// its inorder presessor and inorder successor will takes its place;
// in order presessor :in left subtree right most node
// in order sucessor:in right left most node
#include <iostream>
#include <vector>
#include <string.h>
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

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
}

void IterativeInsert(Node *&root, int val) // pass by reference
{
    Node *r = NULL, *p, *t = root;

    if (t == NULL)
    {
        root = new Node(val); // new root
        return;
    }

    while (t != NULL)
    {

        r = t; // keep track of parent

        if (val < t->data)
        {
            t = t->lchild;
        }
        else if (val > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return; // value already exists
        }
    }

    p = new Node(val);
    if (val < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

Node *inscert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->lchild = inscert(root->lchild, val);
    }
    else
    {
        root->rchild = inscert(root->rchild, val);
    }
    return root;
}

Node *bulitBST(vector<int> arr)
{
    Node *root = NULL;

    for (int val : arr)
    {
        root = inscert(root, val);
    }
    return root;
}

bool searchBST(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (key == root->data)
    {
        return true;
    }

    if (key < root->data)
    {
        return searchBST(root->lchild, key);
    }
    if (key > root->data)
    {
        return searchBST(root->rchild, key);
    }
}

Node *getInorderSuccessor(Node *root)
{
    cout << "getInorderSuccessor used \n";
    while (root != NULL && root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}

Node *getInorderPressor(Node *root)
{
    cout << "getInorderPressor used \n";
    while (root != NULL && root->rchild != NULL)
    {
        root = root->rchild;
    }
    return root;
}

// recursive approach working
//  Node *delNode(Node *root, int key)
//  {
//      if (root == NULL)
//      {
//          return NULL;
//      }
//      if (key < root->data) // key <=Node->data
//      {
//          root->lchild = delNode(root->lchild, key);
//      }
//      else if (key > root->data)
//      {
//          root->rchild = delNode(root->rchild, key);
//  //     }
//      else
//      { // key == Node->data
//          if (root->lchild == NULL)
//          {
//              Node *temp = root->rchild;
//              delete root;
//              return temp;
//          }
//          else if (root->rchild == NULL)
//          {
//              Node *temp = root->lchild;
//              delete root;
//              return temp;
//          }
//          else
//          {
//              // direct case for 2 childern
//              Node *IS = getInorderSuccessor(root->rchild);
//              root->data = IS->data;
//              root->rchild = delNode(root->rchild, IS->data);
//          }
//      }
//      return root;
//  }

// height of tree
int Height(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

// recursive approach another method
Node *delNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        delete root;
        return NULL;
    }
    if (key < root->data) // key <=Node->data
    {
        root->lchild = delNode(root->lchild, key);
    }
    else if (key > root->data)
    {
        root->rchild = delNode(root->rchild, key);
    }
    else
    {
        if (Height(root->lchild) > Height(root->rchild))
        {
            Node *IP = getInorderPressor(root->lchild);
            root->data = IP->data;
            root->lchild = delNode(root->lchild, IP->data);
        }
        else
        {
            Node *IS = getInorderSuccessor(root->rchild);
            root->data = IS->data;
            root->rchild = delNode(root->rchild, IS->data);
        }
    }
    return root;
}
void allPath(Node *root, string path, vector<string> &ans)
{
    if (root->lchild == NULL && root->rchild == NULL)
    {
        ans.push_back(path);
        return;
    }
    if (root->lchild)
    {
        allPath(root->lchild, path + "->" + to_string(root->lchild->data), ans);
    }
    if (root->rchild)
    {
        allPath(root->rchild, path + "->" + to_string(root->rchild->data), ans);
    }
}
int main()
{

    // build BST using recurission
    //  vector<int> arr = {30, 15, 45, 12, 19, 20, 46};
    vector<int> arr = {50, 10, 40, 20, 30};
    Node *root = bulitBST(arr);

    printf("inorder \n");

    // adding elements to BST
    // Node *root = NULL;
    // IterativeInsert(root, 50);
    // IterativeInsert(root, 30);
    // IterativeInsert(root, 70);
    // // IterativeInsert(root, 20);
    // IterativeInsert(root, 40);
    // IterativeInsert(root, 66);
    // IterativeInsert(root, 10);

    // print all paths from node to leaves
    // string path = to_string(root->data);
    // vector<string> ans;
    // allPath(root, path, ans);
    // for (int i = 0; i <= ans.size(); i++)
    // {
    //     cout << ans[i] << endl;
    // }

    // print inorder BST
    inorder(root);
    cout << "\n";
    // delete any node from tree
    delNode(root, 50);

    // delNode(root, 30);

    cout << "\n";
    inorder(root);

    // search in binary search tree
    //  int key = 46;
    //  cout << "\n Found Key: " << searchBST(root, key) << endl;

    return 0;
}