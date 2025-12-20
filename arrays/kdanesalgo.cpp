#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
  int maxSubarraySum(vector<int> &arr)
  {
    // Code here
    int s = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
      s += arr[i];
      if (s > maxi)
      {
        maxi = s;
      }
      if (s < 0)
      {
        s = 0;
      }
    }
    return maxi;
  }
};