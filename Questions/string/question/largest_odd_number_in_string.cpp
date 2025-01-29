#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
  string largestOddNumber(string num)
  {
    int n = num.length();
    string ans = "";

    for (int i = n - 1; i >= 0; i--)
    {
      char lastChar = num[i];
      int lastDig = lastChar - '0'; // convert integer char into is decimal value

      if (lastDig % 2 != 0)
      {
        ans = num.substr(0, i + 1); // string_name.substr(initial_index,length)
        return ans;                 // we will return if we find largest odd substring
      }
    }
    return ans;
  }

  string largestOddNumberTwo(string num)
  {
    for (int i = num.length() - 1; i >= 0; i--)
    {
      if (num[i] % 2)
      {
        return num.substr(0, i + 1);
      }
    }
    return "";
  }
};

int main()
{
  string str;
  cout << "Enter the string(string must only contain interger) : " << endl;
  cin >> str;

  Solution s; // creating instance

  string ans = s.largestOddNumberTwo(str);
  cout << "largestOddNumber : " << ans << endl;
  return 0;
}