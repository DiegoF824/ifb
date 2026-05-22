#include "bubblesort.h"
#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const int N = 10;

int main(void) {
  srand(time(NULL));
  dynamic_array_t *arr;
  dynamic_array_initialize(&arr);
  for (int i = 0; i < N; i++) {
    int value = rand() % 10;
    dynamic_array_push_back(arr, value);
    printf("v[%d] = %d\n", i, arr->v[i]);
  }

  bubble_sort(arr->v, arr->size);

  for (int i = 0; i < N; i++) {
    printf("v[%d] = %d\n", i, arr->v[i]);
  }

  dynamic_array_delete(&arr);
  return 0;
}
