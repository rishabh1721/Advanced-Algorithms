#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void nextPermutation(vector<int> &arr)
  {
    // code here
    next_permutation(arr.begin(), arr.end());
  }
};