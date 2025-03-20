#include <iostream>
using namespace std;

// print 1-N using backtracking

void printN(int i, int N)
{
  // base condition
  if (i < 1)
  {
    return;
  }

  // call the function again
  printN(i - 1, N);

  // print i
  cout << i << " ";
}

/*
TC: O(N)
SC:O(N) stack space call
*/

// print N - 1 using backtraking
void printN_1(int i, int N)
{
  // Base condition
  if (i > N)
    return;

  // call the function again
  printN_1(i + 1, N);
  // print i
  cout << i << " ";
}
int main()
{
  int N;
  cin >> N;
  printN_1(1, N);
  return 0;
}