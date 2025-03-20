#include <iostream>
using namespace std;

// parameterised recursion
int sum1_N(int N, int sum)
{
  // base condition
  if (N < 1)
    return sum;

  sum = sum + N;      // sum calculated
  sum1_N(N - 1, sum); // function call
}

// Functional recursion
int functoionSum1_N(int N)
{
  // base condtion
  if (N < 1)
    return 0;
  return N + functoionSum1_N(N - 1);
}

int main()
{
  int N;
  cin >> N;
  int sum = 0;
  int ans = functoionSum1_N(N);
  cout << ans << endl;
  return 0;
}