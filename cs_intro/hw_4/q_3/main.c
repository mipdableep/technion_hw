#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void printAllDistinctSums(int n);
void print_nums_rec(int nums_added, int *added, int current) {
    if (current < nums_added) {
        printf("%d ", added[current]);
        print_nums_rec(nums_added, added, current + 1);
    }
}

void print_nums(int nums_added, int *added) {
    if (nums_added == 0)
        return;
    printf("%d ", added[0]);
    print_nums_rec(nums_added, added, 1);
}

bool rec(int n, int last_num, int c_num, int c_sum, int n_added, int *added) {
    if (c_sum + c_num == n) {
        print_nums(n_added + 1, added);
        printf("%d \n", c_num);
        return true;
    }

    if (c_sum + c_num < n) {
        added[n_added + 1] = c_num;
        rec(n, c_num, c_num + 1, c_sum + c_num, n_added + 1, added);
        rec(n, last_num, c_num + 1, c_sum, n_added, added);
    }
    return false;
}

void printAllDistinctSums(int n) {
    int start_num = 1, *added = malloc(sizeof(int) * n);
    rec(n, 0, start_num, 0, -1, added);
}


int main() {
    // setbuf(stdout, NULL);
    int input = 16;
    scanf("%d", &input);
    printAllDistinctSums(input);
    return 0;
}
