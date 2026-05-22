#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *v1, int *v2, size_t size) {
  size_t size_v1 = size / 2;
  size_t size_v2 = size - size_v1;
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  for (i = 0; j < size_v1 && k < size_v2; i++) {
    if (v1[j] >= v2[k]) {
      v[i] = v1[j++];
    } else {
      v[i] = v2[k++];
    }
  }
  while (j < size_v1) {
    v[i++] = v1[j++];
  }
  while (k < size_v2) {
    v[i++] = v2[k++];
  }
}

void merge_sort(int *v, size_t size) {
  if (size > 1) {
    size_t mid = size / 2;
    int *v1 = malloc(sizeof(int) * mid);
    int *v2 = malloc(sizeof(int) * (size - mid));
    int i;
    for (i = 0; i < mid; i++) {
      v1[i] = v[i];
    }
    for (i = mid; i < size; i++) {
      v2[i - mid] = v[i];
    }
    merge_sort(v1, mid);
    merge_sort(v2, size - mid);
    merge(v, v1, v2, size);
    free(v1);
    free(v2);
  }
}

typedef struct frequencia {
  int num;
  int f;
} frequencia;

void merge_f(frequencia *x, frequencia *x1, frequencia *x2, size_t size) {
  size_t size_x1 = size / 2;
  size_t size_x2 = size - size_x1;
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  for (i = 0; j < size_x1 && k < size_x2; i++) {
    if (x1[j].f >= x2[k].f) {
      x[i] = x1[j++];
    } else {
      x[i] = x2[k++];
    }
  }
  while (j < size_x1) {
    x[i++] = x1[j++];
  }
  while (k < size_x2) {
    x[i++] = x2[k++];
  }
}

void merge_sort_f(frequencia *x, size_t size) {
  if (size > 1) {
    size_t mid = size / 2;
    frequencia *x1 = malloc(sizeof(frequencia) * mid);
    frequencia *x2 = malloc(sizeof(frequencia) * (size - mid));
    int i;
    for (i = 0; i < mid; i++) {
      x1[i] = x[i];
    }
    for (i = mid; i < size; i++) {
      x2[i - mid] = x[i];
    }
    merge_sort_f(x1, mid);
    merge_sort_f(x2, size - mid);
    merge_f(x, x1, x2, size);
    free(x1);
    free(x2);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int *v = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  merge_sort(v, n);
  frequencia *x;
  int tamanho = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] != v[i + 1]) {
      tamanho++;
    }
  }
  x = malloc(sizeof(frequencia) * tamanho);
  int cont = 1;
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == v[i + 1]) {
      cont++;
    } else {
      x[index].num = v[i];
      x[index++].f = cont;
      cont = 1;
    }
  }
  merge_sort_f(x, tamanho);
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < x[i].f; j++) {
      printf("%d ", x[i].num);
    }
  }
  printf("\n");
  free(v);
  free(x);
  return 0;
}
