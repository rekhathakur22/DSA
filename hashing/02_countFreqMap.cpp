#include <bits/stdc++.h>
using namespace std;

// using map
int main()
{
  int n;
  cout << "Enter the length of array" << endl;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  // map
  map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[arr[i]] = mpp[arr[i]] + 1;
  }

  // map stores elements in increasing order
  for (auto it : mpp)
  {
    cout << it.first << "->" << it.second << endl;
  }

  // taking queries from user
  int q;
  cout << "Enter the number of queries" << endl;
  cin >> q;
  while (q--)
  {
    int x;
    cin >> x;
    cout << mpp[x] << endl;
  }
  return 0;
}