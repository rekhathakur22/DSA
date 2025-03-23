#include <iostream>
#include <vector>
using namespace std;

// subsequence -> it is not contiguous or contigeous part of array which follow the order

class Solution
{
public:
  void helper(int index, vector<vector<int>> &res, vector<int> &arr, vector<int> temp)
  {
    // base condition
    if (index >= arr.size())
    {
      res.push_back(temp);
      return;
    }

    // include the current element
    temp.push_back(arr[index]);

    // make a function call
    helper(index + 1, res, arr, temp);

    // exclude the current element
    temp.pop_back();
    // make function call
    helper(index + 1, res, arr, temp);

    return;
  }
  vector<vector<int>> printSubset(vector<int> &arr)
  {
    vector<vector<int>> res;   // stores final answer
    vector<int> temp;          // store one subsequence
    helper(0, res, arr, temp); // recursive function
    return res;
  }
};

int main()
{
  Solution ob;

  int n;    // size of array
  cin >> n; // take input

  vector<int> arr(n); // input array

  // take array element as input from user
  cout << "input start" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  // creating a object of class Solution which print all sub sequences of array
  vector<vector<int>> res = ob.printSubset(arr);

  // printing all subsequences
  cout << "subSequences" << endl;
  for (int i = 0; i < res.size(); i++)
  {
    if (res[i].empty())
    {
      cout << "{}" << " ";
    }
    else
    {
      for (int j = 0; j < res[i].size(); j++)
      {

        cout << res[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}

/*
tc:O(2^N)
- because for each index there is two function call
sc: O(N)
- for stack space calls
*/