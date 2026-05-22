#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

void list_remove_head(list_t* l) {
    list_node_t *remover;
    remover = l->head;
    if (l->size == 1) {
        l->head = NULL;
        l->tail = NULL;
    } else {
        l->head = l->head->next;
    }
    free(remover);
    l->size--;
}