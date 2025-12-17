#include <vector>
using namespace std;

class Solution
{
public:
  int findUnique(vector<int> &arr)
  {
    // code here
    int xor1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      xor1 = xor1 ^ arr[i];
    }
    return xor1;
  }
};