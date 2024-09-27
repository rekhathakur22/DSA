class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {

    int n = nums.size();
    /*USING HASHMAP TC O(nlogn)*/

    /*     map<int, int> mpp;
        for (int i = 0; i < n; i++)
         {
         mpp[nums[i]] = mpp[nums[i]] + 1;
        }
       for(int i=0; i<n; i++)
       {
         if(mpp[nums[i]] == 1) return nums[i];
      } */

    /*USING XOR  TC O(N)*/
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans = ans ^ nums[i];
    }
    return ans;
  }
};
