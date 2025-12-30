#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  long long total(vector<int> &arr, int k)
  {
    long long hrs = 0;
    for (int x : arr)
    {

      hrs += (x + k - 1) / k;
    }
    return hrs;
  }
  int cleaningWindows(vector<int> &arr, int h)
  {
    int n = arr.size();
    if (n > h)
      return -1;
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    while (low < high)
    {
      int mid = low + (high - low) / 2;
      if (total(arr, mid) <= h)
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