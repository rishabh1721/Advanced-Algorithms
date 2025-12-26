#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  bool canPaint(vector<int> &arr, int k, long long maxTime)
  {
    long long curr = 0;
    int painters = 1;

    for (int i = 0; i < arr.size(); i++)
    {
      if (curr + arr[i] <= maxTime)
      {
        curr += arr[i];
      }
      else
      {
        painters++;
        curr = arr[i];
        if (painters > k)
          return false;
      }
    }
    return true;
  }

  long long minTime(vector<int> &arr, int k)
  {
    long long low = *max_element(arr.begin(), arr.end());
    long long high = 0;
    for (int x : arr)
      high += x;

    long long ans = high;

    while (low <= high)
    {
      long long mid = low + (high - low) / 2;

      if (canPaint(arr, k, mid))
      {
        ans = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return ans;
  }
};
