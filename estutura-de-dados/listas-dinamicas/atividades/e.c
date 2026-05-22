#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

void list_prepend(list_t* l,int data) {
    list_node_t *novo = malloc(sizeof(list_node_t));
    novo->data = data;
    novo->next = NULL;
    novo->next = l->head;
    l->head = novo;
    if (list_empty(l)) {
        l->tail = novo;
    }
    l->size++; 
};

void list_append(list_t* l,int data) {
    list_node_t *novo = malloc(sizeof(list_node_t));
    novo->data = data;
    novo->next = NULL;
    if (list_empty(l)) {
        l->head = novo;
    } else {
        l->tail->next = novo;
    }
    l->tail = novo;
    l->size++;
};

void list_insert(list_t* l, int data, size_t i) {
    if (list_empty(l) || i == 0) {
        list_prepend(l, data);
    } else if (i == l->size) {
        list_append(l, data);
    } else {
        list_node_t *novo = malloc(sizeof(list_node_t));
        novo->data = data;
        novo->next = NULL;
        list_node_t *aux = l->head;
        for (int j = 0; j < i - 1; j++) {
            aux = aux->next;
        }
        novo->next = aux->next;
        aux->next = novo;
        l->size++;
    }
};