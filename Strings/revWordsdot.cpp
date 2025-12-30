#include <string>
using namespace std;

class Solution
{
private:
  void reversee(string &s, int l, int r)
  {
    while (l < r)
    {
      swap(s[l++], s[r--]);
    }
  }

public:
  string reverseWords(string s)
  {
    int n = s.size();

    // reverse whole string
    reversee(s, 0, n - 1);

    int i = 0, j = 0;

    while (j < n)
    {
      // skip dots
      while (j < n && s[j] == '.')
        j++;
      if (j == n)
        break;

      int start = i;

      // copy word
      while (j < n && s[j] != '.')
        s[i++] = s[j++];

      // reverse word
      reversee(s, start, i - 1);

      // add dot if more words
      if (j < n)
        s[i++] = '.';
    }

    // remove trailing dot
    if (i > 0 && s[i - 1] == '.')
      i--;

    return s.substr(0, i);
  }
};
