#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows == 1 || numRows >= (int)s.size())
      return s;

    vector<string> rows(numRows);
    int curRow = 0;
    int dir = 1; // +1 = moving down, -1 = moving up

    for (char ch : s)
    {
      rows[curRow].push_back(ch);
      if (curRow == 0)
        dir = 1;
      else if (curRow == numRows - 1)
        dir = -1;
      curRow += dir;
    }

    string res;
    for (auto &row : rows)
      res += row;
    return res;
  }
};
