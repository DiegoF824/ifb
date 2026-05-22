#include <stdio.h>
#include <stdlib.h>

typedef struct processo {
    char name[40];
    int pid;
    int time;
    int totalTime;
} Processo;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    Processo *p = malloc(sizeof(Processo) * n);
    for (int i = 0; i < n; i++) {
        scanf("%[^\n]", *p[i]->nome)
    }
    return 0;
}