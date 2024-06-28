/*
  author: MrS4g0
  created: 25.06.2024 22:34:13
*/

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

size_t result_size(const char* program) {
  const char* p = program;
  size_t size = 0;
  while (*p) {
    if (*p == 'o') {
      ++size;
    }
    ++p;
  }
  return size;
}

int* parse(const char* program) {
  const char* p = program;
  int number = 0;

  size_t size = result_size(program);
  if (size <= 0) {
    return NULL;
  }

  int* result = (int*)malloc(size * sizeof(int));
  if (result == NULL) {
    return NULL;
  }

  size_t current_idx = 0;
  while (*p) {
    switch (*p) {
      case 'i':
        ++number;
        break;
      case 'd':
        --number;
        break;
      case 's':
        number *= number;
        break;
      case 'o':
        result[current_idx++] = number;
        break;
      default:
        break;
    }
    ++p;
  }

  return result;
}

int main() {
  char str[1024] = {'\0'};
  fgets(str, 1024, stdin);
  int* result = parse(str);
  size_t size = result_size(str);
  for (int i = 0; i < size; ++i) {
    printf("%d ", result[i]);
  }
  return 0;
}
