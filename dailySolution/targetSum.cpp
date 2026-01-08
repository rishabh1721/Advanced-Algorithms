// Back-end complete function Template for C++
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  long long findTargetSumWays(int n, vector<int> &A, int target)
  {
    int total = 0;
    for (int x : A)
      total += x;

    // Invalid cases
    if (total < abs(target) || (total + target) % 2 != 0)
      return 0;

    int P = (total + target) / 2;

    vector<long long> dp(P + 1, 0);
    dp[0] = 1;

    for (int num : A)
    {
      for (int s = P; s >= num; s--)
      {
        dp[s] += dp[s - num];
      }
    }

    return dp[P];
  }
};
