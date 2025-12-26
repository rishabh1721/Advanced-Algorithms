#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
  unordered_map<int, int> mp;
  int validRange;

public:
  Solution(int n, vector<int> &blacklist)
  {
    unordered_set<int> black(blacklist.begin(), blacklist.end());

    validRange = n - blacklist.size();
    int last = n - 1;

    for (int b : blacklist)
    {
      if (b < validRange)
      {
        while (black.count(last))
        {
          last--;
        }
        mp[b] = last;
        last--;
      }
    }
  }

  int pick()
  {
    int x = rand() % validRange;
    if (mp.count(x))
      return mp[x];
    return x;
  }
};
