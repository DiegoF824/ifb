#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *v1, int *v2, size_t size, int m) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] % m <= v2[k] % m) {
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

void merge_par_imp(int *v, int *v1, int *v2, size_t size, int m) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] % m == v2[k] % m) {
            if (v1[j] % 2 == 0 && v2[k] % 2 != 0) {
                v[i] = v2[k++];
            } else if (v1[j] % 2 != 0 && v2[k] % 2 == 0) {
                v[i] = v1[j++];
            } else if (v1[j] % 2 == 0 && v2[k] % 2 == 0) {
                if (v1[j] <= v2[k]) {
                    v[i] = v1[j++];
                } else {
                    v[i] = v2[k++];
                }
            } else {
                if (v1[j] >= v2[k]) {
                    v[i] = v1[j++];
                } else {
                    v[i] = v2[k++];
                }
            }
        } else if (v1[j] % m < v2[k] % m) {
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

void merge_pares(int *v, int *v1, int *v2, size_t size, int m) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] % m == v2[k] % m) {
            if (v1[j] % 2 == 0 && v2[k] % 2 == 0) {
                if (v1[j] <= v2[k]) {
                    v[i] = v1[j++];
                } else {
                    v[i] = v2[k++];
                }
            } else if (v1[j] % 2 != 0 && v2[k] % 2 == 0) {
                v[i] = v1[j++];
            }
        } else if (v1[j] % m < v2[k] % m) {
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

void merge_sort(int *v, size_t size, int m, int x) {
    if (size > 1) {
        size_t mid = size / 2;
        int *v1 = malloc(sizeof(int) * mid);
        int *v2 = malloc(sizeof(int) * (size - mid));
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }
        merge_sort(v1, mid, m, x);
        merge_sort(v2, size - mid, m, x);
        if (x == 0) {
            merge(v, v1, v2, size, m);
        } else if (x == 1) {
            merge_par_imp(v, v1, v2, size, m);
        }
        free(v1);
        free(v2);
    }
}

int main() {
    /* entradas n e m */
    int n, m; 
    scanf("%d %d", &n, &m);
    /* lista V */
    int *V = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &V[i]);
    }
    /* ordenar */
    merge_sort(V, n, m, 0);
    merge_sort(V, n, m, 1);
    /* imprimir */
    for (int i = 0; i < n; i++) {
        printf("%d\n", V[i]);
    }
    /*liberar memória */
    free(V);
    return 0;
}