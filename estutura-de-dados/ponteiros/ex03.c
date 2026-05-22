#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;

  printf("Informe o valor n: ");
  scanf("%d", &n);

  float *ptr = malloc(sizeof(float) * n);

  if (ptr == NULL) {
    printf("Erro de alocação.");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < n; i++)
    ptr[i] = i;
  for (int i = 0; i < n; i++)
    printf("%.2f\n", ptr[i]);
  free(ptr);

  return 0;
}
