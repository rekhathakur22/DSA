#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int maxProfit = 0;
    int buy = INT_MAX;
    int b = 0;
    int sell = 0;
    for (int i = 0; i < n; i++)
    {

      if (prices[i] < buy)
      {
        buy = prices[i];
        b = i;
      }

      else
      {

        sell = prices[i];
        maxProfit = max(maxProfit, sell - buy);
      }
    }

    return maxProfit;
  }

  int maxProfit_two(vector<int> &prices)
  {
    int n = prices.size();
    int profit = 0;
    int mini = prices[0];

    for (int i = 1; i < n; i++)
    {
      int cost = prices[i] - mini;
      profit = max(profit, cost);
      mini = min(mini, prices[i]);
    }

    return profit;
  }
};

int maxProfit(int[] prices)
{
  int maxCur = 0, maxSoFar = 0;
  for (int i = 1; i < prices.length; i++)
  {
    maxCur = Math.max(0, maxCur += prices[i] - prices[i - 1]);
    maxSoFar = Math.max(maxCur, maxSoFar);
  }
  return maxSoFar;
}