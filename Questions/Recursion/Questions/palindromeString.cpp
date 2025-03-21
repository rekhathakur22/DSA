#include <iostream>
using namespace std;

class Solution
{
public:
  bool helper(int i, int n, string s)
  {
    if (i >= n / 2)
      return true;

    if (s[i] != s[n - i - 1])
      return false;

    return helper(i + 1, n, s);
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