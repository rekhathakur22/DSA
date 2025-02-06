
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

/*
Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array. Point to remember for unordered_map in the worst case, the searching time increases to O(N), and hence the overall time complexity increases to O(N2).

Space Complexity: O(N) as we are using a map data structure.
*/