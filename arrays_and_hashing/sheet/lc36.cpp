#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char num = board[row][col];

                if (num == '.') {
                    continue;
                }

                char temp = board[row][col];
                board[row][col] = '.';

                if (isNumberInRow(board, row, temp) ||
                    isNumberInCol(board, col, temp) ||
                    isNumberInSubgrid(board, row - row % 3, col - col % 3, temp)) {
                    return false;
                }

                // Restore the number
                board[row][col] = temp;
            }
        }
        return true;
    }

private:
    bool isNumberInRow(const vector<vector<char>>& board, int row, char num) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == num) {
                return true;
            }
        }
        return false;
    }

    bool isNumberInCol(const vector<vector<char>>& board, int col, char num) {
        for (int row = 0; row < 9; ++row) {
            if (board[row][col] == num) {
                return true;
            }
        }
        return false;
    }

    bool isNumberInSubgrid(const vector<vector<char>>& board, int startRow,
                           int startCol, char num) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[startRow + i][startCol + j] == num) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Sample Sudoku board (valid)
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '9', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '8', '5', '.', '9', '7', '8', '.', '2'}
    };

    bool result = solution.isValidSudoku(board);

    cout << "Is the Sudoku board valid? " << (result ? "Yes" : "No") << endl;

    return 0;
}
