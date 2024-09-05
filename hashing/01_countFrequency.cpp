#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cout << "enter number of elements in arr" << endl;

  // ***************** NOTE *****************************
  // * n should be < 10^7
  /* Stack Memory:
  // The main function's local variables, including arrays, are typically stored on the stack. The stack has a limited size, and attempting to allocate a large array like this can exceed that limit, resulting in a stack overflow error.*/

  /*Alternative Approaches:
   * Dynamic Allocation: Use new or std::vector to allocate the array on the heap, which has a much larger memory capacity.
   ** Global or Static Allocation: Declare the array outside the main function, making it either a global variable or a static variable.*/
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int max = *max_element(arr, arr + n);
  int x = max + 1;
  int hash[x] = {0};
  for (int i = 0; i < n; i++)
  {
    hash[arr[i]] = hash[arr[i]] + 1;
  }

  for (int i = 0; i < x; i++)
  {

    cout << hash[i] << " ";
  }

  for (int i = 0; i < n; i++)
  {
    arr[i] = hash[arr[i]];
  }
  cout << endl;
  int q;
  cout << "enter the number of queries" << endl;

  cin >> q;

  while (q--)
  {
    int num;
    cout << "enter the number" << endl;
    cin >> num;
    cout << hash[num] << " ";
  }

  return 0;
}