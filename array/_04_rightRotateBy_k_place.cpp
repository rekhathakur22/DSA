#include <bits/stdc++.h>
using namespace std;

void rotate_array(vector<int> &nums, int k, int n)
{
  vector<int> arr;

  // modifi k
  // note : it would give error if k > n hence k = k %n;

  k = k % n;

  // copy all the elements in arr
  for (int i = 0; i < n; i++)
  {
    arr.push_back(nums[i]);
  }

  int j = 0;

  // rotate the original array with the help of arr
  while (j < k)
  {
    nums[j] = arr[n - k + j];
    j++;
  }

  while (j < n)
  {
    nums[j] = arr[j - k];
    j++;
  }
}

int main()
{
  int n;
  cout << "length of array : 1 <= nums.length <= 10^5" << endl;
  cin >> n;

  int k;
  cout << "enter the no of steps : 0<=k<=10^5" << endl;
  cin >> k;

  vector<int> nums(n);
  cout << "enter the elements in array" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  rotate_array(nums, k, n);
  for (int i = 0; i < n; i++)
  {
    cout << nums[i] << " ";
  }
  return 0;
}