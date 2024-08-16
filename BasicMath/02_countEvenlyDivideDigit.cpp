#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int evenlyDivide(int N)
  {
    int num = N;
    int count = 0;

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
  int t;
  cin >> t;

  while (t--)
  {
    int N;
    cin >> N;
    cout << sol.evenlyDivide(N) << endl;
  }

  return 0;
}