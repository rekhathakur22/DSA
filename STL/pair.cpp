#include <iostream>
#include <utility>
using namespace std;

int main()
{
  /*******Declaration of pair and initialization********/

  // syntax: pair<data_type1,data_type2> pair_name;
  pair<int, string> p1;
  // assigning values in pair
  p1.first = 1;
  p1.second = "rekha";

  pair<int, string> p2(1, "rekha");

  pair<int, string> p3;
  p3 = {1, "rekha"};

  pair<int, string> p4;
  p4 = make_pair(1, "rekha");

  // cout << "p1: " << p1.first << " " << p1.second << endl;
  // cout << "p2: " << p2.first << " " << p2.second << endl;
  // cout << "p3: " << p3.first << " " << p3.second << endl;
  // cout << "p4: " << p4.first << " " << p4.second << endl;

  /*copy one pair to another*/
  pair<int, string> p5 = p1; // direct copy (assignment)
  pair<int, string> p6(p2);  // copy constructor
  pair<int, string> p7 = {p3.first, p3.second};
  // cout << "p5: " << p5.first << " " << p5.second << endl;
  cout << "p7: " << p7.first << " " << p7.second << endl;

  // using &(refrence)
  pair<int, string> &p8 = p4;
  return 0;
}
