#include <vector>
using namespace std;

class Solution
{
private:
  int helper(int idx, int n, int sum, int k, vector<int> &nums)
  {
    if (sum == k)
    {
      return 1;
    }
    if (n == idx || sum > k)
      return 0;

    int pick = helper(idx + 1, n, sum + nums[idx], k, nums);

    int notPick = helper(idx + 1, n, sum, k, nums);

    return pick + notPick;
  }

public:
  int countSubsequenceWithTargetSum(vector<int> &nums, int k)
  {
    // your code goes here
    return helper(0, nums.size(), 0, k, nums);
  }
};