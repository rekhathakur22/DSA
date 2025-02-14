#include <iostream>
using namespace std;

int main()
{
  //  & is address of operator used to get memory address of a variable
  int a = 10;
  // int b = &a; // it is not possible
  //  cout << &a;

  // pointer -> are special variables that  store memory address of other variable.

  int *ptr = &a; // pointer ptr stores memory address of variable a

  // cout << b << endl;

  // pointer to pointer
  int **ptr2 = &ptr;

  // cout << &ptr << endl;
  // cout << ptr2 << endl;

  // * -> derefrencing operator(value at address)
  // derefrencing means print the value storing in some address

  // cout << *ptr << endl;
  // cout << **ptr2 << endl;

  // Null pointer -> it does not point any valid location
  // derefrencing of null pointer is not possible
  int *pt = NULL;
  cout << pt;

  return 0;
}