#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long long comps;
} Metrics;

static void merge(int v[], int tmp[], int l, int m, int r, Metrics *metrics) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        metrics->comps++;
        if (v[i] <= v[j]) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }

    while (i <= m) tmp[k++] = v[i++];
    while (j <= r) tmp[k++] = v[j++];

    for (int t = l; t <= r; t++) {
        v[t] = tmp[t];
    }
}

static void merge_sort_rec(int v[], int tmp[], int l, int r, Metrics *metrics) {
    if (l >= r) return;

    int m = l + (r - l) / 2;
    merge_sort_rec(v, tmp, l, m, metrics);
    merge_sort_rec(v, tmp, m + 1, r, metrics);

    // Se as duas partes ja estao na ordem correta, nao precisamos mesclar.
    if (v[m] <= v[m + 1]) return;

    merge(v, tmp, l, m, r, metrics);
}

void merge_sort(int v[], int n, Metrics *metrics) {
    metrics->comps = 0;
    if (n <= 1) return;

    int *tmp = malloc((size_t)n * sizeof(int));
    if (!tmp) {
        fprintf(stderr, "Erro ao alocar vetor auxiliar.\n");
        return;
    }

    merge_sort_rec(v, tmp, 0, n - 1, metrics);
    free(tmp);
}

void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void fill_random(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = rand();
}

void fill_reverse(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = n - i;
}

void fill_nearly_sorted(int v[], int n, int k) {
    for (int i = 0; i < n; i++) v[i] = i;
    for (int i = 0; i < k && n > 1; i++) {
        int a = rand() % n;
        int b = rand() % n;
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
    }
}

int is_sorted(const int v[], int n) {
    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) return 0;
    }
    return 1;
}

double elapsed_seconds(clock_t start, clock_t end) {
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void benchmark_merge(const char *nome, int v[], int n) {
    Metrics metrics;
    clock_t start = clock();
    merge_sort(v, n, &metrics);
    clock_t end = clock();

    printf("Merge %-14s n=%-7d tempo=%.6fs comps=%-12lld sorted=%s\n",
           nome, n, elapsed_seconds(start, end), metrics.comps,
           is_sorted(v, n) ? "SIM" : "NAO");
}

int main(void) {
    const int ns[] = {1000, 10000, 100000};
    srand(42);

    printf("=== Merge Sort - Atividade ===\n");
    printf("Comparacao pedida: n = 10^3, 10^4 e 10^5.\n");
    printf("Para evitar uma execucao excessivamente longa, o benchmark do Insertion Sort\n");
    printf("fica limitado a n <= 10000; o Merge Sort roda ate n=100000.\n\n");

    for (size_t i = 0; i < sizeof(ns) / sizeof(ns[0]); i++) {
        int n = ns[i];
        int *v = malloc((size_t)n * sizeof(int));
        if (!v) return 1;

        fill_random(v, n);
        benchmark_merge("aleatorio", v, n);
        if (n <= 10000) {
            fill_random(v, n);
            clock_t start = clock();
            insertion_sort(v, n);
            clock_t end = clock();
            printf("Insertion aleatorio n=%-7d tempo=%.6fs sorted=%s\n",
                   n, elapsed_seconds(start, end), is_sorted(v, n) ? "SIM" : "NAO");
        }

        fill_reverse(v, n);
        benchmark_merge("reverso", v, n);
        if (n <= 10000) {
            fill_reverse(v, n);
            clock_t start = clock();
            insertion_sort(v, n);
            clock_t end = clock();
            printf("Insertion reverso   n=%-7d tempo=%.6fs sorted=%s\n",
                   n, elapsed_seconds(start, end), is_sorted(v, n) ? "SIM" : "NAO");
        }

        fill_nearly_sorted(v, n, 20);
        benchmark_merge("quase k=20", v, n);
        if (n <= 10000) {
            fill_nearly_sorted(v, n, 20);
            clock_t start = clock();
            insertion_sort(v, n);
            clock_t end = clock();
            printf("Insertion quase     n=%-7d tempo=%.6fs sorted=%s\n",
                   n, elapsed_seconds(start, end), is_sorted(v, n) ? "SIM" : "NAO");
        }

        printf("\n");
        free(v);
    }

    printf("Resposta conceitual:\n");
    printf("O Merge Sort tem custo Theta(n log n) no pior caso, enquanto o Insertion\n");
    printf("Sort pode chegar a Theta(n^2). Portanto, conforme n cresce, o Merge tende\n");
    printf("a apresentar vantagem em entradas grandes. O ponto exato depende da maquina,\n");
    printf("do compilador e do tipo de entrada; por isso deve ser medido no laboratorio.\n");

    return 0;
}
