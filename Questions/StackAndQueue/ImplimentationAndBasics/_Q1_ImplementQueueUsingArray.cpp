#include <iostream>
using namespace std;

class MyQueue
{
private:
  int arr[100]; // Array to store queue elements
  int front;    // Index of the from element
  int rear;     // Index to the next element to be pushed

public:
  // Constructure ot initialize front and rear of queue
  MyQueue()
  {
    front = 0;
    rear = 0;
  }

  // Function to push elements in queue
  void push(int x)
  {

    // Assign the elements to the rear index and increment the rear
    arr[rear++] = x;
  }

  // Function to pop an element from queue and return that element
  int pop()
  {
    if (front == rear)
    {
      return -1; // If the queue is empty , return -1
    }

    else
    {
      return arr[front++]; // Return the front element and increment the front
    }
  }
};

int main()
{
  MyQueue q;
  int n;
  cout << "n: ";
  cin >> n; // Read the number of operation

  for (int i = 0; i < n; i++)
  {
    int type;
    cout << "type: ";
    cin >> type; // Read the type of operation(1 for push , 2 for pop)
    if (type == 1)
    {
      int x;
      cout << "vl: ";
      cin >> x;
      q.push(x);
    }

    else if (type == 2)
    {
      cout << q.pop() << endl;
    }
  }
  return 0;
}