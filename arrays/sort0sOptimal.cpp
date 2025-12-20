#include <iostream>
#include <array>
#include <vector>
using namespace std;

class Solution
{
public:
  void sort012(vector<int> &arr)
  {

    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
      if (arr[mid] == 0)
      {
        swap(arr[mid], arr[low]);
        low++;
        mid++;
      }
      else if (arr[mid] == 1)
      {
        mid++;
      }
      else
      {
        swap(arr[high], arr[mid]);
        high--;
      }
    }
  }
};