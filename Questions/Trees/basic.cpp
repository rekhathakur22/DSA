#include <bits/stdc++.h>
using namespace std;

// key naming
/*
1.nodes->  fundamental element that holds data and can be linked to other nodes
2.root ->  the topmost node
3.Parent-> a node that has a branch (or edge) leading to another node
4.child->a node that is directly below another node in a tree or hierarchical structure
5.leaf->a node that has no child nodes.
6.ancestors->any node on the path from that node to the root of the tree.
7.decendants-> all the nodes that are reachable from a given node by following a path of edges downwards (from parent to child).
8.levels->The level of a node is a count of the edges on the path from the root node to that particular node
9.sibling-> nodes that share the same parent node
10.height->  the number of edges on the longest path from the root node to any leaf node
11.Degree of Node->count of child node
12.Degree of Tree->maximum degree of any node
13.Edges->n-1(n no of nodes in tree)
*/
struct Node
{

  Node *left;
  int data;
  Node *right;

  Node(int x)
  {
    data = x;
    left = right = NULL;
  }
};

int main()
{

  int x;
  cout << "Enter the root node";
  cin >> x;
  int first, sec;
  queue<Node *> q; // it will store address of all nodes

  Node *root = new Node(x); // create root node

  q.push(root);

  // Build the binary tree

  while (!q.empty())
  {

    Node *temp = q.front();
    q.pop();
    cout << "left child temp : " << temp->data << " " << endl;
    cin >> first; // value of left node
    // left node

    if (first != -1)
    {
      temp->left = new Node(first);
      q.push(temp->left);
    }

    // right node
    cout << "right child temp : " << temp->data << " " << endl;
    cin >> sec;
    if (sec != -1)
    {
      temp->right = new Node(sec);
      q.push(temp->right);
    }
  }

  return 0;
}