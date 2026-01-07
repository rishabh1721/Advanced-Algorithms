#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  void diagonalSort(vector<vector<int>> &mat, int m, int n)
  {
    n = mat.size();
    m = mat[0].size();

    unordered_map<int, vector<int>> mp;

    // 1. Collect elements by diagonal (except main diagonal)
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (i != j)
        {
          mp[i - j].push_back(mat[i][j]);
        }
      }
    }

    // 2. Sort diagonals
    for (auto &it : mp)
    {
      if (it.first > 0)
      {
        // lower-left → ascending
        sort(it.second.begin(), it.second.end());
      }
      else
      {
        // upper-right → descending
        sort(it.second.begin(), it.second.end(), greater<int>());
      }
    }

    // 3. Put elements back
    unordered_map<int, int> idx; // index per diagonal

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (i != j)
        {
          mat[i][j] = mp[i - j][idx[i - j]++];
        }
      }
    }
  }
};
