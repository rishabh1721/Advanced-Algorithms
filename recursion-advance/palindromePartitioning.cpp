#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
  bool isPal(string &s, int l, int r)
  {
    while (l < r)
    {
      if (s[l++] != s[r--])
      {
        return false;
      }
    }
    return true;
  }

  void helper(int i, string &s, vector<string> &path, vector<vector<string>> &ans)
  {
    if (i == s.size())
    {
      ans.push_back(path);
      return;
    }

    for (int j = i; j < s.size(); j++)
    {
      if (isPal(s, i, j) == true)
      {
        path.push_back(s.substr(i, j - i + 1));
        helper(j + 1, s, path, ans);
        path.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s)
  {
    vector<string> path;
    vector<vector<string>> ans;
    helper(0, s, path, ans);
    return ans;
  }
};