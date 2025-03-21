#include <iostream>
using namespace std;

// Factorial of N
// fac(N)-> N*fac(N-1)

// Functional recursion
int factorial(int N)
{

  if (N == 0)
    return 1;
  return N * factorial(N - 1);
}

// Parameterised recursion
int factorial_N(int N, int fac)
{
  if (N == 0)
    return fac;
  fac = fac * N;
  factorial_N(N - 1, fac);
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int N;
    cin >> N;
    cout << factorial_N(N, 1);
  }

  return 0;
}