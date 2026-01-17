#include <string>
using namespace std;

class Solution
{
public:
  bool checkRecord(string s)
  {
    int absent = 0, late = 0;

    for (char c : s)
    {
      if (c == 'A')
      {
        absent++;
        late = 0;
        if (absent > 1)
          return false;
      }
      else if (c == 'L')
      {
        late++;
        if (late >= 3)
          return false;
      }
      else
      {
        late = 0;
      }
    }
    return true;
  }
};