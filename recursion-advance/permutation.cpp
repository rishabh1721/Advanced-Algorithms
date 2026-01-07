#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void solve(int idx, vector<int> &arr, vector<vector<int>> &res)
  {
    if (idx == arr.size())
    {
      res.push_back(arr);
      return;
    }
    for (int i = idx; i < arr.size(); i++)
    {
      swap(arr[idx], arr[i]);
      solve(idx + 1, arr, res);
      swap(arr[idx], arr[i]);
    }
  }
  vector<vector<int>> permuteDist(vector<int> &arr)
  {
    // code here
    vector<vector<int>> res;
    solve(0, arr, res);
    return res;
  }
};