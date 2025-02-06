#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
  int n = v.size(); // give the size of vector and tc: O(1)
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

// array of vectors
void arr_of_vectors()
{
  int N;
  cout << "enter the size of array: ";
  cin >> N; // N is size of array (no of vectors)
  vector<int> v[N];

  // taking input
  for (int i = 0; i < N; i++)
  {
    int n;
    cout << "enter size of vector: ";
    cin >> n; // size of vector
    for (int j = 0; j < n; j++)
    {
      int x;
      cout << "enter vector element: ";
      cin >> x;
      v[i].push_back(x);
    }
  }

  for (int i = 0; i < N; i++)
  {
    printVector(v[i]);
  }
}

int main()
{
  vector<int> v(5, 3);
  // int n;
  // cin >> n;
  // for (int i = 0; i < n; i++)
  // {
  //   int x;
  //   cin >> x;
  //   v.push_back(x); // used to insert value at the end of vector and tc: O(1)
  // }

  vector<int> v1(5); // it will declare a vector of size 5 and by default set all values to 0

  vector<int> v2(5, 4); // it is a vector of size 5 and default values 4;

  v2.push_back(6); // tc:O(1)
  v2.pop_back();   // tc:O(1)

  v2 = v; // copy of vectors and tc: O(n)
  // &v2  = v; // avoid copy of vector

  arr_of_vectors();

  return 0;
}