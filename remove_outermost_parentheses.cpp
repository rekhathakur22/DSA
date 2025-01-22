#include <iostream>
using namespace std;

//  we have to remove outermost parenthesis
// (()())(()) -> ()()()
class Solution
{
public:
  string outermostParentheses(string s)
  {
    // counts the number of open breakets incounter
    int open = 0;
    string op = "";

    // traverse in string s
    for (int i = 0; i < s.length(); i++)
    {
      // check if string charcter is ( (open bracket or not)
      //  anything in " " consider as string and '' consider as charcter
      // mistake : s[i] == "("
      // s[i] gives character of string and "(" it is string it will type mismatch error
      if (s[i] == '(')
      {
        // if encounter with open bracket just increase the count by one
        open++;

        // if open bracket count is 1 then it means it is outermost bracket
        if (open > 1)
        {
          op = op + "(";
        }
      }

      else
      {
        // if encounter with cose bracket just decrease the count by one
        open--;
        // if open bracket count is 1 then it means it is outermost bracket
        if (open > 0)
        {
          op = op + ")";
        }
      }
    }
    return op;
  }

  string removeOuterParentheses(string S)
  {
    string res;
    int opened = 0;
    for (char c : S)
    {
      if (c == '(' && opened++ > 0)
        res += c;
      if (c == ')' && opened-- > 1)
        res += c;
    }
    return res;
  }
};

int main()
{
  // creating instance of solution class
  Solution obj;

  // input string s
  string s;
  cin >> s;

  // print the output
  cout << obj.outermostParentheses(s) << endl;
  return 0;
}