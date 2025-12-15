#include <vector>
using namespace std;
#include <algorithm>
#include <limits.h>

class Solution
{
public:
  int getSecondLargest(vector<int> &arr)
  {
    // code here
    int large = arr[0];
    int slarge = -1;

    for (int i = 1; i < arr.size(); i++)
    {
      if (arr[i] > large)
      {

        slarge = large;
        large = arr[i];
      }
      else if (arr[i] < large && arr[i] > slarge)
        slarge = arr[i];
    }
    return slarge;
  }
};