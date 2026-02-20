#include <vector>
using namespace std;
class Solution
{
public:
  vector<int> singleNum(vector<int> &arr)
  {
    // Code here.
    long long x = 0;
    for (int n : arr)
    {
      x ^= n;
    }
    long long mask = x & (-x);
    int a = 0, b = 0;
    for (int n : arr)
    {
      if (n & mask)
      {
        a ^= n;
      }
      else
      {
        b ^= n;
      }
    }
    if (a < b)
    {
      return {a, b};
    }
    return {b, a};
  }
};