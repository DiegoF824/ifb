#include <stdio.h>
#include <stdlib.h>

int main() {
    /* entrada n */
    int n;
    scanf("%d", &n);
    /* lista nomes */
    char **nome = malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        nome[i] = malloc(sizeof(char) * 11);
    }
    /* liberar memoria */
    for (int i = 0; i < n; i ++) {
        free(nome[i]);
    }
    free(nome);
    return 0;
}