#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
  long long maxMatrixSum(vector<vector<int>> &matrix)
  {
    long long totalSum = 0;
    long long negativeCount = 0;
    long long minAbs = INT_MAX;
    for (auto &row : matrix)
    {
      for (int x : row)
      {
        if (x < 0)
          negativeCount++;
        int ax = abs(x);
        totalSum += ax;
        minAbs = min(minAbs, (long long)abs(x));
      }
    }
    if (negativeCount % 2 == 0)
      return totalSum;
    else
      return totalSum - 2LL * minAbs;
  }
};