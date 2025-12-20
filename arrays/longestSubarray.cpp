#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &arr, int k)
  {
    map<int, int> mpp;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      sum += arr[i];

      if (sum == k)
      {
        maxLen = max(maxLen, i + 1);
      }

      int rem = sum - k;
      if (mpp.find(rem) != mpp.end())
      {
        maxLen = max(maxLen, i - mpp[rem]);
      }

      // store only FIRST occurrence
      if (mpp.find(sum) == mpp.end())
      {
        mpp[sum] = i;
      }
    }
    return maxLen;
  }
};
