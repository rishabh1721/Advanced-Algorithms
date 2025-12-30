#include <vector>
using namespace std;

// User function template for C++
class Solution
{
public:
  bool matSearch(vector<vector<int>> &mat, int target)
  {
    // your code here
    int row = 0;
    int col = mat[0].size() - 1;
    while (row < mat.size() && col >= 0)
    {
      if (mat[row][col] == target)
      {
        return true;
      }
      else if (mat[row][col] < target)
      {
        row++;
      }

      else
      {
        col--;
      }
    }
    return false;
  }
};