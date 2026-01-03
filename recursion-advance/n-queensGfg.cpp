#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  bool isSafe(int row, int col, vector<int> &board)
  {
    for (int i = 0; i < row; i++)
    {
      // same column or diagonal
      if (board[i] == col ||
          abs(board[i] - col) == abs(i - row))
        return false;
    }
    return true;
  }

  void helper(int row, vector<vector<int>> &ans,
              vector<int> &board, int n)
  {

    if (row == n)
    {
      ans.push_back(board);
      return;
    }

    for (int col = 0; col < board.size(); col++)
    { // YOUR STYLE
      if (isSafe(row, col, board))
      {
        board[row] = col;
        helper(row + 1, ans, board, n);
      }
    }
  }

  vector<vector<int>> nQueen(int n)
  {
    vector<vector<int>> ans;
    vector<int> board(n);
    helper(0, ans, board, n);

    // convert to 1-based indexing for GFG output
    for (auto &v : ans)
    {
      for (int &x : v)
        x++;
    }
    return ans;
  }
};
