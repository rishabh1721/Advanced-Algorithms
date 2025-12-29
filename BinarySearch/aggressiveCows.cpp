#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  bool place(vector<int> &stalls, int dist, int cows)
  {
    int c = 1;
    int last = stalls[0];
    for (int x : stalls)
    {
      if (x - last >= dist)
      {
        c++;
        last = x;
      }
    }
    if (c >= cows)
      return true;
    return false;
  }
  int aggressiveCows(vector<int> &stalls, int k)
  {
    // code here
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (place(stalls, mid, k) == true)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    return high;
  }
};