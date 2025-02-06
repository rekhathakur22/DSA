#include <bits/stdc++.h>
using namespace std;

/*********************************SOLUTION 1************************************* */

vector<int> leaders(int n, int arr[])
{
    // Initialize a vector to store the leaders
    vector<int> ans;

    // Outer loop to consider each element as a candidate for leader
    for (int i = 0; i < n; i++)
    {
        // Reset the flag to true for each element
        bool flg = true;

        // Inner loop to compare the current element with all elements to its right
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                flg = false; // If a larger element is found, this element is not a leader
                break;       // No need to check further, break the loop
            }
        }

        // If no larger element is found on the right, it is a leader
        if (flg)
        {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

/*
Time Complexity:
- Outer loop runs `n` times (for each element).
- Inner loop runs `(n - i - 1)` times for each `i`, where `i` is the index of the current element.
- In the worst case, the inner loop runs a total of approximately `n(n - 1)/2` times (which is O(n^2)).

Thus, the overall time complexity of this code is **O(n^2)**.

Space Complexity:
- The space complexity is **O(k)**, where `k` is the number of leaders found, which in the worst case could be O(n).
*/

/*********************************SOLUTION 2************************************* */
vector<int> leaders(int n, int arr[])
{
    vector<int> ans;

    // The rightmost element is always a leader
    int maxFromRight = arr[n - 1];
    ans.push_back(maxFromRight);

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= maxFromRight)
        {
            // If the current element is greater than or equal to maxFromRight, it's a leader
            ans.push_back(arr[i]);
            maxFromRight = arr[i]; // Update maxFromRight
        }
    }

    // Since we traverse the array from the right, the leaders are stored in reverse order
    reverse(ans.begin(), ans.end()); // Reverse to get correct order

    return ans;
}

/*
Time Complexity: O(n), because we are making a single pass through the array.
Space Complexity: O(k), where k is the number of leaders found.
*/
