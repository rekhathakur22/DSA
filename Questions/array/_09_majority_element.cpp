#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /*
   * sc O(n)
   * tc O(n*logn)
   */
  int majorityElement(vector<int> &nums)
  {
    map<int, int> cnt;
    int n = nums.size();
    int ans;

    for (int i = 0; i < n; i++)
    {
      cnt[nums[i]]++;
    }

    for (auto &it : cnt)
    {
      if (it.second > n / 2)
      {
        ans = it.first;
        break;
      }
    }
    return ans;
  }
};