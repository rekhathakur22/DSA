#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> smp;
    unordered_map<char, char> tmp;

    for (int i = 0; i < s.length(); i++)
    {
      if (smp.count(s[i]) && smp[s[i]] != t[i])
        return false;
      if (tmp.count(t[i]) && tmp[t[i]] != s[i])
        return false;

      smp[s[i]] = t[i];
      tmp[t[i]] = s[i];
    }
    return true;
  }
};

int main()
{
  int t;
  cout << "enter the number of test cases" << endl;
  cin >> t;

  while (t--)
  {
    string s;
    cout << "enter the string s: ";
    cin >> s;
    string t;
    cout << "enter the string t: ";
    cin >> t;
    Solution iso;
    bool result = iso.isIsomorphic(s, t);
    cout << "output: " << result << endl;
  }
  return 0;
}

// tc: O(n) because loop is iterating over string (n is length of string)
// sc: O(n) because two unordered maps are used