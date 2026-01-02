#include <vector>
using namespace std;
#include <string>

class Solution
{
private:
  void help(int idx,
            vector<int> &arr,
            string &path,
            vector<string> &ans,
            vector<string> &mp)
  {

    if (idx == arr.size())
    {
      if (!path.empty())
        ans.push_back(path);
      return;
    }

    // 🚨 Skip digits 0 and 1
    if (mp[arr[idx]].empty())
    {
      help(idx + 1, arr, path, ans, mp);
      return;
    }

    string letters = mp[arr[idx]];
    for (char ch : letters)
    {
      path.push_back(ch);
      help(idx + 1, arr, path, ans, mp);
      path.pop_back();
    }
  }

public:
  vector<string> possibleWords(vector<int> &arr)
  {

    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;
    string path;
    help(0, arr, path, ans, mp);
    return ans;
  }
};
