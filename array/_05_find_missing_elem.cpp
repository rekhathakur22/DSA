#include <bits/stdc++.h>
using namespace std;

/* FIND MISSING ELEMENTS IN ARRAY*/
// 1. sort the array             TC -> O(nlogn)   SC -> (O(1))
// 2. using extra vector         TC -> O(n)   SC -> (O(n))
// 3. using xor                  TC -> O(n)   SC -> (O(1))
// 4. using sum                  TC -> O(n)   SC -> (O(1))

/*SORT THE ARRAY  TC-> O(nlogn)  SC->O(1)*/
class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int ans = n;
    for (int i = 0; i < n; i++)
    {
      if (i != nums[i])
      {
        ans = i;
        break;
      }
    }
    return ans;
  }
};

/*USING EXTRA VECTOR  TC-> O(nlogn)  SC->O(1)*/
class Solution2
{
public:
  int missingNumber(vector<int> &nums)
  {

    int n = nums.size();
    vector<int> temp(n + 1, -1);

    for (int i = 0; i < n; i++)
    {
      temp[nums[i]] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
      if (temp[i] == -1)
        return i;
    }

    return 0;
  }
};

/*USING EXTRA VECTOR  TC-> O(nlogn)  SC->O(1)*/
class Solution3
{
public:
  int missingNumber(vector<int> &nums)
  {

    int n = nums.size();
    // xor all the elements from 1 to n
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      ans = ans ^ i;
    }

    // ans = 1 ^ 2 ^3 ^ ... ^n;

    // eleminate same number from ans and array
    // 2 ^ 2 = 0;
    for (int i = 0; i < n; i++)
    {
      ans = ans ^ nums[i];
    }

    return ans;
  }
};

/*USING SUM  TC-> O(nlogn)  SC->O(1)*/
class Solution4
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;
    return sum - accumulate(nums.begin(), nums.end(), 0);
  }
};

int main()
{
  Solution4 s;
  int n;
  cout << "enter n" << endl;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << "missing num is :" << s.missingNumber(nums) << endl;
  return 0;
}