#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    map<int, int> hash;
    vector<int> ans;
    int key = nums.size() / 3;
    for (int i = 0; i < nums.size(); i++) // O(N)
    {
      hash[nums[i]] = hash[nums[i]] + 1; // O(log N)
    }

    for (auto it : hash)
    {
      if (it.second > key)
      {
        ans.push_back(it.first);
      }
    }
    return ans;
  }
};

int main()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  Solution solution;
  vector<int> result = solution.majorityElement(nums);
  cout << endl;
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}