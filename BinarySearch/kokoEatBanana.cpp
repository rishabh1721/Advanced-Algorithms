#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  long long total(vector<int> &piles, int k)
  {
    long long hours = 0;
    for (int p : piles)
    {
      hours += (p + k - 1) / k; // integer ceil
      if (hours > 1e18)
        break; // safety
    }
    return hours;
  }

  int minEatingSpeed(vector<int> &piles, int h)
  {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while (low < high)
    { // 🔑 IMPORTANT
      int mid = low + (high - low) / 2;

      if (total(piles, mid) <= h)
        high = mid; // keep mid
      else
        low = mid + 1;
    }
    return low;
  }
};
