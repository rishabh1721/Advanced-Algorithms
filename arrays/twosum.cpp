#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &book, int target)
  {
    unordered_map<int, int> mpp;

    for (int i = 0; i < book.size(); i++)
    {
      int more = target - book[i];

      if (mpp.find(more) != mpp.end())
      {
        return {mpp[more], i};
      }

      mpp[book[i]] = i;
    }

    return {}; // no valid pair
  }
};
