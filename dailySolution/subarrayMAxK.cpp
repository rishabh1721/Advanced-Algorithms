#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxSubarraySum(vector<int> &arr, int k)
  {
    // code here
    int n = arr.size();
    int maxSum = INT_MIN;
    int windowSum = 0;

    for (int i = 0; i < n; i++)
    {
      windowSum += arr[i];
      if (i >= k)
      {
        windowSum -= arr[i - k];
      }
      if (i >= k - 1)
      {
        maxSum = max(maxSum, windowSum);
      }
    }
    return maxSum;
  }
};