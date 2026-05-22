#ifndef DYNAMIC_ARRY_H
#define DYNAMIC_ARRY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *v;
  size_t capacity;
  size_t size;
} dynamic_array_t;

void dynamic_array_initialize(dynamic_array_t **arr);
size_t dynamic_array_size(dynamic_array_t *arr);
size_t dynamic_array_capacity(dynamic_array_t *arr);
void dynamic_array_double_capacity(dynamic_array_t *arr);
void dynamic_array_push_back(dynamic_array_t *arr, int x);
void dynamic_array_halve_capacity(dynamic_array_t *arr);
void dynamic_array_pop_back(dynamic_array_t *arr);
int dynamic_array_front(dynamic_array_t *arr);
int dynamic_array_back(dynamic_array_t *arr);
void dynamic_array_delete(dynamic_array_t **arr);

#endif
