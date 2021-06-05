#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef char PlayerID;
#define PLAYER_NIL  0
#define PLAYER_X    'X'
#define PLAYER_O    'O'

PlayerID g_board[3][3];
PlayerID g_players[] = { PLAYER_X, PLAYER_O };
int g_turn = 0;

bool is_full(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g_board[i][j] == PLAYER_NIL) {
                return false;
            }
        }
    }
    return true;
}

void reset(void) {
    g_turn = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            g_board[i][j] = 0;
        }
    }
}

void display_board(void) {
    char display[8][8];
    memset(display, ' ', sizeof(display));
    for (int i = 0; i < 3; i++) {
        int r = 2 * i + 2;
        int c = 2 * i + 2;
        display[0][r] = '0' + i + 1;
        display[c][0] = '0' + i + 1;
    }
    for (int i = 0; i < 4; i++) {
        int r = 2 * i + 1;
        for (int j = 0; j < 7; j++) {
            if (j % 2 == 0) {
                display[r][j + 1] = '+';
            }
            else {
                display[r][j + 1] = '-';
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        int r = 2 * i + 2;
        for (int j = 0; j < 7; j++) {
            if (j % 2 == 0) {
                display[r][j + 1] = '|';
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int r = 2 * i + 2;
            int c = 2 * j + 2;
            if (g_board[i][j] != PLAYER_NIL) {
                display[r][c] = g_board[i][j];
            }
        }
    }
    cout << "Current board:" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << display[i][j];
        }
        cout << endl;
    }
}

bool wins(PlayerID p) {
    bool r[3];
    for (int i = 0; i < 3; i++) {
        r[i] = (g_board[i][0] == p) && (g_board[i][1] == p) && (g_board[i][2] == p);
    }

    bool c[3];
    for (int i = 0; i < 3; i++) {
        c[i] = (g_board[0][i] == p) && (g_board[1][i] == p) && (g_board[2][i] == p);
    }

    bool d[2];
    d[0] = (g_board[0][0] == p) && (g_board[1][1] == p) && (g_board[2][2] == p);
    d[1] = (g_board[0][2] == p) && (g_board[1][1] == p) && (g_board[2][0] == p);

    return r[0] || r[1] || r[2] || c[0] || c[1] || c[2] || d[0] || d[1];
}

PlayerID check_winner(void) {
    if (wins(PLAYER_X)) {
        return PLAYER_X;
    }
    if (wins(PLAYER_O)) {
        return PLAYER_O;
    }
    return PLAYER_NIL;
}

void victory(PlayerID p) {
    if (p == 0) {
        cout << "Round draw" << endl;
    }
    else {
        cout << p << " wins!" << endl;
    }
    reset();
}

bool mark(int r, int c, PlayerID p) {
    if ((1 <= r) && (r <= 3) && (1 <= c) && (c <= 3)) {
        r--;
        c--;
        if (g_board[r][c] == PLAYER_NIL) {
            g_board[r][c] = p;
            return true;
        }
    }
    return false;
}

int main() {
    reset();

    cout << "Commands:" << endl;
    cout << " mark R C - mark at row R column C" << endl;
    cout << " exit - quit the game" << endl;

    bool running = true;
    while (running) {
        PlayerID winner = check_winner();
        if (is_full()) {
            victory(winner);
        }
        else {
            if (winner != PLAYER_NIL) {
                victory(winner);
            }
        }

        display_board();
        cout << "Current turn: " << g_players[g_turn] << endl;

        cout << " $ ";
        string cmd;
        cin >> cmd;

        if (cmd == "mark") {
            int r, c;
            cin >> r >> c;
            if (mark(r, c, g_players[g_turn])) {
                g_turn = (g_turn + 1) % 2;
                cout << "Marked successfully" << endl;
            }
            else {
                cout << "Failed to mark" << endl;
            }
        }
        if (cmd == "exit") {
            running = false;
        }
    }
    cout << "Bye" << endl;

    return 0;
}