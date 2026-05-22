#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

void list_remove_tail(list_t* l) {
    list_node_t *remover = l->tail;
    if (l->size == 1) {
        l->head = NULL;
        l->tail = NULL;
    } else {
        list_node_t *aux = l->head;
        while (aux->next != l->tail) {
            aux = aux->next;
        }
        aux->next = NULL;
        l->tail = aux;
    }
    free(remover);
    l->size--;
}