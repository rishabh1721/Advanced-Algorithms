#include <vector>
using namespace std;
#include <iostream>

class Solution
{
public:
  void bubbleSort(vector<int> &arr)
  {

    // code here

    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {
      bool didSwap = false;
      for (int j = 0; j <= i - 1; j++)
      {
        if (arr[j] > arr[j + 1])
        {
          int temp = arr[j + 1];
          arr[j + 1] = arr[j];
          arr[j] = temp;
          didSwap = true;
        }
      }
      if (!didSwap)
        break;
    }
  }
};