#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int binarysearch(vector<int> &nums, int target)
  {
    // code here
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target)
      {
        ans = mid;      // store possible answer
        high = mid - 1; // move left
      }
      else if (nums[mid] > target)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return ans;
  }
};