#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  int maxOnes(vector<int> &nums, int k)
  {
    // code here
    int left = 0;
    int zero = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++)
    {
      if (nums[right] == 0)
        zero++;
      while (zero > k)
      {
        if (nums[left] == 0)
          zero--;
        left++;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};
