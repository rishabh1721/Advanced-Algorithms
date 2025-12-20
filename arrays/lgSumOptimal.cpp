#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  double lgSumOptimal(vector<int> a, long long k)

  {
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();
    while (right < n)
    {
      if (sum < k)
      {
        right++;
        if (right < n)
          sum += a[right];
      }
      else if (sum > k)
      {
        sum -= a[left];
        left++;
      }
      else
      {
        maxLen = max(maxLen, right - left + 1);
        right++;
        if (right < n)
          sum += a[right];
      }
    }
    return maxLen;
  }
};