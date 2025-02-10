#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string sorted_string(string s)
  {
    string ans = ""; // stores the final sorted string

    // map to store frequency of each character
    unordered_map<char, int> mp;

    for (char ch : s) // counting frequency of each char in given string
      mp[ch]++;

    vector<pair<int, char>> vec; // stores char - frequency pair

    // storing freq-char pair in vector
    for (auto value : mp)
      vec.push_back({value.second, value.first});
     
    // sorting vector in decending order of frequency
    sort(vec.begin(), vec.end(), [](pair<int, char> a, pair<int, char> b)
         { return a > b; });

    // Constructing the sorted string based on frequency
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

// time complexity 
// O(n + m log m) where n is length of string and m is unique no of char

// sc : O(n) ans string will store n char 



