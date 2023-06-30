#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "- - - - - - - - - - - -" << endl;
        }

        for (int j = 0; j < board[0].size(); j++) {
            if (j % 3 == 0 && j != 0) {
                cout << " | ";
            }

            if (j == 8) {
                cout << board[i][j] << endl;
            }
            else {
                cout << board[i][j] << " ";
            }
        }
    }
}

pair<int, int> findEmpty(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 0) {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);
}

bool isValid(const vector<vector<int>>& board, int num, pair<int, int> pos) {
    // Verificar linha
    for (int i = 0; i < board[0].size(); i++) {
        if (board[pos.first][i] == num && pos.second != i) {
            return false;
        }
    }

    // Verificar coluna
    for (int i = 0; i < board.size(); i++) {
        if (board[i][pos.second] == num && pos.first != i) {
            return false;
        }
    }

    // Verificar quadrante 3x3
    int box_x = pos.second / 3;
    int box_y = pos.first / 3;

    for (int i = box_y * 3; i < box_y * 3 + 3; i++) {
        for (int j = box_x * 3; j < box_x * 3 + 3; j++) {
            if (board[i][j] == num && make_pair(i, j) != pos) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    pair<int, int> empty = findEmpty(board);
    if (empty.first == -1 && empty.second == -1) {
        return true;
    }
    else {
        int row = empty.first;
        int col = empty.second;

        for (int num = 1; num <= 9; num++) {
            if (isValid(board, num, make_pair(row, col))) {
                board[row][col] = num;

                if (solveSudoku(board)) {
                    return true;
                }

                board[row][col] = 0;
            }
        }

        return false;
    }
}

int main() {
    // Exemplo de tabuleiro de Sudoku
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solveSudoku(board);
    printBoard(board);

    return 0;
}

