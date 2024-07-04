/*
  author: MrS4g0
  created: 25.06.2024 23:31:46
  kata link: https://www.codewars.com/kata/52597aa56021e91c93000cb0/c
*/

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void move_zeros(size_t len, int arr[len]) {
  size_t end_not_zero_idx = 0;

  for (size_t i = 0; i < len; ++i) {
    if (arr[i] != 0) {
      arr[end_not_zero_idx++] = arr[i];
    }
  }

  for (size_t i = end_not_zero_idx; i < len; ++i) {
    arr[i] = 0;
  }
}

int main() {
  int test_arr[] = {1, 2, 0, 1, 0, 1, 0, 3, 0, 1};
  size_t len = sizeof(test_arr) / sizeof(test_arr[0]);
  move_zeros(len, test_arr);
  for (size_t i = 0; i < len; ++i) {
    printf("%d ", test_arr[i]);
  }
  return 0;
}
