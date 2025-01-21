// c strings also known as charcter array

#include <bits/stdc++.h>
using namespace std;

int main()
{

  // output: abc≡↓@  -> without \0
  // output: abc ->with \0
  // \0 doesnt count in string lenght
  char str[] = {'a', 'b', 'c', '\0'};

  char str2[] = "rekha";
  /*
  -> Automatically includes \0 at the end
  -> internally stored as character array = |r|e|k|h|a|\0|
  -> can be accessed using index -> str2[2] -> output: k
  */

  /*input*/
  char str3[10];
  cin >> str3;
  cout << str3 << endl;
  /*
  -> we can take input string using cin
  -> defining the lenght of string is important like str[10] or str[100]
  -> limitation :
  -> we can not take sentence as input using cin in string
  -> it ignors all the words after space
  -> like  {input: rekha thakur}  ->  output: rekha
  -> we can use cin.getline(str,lenght) for taking sentance as input
  */

  char str4[12];
  cin.getline(str4, 100);

  /*
  input: rekha thakur
  output:rekha thakur
  */

  cin.getline(str4, 100, '#');
  /*
  -> # : is work as delimiter
  -> delimiter is parameter of cin.getline(str,lenght,delim)
  -> generally this function stop taking input if you press enter
  -> but if you want to stop taking input at some character then you can use delimiter
  */

  /*output*/
  // output individual character
  cin.getline(str4, 12);
  // for (char ch : str4)
  // {
  //   cout << ch << " ";
  // }
  // cout << endl;

  // count the length of string
  int len = 0;
  for (int i = 0; str4[i] != '\0'; i++)
  {
    len++;
  }
  cout << len << endl;
  return 0;
}