#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
  int sumd(vector<int> &arr, int div)
  {
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
  }

  int smallestDivisor(vector<int> &arr, int k)
  {
    // Code here
    int low = 1;
    int n = arr.size();

    int high = *max_element(arr.begin(), arr.end());
    if (n > k)
      return -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (sumd(arr, mid) <= k)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return low;
  }
};
