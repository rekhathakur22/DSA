#include <iostream>
#include <vector>
using namespace std;

// question says print all combination with target sum , repeatation of values are allowed , all the elements of given array is unique

class Solution
{
public:
  void helper(int index, int target, vector<int> &temp, vector<vector<int>> &ans, vector<int> &array)
  {
    // base condition
    if (index >= array.size())
    {
      if (target == 0) // target is 0 then temp contain combination with targeted sum
      {
        ans.push_back(temp);
        return;
      }
      return; // else condition
    }

    // include or skip
    if (array[index] <= target)
    {
      temp.push_back(array[index]);
      helper(index, target - array[index], temp, ans, array); // include same index because repetation is allowed
      temp.pop_back();
    }
    // go for next index
    helper(index + 1, target, temp, ans, array);

    return;
  }
  vector<vector<int>> findCombinations(vector<int> &array, int target)
  {
    vector<vector<int>> ans;             // store all unique combinations of elements having targeted sum
    vector<int> temp;                    // store each unique combination
    helper(0, target, temp, ans, array); // helper helps to print all combinations

    return ans;
  }
};

int main()
{
  Solution obj;

  cout << "size" << endl;
  int n;
  cin >> n; // taking input from user

  vector<int> array(n); // input array
  cout << "elements" << endl;

  // taking input from user
  for (int i = 0; i < n; i++)
  {
    cin >> array[i];
  }

  cout << "target";

  int target;
  cin >> target; // input  target  from user

  vector<vector<int>> res = obj.findCombinations(array, target); // function call

  // print all the combinations with targeted sum in given arary
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
tc: O(2^t * k)
- here t is target value , in worst case if value of element is 1 then depth of recursion tree will be target value, 2 is because for each index we have two choice include or skip , k is for length of possible combination

sc:O(k*X)
- if ignor auxillary space , X is space occupied by all the combinations and k is length of one combination
*/