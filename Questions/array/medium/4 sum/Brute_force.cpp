

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
        for (int k = j + 1; k < n; k++)
        {
          for (int l = k + 1; l < n; l++)
          {
            // taking bigger data type
            // to avoid integer overflow:
            long long sum = nums[i] + nums[j];
            sum += nums[k];
            sum += nums[l];

            if (sum == target)
            {
              vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
              sort(temp.begin(), temp.end());
              st.insert(temp);
            }
          }
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

/* Time Complexity: O(N4), where N = size of the array.
 Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting as we are just sorting 4 elements every time.
 */

// Space Complexity: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.
