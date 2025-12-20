#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void sort012(vector<int> &arr)
  {
    // code here
    int n = arr.size();
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
      {
        c0++;
      }
      if (arr[i] == 1)
      {
        c1++;
      }
      else
      {
        c2++;
      }
    }
    for (int i = 0; i <= c0; i++)
    {
      arr[i] = 0;
    }
    for (int i = c0; i <= c0 + c1; i++)
    {
      arr[i] = 1;
    }
    for (int i = c0 + c1; i < c0 + c1 + c2; i++)
    {
      arr[i] = 2;
    }
  }
};