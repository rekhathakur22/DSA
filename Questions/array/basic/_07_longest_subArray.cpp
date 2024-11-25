#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the length of the longest subarray with a sum equal to the given value K.
 *
 * This function uses a map to store the prefix sums of the array and then iterates
 * through the array to find the longest subarray with a sum equal to K.
 * @param arr The input array.
 * @param n The size of the input array.
 * @param k The target sum.
 * @return The length of the longest subarray with a sum equal to K.
 */

int long_subArray_one(vector<int> &arr, int n, int k)
{
  // TC ~O(n^3)  SC O(1)
  int len = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int sum = 0;
      for (int k = i; k <= j; k++)
      {
        sum = sum + arr[k];
      }
      if (sum == k)
      {
        len = max(len, j - i + 1);
      }
    }
    return len;
  }
}

int long_subArray_two(vector<int> &arr, int n, int k)
{
  // TC ~O(n^2)  SC O(1)
  int len = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum = sum + arr[j];
      if (sum == k)
      {
        len = max(len, j - i + 1);
      }
    }
    return len;
  }
}

int long_subArray_three(vector<int> &arr, int n, int k)
{
  /*
   *Time complexity: O(n log n)
   *Space complexity: O(n)
   */

  map<int, int> preSum; // map for storing sum with corresponding index

  // Initialize the maximum length of the subarray
  int maxLen = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) // starting sum from [0....n]
  {
    // Add current element to the sum
    sum += arr[i];

    // If the sum is equal to K, update the maximum length
    if (sum == k)
    {
      maxLen = max(maxLen, i + 1);
    }

    // Calculate the remaining sum
    int rem = sum - k;

    // If the remaining sum is already in the map, update the maximum length
    if (preSum.find(rem) != preSum.end())
    {
      int len = i - preSum[rem];
      maxLen = max(maxLen, len);
    }

    // If the sum is not already in the map, add it
    if (preSum.find(sum) == preSum.end())
    {
      preSum[sum] = i;
    }
  }

  // Return the maximum length of the subarray
  return maxLen;
}

int long_subArray_four(vector<int> &arr, int n, int k)
{
  // TC ~O(n^2)  SC O(1)
  int sum = 0;
  int maxLen = 0;
  int left = -1;
  int right = 0;

  while (right < n)
  {
    sum += arr[right];
    while (sum > k && left < right)
    {
      sum = sum - arr[left];
      left++;
    }

    if (sum == k)
    {
      maxLen = max(maxLen, right - left);
    }
    right++;
  }

  return maxLen;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int K;
  cout << "enter sum : K" << endl;
  cin >> K;
  int len = long_subArray_four(arr, n, K);
  cout << len;
  return 0;
}