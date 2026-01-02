#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
  void helper(int idx,
              vector<int> &candidates,
              vector<int> &temp,
              vector<vector<int>> &ans)
  {

    // Every call represents ONE valid subset
    ans.push_back(temp);

    for (int i = idx; i < candidates.size(); i++)
    {

      // skip duplicates at the same recursion level
      if (i > idx && candidates[i] == candidates[i - 1])
        continue;

      temp.push_back(candidates[i]);
      helper(i + 1, candidates, temp, ans);
      temp.pop_back(); // backtrack
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &candidates)
  {
    sort(candidates.begin(), candidates.end()); // REQUIRED
    vector<vector<int>> ans;
    vector<int> temp;
    helper(0, candidates, temp, ans);
    return ans;
  }
};
