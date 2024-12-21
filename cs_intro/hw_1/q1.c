#include <stdbool.h>
#include <stdio.h>

#define ABS(val) ((val) >= 0 ? (val) : -(val))

bool valid_input(int start_month, int start_year, int end_month, int end_year) {
  if (start_month > 12 || start_month < 1 || end_month > 12 || end_month < 1) {
    return false;
  }

  int start_stamp = start_year * 100 + start_month;
  int end_stamp = end_year * 100 + end_month;

  if (ABS(start_year) > ABS(start_stamp) || ABS(end_year) > ABS(end_stamp)) {
    return false;
  }

  if (start_stamp > end_stamp) {
    return false;
  }

  return true;
}

float get_age(int start_month, int start_year, int end_month, int end_year) {
  float ret = end_year - start_year;
  ret += (float)(end_month - start_month) / 12;

  return ret;
}

int main() {
  int start_month, start_year, end_month, end_year;
  scanf("%d %d %d %d", &start_month, &start_year, &end_month, &end_year);
  if (!valid_input(start_month, start_year, end_month, end_year)) {
    printf("Error!");
    return -1;
  }

  printf("You are %.2f years old",
         get_age(start_month, start_year, end_month, end_year));
}
