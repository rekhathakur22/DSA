#include <iostream>
using namespace std;

//  we have to remove outermost parenthesis
// (()())(()) -> ()()()
class Solution
{
public:
  string outermostParentheses(string s)
  {
    string op = ""; // empty string to store final output
    int open = 0;   // track open brackets or balance

    // iterate trough each character of string
    for (int i = 0; i < s.length(); i++)
    {

      if (s[i] == '(') // if open bracket encounter
      {

        open++; // increase the count by one

        if (open > 1) // if open bracket count is 1 then it means it is outermost bracket
        {
          op = op + "("; // add paranthesis in output string
        }
      }

      else // if encounter with cose bracket
      {

        open--; //  decrease the countof open bracket by one

        if (open > 0) // if open bracket count is 0 then it means it is outermost bracket (close parantesis)
        {
          op = op + ")"; // add paranthesis in output string
        }
      }
    }
    return op;
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

/*
tc: O(n)
-traverse in array only onece , n is number of parenthesis in string

sc:O(n)
-storing output string , in worst case , where n is number of parenthesis in input string
*/