#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ARR_MAX_LENGTH 50

int sum_of_digits_squared(int num);

int sum_of_digits_squared(int num) {
    int sum = 0, devidor = 1;
    int current_befor_div = (num % (devidor * 10));
    int current = current_befor_div / devidor;

    while (current_befor_div <= num) {
        sum += current * current;
        devidor *= 10;

        if (current_befor_div == num)
            break;
        current_befor_div = (num % (devidor * 10));
        current = current_befor_div / devidor;
    }

    return sum;
}

int main(void) {
    // int seen[ARR_MAX_LENGTH] = {0};
    int input = 0;
    printf("please enter a number:\n");
    scanf("%d", &input);
    int current = input;

    for (int i = 0; i < ARR_MAX_LENGTH; i++) {
        current = sum_of_digits_squared(current);
        if (current == 1) {
            printf("the number %d is happy\n", input);
            return 0;
        }
        // seen[i] = current;
    }
    printf("the number %d is not happy", input);
    return 0;
}
