#include <stdio.h>
#include <stdlib.h>

#define max 2000000

typedef struct pilha_numeros {
    int *numeros;
    size_t size;
} Pilha_n;

void iniciar_pilha_numeros(Pilha_n **pn) {
    *pn = malloc(sizeof(Pilha_n));
    (*pn)->numeros = malloc(sizeof(int) * max);
    (*pn)->size = 0;
}

void empilhar_numeros(Pilha_n *pn, int num) {
    pn->numeros[pn->size++] = num;
}

typedef struct pilha_operadores {
    char *operadores;
    size_t size;
} Pilha_o;

void iniciar_pilha_operadores(Pilha_o **po) {
    *po = malloc(sizeof(Pilha_o));
    (*po)->operadores = malloc(sizeof(int) * max);
    (*po)->size = 0;
}

void empilhar_operadores(Pilha_o *po, char op) {
    po->operadores[po->size++] = op;
}

int desempilhar_numeros(Pilha_o *po) {
    if (po->size != 0) {
        return po->operadores[po->size--];
    }
}

void liberar_pilha_o(Pilha_o **po) {
    free((*po)->operadores);
    free(*po);
    *po = NULL;
}

int main() {
    // ler a expressão matemática
    char entrada[max];
    scanf("%[^\n]", entrada);
    // criar as pilhas
    Pilha_n *pn;
    iniciar_pilha_numeros(&pn);
    Pilha_o *po;
    iniciar_pilha_operadores(&po);
    // converter para a notação polonesa
    int i = 0;
    while (entrada[i] != '\0') {
        if (entrada[i] == '(' || entrada[i] == ' ') {
            i++;
        } else if (entrada[i] == ')') {

        }

        i++;
    }
    liberar_pilha_n(&pn);
    liberar_pilha_o(&po);
    return 0;
}