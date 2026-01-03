#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  bool isSafe(int x, int y, int n, vector<vector<int>> &grid, vector<vector<int>> &vis)
  {
    return (
        x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1 && vis[x][y] == 0);
  }

  void help(int x, int y, int n, vector<vector<int>> &grid, vector<vector<int>> &vis, string path, vector<string> &ans)
  {

    // base case
    if (x == n - 1 && y == n - 1)
    {
      ans.push_back(path);
      return;
    }

    vis[x][y] = 1;
    // down
    if (isSafe(x + 1, y, n, grid, vis))
    {
      help(x + 1, y, n, grid, vis, path + 'D', ans);
    }

    // left
    if (isSafe(x, y - 1, n, grid, vis))
    {
      help(x, y - 1, n, grid, vis, path + 'L', ans);
    }
    // right
    if (isSafe(x, y + 1, n, grid, vis))
    {
      help(x, y + 1, n, grid, vis, path + 'R', ans);
    }
    // up
    if (isSafe(x - 1, y, n, grid, vis))
    {
      help(x - 1, y, n, grid, vis, path + 'U', ans);
    }
    vis[x][y] = 0;
  }
  vector<string> findPath(vector<vector<int>> &grid)
  {
    // your code goes here
    int n = grid.size();
    vector<string> ans;
    if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
      return ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    help(0, 0, n, grid, vis, "", ans);
    return ans;
  }
};