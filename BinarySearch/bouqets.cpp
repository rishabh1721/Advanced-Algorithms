#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  bool possible(vector<int> &arr, int day, int k, int m)
  {
    int count = 0;
    int bouq = 0;
    for (int x : arr)
    {
      if (x <= day)
      {
        count++;
        if (count == k)
        {
          bouq++;
          count = 0;
        }
      }
      else
      {
        count = 0;
      }
    }
    return bouq >= m;
  }
  int minDaysBloom(vector<int> &arr, int k, int m)
  {
    // Code here
    long long val = k * 1LL * m * 1LL;
    int n = arr.size();
    if (n < val)
      return -1;
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    while (low < high)
    {
      int mid = low + (high - low) / 2;
      if (possible(arr, mid, k, m))
      {
        high = mid;
      }
      else
      {
        low = mid + 1;
      }
    }
    return low;
  }
};