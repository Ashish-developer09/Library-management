#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void printBoard() {
    system("clear"); // Use "cls" on Windows
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] ||
            board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
        board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int choice;
    int row, col;
    char turn = 'X';
    bool draw = false;

    cout << "Tic-Tac-Toe Game!" << endl;

    while (true) {
        printBoard();
        cout << "Player " << (turn == 'X' ? 1 : 2) << " (" << turn << ")'s turn. Enter the number of the cell: ";
        cin >> choice;

        switch (choice) {
            case 1: row = 0; col = 0; break;
            case 2: row = 0; col = 1; break;
            case 3: row = 0; col = 2; break;
            case 4: row = 1; col = 0; break;
            case 5: row = 1; col = 1; break;
            case 6: row = 1; col = 2; break;
            case 7: row = 2; col = 0; break;
            case 8: row = 2; col = 1; break;
            case 9: row = 2; col = 2; break;
            default:
                cout << "Invalid move! Try again." << endl;
                continue;
        }

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken! Try again." << endl;
            continue;
        }

        board[row][col] = turn;

        if (checkWin()) {
            printBoard();
            cout << "Player " << (turn == 'X' ? 1 : 2) << " (" << turn << ") wins!" << endl;
            break;
        } else if (isBoardFull()) {
            printBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        turn = (turn == 'X') ? 'O' : 'X';
    }

    return 0;
}
