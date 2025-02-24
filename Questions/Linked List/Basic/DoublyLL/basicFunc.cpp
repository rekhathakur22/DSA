#include <iostream>
using namespace std;

// induvidual node
class Node
{
public:
  int data;   // store value
  Node *next; // store address of next node
  Node *prev; // store address of prev node'

  // constructor
  Node(int val)
  {
    data = val;
    next = prev = NULL;
  }
};

// used to link nodes
class DLL
{
  Node *head;
  Node *tail;

public:
  DLL()
  {
    head = tail = NULL;
  }

  // push_front

  void push_front(int val)
  {
    // create a node
    Node *newNode = new Node(val);

    // if list is empty
    if (head == NULL)
    {
      head = tail = newNode;
      return;
    }
    else
    {
      head->prev = newNode;
      newNode->next = head;
      head = newNode;
    }
  }

  void print()
  {
    Node *temp = head;
    cout << "NULL" << "->";
    while (temp != NULL)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main()
{
  DLL ll;
  ll.push_front(5);
  ll.push_front(4);
  ll.push_front(3);
  ll.print();

  return 0;
}