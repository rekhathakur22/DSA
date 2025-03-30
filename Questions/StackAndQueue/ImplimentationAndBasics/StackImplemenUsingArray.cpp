#include <iostream>
using namespace std;

class MyStack
{
private:
  int arr[100]; // Array to store stack elements
  int top;      // Index of the top element of stack

public:
  // Constructure to initialize stack
  MyStack() { top = -1; }

  // Function to push an element into stack
  void push(int x);

  // Function to remove an item from top of the stack
  int pop();

  int Stacktop() const
  {
    return top;
  }
};

// Function to push an integer into stack
void MyStack::push(int x)
{

  arr[++top] = x;
}

// Function to remove item from top of the stack
int MyStack::pop()
{
  // Check if the stack is empty
  if (top == -1)
  {
    return -1;
  }

  else
  {
    // Return the top element and decrement the top index
    return arr[top--];
  }
}

int main()
{
  MyStack stack;
  int n, value;

  // Read the number of operation from the user
  cout << "n: ";
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    string operation;
    cout << "op: ";
    cin >> operation;

    if (operation == "push")
    {
      cout << "vl: ";
      cin >> value;
      stack.push(value);
    }

    else if (operation == "pop")
    {
      cout << stack.pop() << endl;
    }

    else if (operation == "top")
    {
      cout << stack.Stacktop() << endl;
    }

    else
    {
      cout << "invalid operation" << endl;
    }
  }

  return 0;
}