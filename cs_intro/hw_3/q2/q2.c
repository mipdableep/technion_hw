#include <stdbool.h>
#include <stdio.h>

#define ROWS 8
#define COLS 8
#define NUM_OF_BOARDS 5
#define SUBMARINE 'S'
#define WATER '~'
#define HIDDEN_WATER '-'
#define HIDDEN_SUB 'h'
#define HIDDEN ' '

// Function Declarations
void print_welcome_message(void);
void print_wrong_board_number(void);
void print_enter_position(void);
void print_error_row_or_col(void);
void print_error_position_already_bombed(void);
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

void print_welcome_message(void) {
    printf("Welcome to Battleship! Please enter board number:\n");
}
void print_wrong_board_number(void) {
    printf("Error in board number, try again\n");
}
void print_enter_position(void) {
    printf("Please enter position:\n");
}
void print_error_row_or_col(void) {
    printf("Error in row or column - out of bound\n");
}
void print_error_position_already_bombed(void) {
    printf("This position was already bombed - try again!\n");
}
void print_winning_message(int n_submarines, int n_moves) {
    printf("Congratulations, Admiral!\nYou've successfully "
           "revealed all %d submarines in %d moves!\n",
           n_submarines, n_moves);
}
// clang-format on

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

void print_game_matrix(char matrix[ROWS][COLS]) {
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
            char c = matrix[i][j];
            if (c == HIDDEN_SUB || c == HIDDEN_WATER)
                c = HIDDEN;
            printf("|%c", c);
        }
        printf("|\n");
    }
}

void print_win_matrix(char matrix[ROWS][COLS]) {
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
            char c = matrix[i][j];
            if (c == HIDDEN_WATER)
                c = WATER;
            printf("|%c", c);
        }
        printf("|\n");
    }
}

bool get_valid_loc(int *row_ret, int *col_ret) {
    char col = ' ';
    int row = -1;

    while (true) {
        print_enter_position();
        if (scanf("%d %c", &row, &col) != 2)
            return false;
        if (!((col >= 'A' && col <= 'Z') || (col >= 'a' && col <= 'z')))
            return false;
        if ((row >= 0 && row <= 7 && col >= 'A' && col <= 'H'))
            break;
        print_error_row_or_col();
    }
    *row_ret = row;
    *col_ret = (int) (col - 'A');
    return true;
}

// - is hidden water
// h is hidden sub
void cp_board_and_hide_water(const char from[ROWS][COLS], char to[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            char current = from[r][c];
            if (current == WATER)
                to[r][c] = HIDDEN_WATER;
            else
                to[r][c] = from[r][c];
        }
    }
}

void get_board(char board[ROWS][COLS], int board_num) {

    if (board_num == 1)
        cp_board_and_hide_water(MATRIX_1, board);
    if (board_num == 2)
        cp_board_and_hide_water(MATRIX_2, board);
    if (board_num == 3)
        cp_board_and_hide_water(MATRIX_3, board);
    if (board_num == 4)
        cp_board_and_hide_water(MATRIX_4, board);
    if (board_num == 5)
        cp_board_and_hide_water(MATRIX_5, board);
}

// Add your functions here
bool get_board_from_user(char board_copy[ROWS][COLS]) {
    int board_num = -1;
    while (true) {
        if (scanf("%d", &board_num) != 1) {
            return false;
        }
        if (!(board_num >= 1 && board_num <= NUM_OF_BOARDS))
            print_wrong_board_number();
        else
            break;
    }
    get_board(board_copy, board_num);
    return true;
}

void get_board_from_num(char board_copy[ROWS][COLS], int board_num) {
    if (!(board_num >= 1 && board_num <= NUM_OF_BOARDS)) {
        print_wrong_board_number();
        return;
    }
    get_board(board_copy, board_num);
}

void hide_subs_up_down(char board[ROWS][COLS], int s_row, int s_col) {
    if (s_row > 0) {
        for (int i = s_row - 1; i >= 0; i--) {
            if (board[i][s_col] == SUBMARINE)
                board[i][s_col] = HIDDEN_SUB;
            else
                break;
        }
    }
    if (s_row < 7) {
        for (int i = s_row + 1; i <= 7; i++) {
            if (board[i][s_col] == SUBMARINE)
                board[i][s_col] = HIDDEN_SUB;
            else
                break;
        }
    }
}

void hide_subs_left_right(char board[ROWS][COLS], int s_row, int s_col) {
    if (s_col > 0) {
        for (int j = s_col - 1; j >= 0; j--) {
            if (board[s_row][j] == SUBMARINE)
                board[s_row][j] = HIDDEN_SUB;
            else
                break;
        }
    }
    if (s_col < 7) {
        for (int j = s_col + 1; j <= 7; j++) {
            if (board[s_row][j] == SUBMARINE)
                board[s_row][j] = HIDDEN_SUB;
            else
                break;
        }
    }
}

void hide_sub(char board[ROWS][COLS], int s_row, int s_col) {
    board[s_row][s_col] = HIDDEN_SUB;
    hide_subs_up_down(board, s_row, s_col);
    hide_subs_left_right(board, s_row, s_col);
}

void reveal_subs_up_down(char board[ROWS][COLS], int s_row, int s_col) {
    if (s_row > 0) {
        for (int i = s_row - 1; i >= 0; i--) {
            if (board[i][s_col] == HIDDEN_SUB)
                board[i][s_col] = SUBMARINE;
            else
                break;
        }
    }
    if (s_row < 7) {
        for (int i = s_row + 1; i <= 7; i++) {
            if (board[i][s_col] == HIDDEN_SUB)
                board[i][s_col] = SUBMARINE;
            else
                break;
        }
    }
}

void reveal_subs_left_right(char board[ROWS][COLS], int s_row, int s_col) {
    if (s_col > 0) {
        for (int j = s_col - 1; j >= 0; j--) {
            if (board[s_row][j] == HIDDEN_SUB)
                board[s_row][j] = SUBMARINE;
            else
                break;
        }
    }
    if (s_col < 7) {
        for (int j = s_col + 1; j <= 7; j++) {
            if (board[s_row][j] == HIDDEN_SUB)
                board[s_row][j] = SUBMARINE;
            else
                break;
        }
    }
}

void reveal_sub(char board[ROWS][COLS], int s_row, int s_col) {
    board[s_row][s_col] = SUBMARINE;
    reveal_subs_up_down(board, s_row, s_col);
    reveal_subs_left_right(board, s_row, s_col);
}

int get_num_of_subs_and_hide(char board[ROWS][COLS]) {
    int num_subs = 0;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (board[row][col] == SUBMARINE) {
                num_subs++;
                hide_sub(board, row, col);
            }
        }
    }
    return num_subs;
}

enum PLAY_MOVE_RET { INVALID_MOVE, HIT_WATER, HIT_SUB };

int play_move_return_valid(char board[ROWS][COLS], int row, int col) {
    if (board[row][col] == SUBMARINE || board[row][col] == WATER) {
        print_error_position_already_bombed();
        return INVALID_MOVE;
    }

    if (board[row][col] == HIDDEN_WATER) {
        board[row][col] = WATER;
        return HIT_WATER;
    }
    if (board[row][col] == HIDDEN_SUB) {
        reveal_sub(board, row, col);
        return HIT_SUB;
    } else {
        printf("PANIC!! - ileagal tile");
        return -1;
    }
}

int play_game(char board[ROWS][COLS], int num_of_subs) {
    int row = -1, col = -1, turns = 0, subs_left = num_of_subs;
    print_game_matrix(board);
    while (subs_left > 0) {
        if (!get_valid_loc(&row, &col))
            return -1;
        int move_res = play_move_return_valid(board, row, col);
        if (move_res == INVALID_MOVE) {
            continue;
        }
        turns++;
        if (move_res == HIT_SUB)
            subs_left--;
        if (subs_left > 0)
            print_game_matrix(board);
        else
            print_win_matrix(board);
    }

    return turns;
}

int main(void) {
    print_welcome_message();
    char mut_board[ROWS][COLS] = {0};
    if (!get_board_from_user(mut_board))
        return -1;
    int num_of_subs = get_num_of_subs_and_hide(mut_board);

    int turns = play_game(mut_board, num_of_subs);
    if (turns == -1)
        return 0;


    print_winning_message(num_of_subs, turns);

    return 0;
}
