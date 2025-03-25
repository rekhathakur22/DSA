#include <iostream>
using namespace std;

int fibonacci(int N)
{
  if (N <= 1)
    return 1;
  return fibonacci(N - 1) + fibonacci(N - 2);
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    cout << fibonacci(N);
  }

  return 0;
}

/*
Tc:O(2^n)
- exponential in nature , because every function call couple of functions

Sc:O(N)
- The maximum depth of the recursion tree is N
*/