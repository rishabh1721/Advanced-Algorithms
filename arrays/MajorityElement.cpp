#include <vector>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &arr)
  {
    int el = 0, c = 0;

    // Phase 1: Find candidate
    for (int i = 0; i < arr.size(); i++)
    {
      if (c == 0)
      {
        el = arr[i];
        c = 1;
      }
      else if (arr[i] == el)
      {
        c++;
      }
      else
      {
        c--;
      }
    }

    // Phase 2: Verify candidate
    int c1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] == el)
      {
        c1++;
      }
    }

    if (c1 > arr.size() / 2)
    {
      return el;
    }

    return -1;
  }
};
