#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
  vector<int> smallestDifferenceTriplet(vector<int> &arr1,
                                        vector<int> &arr2,
                                        vector<int> &arr3)
  {

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end());

    int i = 0, j = 0, k = 0;
    int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();

    int bestDiff = INT_MAX;
    int bestSum = INT_MAX;
    vector<int> best(3);

    while (i < n1 && j < n2 && k < n3)
    {
      int x = arr1[i], y = arr2[j], z = arr3[k];

      int mx = max({x, y, z});
      int mn = min({x, y, z});
      int diff = mx - mn;
      int sum = x + y + z;

      if (diff < bestDiff || (diff == bestDiff && sum < bestSum))
      {
        bestDiff = diff;
        bestSum = sum;
        best = {x, y, z};
      }

      if (mn == x)
        i++;
      else if (mn == y)
        j++;
      else
        k++;
    }

    sort(best.begin(), best.end(), greater<int>());
    return best;
  }
};
