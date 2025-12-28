#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
  int secondMostFrequentElement(vector<int> &arr)
  {
    unordered_map<int, int> freq;

    // Count frequencies
    for (int x : arr)
    {
      freq[x]++;
    }

    int maxFreq = 0;
    for (auto &p : freq)
    {
      maxFreq = max(maxFreq, p.second);
    }

    int secondMaxFreq = 0;
    for (auto &p : freq)
    {
      if (p.second < maxFreq)
      {
        secondMaxFreq = max(secondMaxFreq, p.second);
      }
    }

    // If no second most frequent exists
    if (secondMaxFreq == 0)
      return -1;

    int ans = INT_MAX;
    for (auto &p : freq)
    {
      if (p.second == secondMaxFreq)
      {
        ans = min(ans, p.first);
      }
    }

    return ans;
  }
};
