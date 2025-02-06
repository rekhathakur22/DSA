// #include<iostream>
#include <bits/stdc++.h> // we have include stl for use reverse() function
using namespace std;

class Solution
{
public:
  string reverse_string(string s)
  {
    int n = s.length();
    string ans = "";
    // Reverse the entire string
    // words comes into its correct position
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
      string word = "";
      // extrat a word
      while (i < n && s[i] != ' ')
      {
        word += s[i];
        i++;
      }

      reverse(word.begin(), word.end()); // reverse the word to bring it to correct order
      if (word.length() > 0)
      {
        ans += " " + word; // adding one extra space in all words
      }
    }
    return ans.substr(1); // append the result without extra space
  }
};

int main()
{
  Solution str;
  int t;
  cout << "enter the number of test cases: " << endl;
  cin >> t;     // Reads the number and leaves '\n'
  cin.ignore(); // Discards '\n' from the input buffer
  while (t--)
  {
    string s;
    cout << "enter the strings contains English letters,digits, and spaces" << endl;
    getline(cin, s); // Reads the actual input correctly
    string result = str.reverse_string(s);
    cout << "output: " << result << endl;
  }
  return 0;
}

// tc: O(n) where n is length of string
// sc: O(1)