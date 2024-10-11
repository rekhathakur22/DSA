#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int n = nums.size();
    int breakPoint = -1;

    // Step 1: Find the first decreasing element from the right
    for (int i = n - 2; i >= 0; i--)
    {
      if (nums[i] < nums[i + 1])
      {
        breakPoint = i;
        break;
      }
    }

    // Step 2: If there's a breakPoint, find the next larger element and swap
    if (breakPoint != -1)
    { // Only perform swap if a valid breakPoint is found
      for (int i = n - 1; i > breakPoint; i--)
      {
        if (nums[i] > nums[breakPoint])
        {
          swap(nums[i], nums[breakPoint]);
          break;
        }
      }
    }

    // Step 3: Reverse the elements from breakPoint + 1 to the end of the array
    reverse(nums.begin() + breakPoint + 1, nums.end());
  }
};
