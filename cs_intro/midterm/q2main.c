#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
	printf("%s", DONT_KNOW);
	exit(0);
}

void print_value(int num);
void midterm_quiz_q2(int n);

int main() {
    // uncomment next line if you don't know the answer
	// printIDontKnow();
	
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    midterm_quiz_q2(n);
    return 0;
}


void print_value(int num) {
    printf("%d ", num);
}

void midterm_quiz_q2(int n) {
    //your code here
    for (int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (int devidor = 2; devidor < (i / 2 )+ 1; devidor++) {
            if (i % devidor == 0) is_prime = false;
        }
        if (is_prime) print_value(i);
    }
}

