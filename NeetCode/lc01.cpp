#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &arr, int target)
  {
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
      int need = target - arr[i];
      if (mp.count(need))
      {
        return {mp[need], i};
      }
      mp[arr[i]] = i;
    }
    return {};
  }
};
