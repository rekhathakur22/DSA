#include <bits/stdc++.h>
using namespace std;

// APPROCH
// 1.brute force
// 2.better
// 3. optimal

// brute force solution
void maxOne(vector<int> &arr)
{
  sort(arr.begin(), arr.end());
  // TC
  // nlog(n)
}

// optimal solution
int maxTwo(vector<int> &arr)
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
}

int main()
{
  int n;
  cout << "enter the number of elements " << endl;
  // taking input
  cin >> n;
  vector<int> arr(n);
  cout << "enter the elements " << endl;
  // talking input from user
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  maxOne(arr);
  int ans = maxTwo(arr);
  cout << ans;

  return 0;
}