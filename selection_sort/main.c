#include <stdio.h>

typedef struct {
    long long comps;
    long long moves;
} Metrics;

void selection_sort_metrics(int v[], int n, Metrics *m) {
    m->comps = 0;
    m->moves = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            m->comps++;
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int tmp = v[i];
            v[i] = v[min_idx];
            m->moves++;
            v[min_idx] = tmp;
            m->moves++;
        }
    }
}

int is_sorted(const int v[], int n) {
    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) return 0;
    }
    return 1;
}

void print_array(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], i == n - 1 ? "\n" : " ");
    }
}

int main(void) {
    int v[] = {7, 3, 5, 2, 9, 1, 8, 4};
    int n = sizeof(v) / sizeof(v[0]);
    Metrics m;

    printf("Selection Sort\n");
    printf("Antes:  ");
    print_array(v, n);

    selection_sort_metrics(v, n, &m);

    printf("Depois: ");
    print_array(v, n);
    printf("Comparacoes: %lld\n", m.comps);
    printf("Movimentacoes (escritas em v[]): %lld\n", m.moves);
    printf("Ordenado: %s\n", is_sorted(v, n) ? "SIM" : "NAO");

    return 0;
}
