#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  int maxDiff(vector<int> &nums)
  {
    // code here
    sort(nums.begin(), nums.end());
    int maxi = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
      int j = i + 1;

      int diff = nums[j] - nums[i];
      maxi = max(maxi, diff);
      j++;
    }
    return maxi;
  }
};