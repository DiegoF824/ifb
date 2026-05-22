#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *v1, int *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] <= v2[k]) {
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

void merge_sort(int *v, size_t size) {
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
        merge_sort(v1, mid);
        merge_sort(v2, size - mid);
        merge(v, v1, v2, size);
        free(v1);
        free(v2);
    }
}

int busca_esq(int *v, size_t size, int key) {
    int resultado = -1;
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (key == v[mid]) {
            resultado = mid;
            r = mid - 1;
        } else if (key < v[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return resultado;
}

int busca_dir(int *v, size_t size, int key) {
    int resultado = -1;
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (key == v[mid]) {
            resultado = mid;
            l = mid + 1;
        } else if (key < v[mid]) {
            r = mid -1;
        } else {
            l = mid + 1;
        }
    }
    return resultado;
}

int main() {
    /* entrada n e q */
    int n, q;
    scanf("%d %d", &n, &q);
    /* lista de n inteiros */
    int *v = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    /* lista de q inteiros */
    int *x = malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &x[i]);
    }
    /* ordenar lista n */
    merge_sort(v, n);
    /* buscar extremos */
    for (int i = 0; i < q; i++) {
        int l = busca_esq(v, n, x[i]);
        int r = busca_dir(v, n, x[i]);
        if (l == -1 || r == -1) {
            printf("-1\n");
        } else {
            printf("%d %d\n", l + 1, r + 1);
        }
    }
    /* liberar memória */
    free(v);
    free(x);
    return 0;
}