#include <iostream>
#include <cmath> // To use sqrt() function
using namespace std;

/*********************PRINT ALL DIVISORS IN SORTED ORDER****************** */

// Function to print all divisors of a given number 'n'
void print_divisors(int n)
{

  // Loop to find divisors from 1 to sqrt(n)
  // This loop runs until 'i * i <= n' (i.e., i <= sqrt(n))
  for (int i = 1; i * i <= n; i++)
  {
    // If 'i' divides 'n' perfectly, then 'i' is a divisor
    if (n % i == 0)
    {
      cout << i << " "; // Print the divisor
    }
  }

  // Loop to find divisors greater than sqrt(n)
  // Start from sqrt(n) and go down to 1
  for (int i = sqrt(n); i >= 1; i--)
  {
    // If 'i' divides 'n' perfectly
    if (n % i == 0)
    {
      // 'n / i' will be the corresponding divisor paired with 'i'
      // We ensure that 'n / i' is not the same as 'i' (to avoid duplicates when n is a perfect square)
      if (n / i != i)
      {
        cout << n / i << " "; // Print the corresponding divisor
      }
    }
  }
}

/*
    Time Complexity (TC):
    - First loop runs up to sqrt(n): O(sqrt(n))
    - Second loop runs from sqrt(n) to 1: O(sqrt(n))
    - Total TC = O(sqrt(n)) + O(sqrt(n)) = O(sqrt(n))

    Space Complexity (SC):
    - The function uses a constant amount of extra space for variables i and n
    - Total SC = O(1) (constant space)
*/

int main()
{
  int n;
  cin >> n;
  print_divisors(n); // Call the function
  return 0;
}
