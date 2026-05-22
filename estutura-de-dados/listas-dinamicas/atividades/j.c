#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

void list_reverse(list_t* l) {
    if (l == NULL || l->head == NULL) {
        return;
    }
    list_node_t *reverter = l->head, *proximo = NULL, *anterior = NULL;
    while (reverter != NULL) {
        proximo = reverter->next;
        reverter->next = anterior;
        anterior = reverter;
        reverter = proximo;
    }
    l->tail = l->head;
    l->head = anterior;
}