#include <bits/stdc++.h>
using namespace std;

// 1. pick the pivot
// 2.place the pivot in its right place
// 3.partition the array by the pivot

// note:
// pivot can be
// 1.first element of array
// 2.last element
// 3.random element
// default its first element

// all the smaller elements less pivot placed at left
// greater elements placed at right

int sort(int arr[], int low, int high)
{
  int pivot = low;
  int i = low;
  int j = high;

  while (i < j)
  {
    while (arr[i] <= arr[pivot] && i <= high)
    {
      i++;
    }
    while (arr[j] > arr[pivot] && j >= low)
    {
      j--;
    }
    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[j], arr[pivot]);
  return j;
}

void quick_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int part_index = sort(arr, low, high);
    quick_sort(arr, low, part_index - 1);
    quick_sort(arr, part_index + 1, high);
  }
}
int main()
{
  int n;
  cout << "enter the no of elements you want to sort" << endl;
  cin >> n;

  int arr[n];
  cout << "enter the elments in array" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  quick_sort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}

// TC
// Best case
// The time complexity is O(n*log(n)). This happens when the pivot is always selected as the middle or closest to the middle element of the array.
// Average case
// The time complexity is O(n*log(n)). This happens when the pivot is not the middle or farthest element of the array.
// Worst case
// The time complexity is O(n^2). This happens when the pivot is consistently selected as the first or last element of the array, resulting in unbalanced partitions

// SC O(1)