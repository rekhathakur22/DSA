#include <bits/stdc++.h>
using namespace std;

// pick a element and put it into its correct place

void insertion_sort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
      swap(arr[j - 1], arr[j]);
      j--;
      cout << "run" << endl;
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
  insertion_sort(arr, n);
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