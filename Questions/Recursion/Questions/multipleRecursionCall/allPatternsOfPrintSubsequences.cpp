#include <iostream>
#include <vector>
using namespace std;

void helper(int index, vector<vector<int>> &res, vector<int> temp, vector<int> arr, int target, int currSum)
{
  if (index == arr.size())
  {
    if (currSum == target)
    {
      res.push_back(temp);
      return;
    }
    return;
  }

  temp.push_back(arr[index]);
  helper(index + 1, res, temp, arr, target, currSum + arr[index]);
  temp.pop_back();
  helper(index + 1, res, temp, arr, target, currSum);
  return;
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