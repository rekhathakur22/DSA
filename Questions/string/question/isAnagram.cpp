#include <iostream>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    // we can solve this problem by sorting both string but it will give tc of nlog(n)
    // we can solve it by hashtable using hashmap
    // we can solve it by hashtable using array

    int count[26] = {0};

    // count the frequency of characters in string s
    for (char x : s)
    {
      count[x - 'a']++;
    }

    // decrement  the frequency of characters in string t
    for (char x : t)
    {
      count[x - 'a']--;
    }

    // check if any character has non zero frequency
    for (int val : count)
    {
      if (val != 0)
        return false;
    }

    return true;
  }
};

int main()
{
  Solution str;
  int t;
  cout << "enter the number of test cased: ";
  cin >> t;
  while (t--)
  {
    string s1, s2;
    cout << "enter the string which only contain lower case letters: " << endl;
    cout << "enter s1: ";
    cin >> s1;
    cout << "enter s2: ";
    cin >> s2;
    bool result = str.isAnagram(s1, s2);
    cout << "output: " << result << endl;
  }
  return 0;
}
// tc: O(n)
// sc : O(26)