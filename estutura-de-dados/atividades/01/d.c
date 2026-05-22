#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[31];
    int parciais[3];
    int t_total;
} pilotos;

void ler_pilotos(pilotos *v, size_t size) {
    for (int i = 0; i < size; i++) {
        scanf("%31[^\n]", v[i].nome);
        getchar();
        int ss1, mm1, ss2, mm2, ss3, mm3;
        scanf("%d.%d %d.%d %d.%d", &ss1, &mm1, &ss2, &mm2, &ss3, &mm3);
        getchar();
        v[i].parciais[0] = ss1 * 1000 + mm1;
        v[i].parciais[1] = ss2 * 1000 + mm2;
        v[i].parciais[2] = ss3 * 1000 + mm3;
        v[i].t_total = v[i].parciais[0] + v[i].parciais[1] + v[i].parciais[2];
    }
}

void imprimi_pilotos(pilotos *v, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d. ", i + 1);
        printf("%s - ", v[i].nome);
        int m, ss, mm;
        m = v[i].t_total / 60000;
        ss = (v[i].t_total % 60000) / 1000;
        mm = v[i].t_total % 1000;
        printf("%d:%02d.%03d\n", m, ss, mm); 
    }
}

void swap(pilotos *v, int i, int j) {
    pilotos t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void bubble_sort(pilotos *v, size_t size) {
    int swapped = 1;
    for (int i = 0; i < size - 1 && swapped; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (v[j].t_total > v[j + 1].t_total) {
                swap(v, j, j + 1);
                swapped = 1;
            }
        }
    }
}

int main() {
    /* entrada N */
    int N;
    scanf("%d", &N);
    getchar();
    /* informações do pilioto */
    pilotos *arr;
    arr = malloc(sizeof(pilotos) * N);
    ler_pilotos(arr, N);
    /* ordenar pilotos */
    bubble_sort(arr, N);
    /* imprimir pilotos na ordem descrescente do tempo */
    imprimi_pilotos(arr, N);
    free(arr);
    return 0;
}