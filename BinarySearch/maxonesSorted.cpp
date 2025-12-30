#include <vector>
using namespace std;

// User function template for C++
class Solution
{
public:
  int lower(vector<int> arr, int n, int x)
  {
    int low = 0;
    n = arr.size();
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] >= x)
      {
        ans = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return ans;
  }
  int rowWithMax1s(vector<vector<int>> &mat)
  {
    // code here
    int index = -1;

    int maxi = 0;
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
      int count_ones = m - lower(mat[i], m, 1);
      if (count_ones > maxi)
      {
        maxi = count_ones;
        index = i;
      }
    }
    return index;
  }
};
