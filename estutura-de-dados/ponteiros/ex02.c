#include <stdio.h>

void troca(int *i, int *j) {
  int tmp = *i;
  *i = *j;
  *j = tmp;
}

int main(int argc, char *argv[]) {
  int a, b;
  a = 2;
  b = 3;
  printf("a = %d\nb = %d\n", a, b);
  troca(&a, &b);
  printf("a = %d\nb = %d\n", a, b);
  return 0;
}
