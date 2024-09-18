#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char current_Player;

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        current_Player = 'X';
    }

    void displayBoard() {
        cout << "Current board state:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "-----\n";
        }
    }

    bool placeMark(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = current_Player;
            return true;
        }
        return false;
    }

    bool checkWin() {

        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == current_Player && board[i][1] == current_Player && board[i][2] == current_Player) ||
                (board[0][i] == current_Player && board[1][i] == current_Player && board[2][i] == current_Player)) {
                return true;
            }
        }
        if ((board[0][0] == current_Player && board[1][1] == current_Player && board[2][2] == current_Player) ||
            (board[0][2] == current_Player && board[1][1] == current_Player && board[2][0] == current_Player)) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        current_Player = (current_Player == 'X') ? 'O' : 'X';
    }

    void resetBoard() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        current_Player = 'X';
    }

    void play() {
        int row, col;
        while (true) {
            displayBoard();
            cout << "Player " << current_Player << ", enter your move (row and column): ";
            cin >> row >> col;

            if (placeMark(row - 1, col - 1)) {
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << current_Player << " wins!\n";
                    break;
                }
                if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw!\n";
                    break;
                }
                switchPlayer();
            } else {
                cout << "Invalid move, try again.\n";
            }
        }
    }
};

int main() {
    TicTacToe game;
    char playAgain;

    game.play();

    return 0;
}
