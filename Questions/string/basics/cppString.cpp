#include <iostream>
using namespace std;

int main()
{
  /*
  -> class : string
  -> object : str
  */
  string str = "rekha thakur";
  cout << str << endl;

  // KEY FEATURES
  // 1. string is a class in c++
  // 2. strings stored in contiguous manner
  // 3. Dynamic Resizing -> runtime resizing

  string str2 = "HELLO";
  cout << str2 << endl;

  str2 = "hello";
  cout << str2 << endl;

  /*
  std::string supports operators for ease of use:
  1. +: Concatenation.
  2. ==, !=, <, >: Comparison.
  3. []: Access individual characters
  */

  // + operator
  string str3 = "hello";
  string str4 = "world";
  string str5 = str3 + " " + str4;
  cout << str5 << endl;
  // () parenthisis is important without them it will give error
  cout << (str3 == str4) << endl;
  cout << (str3 != str4) << endl;
  cout << (str3 < str4) << endl;
  cout << (str3 > str4) << endl;

  /*
  std::string provides many functions for string manipulation:
 1-> .length() or .size(): Returns the length of the string.
 2->.substr(start, length): Extracts a substring.
 3->.find(substring): Searches for a substring and returns its position.
 4->.append(string): Adds another string to the current string.
 5->.erase(start, length): Removes part of the string.
 6-> .replace(start, length, string): Replaces part of the string.
  */

  cout << "length of str5 : " << str5.length() << endl;

  // INPUTS

  // we can not take sentence as input using cin in string
  // string str6;
  // cin >> str6;
  // cout << "str 6 -> " << str6 << endl;

  // we can use getline(cin,str);
  // string str7;
  // getline(cin, str7);
  // cout << "output: " << str7 << endl;

  // LOOPS
  string str8 = "rekha thakur";

  for (int i = 0; i < str8.length(); i++)
  {
    cout << str[i] << " ";
  }
  cout << endl;

  for (char ch : str8)
  {
    cout << ch << " ";
  }
  cout << endl;
  return 0;
}