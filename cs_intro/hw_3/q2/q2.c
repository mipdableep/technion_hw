#include <stdbool.h>
#include <stdio.h>

#define ROWS 8
#define COLS 8
#define NUM_OF_BOARDS 5
#define SUBMARINE 'S'
#define EMPTY '~'
#define HIDDEN ' '

// Function Declarations
void print_welcome_message();
void print_wrong_board_number();
void print_enter_position();
void print_error_row_or_col();
void print_error_position_already_bombed();
void print_winning_message(int n_submarines, int n_moves);
void printMatrix(char matrix[ROWS][COLS]);


// Optional Boards

// clang-format off
const char MATRIX_1[ROWS][COLS] = {{'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', 'S', '~', '~', '~', 'S', '~'},
                                   {'~', '~', 'S', '~', '~', '~', 'S', '~'},
                                   {'~', '~', 'S', '~', '~', '~', 'S', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'S', '~', '~', 'S', '~', '~', '~', '~'},
                                   {'S', '~', '~', 'S', '~', '~', '~', '~'},
                                   {'S', '~', '~', 'S', '~', '~', '~', '~'}};

const char MATRIX_2[ROWS][COLS] = {{'S', '~', '~', '~', '~', '~', '~', '~'},
                                   {'S', '~', 'S', '~', '~', '~', '~', '~'},
                                   {'S', '~', 'S', '~', '~', '~', '~', '~'},
                                   {'~', '~', 'S', '~', '~', '~', '~', 'S'},
                                   {'~', '~', '~', '~', '~', '~', '~', 'S'},
                                   {'~', '~', '~', '~', '~', '~', '~', 'S'},
                                   {'~', 'S', 'S', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}};

const char MATRIX_3[ROWS][COLS] = {{'~', 'S', 'S', 'S', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', 'S', 'S', 'S'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', 'S', 'S', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', 'S', 'S', 'S', 'S', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'S', '~', '~', '~', '~', '~', '~', '~'}};

const char MATRIX_4[ROWS][COLS] = {{'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}};

const char MATRIX_5[ROWS][COLS] = {{'S', '~', 'S', '~', '~', '~', '~', 'S'},
                                   {'~', '~', '~', '~', '~', 'S', '~', '~'},
                                   {'~', '~', 'S', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', 'S', '~'},
                                   {'~', '~', '~', 'S', '~', '~', '~', '~'},
                                   {'~', 'S', '~', '~', '~', '~', 'S', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'S', '~', '~', 'S', '~', '~', '~', 'S'}};

//clang-format on
void print_welcome_message() { printf("Welcome to Battleship! Please enter board number:\n"); }
void print_wrong_board_number() { printf("Error in board number, try again\n"); }
void print_enter_position() { printf("Please enter position:\n"); }
void print_error_row_or_col() { printf("Error in row or column - out of bound\n"); }
void print_error_position_already_bombed() { printf("This position was already bombed - try again!\n"); }
void print_winning_message(int n_submarines, int n_moves) {
    printf("Congratulations, Admiral!\nYou've successfully "
           "revealed all %d submarines in %d moves!\n",
           n_submarines, n_moves);
}

// Print a ROWSxCOLS matrix
void printMatrix(char matrix[ROWS][COLS]) {
    // Print column headers
    printf("  ");
    for (int j = 0; j < COLS; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        // Print row label
        printf("%d ", i);

        // Print row
        for (int j = 0; j < COLS; j++) {
            // Each cell is in "|x|" format
            printf("|%c", matrix[i][j]);
        }
        printf("|\n");
    }
}

void get_valid_loc(int *row_ret, int *col_ret) {
    char col = ' ';
    int row = -1;

    while (true) {
        print_enter_position();
        bool valid = true;
        if (scanf("%d %c", &row, &col) != 2)
            valid = false;
        if (!(row >= 0 && row <= 7 && col >= 'A' && col <= 'H'))
            valid = false;
        if (valid)
            break;
        print_error_row_or_col();
    }
    *row_ret = row;
    *col_ret = (int) (col - 'A');
}

void cp_board(const char from[8][8], char to[8][8]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            to[r][c] = from[r][c];
        }
    }
}

void get_board(char board[8][8], int board_num) {

    if (board_num == 1)
        cp_board(MATRIX_1, board);
    if (board_num == 2)
        cp_board(MATRIX_2, board);
    if (board_num == 3)
        cp_board(MATRIX_3, board);
    if (board_num == 4)
        cp_board(MATRIX_4, board);
    if (board_num == 5)
        cp_board(MATRIX_5, board);
}

// Add your functions here
void get_board_from_user(char board_copy[8][8]) {
    int board_num = -1;
    while (true) {
        if (scanf("%d", &board_num) != 1) {
            print_wrong_board_number();
            continue;
        }
        if (!(board_num >= 1 && board_num <= 5))
            print_wrong_board_number();
        else
            break;
    }
    get_board(board_copy, board_num);
}

int main(void) {
    print_welcome_message();
    char mut_board[ROWS][COLS] = {0};
    get_board_from_user(mut_board);
    printMatrix(mut_board);

    int row = -1, col = -1;
    while (true) {
        get_valid_loc(&row, &col);
        printf("pos: %d, %d", row, col);
    }


    return 0;
}
