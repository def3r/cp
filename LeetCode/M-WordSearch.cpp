#include "dbg.h"

bool recFun(int row, int col, int w_idx, vector<vector<char>> &board,
            string &word) {
  if (w_idx >= word.length()) {
    return true;
  }

  if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
      board[row][col] != word[w_idx]) {
    return false;
  }

  char c = board[row][col];
  board[row][col] = ' ';
  bool res = false;
  res |= recFun(row - 1, col, w_idx + 1, board, word);
  res |= recFun(row, col + 1, w_idx + 1, board, word);
  res |= recFun(row + 1, col, w_idx + 1, board, word);
  res |= recFun(row, col - 1, w_idx + 1, board, word);
  board[row][col] = c;

  return res;
}

bool exist(vector<vector<char>> &board, string word) {
  int row_idx = 0, col_idx = 0;
  for (row_idx = 0; row_idx < board.size(); row_idx++) {
    for (col_idx = 0; col_idx < board[0].size(); col_idx++) {
      if (board[row_idx][col_idx] == word[0] &&
          recFun(row_idx, col_idx, 0, board, word)) {
        return true;
      }
    }
  }
  return false;
}

#undef dbg_test_fun
int main() {
  vector<vector<char>> board;
  string word;

#define dbg_test_fun exist(board, word)
  dbg_test_with(true, board = {{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};
                word = "ABCCED");

  dbg_test_with(true, word = "SEE");
  dbg_test_with(false, word = "ABCB");

  return EXIT_SUCCESS;
}
