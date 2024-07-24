#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char valid_marker;
char valid_player;

void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int place_marker(int row, int col) {
    if (board[row][col] != ' ') {
        return 0;
    }
    board[row][col] = valid_marker;
    return 1;
}

int has_won() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    return 0;
}

int draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void exchange_player_and_marker() {
    if (valid_marker == 'X') {
        valid_marker = 'O';
    } else {
        valid_marker = 'X';
    }

    if (valid_player == '1') {
        valid_player = '2';
    } else {
        valid_player = '1';
    }
}

int main() {
    valid_marker = 'X';
    valid_player = '1';

    initialize_board();

    while (1) {
        print_board();

        int row, col;
        printf("Player %c, enter your move (row and column): ", valid_player);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (!place_marker(row - 1, col - 1)) {
            printf("This position is already taken! Try again.\n");
            continue;
        }

        if (has_won()) {
            print_board();
            printf("Player %c wins!\n", valid_player);
            break;
        }

        if (draw()) {
            print_board();
            printf("It's a draw!\n");
            break;
        }

        exchange_player_and_marker();
    }

    return 0;
}
