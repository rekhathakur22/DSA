#include <bits/stdc++.h>
using namespace std;

// find largest element in array

int brute_force(vector<int> &arr)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());

  return arr[n - 1];
  /*
  tc: O(nlogn) which is tc of sorting n elements , n is num of elements in array
  sc:O(1) using no extra space
  */
}

int optimal(vector<int> &arr)
{
  int max = arr[0];
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
  /*
  tc: O(n), traversing array once , n is number of elements in arr
  sc: O(1), using no extra space
  */
}

int main()
{
  int n;
  cout << "enter the number of elements " << endl;
  cin >> n; // taking input

  vector<int> arr(n);
  cout << "enter the elements " << endl;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i]; // talking input from user
  }
  maxOne(arr);
  int ans = maxTwo(arr);
  cout << ans;

  return 0;
}

/*
array <= 10^6 store in main memory local or global
array > 10^6 use heap or global array
array > 10^9 not feasible to use
*/

/*
Note: this could be more difficult if array size will increase
*/