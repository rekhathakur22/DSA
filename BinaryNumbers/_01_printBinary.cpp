#include <bits/stdc++.h>
using namespace std;

int bitCount(int n)
{
  int ct = 0;

  for (int i = 10; i >= 0; i--)
  {
    if ((n & (1 << i)) != 0)
    {
      ct++;
    }
  }

  return ct;
}

int main()
{
  int n;
  cin >> n;
  cout << "print binary of n" << endl;
  cout << bitset<12>(n);

  // check a^th bit of any number if set or not

  int a;
  cin >> a;

  if ((n & (1 << a)) != 0)
  {
    cout << "bit is set" << endl;
  }
  else
  {
    cout << "bit is unset" << endl;
  }

  // set a^th bit of any number

  int setBit = n | (1 << a);
  cout << "after bit set n is:" << bitset<10>(setBit) << endl;

  int unsetBit = n & ~(1 << a);
  cout << "after bit unset n is:" << bitset<10>(unsetBit) << endl;

  int toggleBit = n ^ (1 << a);
  cout << "after bit toggle n is:" << bitset<10>(toggleBit) << endl;

  cout << "set bit count is " << bitCount(n);
  return 0;
}