#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void min_max(int *ptr, int n, int *min, int *max) {
  *min = ptr[0];
  *max = ptr[0];
  for (int i = 1; i < n; i++) {
    if (ptr[i] < *min)
      *min = ptr[i];
    if (ptr[i] > *max)
      *max = ptr[i];
  }
}

int main() {
  int n, min, max;
  printf("Informe o valor n: ");
  scanf("%d", &n);

  int *ptr = malloc(sizeof(int) * n);

  if (ptr == NULL) {
    printf("Falha de alocação");
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));

  for (int i = 0; i < n; i++)
    ptr[i] = rand() % 1000;

  min_max(ptr, n, &min, &max);

  for (int i = 0; i < n; i++)
    printf("%d ", ptr[i]);
  printf("\n");

  printf("min = %d\nmax = %d\n", min, max);

  free(ptr);
  return 0;
}
