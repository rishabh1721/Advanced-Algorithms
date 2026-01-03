#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  bool isSafe(vector<string> &board, int row, int col)
  {
    int n = board.size();

    // same column
    for (int i = row - 1; i >= 0; i--)
    {
      if (board[i][col] == 'Q')
        return false;
    }

    // top-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--)
    {
      if (board[i][j] == 'Q')
        return false;
    }

    // top-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n;
         i--, j++)
    {
      if (board[i][j] == 'Q')
        return false;
    }

    return true;
  }

  void helper(int row, vector<vector<string>> &ans, vector<string> &board)
  {
    // base class

    if (row == board.size())
    {
      ans.push_back(board);
      return;
    }
    for (int col = 0; col < board.size(); col++)
    {
      if (isSafe(board, row, col))
      {
        board[row][col] = 'Q';
        helper(row + 1, ans, board);
        board[row][col] = '.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n)
  {

    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    helper(0, ans, board);
    return ans;
  }
};