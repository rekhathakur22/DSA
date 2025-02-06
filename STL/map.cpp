#include <bits/stdc++.h>
using namespace std;

void print(map<int, string> &mp)
{
  for (auto &value : mp)
  {
    cout << value.first << " " << value.second << endl;
  }
}
int main()
{
  // insertion : tc: O(log(n)) n is size of map
  // access : tc:(log n)
  map<int, string> mp = {{1, "rekha"}, {2, "shobha"}};

  // for (auto &value : mp)
  // {
  //   cout << value.first << " " << value.second << endl;
  // }

  // cout << endl;
  // for (pair<const int, string> &value : mp)
  // {
  //   cout << value.first << " " << value.second << endl;
  // }
  // cout << endl;
  // map<int, string>::iterator it = mp.begin();
  // for (it; it != mp.end(); it++)
  // {
  //   cout << (*it).first << " " << (it->second) << endl;
  // }

  auto it = mp.find(2);
  cout << it.second << endl;

  return 0;
}
