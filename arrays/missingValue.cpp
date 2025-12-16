#include <vector>
using namespace std;

class Solution
{
public:
  int missingNum(vector<int> &arr)
  {
    int n = arr.size() + 1; // because one number is missing gfg
    int x = 0;

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
      x ^= i;
    }

    // XOR all elements of array
    for (int val : arr)
    {
      x ^= val;
    }

    return x;
  }
};
