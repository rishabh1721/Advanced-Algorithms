#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  vector<int> buildLPS(string &pat)
  {
    int n = pat.size();
    vector<int> lps(n, 0);
    int len = 0;

    for (int i = 1; i < n;)
    {
      if (pat[i] == pat[len])
      {
        lps[i++] = ++len;
      }
      else
      {
        if (len != 0)
          len = lps[len - 1];
        else
          lps[i++] = 0;
      }
    }
    return lps;
  }

  bool KMP(string &txt, string &pat)
  {
    vector<int> lps = buildLPS(pat);
    int i = 0, j = 0;

    while (i < txt.size())
    {
      if (txt[i] == pat[j])
      {
        i++;
        j++;
        if (j == pat.size())
          return true;
      }
      else
      {
        if (j != 0)
          j = lps[j - 1];
        else
          i++;
      }
    }
    return false;
  }

  bool areRotations(string s1, string s2)
  {
    if (s1.size() != s2.size())
      return false;
    string txt = s1 + s1;
    return KMP(txt, s2);
  }
};
