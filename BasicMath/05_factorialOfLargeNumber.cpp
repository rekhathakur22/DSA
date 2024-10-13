#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void multiply(vector<int> &arr, int &size, int multiplier)
  {
    // store carry
    int carry = 0;

    for (int i = 0; i < size; i++)
    {
      int res = multiplier * arr[i];

      res = res + carry;

      arr[i] = res % 10;
      carry = res / 10;
    }

    while (carry > 0)
    {
      arr[size] = carry % 10;
      size++;
      carry = carry / 10;
    }
  }
  vector<int> factorial(int N)
  {
    // code here
    // define an an array of large size
    vector<int> arr(10000, 0);

    // set first element of arr to 1
    arr[0] = 1;

    // this is the number of elements stored in the array
    int size = 1;

    // loop to find factorial of N

    for (int multiplier = 2; multiplier <= N; multiplier++)
    {
      // for each multiplier it manage the array digits
      multiply(arr, size, multiplier);
    }

    // result array
    vector<int> result;

    // put all the elements in result array from arr
    for (int i = size - 1; i >= 0; i--)
    {
      result.push_back(arr[i]);
    }

    return result;
  }
};