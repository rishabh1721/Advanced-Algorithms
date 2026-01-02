#include <vector>
using namespace std;

class Solution
{
private:
  void helper(int idx, int target, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
  {
    if (target == 0)
    {
      ans.push_back(temp);
      return;
    }
    if (target < 0 || idx == arr.size())
    {
      return;
    }
    temp.push_back(arr[idx]);
    helper(idx, target - arr[idx], arr, temp, ans);
    temp.pop_back();

    helper(idx + 1, target, arr, temp, ans);
  }

public:
  vector<vector<int>> targetSumComb(vector<int> &arr, int target)
  {
    // code here
    vector<int> temp;
    vector<vector<int>> ans;
    helper(0, target, arr, temp, ans);
    return ans;
  }
};