#include "dynamic_array.h"
#include <stdlib.h>

void dynamic_array_initialize(dynamic_array_t **arr) {
  (*arr) = malloc(sizeof(dynamic_array_t));
  (*arr)->capacity = 4;
  (*arr)->size = 0;
  (*arr)->v = malloc(sizeof(int) * 4);
}

size_t dynamic_array_size(dynamic_array_t *arr) { return arr->size; }

size_t dynamic_array_capacity(dynamic_array_t *arr) { return arr->capacity; }

void dynamic_array_double_capacity(dynamic_array_t *arr) {
  arr->capacity *= 2;
  arr->v = realloc(arr->v, sizeof(int) * arr->capacity);
}

void dynamic_array_push_back(dynamic_array_t *arr, int x) {
  if (arr->size == arr->capacity) {
    dynamic_array_double_capacity(arr);
  }
  arr->v[arr->size] = x;
  arr->size++;
}

void dynamic_array_halve_capacity(dynamic_array_t *arr) {
  arr->capacity /= 2;
  arr->v = realloc(arr->v, sizeof(int) * arr->capacity);
}

void dynamic_array_pop_back(dynamic_array_t *arr) {
  if (arr->size == arr->capacity / 4 && arr->capacity > 4) {
    dynamic_array_halve_capacity(arr);
  }
  arr->size--;
}

int dynamic_array_front(dynamic_array_t *arr) { return arr->v[0]; }

int dynamic_array_back(dynamic_array_t *arr) { return arr->v[arr->size - 1]; }

void dynamic_array_delete(dynamic_array_t **arr) {
  free((*arr)->v);
  free(*arr);
  *arr = NULL;
}
