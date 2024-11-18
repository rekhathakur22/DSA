#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> extractDigit(int num)
  {
    int N = num;

    // store extracted digits
    vector<int> digit;

    while (N > 0)
    {
      // extract last digit
      int lastDigit = N % 10;

      digit.push_back(lastDigit);

      N = N / 10;
    }
    return digit;
  }
};

int main()
{
  Solution sol;

  int num;
  vector<int> result;

  // take input from user
  cin >> num;

  result = sol.extractDigit(num);

  // print all digits present in num
  // print the digit in reverse order
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}

/*
time complexity : O(log10(N);
 loop is run until all digit not extracted'

 space complexity : O(log10(N);
 extra space reqired for storing the extracted digit
 this extra space is equal to no of digits present in the number
 */
