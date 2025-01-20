#include <stdbool.h>
#include <stdio.h>

#define ROWS 8
#define COLS 8
#define NUM_OF_BOARDS 5
#define SUBMARINE 'S'
#define EMPTY '~'
#define HIDDEN ' '

// Function Declarations
void print_welcome_message(void);
void print_wrong_board_number(void);
void print_enter_position(void);
void print_error_row_or_col(void);
void print_error_position_already_bombed(void);
void print_winning_message(int n_submarines, int n_moves);
void printMatrix(char *matrix);


// Optional Boards

const char MATRIX_1[ROWS][COLS] = {{'~', '~', '~', '~', '~', '~', '~', '~'}, {'~', '~', 'S', '~', '~', '~', 'S', '~'},
                                   {'~', '~', 'S', '~', '~', '~', 'S', '~'}, {'~', '~', 'S', '~', '~', '~', 'S', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}, {'S', '~', '~', 'S', '~', '~', '~', '~'},
                                   {'S', '~', '~', 'S', '~', '~', '~', '~'}, {'S', '~', '~', 'S', '~', '~', '~', '~'}};
const char MATRIX_2[ROWS][COLS] = {{'S', '~', '~', '~', '~', '~', '~', '~'}, {'S', '~', 'S', '~', '~', '~', '~', '~'},
                                   {'S', '~', 'S', '~', '~', '~', '~', '~'}, {'~', '~', 'S', '~', '~', '~', '~', 'S'},
                                   {'~', '~', '~', '~', '~', '~', '~', 'S'}, {'~', '~', '~', '~', '~', '~', '~', 'S'},
                                   {'~', 'S', 'S', '~', '~', '~', '~', '~'}, {'~', '~', '~', '~', '~', '~', '~', '~'}};
const char MATRIX_3[ROWS][COLS] = {{'~', 'S', 'S', 'S', '~', '~', '~', '~'}, {'~', '~', '~', '~', '~', 'S', 'S', 'S'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}, {'~', '~', '~', '~', 'S', 'S', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}, {'~', '~', 'S', 'S', 'S', 'S', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}, {'S', '~', '~', '~', '~', '~', '~', '~'}};
const char MATRIX_4[ROWS][COLS] = {{'~', '~', '~', '~', '~', '~', '~', '~'}, {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}, {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}, {'~', '~', '~', '~', '~', '~', '~', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}, {'~', '~', '~', '~', '~', '~', '~', '~'}};
const char MATRIX_5[ROWS][COLS] = {{'S', '~', 'S', '~', '~', '~', '~', 'S'}, {'~', '~', '~', '~', '~', 'S', '~', '~'},
                                   {'~', '~', 'S', '~', '~', '~', '~', '~'}, {'~', '~', '~', '~', '~', '~', 'S', '~'},
                                   {'~', '~', '~', 'S', '~', '~', '~', '~'}, {'~', 'S', '~', '~', '~', '~', 'S', '~'},
                                   {'~', '~', '~', '~', '~', '~', '~', '~'}, {'S', '~', '~', 'S', '~', '~', '~', 'S'}};

void print_welcome_message(void) { printf("Welcome to Battleship! Please enter board number:\n"); }
void print_wrong_board_number(void) { printf("Error in board number, try again\n"); }
void print_enter_position(void) { printf("Please enter position:\n"); }
void print_error_row_or_col(void) { printf("Error in row or column - out of bound\n"); }
void print_error_position_already_bombed(void) { printf("This position was already bombed - try again!\n"); }
void print_winning_message(int n_submarines, int n_moves) {
    printf("Congratulations, Admiral!\nYou've successfully "
           "revealed all %d submarines in %d moves!\n",
           n_submarines, n_moves);
}

// Print a ROWSxCOLS matrix
void printMatrix(char *matrix) {
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

    while (!((scanf("%d", &row) != 1 && row >= 0 && row <= 7) &&
             (scanf("%c", &col) != 1 && col >= 'A' && col <= 'H'))) {
        print_error_row_or_col();
    }
    *row_ret = row;
    *col_ret = (int) (col - 'A');
}

void cp_board(const char *from, char *to) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            to[r][c] = from[r][c];
        }
    }
}

// Add your functions here
char *get_board_from_user() {
    int board_num;
    while (!(scanf("%d", &board_num) != 1 && board_num >= 1 && board_num <= 5)) {
        print_wrong_board_number();
    }
    if (board_num == 1)
        return (char *) (*MATRIX_1);
    if (board_num == 2)
        return (char *) (*MATRIX_2);
    if (board_num == 3)
        return (char *) (*MATRIX_3);
    if (board_num == 4)
        return (char *) (*MATRIX_4);
    if (board_num == 5)
        return (char *) (*MATRIX_5);
    else
        return NULL;
}

int main(void) {
    print_welcome_message();
    char *board = get_board_from_user(), board_2[8][8] = {0}, *mut_board[] = *board_2;
    cp_board(board, mut_board);
    printMatrix((&mut_board));


    int row = -1, col = -1;
    while (true) {
        get_valid_loc(&row, &col);
        break;
    }


    return 0;
}
