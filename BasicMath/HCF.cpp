#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // GCD (greatest common divisor) or HCF (highest common factor)

  // 1st way to approach
  // in this approach we start finding gcd from 1 in increasing order
  // and check if it is a factor of both numbers
  int gcd_one(int n1, int n2)
  {
    int num = min(n1, n2);
    int gcd = 1;

    for (int i = 1; i <= num; i++)
    {
      if (n1 % i == 0 && n2 % i == 0)
      {
        gcd = i;
      }
    }

    return gcd;
  }

  // time complexity of by this method in wrost case is
  // TC = O(min(n1,n2));
  // SC = O(1);

  // itering from back
  int gcd_two(int n1, int n2)
  {
    int num = min(n1, n2);
    int gcd = 1;

    for (int i = num; i >= 1; i--)
    {
      if (n1 % i == 0 && n2 % i == 0)
      {
        gcd = i;
        break;
      }
    }

    return gcd;
  }
  // wrost case tc is O(min(n1,n2))
  // but in best case it will reduce somehow

  // Euclidean algorithm
  // gcd(a,b)=gcd(a-b,a) a>b
  // gcd(0,a) = a;
  int gcd_three(int n1, int n2)
  {
    while (n1 > 0 && n2 > 0)
    {
      if (n1 > n2)
        n1 = n1 % n2;
      else
        n2 = n2 % n1;
    }

    if (n1 == 0)
      return n2;
    else
      return n1;
  }

  // TC = O(log(min(n1,n2)))
  // SC = O(1)
};

int main()
{
  Solution s;

  int n1, n2;

  // take input
  cin >> n1;
  cout << endl;
  cin >> n2;
  cout << endl;

  cout << "gcd by gcd_one : " << s.gcd_one(n1, n2) << endl;
  cout << "gcd by gcd_two : " << s.gcd_two(n1, n2) << endl;
  cout << "gcd by gcd_three : " << s.gcd_one(n1, n2) << endl;

  return 0;
}
