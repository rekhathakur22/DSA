// insert a element at the end of the string

#include <iostream>
using namespace std;

// structure of the linked list node as
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

class Solution
{
public:
  Node *insertAtEnd(Node *head, int x)
  {
    Node *newNode = new Node(x); // new node is created

    // if list is empty
    if (head == NULL)
    {
      head = newNode;
      return head;
    }

    Node *temp = head; // iterator start from head

    while (temp->next != NULL)
    {
      temp = temp->next;
    }

    temp->next = newNode; // as find last node we store address of newNode

    return head;
  }
};

// print the linked list
void print(Node *head)
{ // start
  Node *temp = head;
  if (head == NULL)
    return;

  while (temp != NULL)
  {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
  // end(code)
}

int main()
{
  Node *head = NULL;
  Solution oj;
  int n, val;

  cout << "enter the number of elements to insert: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cout << "enter value: ";
    cin >> val;
    head = oj.insertAtEnd(head, val);
  }

  print(head);

  head = oj.insertAtEnd(head, 6);
  print(head);
  return 0;
}

/*
tc: O(n)
- we traverse the array once to find last node of the list , n is number of elements in linked list

sc: O(1)
- we use any additional space , we just store a single node .
*/