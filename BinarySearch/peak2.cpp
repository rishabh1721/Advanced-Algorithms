#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
  int findMax(vector<vector<int>> &mat, int col)
  {
    int maxVal = INT_MIN;
    int idx = -1;

    for (int i = 0; i < mat.size(); i++)
    {
      if (mat[i][col] > maxVal)
      {
        maxVal = mat[i][col];
        idx = i;
      }
    }
    return idx;
  }

  vector<int> findPeakGrid(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      int maxRow = findMax(mat, mid);

      int left = (mid > 0) ? mat[maxRow][mid - 1] : INT_MIN;
      int right = (mid < m - 1) ? mat[maxRow][mid + 1] : INT_MIN;

      if (mat[maxRow][mid] >= left && mat[maxRow][mid] >= right)
      {

        return {maxRow, mid};
      }
      else if (mat[maxRow][mid] < left)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return {-1, -1};
  }
};
