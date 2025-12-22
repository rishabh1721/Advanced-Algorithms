#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> majority(vector<int> &arr)
  {
    int n = arr.size();
    map<int, int> mpp;
    vector<int> ans;
    int mini = (int)(n / 3) + 1;
    for (int i = 0; i < n; i++)
    {
      mpp[arr[i]]++;
      if (mpp[arr[i]] == mini)
      {
        ans.push_back(arr[i]);
      }
      if (ans.size() == 2)
        break;
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
