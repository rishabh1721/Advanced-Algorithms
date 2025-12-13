#include <vector>
using namespace std;
#include <iostream>

class Solution
{
public:
  int partition(vector<int> &arr, int low, int high)
  {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
      while (arr[i] <= pivot && i < high)
        i++;
      while (arr[j] > pivot && j > low)
        j--;

      if (i < j)
        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j; // pivot index
  }

  void qs(vector<int> &arr, int low, int high)
  {
    if (low < high)
    {
      int pIndex = partition(arr, low, high);
      qs(arr, low, pIndex - 1);
      qs(arr, pIndex + 1, high);
    }
  }

  void quickSort(vector<int> &arr, int low, int high)
  {
    qs(arr, low, high);
  }
};
