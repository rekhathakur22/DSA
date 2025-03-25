#include <iostream>
#include <vector>
using namespace std;

// print the subsequences whose sum are equal to target

void helper(int index, vector<vector<int>> &res, vector<int> temp, vector<int> arr, int target, int currSum)
{
  // base condition -> if we reach end of the array
  if (index == arr.size())
  {
    // base condition -> if it meets the target
    if (currSum == target)
    {
      res.push_back(temp);
      return;
    }
    // else condition
    return;
  }

  // include current index
  temp.push_back(arr[index]);
  helper(index + 1, res, temp, arr, target, currSum + arr[index]); // function call
  // exclude current index
  temp.pop_back();
  helper(index + 1, res, temp, arr, target, currSum); // function call
}
vector<vector<int>> printSubset_Ksum(vector<int> &arr, int target)
{
  vector<vector<int>> res;
  vector<int> temp;
  int currSum = 0;
  helper(0, res, temp, arr, target, currSum);
  return res;
}

int main()
{
  cout << "size" << endl;
  int n;    // size of array
  cin >> n; // taking input from user

  vector<int> arr(n);

  // taking input from user
  cout << "input" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "target" << endl;
  int target;    // target sum
  cin >> target; // user input
  vector<vector<int>> res = printSubset_Ksum(arr, target);

  cout << "subsequences" << endl;
  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[i].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
tc: O(2^N)
- Since we generate all subsequences, the number of recursive calls at the leaf level is approximately 2ⁿ. N is elements in array

sc: O(N * 2^N) and O(N)
-  storing subsequences, space complexity becomes O(n × 2ⁿ) because there are 2ⁿ subsequences, each of size at most O(n).
- O(N) for stack space
*/