#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {

    int n = nums.size();
    if (n == 0)
      return 0;
    unordered_set<int> st;
    int longe = 1;

    for (int i = 0; i < n; i++)
    {
      st.insert(nums[i]);
    }

    for (auto it : st)
    {
      if (st.find(it - 1) == st.end())
      {
        int cnt = 1;
        int x = it;

        while (st.find(x + 1) != st.end())
        {
          x = x + 1;
          cnt += 1;
        }
        longe = max(longe, cnt);
      }
    }

    return longe;
  }
};