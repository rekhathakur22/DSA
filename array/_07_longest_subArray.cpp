#include <bits/stdc++.h>
using namespace std;

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
5 int main()
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
  int len = long_subArray_two(arr, n, K);
  cout << len;
  return 0;
}