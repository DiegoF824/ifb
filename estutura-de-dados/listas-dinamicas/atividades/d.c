#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

void list_append(list_t* l,int data) {
    list_node_t *novo = malloc(sizeof(list_node_t));
    novo->data = data;
    novo->next = NULL;
    if (list_empty(l)) {
        l->head = novo;
        l->tail = novo;
    } else {
        l->tail->next = novo;
        l->tail = novo;
    }
    l->size++;
};