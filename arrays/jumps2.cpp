#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int jumps = 0;
    int ends = 0;
    int far = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
      far = max(far, i + nums[i]);
      if (i == ends)
      {
        jumps++;
        ends = far;
      }
    }
    return jumps;
  }
};