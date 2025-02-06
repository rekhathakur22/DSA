#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v = {1, 2, 3, 4, 5}; // without refrence this will print copy of values
  cout << "output using data type: ";
  for (int t : v)
  {
    cout << t << "  ";
  }

  cout << endl;
  cout << "output using auto keyword: ";
  for (auto t : v)
  {
    cout << t << "  ";
  }

  int arr[] = {1, 2, 3, 4, 5};
  cout << "output using data type: ";
  for (int t : arr)
  {
    cout << t << " ";
  }

  cout << endl;
  cout << "output using auto: ";
  for (auto t : arr)
  {
    cout << t << " ";
  }
  // this will represent actual value from vector
  cout << endl
       << "actual values: ";
  for (int &t : v)
  {
    cout << t++ << "  ";
  }
  cout << endl
       << "output: ";
  for (int t : v)
  {
    cout << t << "  ";
  }
  return 0;
}