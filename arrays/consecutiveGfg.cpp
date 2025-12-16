#include <vector>
using namespace std;

class Solution
{
public:
  int maxConsecBits(vector<int> &nums)
  {
    // code here
    int maxi = 0;
    int t = 0;

    int cnt = 0;
    int ynt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 1)
      {
        cnt++;
        maxi = max(maxi, cnt);
      }
      else
      {
        cnt = 0;
      }
      if (nums[i] == 0)
      {
        ynt++;
        t = max(ynt, t);
      }
      else
      {
        ynt = 0;
      }
    }
    int res = max(maxi, t);
    return res;
  }
};