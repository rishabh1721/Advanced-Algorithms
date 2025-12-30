#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> transpose(vector<vector<int>> &m)
  {
    // code here
    int n = m.size();
    int x = m[0].size();

    vector<vector<int>> T(x, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < x; j++)
      {
        T[j][i] = m[i][j];
      }
    }
    return T;
  }
};