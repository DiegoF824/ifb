#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

void list_prepend(list_t* l,int data) {
    list_node_t *novo = malloc(sizeof(list_node_t));
    novo->data = data;
    novo->next = NULL;
    if (list_empty(l)) {
        l->head = novo;
        l->tail = novo;
    } else {
        novo->next = l->head;
        l->head = novo;
    }
    l->size++;
};