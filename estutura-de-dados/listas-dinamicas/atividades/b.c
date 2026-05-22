#include <stdio.h>
#include "grader.h"

void list_concat(list_t* l1,list_t* l2) {
    if (list_empty(l1)) {
        l1->head = l2->head;
        l1->tail = l2->tail;
        l1->size = list_size(l2);
    } else {
        l1->tail->next = l2->head;
        l1->tail = l2->tail;
        l1->size += list_size(l2);
    }
};