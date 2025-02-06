#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string sorted_string(string s)
  {
    string ans = ""; // space : O(n)

    // space : O(M)
    unordered_map<char, int> mp;

    //  insertion: O(1)
    // for loop n times
    // tc: O(n*1)
    for (char ch : s)
      mp[ch]++;

    vector<pair<int, char>> vec; // space: O(M)

    for (auto value : mp)
      vec.push_back({value.second, value.first}); // tc: O(M)

    sort(vec.begin(), vec.end(), [](pair<int, char> a, pair<int, char> b)
         { return a > b; }); // tc: O(M logM)

    // O(N)
    for (auto value : vec)
    {
      ans.append(value.first, value.second);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int t;
  cout << "enter the test cases: ";
  cin >> t;

  while (t--)
  {
    string str;
    cout << "enter the string: ";
    cin >> str;
    string result = s.sorted_string(str);
    cout << "output: " << result << endl;
  }
  return 0;
}