#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<int> countNeighbours(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
      v.push_back({nums[i], i});

    sort(v.begin(), v.end());

    vector<int> ans(n);
    int l = 0, r = 0;

    for (int i = 0; i < n; i++)
    {
      // expand right boundary
      while (r < n && v[r].first <= v[i].first + k)
        r++;

      // shrink left boundary
      while (v[l].first < v[i].first - k)
        l++;

      ans[v[i].second] = r - l;
    }
    return ans;
  }
};
