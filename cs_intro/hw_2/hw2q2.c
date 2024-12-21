#include <stdio.h>
#define MAX_LEN 50
#define MAX_REMOVE 2147483648

// "Enter a positive integer: \n"
//"Binary representation of %d: "
//"The largest sum is: %d\n"

int get_bin_rep(unsigned int num, int bin_rep[]) {

    int current_index = 0, sum_of_removes = 0;
    unsigned int current_remove = 1 << 31;

    while (current_remove > num)
        current_remove = current_remove >> 1;

    while (current_remove != 0) {
        if (current_remove <= num - sum_of_removes) {
            bin_rep[current_index] = 1;
            sum_of_removes += current_remove;
        }
        current_index++;
        current_remove /= 2;
    }

    return current_index;
}

void print_array(int *array, int array_len, int num) {
    printf("Binary representation of %d: ", num);
    for (int i = 0; i < array_len; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

void print_largest_seq_of_1(int array[], int array_len) {
    int largest = 0, current = 0;
    for (int i = 0; i < array_len; i++) {
        if (array[i] == 1) {
            current++;
        } else {
            if (current > largest)
                largest = current;
            current = 0;
        }
    }
    if (current > largest)
        largest = current;
    printf("The largest sum is: %d\n", largest);
}

int main() {
    int bin_rep[MAX_LEN] = {0};
    int input = 0;
    printf("Enter a positive integer: \n");
    scanf("%d", &input);
    int rep_len = get_bin_rep(input, bin_rep);
    print_array(bin_rep, rep_len, input);
    print_largest_seq_of_1(bin_rep, rep_len);

    return 0;
}
