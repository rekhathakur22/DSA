#include <bits/stdc++.h>
using namespace std;
// Find starting point of cycle in LL

// node structure
struct Node
{
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

// connect nodes
class List
{
  Node *head;
  Node *tail;

public:
  List()
  {
    head = tail = NULL;
  }

  void push_back(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
      head = tail = newNode;
    else
    {
      tail->next = newNode;
      tail = tail->next;
    }
  }

  void print()

  {
    Node *temp = head;
    if (head == NULL)
      return;

    while (temp != NULL)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }

    cout << "NULL" << endl;
  }

  Node *headNode()
  {
    return head;
  }

  void create_cycle(int pos)
  {
    if (pos == -1)
      return;
    Node *temp = head;
    Node *cycleNode = NULL;
    int count = 1;

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

int brute_force(Node *head)
{
  // use hashing tachnique
  map<Node *, int> mpp;
  Node *temp = head;
  while (temp != NULL)
  {
    if (mpp[temp] == 1)
      return temp->data;
    mpp[temp] = 1;
    temp = temp->next;
  }

  return -1;

  /*
  Tc: O(N * 2 * log N)
  - N for traversing the LL , log N for map operations , N is number of nodes in LL
  Sc:O(N)
  - this will store all nodes of LL in worst case
  */
}

int detect_cycle(Node *head)
{
  // use tortoise method
  // initialise the slow and fast pointer
  // to the head of the list
  Node *slow = head;
  Node *fast = head;

  // phase1: detect the loop
  while (fast != NULL && fast->next != NULL)
  {
    // move slow one step
    slow = slow->next;

    // move fast two step
    fast = fast->next->next;

    // if slow and fast meet
    // loop is detected
    if (slow == fast)
    {
      // reset the slow pointer to
      // head of the list
      slow = head;

      // phase2: find the start node of cylce
      while (slow != fast)
      {
        // move slow and fast one step at a time
        slow = slow->next;
        fast = fast->next;

        // if slow and fast meet again
        // it`s a first node of cycle
      }

      return slow->data;
    }
  }

  return -1;

  /*
  tc: O(N)
  - code traverse the entire ll once , N is number of nodes in linked list . Traversal takes linear time complexity;
  sc: O(1)
  - using constant extra space
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
  Node *head = ll.headNode();

  cout << detect_cycle(head);
  return 0;
}
