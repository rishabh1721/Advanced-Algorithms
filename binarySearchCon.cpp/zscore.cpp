#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int ZScore(vector<int> &marks, int k)
  {
    sort(marks.begin(), marks.end(), greater<int>());
    int z = 0;
    for (int i = 0; i < marks.size(); i++)
    {
      if (marks[i] >= (i + 1) * k)
      {
        z = i + 1;
      }
      else
      {
        break;
      }
    }
    return z;
  }
};