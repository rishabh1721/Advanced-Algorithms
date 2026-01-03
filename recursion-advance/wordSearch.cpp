#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  int n, m;

  bool wordSearch(int r, int c, int idx,
                  vector<vector<char>> &mat, string &word)
  {

    if (idx == word.size())
      return true;

    if (r < 0 || c < 0 || r >= n || c >= m ||
        mat[r][c] != word[idx])
      return false;

    char temp = mat[r][c];
    mat[r][c] = '#';

    bool found =
        wordSearch(r - 1, c, idx + 1, mat, word) ||
        wordSearch(r + 1, c, idx + 1, mat, word) ||
        wordSearch(r, c - 1, idx + 1, mat, word) ||
        wordSearch(r, c + 1, idx + 1, mat, word);

    mat[r][c] = temp; // backtrack
    return found;
  }

  bool isWordExist(vector<vector<char>> &mat, string &word)
  {
    n = mat.size();
    m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (wordSearch(i, j, 0, mat, word))
          return true;
      }
    }
    return false;
  }
};
