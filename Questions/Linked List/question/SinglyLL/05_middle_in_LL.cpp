#include <bits/stdc++.h>
using namespace std;

/*FIND MIDDLE IN LL*/

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
};

void brute_force(Node *head)
{
  Node *temp = head;
  int n = 0; // store total num of nodes

  // count num of nodes
  while (temp != NULL)
  {
    n++;
    temp = temp->next;
  }

  int mid = (n / 2) + 1; // calculate mid upar bound starting from 1 to n
  temp = head;
  while (mid)
  {
    mid--;
    if (mid == 0)
      cout << temp->data;
    temp = temp->next;
  }

  /*
  tc:O(n+n/2)
  - where n is number of nodes , traversing to find total nodes
  - n/2 is number of nodes we are traversing to find middle node

  sc:O(1)
  -using no extra space
  */
}

void optimal(Node *head)
{
  // Tortoise hare method
  /*intution -> if p1 has speed of x and p2 has x/2 the distance travel by p2 is half of p1
   */
  Node *slow = head; // move with speed x/2;
  Node *fast = head; // move with speed x;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;       // move slow one step
    fast = fast->next->next; // move fast two step
  }
  cout << slow->data << endl;

  /*
  tc: O(N/2)
  - traversing the half nodes of linked list.where N is total number of nodes in LL
  sc:O(1)
  - using constant space
  */
}

// main function
int main()
{
  List ll;
  int n;
  cout << "n: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    ll.push_back(a);
  }
  ll.print();
  Node *head = ll.headNode();
  optimal(head);
  return 0;
}