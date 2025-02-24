#include <iostream>
using namespace std;

struct Node
{
  int data;   // store data
  Node *next; // store next node address

  // default constructor
  Node() : data(0), next(NULL) {}

  // parameterised constructor
  Node(int val) : data(val), next(NULL) {}
};

class List
{
  Node *head;
  Node *tail;

public:
  List() : head(NULL), tail(NULL) {}

  void push_back(int val)
  {
    Node *newNode = new Node(val);

    if (head == NULL)
    {
      head = tail = newNode;
      return;
    }

    tail->next = newNode;
    tail = newNode;

    return;
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

    return;
  }

  void reverse()
  {
    Node *temp = head;
    Node *prev = NULL; // store address of current node
    Node *nex = NULL;  // store address of next node

    while (temp != NULL)
    {
      if (temp->next == NULL)
        head = temp;
      nex = temp->next;
      temp->next = prev;
      prev = temp;
      temp = nex;
    }
  }
};

int main()
{
  List ll;
  int n;
  cout << "enter the number of elemensts: ";
  cin >> n;

  cout << "enter the elements :" << endl;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;

    ll.push_back(a);
  }

  cout << "end" << endl;

  ll.print();

  ll.reverse();

  ll.print();

  return 0;
}

/*
tc: O(n)
- iterating the complete list just once , n is elements in list

sc:O(1)
- no extra space is used
*/