#include <vector>
using namespace std;

class Solution
{
public:
  int func(int mid, int n, int m)
  {
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
      ans *= mid;
      if (ans > m)
        return 2; // too large
    }
    if (ans == m)
      return 1; // exact
    return 0;   // too small
  }

  int nthRoot(int n, int m)
  {
    if (m == 0)
      return 0;
    if (m == 1)
      return 1;
    int low = 1, high = m;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      int val = func(mid, n, m);

      if (val == 1)
        return mid;
      else if (val == 0)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return -1; // ❗ mandatory
  }
};
