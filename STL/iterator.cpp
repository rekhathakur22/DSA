#include <bits/stdc++.h>

using namespace std;

int main()
{
  vector<int> v = {1, 2, 3, 4, 5};

  vector<int>::iterator it = v.begin();
  for (it; it != v.end(); it++)
  {
    cout << (*it) << " ";
  }
  cout << endl;
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  for (int &value : v)
  {
    ++value;
  }
  cout << endl;

  for (int value : v)
  {
    cout << value << " ";
  }

  for (auto value : v)
  {
    cout << value << " ";
  }
  return 0;
}
