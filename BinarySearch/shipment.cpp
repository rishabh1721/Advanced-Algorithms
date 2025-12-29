#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int Finddays(int arr[], int n, int cap)
  {
    int days = 1, load = 0;

    for (int i = 0; i < n; i++)
    {
      if (load + arr[i] > cap)
      {
        days++;
        load = arr[i];
      }
      else
      {
        load += arr[i];
      }
    }
    return days;
  }

  int sum(int arr[], int n)
  {
    int s = 0;
    for (int i = 0; i < n; i++)
      s += arr[i];
    return s;
  }

  int leastWeightCapacity(int arr[], int n, int d)
  {
    int low = *max_element(arr, arr + n);
    int high = sum(arr, n);

    while (low < high)
    {
      int mid = low + (high - low) / 2;

      if (Finddays(arr, n, mid) <= d)
        high = mid;
      else
        low = mid + 1;
    }
    return low;
  }
};
