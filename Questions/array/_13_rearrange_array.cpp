class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {

    // size of input array stored in n
    int n = nums.size();
    // define two vecctors size of n/2
    vector<int> pos; // stores all the +ve elements in there order
    vector<int> neg; // stores all the -ve elements in there order
    vector<int> arr(n);

    // iterate over nums and find all the neg and pos elements and
    // put them in corresponding pos or neg vector
    for (int i = 0; i < n; i++)
    {
      // check for pos ele
      if (nums[i] > 0)
      {
        pos.push_back(nums[i]);
      }
      // neg ele
      else
      {
        neg.push_back(nums[i]);
      }
    }

    // puting all the pos in arr at even position
    for (int i = 0; i < pos.size(); i++)
    {
      arr[2 * i] = pos[i];
    }
    // puting all the pos in arr at odd position
    for (int i = 0; i < neg.size(); i++)
    {
      arr[(2 * i) + 1] = neg[i];
    }

    return arr;
  }
};

class SolutionTwo
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {

    // size of input array stored in n
    int n = nums.size();

    vector<int> arr(n, 0);
    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] > 0)
      {
        arr[posIndex] = nums[i];
        posIndex += 2;
      }

      else
      {
        arr[negIndex] = nums[i];
        negIndex += 2;
      }
    }

    return arr;
  }
};