#include <iostream>
using namespace std;

class Solution
{
public:
  bool rotate_string(string s, string goal)
  {
    string newstr = s;
    int i = 0;
    while (i < s.length())
    {
      char ch = s[i];
      newstr.erase(newstr.begin());
      newstr = newstr + ch;
      if (newstr == goal)
        return true;
      i++;
    }
    return false;
  }
};

// main function
int main()
{
  Solution str;
  int t;
  cout << "Enter the number of test cases: ";
  cin >> t;
  while (t--)
  {
    string s, goal;
    cout << "enter the string (only contain lower case letters):" << endl;
    cout << "enter string s: ";
    cin >> s;
    cout << "enter string goal: ";
    cin >> goal;
    bool result = str.rotate_string(s, goal);
    cout << "output: " << result << endl;
  }
  return 0;
}

// tc: O(n) because loop is iterating over string s (n is length of string s)
// sc:O(1) we are not using any extra space