#include "bubblesort.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int *v, int i, int j) {
  int t = v[i];
  v[i] = v[j];
  v[j] = t;
}

void bubble_sort(int *v, size_t size) {
  int swapped = 1;
  for (int i = 0; i < size - 1 && swapped; i++) {
    swapped = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v, j, j + 1);
        swapped = 1;
      }
    }
  }
}
