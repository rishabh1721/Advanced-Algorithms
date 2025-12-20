#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maximumProfit(vector<int> &arr)
  {
    // code here
    int mini = arr[0], profit = 0;
    for (int i = 1; i < arr.size(); i++)
    {
      int cost = arr[i] - mini;
      profit = max(profit, cost);
      mini = min(mini, arr[i]);
    }
    return profit;
  }
};
