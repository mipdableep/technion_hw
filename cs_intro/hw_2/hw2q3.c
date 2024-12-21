#include <stdio.h>
#include <stdlib.h>

int sum_indexes(int arr[], int start_index, int len) {
    int sum = 0;
    for (int i = start_index; i < start_index+len; i++) {
        sum += arr[i];
    }
    return sum;
}

void sumAndJump(int arr[], int len) {
    int index = 0, current_val = 0, sum = 0;
    for  (int i = 0; i < len; i++) {
        current_val = arr[index];

        if(current_val == 0) {
            printf("%d\n", i);
            exit(0);
        }

        if (index + current_val > len) {
            printf("-1\n");
            exit(-1);
        }

        sum = sum_indexes(arr, index, current_val);

        if (sum >= len) {
            printf("-1\n");
            exit(-1);
        }
        index = sum;
    }
    printf("-2\n");
}


int main() {
    int len_array = 0;
    // First enter the size of the array
    scanf("%d", &len_array);
    // allocating the array - will be explained later in the course
    int* arr = malloc(sizeof(int) * len_array);
    if(arr) {
        // Enter the numbers that the array will hold
        for (int start_index = 0; start_index < len_array; start_index++) {
            scanf("%d", &(arr[start_index]));
        }
        sumAndJump(arr, len_array);
    }
    // Freeing the array - will be explained later in the course
    free(arr);
    return 0;
}