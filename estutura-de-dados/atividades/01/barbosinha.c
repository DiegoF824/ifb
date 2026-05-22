#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *v1, int *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; i < size_v1 && k < size_v2; i++) {
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
        merge_sort(v1, mid);
        merge_sort(v2, size - mid);
        merge(v, v1, v2, size);
        free(v1);
        free(v2);
    }
}

int main() {
    int N;
    scanf("%d", &N); //entrada N
    int *chegada = malloc(sizeof(int) * N);
    int *saida = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        int h1, m1, s1, h2, m2, s2;
        scanf("%2d:%2d:%2d %2d:%2d:%2d", &h1, &m1, &s1, &h2, &m2, &s2);
        chegada[i] = h1 * 10000 + m1 * 100 + s1;
        saida[i] = h2 * 10000 + m2 * 100 + s2;
        if (chegada[i] > saida[i]) {
            free(chegada);
            free(saida);
            return 0;
        }
    }
    merge_sort(chegada, N);
    merge_sort(saida, N);
    int cadeira_atual = 0;
    int cadeiras_max = 0;
    int i = 0, j = 0;
    while (i < N && j < N) {
        if (chegada[i] < saida[j]) {
            cadeira_atual++;
            if (cadeira_atual > cadeiras_max) {
                cadeiras_max = cadeira_atual;
            }
            i++;
        } else {
            cadeira_atual--;
            j++;
        }
    }
    printf("%d\n", cadeiras_max);
    free(chegada);
    free(saida);
    return 0;
}
