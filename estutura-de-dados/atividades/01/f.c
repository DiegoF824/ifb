#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *v1, int *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i =  0; j < size_v1 && k < size_v2; i++) {
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

static void heapify(int *v, size_t i, size_t size) {
    int left;
    int right;
    int largest;
    while (i < size) {
        left = (i * 2) + 1;
        right = (i * 2) + 2;
        largest = i;
        if (left < size && v[left] > v[largest]) {
            largest = left;
        }
        if (right < size && v[right] > v[largest]) {
            largest = right;
        }
        if (i == largest) {
            break;
        }
        int swp = v[i];
        v[i] = v[largest];
        v[largest] = swp;
        i = largest;
    }
}

static void make_heap(int *v, size_t size) {
    int i;
    for (i = size / 2; i >= 0; i--) {
        heapify(v, i, size);
    }
}

void heap_sort(int *v, size_t size) {
    make_heap(v, size);
    for (int i = size - 1; i > 0; i--) {
        int swp = v[i];
        v[i] = v[0];
        v[0] = swp;
        heapify(v, 0, i);
    }
}

int equilibrio(int *v, size_t size) {
    for (int i = 0; i < size; i++) {
        if (v[i - 1] == 0) {
            if (v[i] != 0)
                i++;
        } else if (v[i] % v[i - 1] != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    /* ler N */
    int N;
    scanf("%d", &N);
    /* criar a lista com N inteiros */
    int *x = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
    }
    /* ordenar inteiros */
    merge_sort(x, N);
    /* checar equilibrio */
    if (equilibrio(x, N)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }
    /* liberar memória */
    free(x);
    return 0;
}