#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
  int findKRotation(vector<int> &arr)
  {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      // already sorted
      if (arr[low] <= arr[high])
      {
        if (arr[low] < ans)
        {
          ans = arr[low];
          index = low;
        }
        break;
      }

      // left half sorted
      if (arr[low] <= arr[mid])
      {
        if (arr[low] < ans)
        {
          ans = arr[low];
          index = low;
        }
        low = mid + 1;
      }
      // right half sorted
      else
      {
        if (arr[mid] < ans)
        {
          ans = arr[mid];
          index = mid;
        }
        high = mid - 1;
      }
    }
    return index;
  }
};
