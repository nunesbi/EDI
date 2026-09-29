#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long comps;
    long long moves;
} Metrics;

void reset_metrics(Metrics *m) {
    m->comps = 0;
    m->moves = 0;
}

void insertion_sort_metrics(int v[], int n, Metrics *m) {
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i - 1;

        while (j >= 0) {
            m->comps++;
            if (!(v[j] > x)) break;

            v[j + 1] = v[j];
            m->moves++;
            j--;
        }

        v[j + 1] = x;
        m->moves++;
    }
}

void fill_random(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = rand();
}

void fill_sorted(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = i;
}

void fill_reverse(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = n - i;
}

void fill_nearly_sorted(int v[], int n, int k) {
    fill_sorted(v, n);
    if (n < 2) return;

    for (int i = 0; i < k; i++) {
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

void executar_caso(const char *nome, int v[], int n) {
    Metrics m;
    reset_metrics(&m);
    insertion_sort_metrics(v, n, &m);

    printf("%-18s n=%-5d comps=%-12lld moves=%-12lld sorted=%s\n",
           nome, n, m.comps, m.moves, is_sorted(v, n) ? "SIM" : "NAO");
}

int main(void) {
    const int ns[] = {50, 200, 1000, 5000};
    const int ks[] = {1, 5, 20, 200};

    srand(42);

    printf("=== Insertion Sort - Atividade ===\n");
    printf("Metricas: movimentacoes = escritas em v[], conforme a aula.\n\n");

    for (size_t ni = 0; ni < sizeof(ns) / sizeof(ns[0]); ni++) {
        int n = ns[ni];
        int *v = malloc((size_t)n * sizeof(int));
        if (!v) {
            fprintf(stderr, "Erro de memoria para n=%d\n", n);
            return 1;
        }

        fill_random(v, n);
        executar_caso("aleatorio", v, n);

        fill_sorted(v, n);
        executar_caso("ordenado", v, n);

        fill_reverse(v, n);
        executar_caso("reverso", v, n);

        for (size_t ki = 0; ki < sizeof(ks) / sizeof(ks[0]); ki++) {
            int k = ks[ki];
            fill_nearly_sorted(v, n, k);
            char nome[64];
            snprintf(nome, sizeof(nome), "quase k=%d", k);
            executar_caso(nome, v, n);
        }

        printf("\n");
        free(v);
    }

    printf("Conclusoes:\n");
    printf("- Ordenado: crescimento aproximadamente linear.\n");
    printf("- Reverso: crescimento quadratico.\n");
    printf("- Quase ordenado: quanto menor a perturbacao, menor tende a ser o custo.\n");
    printf("- Isso ocorre porque os deslocamentos acompanham as inversoes do vetor.\n");

    return 0;
}
