#include <string>
using namespace std;
#include <algorithm>

class Solution
{
private:
  void reversee(string &s, int start, int end)
  {
    while (start < end)
    {
      swap(s[start++], s[end--]);
    }
  }

public:
  string reverseWords(string s)
  {
    int n = s.length();
    reversee(s, 0, n - 1);

    int i = 0, j = 0;

    while (j < n)
    {
      while (j < n && s[j] == ' ')
        j++; // skip spaces
      if (j == n)
        break;

      int start = i;
      while (j < n && s[j] != ' ')
        s[i++] = s[j++];

      reversee(s, start, i - 1);

      if (j < n)
        s[i++] = ' ';
    }

    if (i > 0 && s[i - 1] == ' ')
      i--;
    return s.substr(0, i);
  }
};
