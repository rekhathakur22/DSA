#include <iostream>
using namespace std;

// individual node
class Node
{
public:
  int data;
  Node *next;

  // constructure to initialize the node
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

// we created a single node
// now we have to connect them
// each list must have address of starting node as head ptr
// also it have to maintain tail ptr

class List
{
  Node *head;
  Node *tail;

public:
  List()
  {
    head = tail = NULL;
  }

  // push_front ()
  // before impliment push on ll there could be two condition
  // either a ll is empty head=NUll
  // or it may contain some values;
  void push_front(int val)
  {

    Node *newNode = new Node(val); // dynamic memory allocation object
    // Node newNode(val); static memory allocation for object

    // if list is empty head is null
    if (head == NULL)
    {
      head = tail = newNode;
    }
    // if list is not empty
    else
    {
      newNode->next = head; //((*newNode).next = head)
      head = newNode;
    }
  }

  void print()
  {
    Node *temp = head;

    while (temp != NULL)
    {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

// each linked must have some function
// push_front(),push_back(),pop_front(),pop_back()

int main()
{
  List ll;
  ll.push_front(5);
  ll.push_front(10);
  ll.push_front(1);
  ll.push_front(2);
  ll.print();

  return 0;
}