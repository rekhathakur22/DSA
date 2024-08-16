#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int evenlyDivide(int N)
  {

    int num = N;
    int count = 0;

    // num is changed based on removel of last digit
    // if lastdigit is not zero and it divides the given number evenly
    // such that remainder is zero then we increase the count by one
    while (num > 0)
    {
      int lastDigit = num % 10;
      if ((lastDigit != 0) && (N % lastDigit == 0))
      {
        count++;
      }
      num = num / 10;
    }

    return count;
  }
};

int main()
{
  Solution sol;
  //  t is the number of test cases
  int t;
  // take the input for test case
  cin >> t;

  while (t--)
  {
    int N;
    // take the input
    cin >> N;
    cout << sol.evenlyDivide(N) << endl;
  }

  return 0;
}