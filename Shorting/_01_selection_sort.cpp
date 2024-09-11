#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &vc)
{
  // size of array
  int n = vc.size();

  // loop run till second last element for swaping
  for (int i = 0; i < n - 1; i++)
  {

    int min = i;

    // loop run till last element for finding min element
    for (int j = i; j < n; j++)
    {
      if (vc[j] < vc[min])
      {
        min = j;
      }
    }

    swap(vc[i], vc[min]);
  }
}

int main()
{
  int n;
  cout << "enter the size of array";
  cin >> n;
  vector<int> vc(n);
  for (int i = 0; i < n; i++)
  {
    cin >> vc[i];
  }
  cout << "selection sort calling" << endl;
  selection_sort(vc);
  cout << "selection sort exicution complete" << endl;

  cout << "sorted array" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << vc[i] << " ";
  }
  return 0;
}

// TC O((N-1)*N)