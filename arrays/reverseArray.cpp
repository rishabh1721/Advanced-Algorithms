#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void reverseArray(vector<int> &arr)
  {
    // code here
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;
    }
  }
};