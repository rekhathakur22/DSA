class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size(); // size of the array
    vector<vector<int>> ans;

    // sort the given array
    sort(nums.begin(), nums.end());

    // calculating the quadruplets:
    for (int i = 0; i < n; i++)
    {
      // avoid the duplicates while moving i:
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      for (int j = i + 1; j < n; j++)
      {
        // avoid the duplicates while moving j:
        if (j != i + 1 && nums[j] == nums[j - 1])
          continue;
        // 2 pointers:
        int left = j + 1;
        int right = n - 1;

        while (left < right)
        {
          long long sum = nums[i] + nums[j];
          sum += nums[left];
          sum += nums[right];
          if (sum == target)
          {
            vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
            ans.push_back(temp);
            left++;
            right--;
            // skip the duplicates:
            while (left < right && nums[left] == nums[left - 1])
              left++;
            while (left < right && nums[right] == nums[right + 1])
              right--;
          }
          else if (sum < target)
            left++;

          else
            right--;
        }
      }
    }

    return ans;
  }
};

// Time Complexity: O(N3), where N = size of the array.
// Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3).

// Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity