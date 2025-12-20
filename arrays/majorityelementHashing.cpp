#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &arr)
  {
    // code here
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
      mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
      if (it.second > arr.size() / 2)
      {
        return it.first;
      }
    }
    return -1;
  }
};