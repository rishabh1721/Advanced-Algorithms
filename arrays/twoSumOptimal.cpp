#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &arr, int target)
  {
    // code here

    int left = 0;
    int right = arr.size() - 1;
    sort(arr.begin(), arr.end());
    while (left < right)
    {
      int sum = arr[left] + arr[right];
      if (sum == target)
      {
        return {left + 1, right + 1};
      }
      else if (sum < target)
      {
        left++;
      }
      else
      {
        right--;
      }
    }
    return {};
  }
};
