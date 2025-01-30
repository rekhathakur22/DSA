#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    if (strs.empty())
      return ""; // Handle empty input

    string ans = "";
    sort(strs.begin(), strs.end()); // Sort lexicographically
    int n = strs.size();
    string first = strs[0], last = strs[n - 1];

    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
      if (first[i] != last[i])
      {
        return ans;
      }
      ans = ans + first[i];
    }

    return ans;
  }
};

int main()
{
  vector<string> num;
  int n;
  cout << "Enter the size of string vector: ";
  cin >> n;

  while (n)
  {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    num.push_back(str);
    n--;
  }

  Solution s;
  string result = s.longestCommonPrefix(num);
  cout << "output: " << result << endl;

  return 0;
}

