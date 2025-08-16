#include "dbg.h"

// TC -> 81 ^ 9
// SC -> no of empty cells

bool isValidPos(char i, int row, int col, vector<vector<char>> &board) {
  int t_row = (row / 3) * 3;
  int t_col = (col / 3) * 3;
  for (int j = 0; j < 9; j++) {
    if (board[j][col] == i) {
      return false;
    }
    if (board[row][j] == i) {
      return false;
    }
    if (board[t_row + (j / 3)][t_col + (j % 3)] == i) {
      return false;
    }
  }
  return true;
}

void newSpot(int &row, int &col, vector<vector<char>> &board) {
  int r, c;
  for (r = row; r < 9; r++) {
    for (c = 0; c < 9; c++) {
      if (board[r][c] == '.') {
        row = r, col = c;
        return;
      }
    }
  }
  row = 9, col = 0;
}

bool recFun(int row, int col, vector<vector<char>> &board) {
  if (row >= 9) {
    return true;
  }
  int box = (row / 3) * 3 + (col / 3);
  for (char i = '1'; i <= '9'; i++) {
    if (isValidPos(i, row, col, board)) {
      board[row][col] = i;
      int r = row, c = col;
      newSpot(r, c, board);
      if (recFun(r, c, board)) {
        return true;
      }
      board[row][col] = '.';
    }
  }
  return false;
}

void solveSudoku(vector<vector<char>> &board) {
  int row = 0, col = 0;
  newSpot(row, col, board);
  recFun(row, col, board);
  for (vector<char> &list : board) {
    dbg_print_each(list);
  }
  return;
}

#undef dbg_test_fun
int main() {
  vector<vector<char>> board;

#define dbg_test_fun solveSudoku(board)

  board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  dbg_test_fun;

  return EXIT_SUCCESS;
}
