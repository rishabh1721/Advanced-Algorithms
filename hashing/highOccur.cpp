#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int mostFrequentElement(vector<int> &nums)
  {
    unordered_map<int, int> freq;
    int maxi = 0;
    int ans = nums[0];
    for (int x : nums)
    {
      freq[x]++;
      if (freq[x] > maxi)
      {
        maxi = freq[x];
        ans = x;
      }
      else if (freq[x] == maxi)
      {
        ans = min(ans, x);
      }
    }
    return ans;
  }
};