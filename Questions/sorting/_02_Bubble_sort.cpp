#include <bits/stdc++.h>
using namespace std;

// compare two adjacent number and swap them if they are not in correct order
// it puts maximum number at last by swaping two adjacent elements in increasing order

void bubble_sort(int arr[], int n)
{
  for (int i = n - 1; i >= 0; i--)
  {
    int didswap = 0;
    for (int j = 0; j <= i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        diswap = 1;
      }
    }
    if (didswap == 0)
    {
      break;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  bubble_sort(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}

// TC
// best case = O(n)
// average case = O(n^2)
// worst case = O(n^2)
// SC O(1)