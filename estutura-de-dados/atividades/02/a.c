#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int indice;
} numero;


void merge(numero *v, numero *v1, numero *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j].valor <= v2[k].valor) {
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

void merge_sort(numero *v, size_t size) {
    if (size > 1) {
        size_t mid = size / 2;
        numero *v1 = malloc(sizeof(numero) * mid);
        numero *v2 = malloc(sizeof(numero) * (size - mid));
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

int busca_binaria(numero *v, int left, int right, int x) {
    int resultado = -1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (v[mid].valor == x) {
            resultado = mid;
            right = mid - 1;
        } else if (v[mid].valor > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return resultado;
}

int busca_distintos(numero *v, size_t size, int c, int *d1, int *d2) {
    for (int i = 0; i < size; i++) {
        /*
        for (j = 1; j < size; j++) {
            if (v[i] + v[j] > c) {
                break;
            } else if (v[i] + v[j] == c) {
                *d1 = i + 1;
                *d2 = j + 1;
                return 0;
            }
        }
        */
        int alvo = c - v[i].valor;
        int j = busca_binaria(v, i + 1, size - 1, alvo);
        if (j != -1) {
            *d1 = v[i].indice;
            *d2 = v[j].indice;
            return 1;
        }
    }
    return 0;
}

int main() {
    /* entrada n e C */
    int n, C;
    scanf("%d %d", &n, &C);
    /* entrada V */
    numero *V = malloc(sizeof(numero) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &V[i].valor);
        V[i].indice = i + 1;
    }
    /* ordenar V */
    merge_sort(V, n);
    /* procurar distintos */
    int d1 = 0;
    int d2 = 0;
    if (busca_distintos(V, n, C, &d1, &d2)) {
        printf("%d %d\n", d1, d2);
    } else {
        printf("-1");
    }
    /* liberar memoria */
    free(V);
    return 0;
}
