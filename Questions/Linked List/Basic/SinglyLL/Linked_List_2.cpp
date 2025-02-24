#include <iostream>
using namespace std;

// individual node creation
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

// link all the nodes

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

    // if list is empty
    if (head == NULL)
    {
      head = tail = newNode;
      return;
    }

    // if list is not empty
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void print()
  {
    Node *temp = head;

    while (temp != NULL)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  void pop_front()
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
      return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
  }

  void pop_back()
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
      return;
    }
    Node *temp = head;
    while (temp->next != tail)
    {
      temp = temp->next;
    }

    temp->next = NULL;
    delete tail;
    tail = temp;
  }

  ~List()
  {
    while (head)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
    cout << "me";
  }
};

// main function
int main()
{
  List ll;
  int n;
  cout << "enter the num of elements: " << endl;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int ele;
    cin >> ele;
    ll.push_back(ele);
  }
  ll.print();
  return 0;
}