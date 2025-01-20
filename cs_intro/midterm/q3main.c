#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 100

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
	printf("%s", DONT_KNOW);
	exit(0);
}

void print_array(char arr[], int n);
void midterm_quiz_q3(char arr[], int n);

int main() {
    // uncomment next line if you don't know the answer
	// printIDontKnow();
    
    int n;

    if (scanf("%d", &n) != 1 || n > MAX_LEN) {
        return 1;
    }

    char arr[MAX_LEN] = {0};
    for(int i = 0; i < n; i++) {
        if (scanf(" %c", &arr[i]) != 1) { 
            return 1;
        }
    }

    midterm_quiz_q3(arr, n);

    printf("Array after changes: \n");
    print_array(arr, n);

    return 0;
}

bool char_is_num(char c) {
    return (c >= '0' && c <= '9');
}

void palindrome_with_point(char arr[], int arr_len, int point_index) {
    int left = 0, right = 0;
    for (int i = 1; i + point_index < arr_len; i++) {
        left = arr[point_index - i], right = arr[point_index + i];
        if (right == left && !char_is_num(right)) {
            //just place number
            arr[point_index - i] = 5;
            arr[point_index + i] = 5;
            break;
        } else if (right != left) {
            if (char_is_num(left))  arr[point_index + i] = left;
            else arr[point_index - i] = right;
            break;
        }
    }
}

void midterm_quiz_q3(char arr[], int n) {
    //your code here:
    // check if there is a point
    int mid_point = (n / 2);
    if (arr[mid_point] == '.') {
        palindrome_with_point(arr, n, mid_point);
        return;
    } else {
        arr[mid_point] = '.';
        return;
    }



}

void print_array(char arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
}