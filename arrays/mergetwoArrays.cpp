#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void mergeArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    int m = nums2.size();

    int gap = (n + m + 1) / 2;

    while (gap > 0)
    {
      int i = 0;
      int j = gap;

      while (j < n + m)
      {
        // both in nums1
        if (i < n && j < n)
        {
          if (nums1[i] > nums1[j])
            swap(nums1[i], nums1[j]);
        }
        // i in nums1, j in nums2
        else if (i < n && j >= n)
        {
          if (nums1[i] > nums2[j - n])
            swap(nums1[i], nums2[j - n]);
        }
        // both in nums2
        else
        {
          if (nums2[i - n] > nums2[j - n])
            swap(nums2[i - n], nums2[j - n]);
        }
        i++;
        j++;
      }

      if (gap == 1)
        break;
      gap = (gap + 1) / 2;
    }
  }
};
