#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> pascals_triangle(int numRows)
  {
    vector<vector<int>> ans;

    // traverse in num of rows ex row=1 to 2,3,4,5,row=6
    for (int row = 1; row <= numRows; row++)
    {
      // store elements(no_of_col == row_no) present in that row
      vector<int> temp;
      int num = 1;
      // first element of each row is one
      temp.push_back(num);
      // traverse in col ex col=1 to 2,3,4 col=5; where row=6
      // 0 based index
      for (int col = 1; col < row; col++)
      {
        num = num * (row - col) / col;
        temp.push_back(num);
      }
      ans.push_back(temp);
    }

    return ans;
  }
};

int main()
{
  int numRows;
  cin >> numRows; // input the number of rows in pascals triangle

  Solution solution;
  vector<vector<int>> result = solution.pascals_triangle(numRows);
  cout << "Pacals triangle is" << endl;

  // printing pascals triangle
  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

// time complexity: O(numRows*numRows);
// space complexity O(numsRows*numsRows); for storing the answer which return pascals triangle