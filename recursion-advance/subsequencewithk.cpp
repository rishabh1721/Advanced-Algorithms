#include <vector>
using namespace std;

class Solution
{
private:
  bool helper(int idx, int n, int sum, vector<int> &arr, int k)
  {
    // Code here
    if (sum == k)
      return true;
    if (idx == n || sum > k)
      return false;

    // pick
    if (helper(idx + 1, n, sum + arr[idx], arr, k))
      return true;

    // not pick
    if (helper(idx + 1, n, sum, arr, k))
      return true;

    return false;
  }

public:
  bool checkSubsequenceSum(int n, vector<int> &arr, int k)
  {
    // Code here

    return helper(0, n, 0, arr, k);
  }
};