#include <iostream>
#include <vector>
using namespace std;

/*
There total three way to solve this particular problem
-> using two pointer recursion
-> using  loop
-> using single variable recursion
*/

class Solution
{
public:
  void helper(vector<int> &arr, int i, int n)
  {
    if (i >= n / 2)
      return; // base condition

    // swap two elements
    swap(arr[i], arr[n - i - 1]);

    // function call
    helper(arr, i + 1, n);
  }

  void reverseArray(vector<int> &arr)
  {
    int n = arr.size();
    helper(arr, 0, n); // function call
  }
};

int main()
{
  Solution obj;
  int t;    // test cases
  cin >> t; // taking input from user

  while (t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    // solution class object return reverse array
    obj.reverseArray(arr);

    // print the reverse array
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }

    cout << endl;
  }
  return 0;
}
