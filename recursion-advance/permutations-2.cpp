#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  void solve(int idx, vector<int> &nums, vector<vector<int>> &res)
  {
    if (idx == nums.size())
    {
      res.push_back(nums);
      return;
    }

    unordered_set<int> used;
    for (int i = idx; i < nums.size(); i++)
    {
      if (used.count(nums[i]))
        continue;
      used.insert(nums[i]);
      swap(nums[idx], nums[i]);
      solve(idx + 1, nums, res);
      swap(nums[idx], nums[i]);
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums)
  {
    vector<vector<int>> res;
    solve(0, nums, res);
    return res;
  }
};