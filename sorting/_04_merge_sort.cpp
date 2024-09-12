#include <bits/stdc++.h>
using namespace std;

// divide & merge
// divide the complete array into two hypothetical array
// play with index for dividing the array into two half

// merge the two half array into one array
void merge(int arr[], int low, int mid, int high)
{
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid)
  {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high)
  {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}

// divide array into two half
void merge_sort(int arr[], int low, int high)
{
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  merge_sort(arr, low, mid);
  merge_sort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

int main()
{
  int n;
  cout << "enter the number of elements you want to sort" << endl;
  cin >> n;

  int arr[n];
  cout << "enter the elements" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  merge_sort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}

// TC
// Best case O(nlogn)
// worst case O(nlogn)
// average case O(n (log n))

// SC
// O(n);
