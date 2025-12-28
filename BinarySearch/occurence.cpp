#include <vector>
using namespace std;

class Solution
{
public:
  int first(vector<int> &arr, int x)
  {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] == x)
      {
        ans = mid;
        high = mid - 1; // move left
      }
      else if (arr[mid] < x)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    return ans;
  }

  int last(vector<int> &arr, int x)
  {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] == x)
      {
        ans = mid;
        low = mid + 1; // move right
      }
      else if (arr[mid] < x)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    return ans;
  }
  vector<int> searchRange(vector<int> &arr, int x)
  {

    int f = first(arr, x);
    if (f == -1)
      return {-1, -1};
    int l = last(arr, x);
    return {f, l};
  }
};