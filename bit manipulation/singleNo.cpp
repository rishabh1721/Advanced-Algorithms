// User function template for C++
#include <vector>
using namespace std;
class Solution
{
public:
  int getSingle(vector<int> &arr)
  {
    // code here
    int x = 0;
    for (int num : arr)
    {
      x ^= num;
    }
    return x;
  }
};