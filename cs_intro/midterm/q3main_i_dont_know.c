#include <stdio.h>
#include <stdlib.h> 

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
	 printIDontKnow();
    
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

void midterm_quiz_q3(char arr[], int n) {
    //your code here:
    return;
}

void print_array(char arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
}