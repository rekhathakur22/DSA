#include <iostream>
using namespace std;

class Solution
{
public:
  bool helper(int i, int n, string s)
  {
    if (i >= n / 2) // base condition
      return true;

    if (s[i] != s[n - i - 1]) // if corresponding reverse elements are not equal
      return false;

    return helper(i + 1, n, s); // check for next two values;
  }

  bool isPalindrome(string s)
  {
    int n = s.length();

    return helper(0, n, s);
  }
};

int main()
{
  Solution obj;
  int t;    // test cases
  cin >> t; // taking input form user

  while (t--)
  {
    string s;
    cin >> s; // taking input from user

    // creating solution class object and check string is palindrome or not

    cout << obj.isPalindrome(s);
  }
  return 0;
}