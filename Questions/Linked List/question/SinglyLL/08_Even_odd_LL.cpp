#include <iostream>
#include <unordered_set>
using namespace std;

// structure of singly list
struct Node
{
  int data;
  Node *next;
  Node(int val) : data(val), next(NULL) {}
};

class Solution
{
public:
  // function to segrregate even and odd indices
  Node *seggregateEvenOdd(Node *head)
  {
    // if length of ll is 0,1,2 it will remail unchanged;
    if (head == NULL || head->next == NULL || head->next->next == NULL)
      return head;

    Node *evenHead = head->next; // head of even indices list
    Node *odd = head;            // traverse in all odd indices
    Node *even = head->next;     // traverse in all even indices

    // traverse until we find last node of odd indices
    while (odd->next != NULL && odd->next->next != NULL)
    {
      // link current odd index to next odd index
      odd->next = odd->next->next;
      // move odd index to next odd index
      odd = odd->next;

      // link current even index to next even index
      even->next = even->next->next;

      // move even index to next even index
      even = even->next;
    }

    // connect odd index linked list to even index linked list
    odd->next = evenHead;

    return head;

    /*
    tc:O(N)
    -there is two operation in linked list each of them taking N/2 time,N is nodes in LL
    sc:O(1)
    - using constant space
    */
  }
};

// main function
int main()
{
  int n;
  cin >> n; // input number of nodes in LL

  unordered_set<Node *> nodes;
  Node *head = NULL;
  Node *tail = NULL;

  // creating linked list
  for (int i = 0; i < n; i++)
  {
    int value;
    cin >> value;
    Node *newNode = new Node(value);
    nodes.insert(newNode);
    if (head == NULL)
    {
      head = tail = newNode;
    }

    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // creating solution class object and seggragate even odd indices in linked list
  Solution sol;
  head = sol.seggregateEvenOdd(head);

  // print Linked List
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;

  // delete the linked list to prevent memory leak
  for (auto node : nodes)
  {
    delete node;
  }
  return 0;
}