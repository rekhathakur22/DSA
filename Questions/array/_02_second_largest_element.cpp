#include <bits/stdc++.h>
using namespace std;

// brute force
int sec_largest_one(vector<int> &arr, int n)
{
  sort(arr.begin(), arr.end()); // time complexity Nlog(N)

  int max = arr[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    if (arr[i] < max)
      return arr[i];
  }
}

// optimal
// time complexity O(N)
int sec_largest_two(vector<int> &arr, int n)
{
  int max = arr[0];
  int sec_max = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > max)
    {
      sec_max = max;
      max = arr[i];
    }
  }

  if (sec_max)
    return sec_max;
  else
    return -1;
}

int main()
{
  int n;
  // taking input
  cin >> n;
  vector<int> arr(n);
  // array elements input from user
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int ans = sec_largest_two(arr, n);

  cout << "ans :" << ans << endl;

  return 0;
}

// constraint
// arr[i]>0