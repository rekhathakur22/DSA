#include <bits/stdc++.h>
using namespace std;

// node structure
class Node
{
public:
  int data;
  Node *next;

  // default constructure
  Node()
  {
    data = 0;
    next = NULL;
  }

  // parameterised constructure
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

// create linked list and return head pointer
Node *constructLL(vector<int> &arr)
{
  Node *head = NULL;
  Node *tail = NULL;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    Node *newNode = new Node(arr[i]);
    // if list is empty
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
  // end(code)
  return head;
}

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
  int n;
  cout << "enter the number of elements: ";
  cin >> n;

  vector<int> arr;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    arr.push_back(a);
  }

  Node *head = constructLL(arr);

  print(head);

  // end(code)
  return 0;
}