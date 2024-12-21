
#include <stdio.h>

int sum_of_range(int start, int end) {
    int sum = 0;
    for (; start <= end; start++) {
        sum += start;
    }
    return sum;
}

int sum_of_sq(int start, int end) {
    int sum = 0;
    for (; start <= end; start++) {
        sum += start * start;
    }
    return sum;
}
int main(){
    int start = 0, end = 0;
    scanf("%d, %d", &start, &end);
    int sum_of_r = sum_of_range(start, end);
    int sum_of_s = sum_of_sq(start, end);
    printf("The difference between the sum of the squares: %d",
        (sum_of_r*sum_of_r) - sum_of_s);



  }

