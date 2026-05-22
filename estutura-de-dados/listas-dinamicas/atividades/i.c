#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

void list_remove_head(list_t* l) {
    list_node_t *remover = l->head;
    if (l->size == 1) {
        l->tail = NULL;
    }    
    l->head = l->head->next;
    free(remover);
    l->size--;
}

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

void list_remove(list_t* l, size_t i) {
    if (i == 0 || l->size == 1) {
        list_remove_head(l);
    } else if (i == l->size - 1) {
        list_remove_tail(l);
    } else {
        list_node_t *aux = l->head;
        for (int j = 0; j < i - 1; j++) {
            aux = aux->next;
        }
        list_node_t *remover = aux->next;
        aux->next = remover->next;
        free(remover);
        l->size--;
    }
}