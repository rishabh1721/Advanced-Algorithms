#include <vector>
using namespace std;

class Solution
{
private:
  bool isValid(vector<vector<char>> &board, int row, int col, char ch)
  {
    for (int i = 0; i < 9; i++)
    {
      // row
      if (board[row][i] == ch)
        return false;
      // column
      if (board[i][col] == ch)
        return false;
      // 3x3 grid
      int startRow = 3 * (row / 3) + i / 3;
      int startCol = 3 * (col / 3) + i % 3;
      if (board[startRow][startCol] == ch)
        return false;
    }
    return true;
  }

public:
  bool solve(vector<vector<char>> &board)
  {
    int n = 9;
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < n; col++)
      {
        if (board[row][col] == '.')
        {
          for (char ch = '1'; ch <= '9'; ch++)
          {
            if (isValid(board, row, col, ch))
            {
              board[row][col] = ch;
              if (solve(board))
                return true;
              board[row][col] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  void solveSudoku(vector<vector<char>> &board)
  {

    solve(board);
  }
};