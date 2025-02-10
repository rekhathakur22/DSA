#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int countFunc(string &s, int k)
  {
    int n = s.length();
    int l = 0;
    int r = 0;
    int count = 0;
    map<char, int> mpp;
    while (r < n)
    {
      mpp[s[r]]++;
      while (mpp.size() > k)
      {
        mpp[s[l]]--;
        if (mpp[s[l]] == 0)
        {
          mpp.erase(s[l]);
        }
        l++;
      }
      count = count + r - l + 1;
      r = r + 1;
    }
    return count;
  }
  int countKdistinct(string &s, int k)
  {
    int count = countFunc(s, k) - countFunc(s, k - 1);
    return count;
  }
};
int main()
{
  Solution s;
  int t;
  cout << "enter the test case: " << endl;
  cin >> t;
  while (t--)
  {
    string str;
    int k;
    cout << "enter the string must contain lowercase letters only: " << endl;
    cin >> str;
    cout << "enter k: ";
    cin >> k;
    int result = s.countKdistinct(str, k);
    cout << "output: " << result << endl;
  }
  return 0;
}

//  tc : O(4N) because countFunc run has tc of O(2N)
// sc: O(26) because we are storing k distinct character
// brute force approach : O(N^2);