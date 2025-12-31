#include <vector>
#include <string>
using namespace std;
class Solution
{
private:
  void recursive(int open, int close, int n, string s, vector<string> &ans)
  {
    if (s.length() == 2 * n)
    {
      ans.push_back(s);
      return;
    }
    if (open < n)
    {
      recursive(open + 1, close, n, s + "(", ans);
    }
    if (close < open)
    {
      recursive(open, close + 1, n, s + ")", ans);
    }
  }

public:
  vector<string> generateParentheses(int d)
  {
    // code here
    vector<string> ans;
    int n = d / 2;

    recursive(0, 0, n, "", ans);
    return ans;
  }
};