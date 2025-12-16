#include <iostream>
#include <vector>
#include <utility> // for std::move
using namespace std;

class Solution
{
public:
  int missingNumber(vector<int> &arr)
  {
    int n = arr.size();
    int x = 0;

    // XOR all indices and array values
    for (int i = 0; i < n; i++)
    {
      x ^= i;
      x ^= arr[i];
    }

    // XOR with n
    x ^= n;

    return x;
  }
};
