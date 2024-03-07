#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display_board(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl;
        cout << "---------" << endl;
    }
}

bool check_win(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool check_draw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

void switch_player(char& current_player) {
    current_player = (current_player == 'X') ? 'O' : 'X';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char current_player = 'X';
    bool game_over = false;

    while (!game_over) {
        display_board(board);
        int row, col;
        cout << "Player " << current_player << ", enter row (1-3): ";
        cin >> row;
        cout << "Player " << current_player << ", enter column (1-3): ";
        cin >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = current_player;

        if (check_win(board, current_player)) {
            display_board(board);
            cout << "Player " << current_player << " wins!" << endl;
            game_over = true;
        } else if (check_draw(board)) {
            display_board(board);
            cout << "It's a draw!" << endl;
            game_over = true;
        } else {
            switch_player(current_player);
        }
    }

    char play_again;
    cout << "Do you want to play again? (y/n): ";
    cin >> play_again;
    if (play_again == 'y' || play_again == 'Y') {
        main(); // Restart the game
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}
