#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  bool areAnagrams(string &s1, string &s2)
  {
    // code here
    if (s1.length() != s2.length())
      return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2)
    {
      return true;
    }
    return false;
  }
};