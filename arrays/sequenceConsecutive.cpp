#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
  // Function to return length of longest subsequence of consecutive integers.
  int longestConsecutive(vector<int> &nums)
  {
    // Your code here
    if (nums.size() == 0)
      return 0;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    int longest = 1;
    int lastSmaller = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] - 1 == lastSmaller)
      {
        count += 1;
        lastSmaller = nums[i];
      }
      else if (nums[i] != lastSmaller)
      {
        count = 1;
        lastSmaller = nums[i];
      }
      longest = max(count, longest);
    }

    return longest;
  }
};