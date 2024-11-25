#include <bits/stdc++.h>
using namespace std;

// MOORES VOTING ALGORITHM

/*Intuition:
The intuition behind the Moore's Voting Algorithm is based on the fact that if there is a majority element in an array, it will always remain in the lead, even after encountering other elements.
*/

// find majority element
class Solution
{
public:
  // tc O(n)
  // sc O(1)
  int majorityElement(vector<int> &nums)
  {

    int n = nums.size();
    // holds the majority element
    int ele;
    int count = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
      // If count is zero, set the current element as the majority element
      if (count == 0)
      {
        ele = nums[i];
        count++;
      }

      // If the current element is the same as the majority element, increment the count
      else if (nums[i] == ele)
      {
        count++;
      }

      // If the current element is different from the majority element, decrement the count
      else
      {
        count--;
      }
    }

    // Return the majority element
    return ele;
  }
};