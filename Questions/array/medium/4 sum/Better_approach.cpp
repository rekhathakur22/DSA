

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size(); // size of the array
    set<vector<int>> st;

    // checking all possible quadruplets:
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        set<long long> hashset;
        for (int k = j + 1; k < n; k++)
        {
          // taking bigger data type
          // to avoid integer overflow:
          long long sum = nums[i] + nums[j];
          sum += nums[k];
          long long fourth = target - sum;
          if (hashset.find(fourth) != hashset.end())
          {
            vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
            sort(temp.begin(), temp.end());
            st.insert(temp);
          }
          // put the kth element into the hashset:
          hashset.insert(nums[k]);
        }
      }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
  }
};
int main()
{
  // vector<int> nums = {1, 0, -1, 0, -2, 2};
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int target;
  cin >> target;
  Solution obj;
  vector<vector<int>> ans = obj.fourSum(nums, target);
  cout << "The quadruplets are: \n";
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < 4; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << "] ";
  }
  cout << "\n";
  return 0;
}

// Time Complexity: O(N3*log(M)), where N = size of the array, M = no. of elements in the set.
// Reason: Here, we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.

// Space Complexity: O(2 * no. of the quadruplets)+O(N)
// Reason: we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).
