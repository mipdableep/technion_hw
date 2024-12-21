#include <stdbool.h>
#include <stdio.h>

#define ABS(val) ((val) >= 0 ? (val) : -(val))

#define DIFF_SMALL_BIG ('a' - 'A')

bool is_alpah_bet (char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool valid_input(char c) {
    if (!is_alpah_bet(c)) {
        return false;
    }
    return true;
}


char lower_case(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char)((int)(c) - DIFF_SMALL_BIG);
    }
    return c;
}

char upper_case(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c;
    }
    return (char)((int)(c) + DIFF_SMALL_BIG);
}

char get_prev_char(char c) {
    if (c == 'a' || c == 'A') {
        return 'z';
    }
    return lower_case((char)((int)(c)-1));
}

char get_next_char(char c) {
    if (c == 'z' || c == 'Z') {
        return 'A';
    }
    return upper_case((char)((int)(c)+1));
}

void print_result(char c, char prev, char next,
                  int amount_prev, int amount_next) {
    printf("%c: %d\n", prev, amount_prev);
    printf("%c: %d", next, amount_next);
}

int main() {
    int prev_amount = 0, next_amount = 0;
    char initial_char = 0, cur_char = 0;
    scanf("%c", &initial_char);

    if (!valid_input(initial_char)) {
        printf("Error!!");
        return 0;
    }
    char next_char = get_next_char(initial_char);
    char prev_char = get_prev_char(initial_char);

    while (scanf("%c", &cur_char) != EOF) {
        if (!valid_input(cur_char) && cur_char != '\n' && cur_char != ' ') {
            printf("Error!!");
            return 0;
        }
        if (cur_char == next_char) next_amount++;
        if (cur_char == prev_char) prev_amount++;
   }
    print_result(initial_char, prev_char, next_char, prev_amount, next_amount);
}
