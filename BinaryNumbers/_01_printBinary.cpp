#include <bits/stdc++.h>
using namespace std;

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

  return 0;
}