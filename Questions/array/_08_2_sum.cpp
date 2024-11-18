#include <bits/stdc++.h>
using namespace std;

class Solution
{
  /*
   *time complexity O(n^2)
   *space complexity O(1)
   */
  vector<int> twoSumOne(vector<int> nums, int n, int target)
  {
    // nested loop
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        long long sum = nums[i] + nums[j];
        if (sum == target)
        {
          return {i, j};
        }
      }
    }
    return {};
  }

  /*
   *time complexity O(n)
   *space complexity O(n)
   */
  vector<int> twoSumTwo(vector<int> nums, int n, int target)
  {

    // using map
    map<int, int> mpp;

    // single loop
    for (int i = 0; i < n; i++)
    {
      int complement = target - nums[i];
      if (mpp.find(complement) != mpp.end())
      {
        return {i, mpp[complement]};
      }

      else
      {
        mpp[nums[i]] = i;
      }
    }

    return {};
  }
};