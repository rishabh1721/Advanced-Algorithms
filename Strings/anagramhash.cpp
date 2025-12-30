#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    int n = s.length();
    if (n != t.length())
      return false;
    int freqs[26] = {0};
    int freqt[26] = {0};

    for (int i = 0; i < n; i++)
    {
      freqs[s[i] - 'a']++;
      freqt[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
      if (freqs[i] != freqt[i])
        return false;
    }
    return true;
  }
};