#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> intersection(vector<int> &a, vector<int> &b)
  {
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector<int> ans;

    while (i < n && j < m)
    {
      if (a[i] < b[j])
      {
        i++;
      }
      else if (a[i] > b[j])
      {
        j++;
      }
      else
      {
        int val = a[i];
        ans.push_back(val);

        while (i < n && a[i] == val)
          i++;
        while (j < m && b[j] == val)
          j++;
      }
    }
    return ans;
  }
};
