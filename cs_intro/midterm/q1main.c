#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
	printf("%s", DONT_KNOW);
	exit(0);
}

void print_value(int num);
void midterm_quiz_q1();

int main() {
	// uncomment next line if you don't know the answer
	// printIDontKnow();
	
    midterm_quiz_q1();
    return 0;
}

bool valid_input(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        c == '+' || c == '-' || c == '!') {
        return true;
    }
    return false;
}


void midterm_quiz_q1() {
    // Write your code here:
    int n1 = 0, n2 = 0, n3 = 0, sum = 0;
    char cur_char = '@';

    while (scanf("%c", &cur_char) != EOF) {
        // if (!valid_input(cur_char) && cur_char != '\n' && cur_char != ' ') {
        if (!valid_input(cur_char)) {
            print_value(-1);
            return;
        }
        sum -= n3;
        n3 = n2;
        n2 = n1;
        n1 = (int) cur_char;
        sum += n1;
        if (n3 != 0) print_value(sum);
    }

    print_value(sum);
}


void print_value(int num) {
    if(num == -1){
        printf("\nError!");
    } else {
        printf("\n%d\n", num);
    }
}
