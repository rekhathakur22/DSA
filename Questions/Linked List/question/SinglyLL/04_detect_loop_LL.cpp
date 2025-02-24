#include <bits/stdc++.h>
using namespace std;
// detect loop in linked list

// node structure
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
  Node *head;
  Node *tail;

public:
  List()
  {
    head = tail = NULL;
  }
  Node *node()
  {
    return head;
  }
  void push_back(int val)
  {
    Node *newNode = new Node(val);

    if (head == NULL)
    {
      head = tail = newNode;
    }

    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  };

  void print()
  {
    if (head == NULL)
      return;
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  void create_cycle(int pos)
  {
    if (pos == -1)
      return;
    Node *temp = head;
    Node *cycleNode = NULL;
    int count = 0;

    while (temp->next != NULL)
    {
      if (count == pos)
        cycleNode = temp;
      temp = temp->next;
      count++;
    }
    if (cycleNode != NULL)
    {
      temp->next = cycleNode;
    }
  }
};

bool brute_force(Node *head)
{
  map<Node *, int> mpp; // if node appear marked 1 , if not appears marked 0
  Node *temp = head;

  while (temp != NULL)
  {
    if (mpp[temp] == 1)
      return true;
    mpp[temp] = 1; // insertion tc(log n)
    temp = temp->next;
  }

  return false;

  /*
  tc: O(n *2*log n)
  -n for traversing and log n for insertion in ordered map , n is number of nodes is LL
  sc: O(n)
  - store nodes address in map , n is num of nodes
  */
}

bool optimal(Node *head)
{
  // using tortoisehare algorithm
  Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    if (slow == fast)
      return true;
    slow = slow->next;
    fast = fast->next;
  }
  return false;
  /*
  tc: ~O(N)
  - it will depend upon different test cases, N is num of nodes in LL
  sc: O(1)
  - using no extra space
  */
}

int main()
{
  List ll;
  int n;
  cout << "enter the number of elements: ";
  cin >> n;

  int pos;
  cout << "enter the pos you want to create cycle: ";
  cin >> pos;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    ll.push_back(a);
  }

  ll.create_cycle(pos);
  Node *head = ll.node();
  cout << optimal(head);
  return 0;
}