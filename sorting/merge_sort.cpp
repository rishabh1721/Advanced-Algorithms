#include <vector>
using namespace std;
#include <iostream>

class Solution
{
public:
  void merge(vector<int> &arr, int low, int mid, int high)
  {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merge both halves
    while (left <= mid && right <= high)
    {
      if (arr[left] <= arr[right])
      {
        temp.push_back(arr[left]);
        left++;
      }
      else
      {
        temp.push_back(arr[right]);
        right++;
      }
    }

    // Copy remaining left half
    while (left <= mid)
    {
      temp.push_back(arr[left]);
      left++;
    }

    // Copy remaining right half
    while (right <= high)
    {
      temp.push_back(arr[right]);
      right++;
    }

    // Copy sorted temp back to arr
    for (int i = low; i <= high; i++)
    {
      arr[i] = temp[i - low];
    }
  }

  void ms(vector<int> &arr, int low, int high)
  {
    if (low >= high)
      return;

    int mid = low + (high - low) / 2;

    ms(arr, low, mid);
    ms(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }

  void mergeSort(vector<int> &arr, int l, int r)
  {
    ms(arr, l, r);
  }
};
