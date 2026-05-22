#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
//estrutura do vetor dinâmico de string
typedef struct {
    char **v;
    size_t capacity;
    size_t size;
} dynamic_string_array_t;

//função para criar o vetor de string
void dynamic_string_array_initialize(dynamic_string_array_t **arr, int x) {
    (*arr) = malloc(sizeof(dynamic_string_array_t));
    (*arr)->capacity = x;
    (*arr)->size = 0;
    (*arr)->v = (char **) malloc(sizeof(char *) * x);
    //alocar memória para cada string
    for (int i = 0; i < x; i++) {
        (*arr)->v[i] = (char *) malloc(sizeof(char) * 11); //10 caracteres por string + \0 
    }
}
*/
//bubblesort
/*
void swap(char **v, int i, int j) {
    char *t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}
void bubble_sort(char **v, int size) {
    int swapped = 1;
    for (int i = 0; i < size - 1 && swapped; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (strlen(v[j]) > strlen(v[j + 1])) {
                swap(v, j, j + 1);
                swapped = 1;
            }
        }
    }
}
*/
//merge sort
static void merge(char **v, char **v1, char **v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (strlen(v1[j]) <= strlen(v2[k])) {
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
void merge_sort(char **v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;
        char **v1 = malloc(sizeof(char *) * mid);
        char **v2 = malloc(sizeof(char *) * (size - mid));
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }
        merge_sort(v1, mid);
        merge_sort(v2, size - mid);
        merge(v, v1, v2, size);
        //liberar o espaço
        free(v1);
        free(v2);
    }
}
/*
//função para deleter o vetor
void dynamic_string_array_delete(dynamic_string_array_t **arr, int x) {
    for (int i = 0; i < x; i++) {
        free((*arr)->v[i]);
    }
    free((*arr)->v);
    free(*arr);
    *arr = NULL;
}
*/

int main() {
    //entrada de n linhas
    int n;
    scanf("%d", &n);
    getchar();

//criar e preenchendo o vetor string
    /*
    dynamic_string_array_t *arr;
    dynamic_string_array_initialize(&arr, n);
    */
    char **v = malloc(sizeof(char *) * n);
    //alocar memória para cada string
    for (int i = 0; i < n; i++) {
        v[i] = malloc(sizeof(char) * 12);
        fgets(v[i], 12, stdin);
    }

//ordenar o vetor
    //bubble_sort(v, n);
    merge_sort(v, n);

//imprimir o vetor
    /*
    for (int i = 0; i < n; i++) {
        printf("%s", arr->v[i]);
    }
    */
    for (int i = 0; i < n; i++)
        printf("%s", v[i]);

//liberar a memória
    /*
    dynamic_string_array_delete(&arr, n);
    */
    for (int i = 0; i < n; i++)
        free(v[i]);
    free(v);
    return 0;
}
