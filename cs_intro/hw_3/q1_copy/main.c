#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// int hw3_primes_binary_search(int arr[], int n, int target);
// void print_pow_rep(int target);
int power_of_3_in_rep(int num);


/* Your code here */

void print_pow_rep(int target) {
    int pow_t = power_of_3_in_rep(target);
    printf("in %d : 3^%d\n", target, pow_t);
}

// returns the power of 3 (k) in the wierd binary representation
int power_of_3_in_rep(int num) {
    int rem = 0;
    int power = 0;
    for (int i = 1; rem == 0; i++) {
        rem = num % ((int) pow(3, (double) i));
        power = i;
    }
    return power - 1;
}

int low_idx_current_3_pow(int arr[], int n, int target_pow_3) {
    int start = 0, end = n - 1, i = 0;
    int res = -1;

    while (start <= end) {
        i = (start + end) / 2;
        int current_pow_3 = power_of_3_in_rep(arr[i]);
        if (current_pow_3 > target_pow_3) {
            end = i - 1;
        } else if (current_pow_3 < target_pow_3) {
            start = i + 1;
        } else {
            res = i;
            end = i - 1;
        }
    }
    return res;
}

int high_idx_current_3_pow(int arr[], int n, int target_pow_3) {
    int start = 0, end = n - 1, i = 0;
    int res = -1;

    while (start <= end) {
        i = (start + end) / 2;
        int current_pow_3 = power_of_3_in_rep(arr[i]);
        if (current_pow_3 > target_pow_3) {
            end = i - 1;
        } else if (current_pow_3 < target_pow_3) {
            start = i + 1;
        } else {
            res = i;
            start = i + 1;
        }
    }
    return res;
}

int first_idx_in_orderd(int arr[], int start, int end, int target) {
    int i = 0, res = -1;

    while (start <= end) {
        i = (start + end) / 2;
        if (arr[i] > target) {
            end = i - 1;
        } else if (arr[i] < target) {
            start = i + 1;
        } else {
            res = i;
            end = i - 1;
        }
    }
    return res;
}

int hw3_primes_binary_search(int arr[], int n, int target) {
    int correct_pow_idx = power_of_3_in_rep(target);

    int k_start_idx = low_idx_current_3_pow(arr, n, correct_pow_idx);
    int k_end_idx = high_idx_current_3_pow(arr, n, correct_pow_idx);
    if (k_start_idx == -1) {
        return -1;
    }

    return first_idx_in_orderd(arr, k_start_idx, k_end_idx, target);
}

/* int main(void) { */
/*     int n = 8, arr[] = {2, 4, 3, 9, 9, 9, 9, 9}, target = 3; */
/*     hw3_primes_binary_search(arr, n, target); */
/*     printf("%d", hw3_primes_binary_search(arr, n, target)); */
/* } */

int main(void) {
    // read the array (length and items)
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int *arr = (int *) malloc(sizeof(int) * n);
    if (!arr) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return 1;
        }
    }
    int target;
    if (scanf("%d", &target) != 1) {
        free(arr);
        return 1;
    }

    printf("%d", hw3_primes_binary_search(arr, n, target));
}
