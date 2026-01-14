#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution
{
  int m, n, total;
  unordered_map<int, int> mp;

public:
  Solution(int m, int n)
  {
    this->m = m;
    this->n = n;
    total = m * n;
  }

  vector<int> flip()
  {
    int r = rand() % total;
    total--;

    int idx = mp.count(r) ? mp[r] : r;
    mp[r] = mp.count(total) ? mp[total] : total;

    return {idx / n, idx % n};
  }

  void reset()
  {
    mp.clear();
    total = m * n;
  }
};
