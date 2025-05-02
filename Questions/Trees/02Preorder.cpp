#include <bits/stdc++.h>
using namespace std;

// Preorder Sequence - NLR (root left right)

class Node
{
public:
  Node *left;
  int data;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

static int ind = -1;

Node *buildTree(vector<int> preOrder)
{
  ind++;

  if (preOrder[ind] == -1)
    return NULL;

  Node *root = new Node(preOrder[ind]);

  root->left = buildTree(preOrder);
  root->right = buildTree(preOrder);

  return root;
}

void printTreePre(Node *root)
{
  if (root == NULL)
  {
    cout << -1 << " ";
    return;
  }
  cout << root->data << " ";
  printTreePre(root->left);
  printTreePre(root->right);
}

void printTreeIn(Node *root)
{
  if (root == NULL)
  {
    cout << -1 << " ";
    return;
  }
  printTreeIn(root->left);
  cout << root->data << " ";
  printTreeIn(root->right);
}

void printTreePost(Node *root)
{

  if (root == NULL)
  {
    cout << -1 << " ";
    return;
  }
  printTreePost(root->left);
  printTreePost(root->right);
  cout << root->data << " ";
}
int main()
{
  vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node *root = buildTree(preOrder);
  // cout << root->data << endl;
  // cout << root->left->data << endl;
  // cout << root->right->data << endl;
  printTreePre(root);
  cout << endl;
  printTreeIn(root);
  cout << endl;
  printTreePost(root);
  return 0;
}

/*
Tc:O(n), where n is number of nodes in tree

*/