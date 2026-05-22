#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct pilha {
    int* data;
    size_t capacity;
    size_t size;
} Pilha;

void iniciar_pilha(Pilha **p) {
    *p = malloc(sizeof(Pilha));
    (*p)->capacity = 4;
    (*p)->data = malloc(sizeof(int) * (*p)->capacity);
    (*p)->size = 0;
}

size_t size_pilha(Pilha *p) {
    return p->size;
}

int pilha_vazia(Pilha *p) {
    return size_pilha(p) == 0;
}

static void expandir_pilha(Pilha *p) {
    p->capacity *= 2;
    p->data = realloc(p->data, sizeof(int) * p->capacity);
}

void push(Pilha *p, int data) {
    if (p->size == p->capacity) {
        expandir_pilha(p);
    }
    p->data[p->size++] = data;
}

static void encolher_pilha(Pilha *p) {
    p->capacity /= 2;
    p->data = realloc(p->data, sizeof(int) * p->capacity);
}

void pop(Pilha *p) {
    if (p->size == p->capacity / 4 && p->capacity > 4) {
        encolher_pilha(p);
    }
    p->size--;
}

int pegar_topo(Pilha *p) {
    assert(!pilha_vazia(p));
    return p->data[p->size - 1];
}

void deletar_pilha(Pilha **p) {
    free((*p)->data);
    free(*p);
    *p = NULL;
}

int main() {
    Pilha *p;
    iniciar_pilha(&p);
    for (int i = 0; i < 1000000; i++) {
        push(p, i);
    }
    while (!pilha_vazia(p)) {
        printf("\n%d\n", pegar_topo(p));
        pop(p);
    }
    deletar_pilha(&p);
    return 0;
}