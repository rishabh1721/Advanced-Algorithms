#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int countSubset(vector<int> &arr, int k)
  {
    // code here
    int n = arr.size();
    int mid = n / 2;

    unordered_map<long long, int> leftSumCount;

    // Generate subset sums for left half
    for (int mask = 0; mask < (1 << mid); mask++)
    {
      long long sum = 0;
      for (int i = 0; i < mid; i++)
      {
        if (mask & (1 << i))
          sum += arr[i];
      }
      leftSumCount[sum]++;
    }

    int ans = 0;
    int rightSize = n - mid;

    // Generate subset sums for right half
    for (int mask = 0; mask < (1 << rightSize); mask++)
    {
      long long sum = 0;
      for (int i = 0; i < rightSize; i++)
      {
        if (mask & (1 << i))
          sum += arr[mid + i];
      }

      long long need = k - sum;
      if (leftSumCount.count(need))
        ans += leftSumCount[need];
    }

    return ans;
  }
};