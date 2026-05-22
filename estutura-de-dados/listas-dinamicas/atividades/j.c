#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

void list_reverse(list_t* l) {
    if (l->size == 0) {
        return 1;
    }
    list_node_t *aux = l->head;
    l->head = l->tail;
    l->tail = aux;
    if (l->size > 1) {
        
    }
}