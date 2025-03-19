#include <iostream>
using namespace std;

void test(int count)
{
  if (count == 0)
    return;
  cout << "test" << endl;
  test(--count);
}

int main()
{
  int count = 5;
  test(count);
  return 0;
}