#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int func(vector<int> &arr, int pages)
  {
    int stu = 1, pageStu = 0;

    for (int x : arr)
    {
      if (pageStu + x <= pages)
      {
        pageStu += x;
      }
      else
      {
        stu++;
        pageStu = x;
      }
    }
    return stu;
  }

  int summ(vector<int> &arr)
  {
    int sum = 0;
    for (int x : arr)
      sum += x;
    return sum;
  }

  int findPages(vector<int> &arr, int k)
  {
    if (arr.size() < k)
      return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = summ(arr);

    while (low < high)
    {
      int mid = low + (high - low) / 2;

      if (func(arr, mid) <= k)
        high = mid;
      else
        low = mid + 1;
    }
    return low;
  }

  // LeetCode 410
  int splitArray(vector<int> &arr, int k)
  {
    return findPages(arr, k);
  }
};
