#include <vector>
using namespace std;

class Solution
{
private:
  void helper(int start, int k, int n, vector<int> &temp, vector<vector<int>> &ans)
  {
    // valid state
    if (k == 0 && n == 0)
    {
      ans.push_back(temp);
    }
    // invalid state
    if (k == 0 || n < 0)
    {
      return;
    }
    for (int i = start; i <= 9; i++)
    {
      temp.push_back(i);
      helper(i + 1, k - 1, n - i, temp, ans);
      temp.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int> temp;
    vector<vector<int>> ans;
    helper(1, k, n, temp, ans);
    return ans;
  }
};