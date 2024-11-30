
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findXor(vector<int> &arr, int k)
  {
    int cnt = 0; // Initialize count of subarrays with given xor
    int n = arr.size();
    int zor = 0;       // Variable to store cumulative XOR up to the current index
    map<int, int> mpp; // Map to store the frequency of cumulative XOR values
    mpp[0] = 1;        // Initialize the map with XOR 0 having one occurrence

    // Iterate through each element in the array
    for (int i = 0; i < n; i++)
    {
      zor = zor ^ arr[i]; // Update the cumulative XOR with the current element
      int x = zor ^ k;    // Calculate the required XOR value to find in the map

      // Check if the required XOR value exists in the map
      if (mpp.find(x) != mpp.end())
      {
        cnt += mpp[x]; // If found, add its frequency to the count
      }

      // Increment the frequency of the current cumulative XOR in the map
      mpp[zor]++;
    }
    return cnt;
  }
};
