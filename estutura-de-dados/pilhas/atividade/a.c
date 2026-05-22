#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ganho {
    char **ganhos;
    size_t capacity;
    size_t size;
} Ganho;

void iniciar_ganho(Ganho **g) {
    *g = malloc(sizeof(Ganho));
    (*g)->capacity = 4;
    (*g)->ganhos = malloc(sizeof(char*) * (*g)->capacity);
    (*g)->size = 0;
}

static void expandir(Ganho *g) {
    g->capacity *= 2;
    g->ganhos = realloc(g->ganhos, sizeof(char*) * g->capacity);
}

void adicionar(Ganho *g, char *valor) {
    if (g->size == g->capacity) {
        expandir(g);
    }
    g->ganhos[g->size++] = valor;
}

void deletar(Ganho **g) {
    for (size_t i = 0; i < (*g)->size; i++) {
        free((*g)->ganhos[i]);
    }
    free((*g)->ganhos);
    free(*g);
    *g = NULL;
}

int main() {
    int N, D;
    Ganho *g;
    iniciar_ganho(&g);

    while (1) {
        scanf("%d %d", &N, &D);
        if (N == 0 && D == 0) break;

        char numero[100001];
        scanf("%s", numero);

        char *pilha = malloc(sizeof(char) * N);
        int topo = 0;

        int remov = D;

        for (int i = 0; i < N; i++) {
            char atual = numero[i];

            while (topo > 0 && remov > 0 && pilha[topo - 1] < atual) {
                topo--;
                remov--;
            }

            pilha[topo++] = atual;
        }

        // remove do final se ainda sobrou
        topo -= remov;

        // cria string resultado
        char *resultado = malloc(sizeof(char) * (topo + 1));
        for (int i = 0; i < topo; i++) {
            resultado[i] = pilha[i];
        }
        resultado[topo] = '\0';

        adicionar(g, resultado);

        free(pilha);
    }

    // imprime tudo no final
    for (size_t i = 0; i < g->size; i++) {
        printf("%s\n", g->ganhos[i]);
    }

    deletar(&g);
    return 0;
}