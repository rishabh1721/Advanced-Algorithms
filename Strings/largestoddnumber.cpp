#include <vector>

#include <string>
using namespace std;

class Solution
{
public:
  string maxOdd(string s)
  {
    // code here
    int n = s.length();
    int j = -1;
    for (int i = n - 1; i >= 0; i--)
    {
      if ((s[i] - '0') % 2 == 1)
      {
        return s.substr(0, i + 1);
      }
    }
    return "";
  }
};