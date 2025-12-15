#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> removeDuplicates(vector<int> &arr)
  {
    // code here
    int i = 0;
    int n = arr.size();
    for (int j = 1; j < n; j++)
    {
      if (arr[j] != arr[i])
      {
        arr[i + 1] = arr[j];
        i++;
      }
    }
    vector<int> rs;
    for (int k = 0; k <= i; k++)
    {
      rs.push_back(arr[k]);
    }
    return rs;
  }
};