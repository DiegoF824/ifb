#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[31];
    int p;
    int *c;
    size_t capacity_c;
    size_t size_c;
    int h;
} autores;

void inicia_c(autores *arr) {
    arr->capacity_c = arr->p;
    arr->size_c = 0;
    arr->c = malloc(sizeof(int) * arr->p);
}

void escreve_autor(autores *arr, int x) {
    for (int i = 0; i < x; i++) {
        scanf("%31s %d", arr[i].nome, &arr[i].p);
        inicia_c(&arr[i]);
        for (int j = 0; j < arr[i].p; j++) {
            scanf("%d", &arr[i].c[j]);
            arr[i].size_c++;
        }
    }
}

void deleta_autores(autores *arr, int x) {
    for (int i = 0; i < x; i++)
        free(arr[i].c);
    free(arr);
}

void merge_autores_nome(autores *v, autores *v1, autores *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (strcmp(v1[j].nome, v2[k].nome) >= 0) {
            v[i] = v1[j++];
        } else {
            v[i] = v2[k++];
        }
    }
    while (j < size_v1) {
        v[i++] = v1[j++];
    }
    while (k < size_v2) {
        v[i++] = v2[k++];
    }
}

void merge_sort_autores_por_nome(autores *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;
        autores *v1 = malloc(sizeof(autores) * mid);
        autores *v2 = malloc(sizeof(autores) * (size - mid));
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }
        merge_sort_autores_por_nome(v1, mid);
        merge_sort_autores_por_nome(v2, size - mid);
        merge_autores_nome(v, v1, v2, size);
        free(v1);
        free(v2);
    }
}

void merge_autores (autores *v, autores *v1, autores *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j].h <= v2[k].h) {
            v[i] = v1[j++];
        } else {
            v[i] = v2[k++];
        }
    }
    while (j < size_v1) {
        v[i++] = v1[j++];
    }
    while (k < size_v2) {
        v[i++] = v2[k++];
    }
}

void merge_sort_autores(autores *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;
        autores *v1 = malloc(sizeof(autores) * mid);
        autores *v2 = malloc(sizeof(autores) * (size - mid));
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }
        merge_sort_autores(v1, mid);
        merge_sort_autores(v2, size - mid);
        merge_autores(v, v1, v2, size);
        free(v1);
        free(v2);
    }
}

void merge_int (int *v, int *v1, int *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] >= v2[k]) {
            v[i] = v1[j++];
        } else {
            v[i] = v2[k++];
        }
    }
    while (j < size_v1) {
        v[i++] = v1[j++];
    }
    while (k < size_v2) {
        v[i++] = v2[k++];
    }
}

void merge_sort_int(int *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;
        int *v1 = malloc(sizeof(int) * mid);
        int *v2 = malloc(sizeof(int) * (size - mid));
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }
        merge_sort_int(v1, mid);
        merge_sort_int(v2, size - mid);
        merge_int(v, v1, v2, size);
        free(v1);
        free(v2);
    }
}

void indice_h(autores *arr, int x) {
    for (int i = 0; i < x; i++) {
        arr[i].h = 0;
        merge_sort_int(arr[i].c, arr[i]. p);
        for (int j = 0; j < arr[i].p; j++) {
            if (arr[i].c[j] >= j + 1) {
                arr[i].h++;
            } else {
                break;
            }
        }
    }
}

int main() {
    /* entrada N */
    int N;
    scanf("%d", &N);
    getchar();
    /* informações autor */
    autores *arr;
    arr = malloc(sizeof(autores) * N);
    escreve_autor(arr, N);
    /* aumenta h */
    indice_h(arr, N);
    /* ordenar autores por nome */
    merge_sort_autores_por_nome(arr, N);
    /* ordenar autores pelo indice h */
    merge_sort_autores(arr, N);
    /* imprimir autores + indice h*/
    for (int i = N  - 1; i >= 0; i--) {
        printf("%s %d\n", arr[i].nome, arr[i].h);
    }
    /* liberar memória */
    deleta_autores(arr, N);
    return 0;
}