#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long long comparacoes;
    long long movimentacoes;
} Metrics;

void reset_metrics(Metrics *m) {
    m->comparacoes = 0;
    m->movimentacoes = 0;
}

int is_sorted(const int v[], int n) {
    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) return 0;
    }
    return 1;
}

void fill_sorted(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = i;
}

// Gera vetor ordenado e faz k trocas aleatorias.
// k mede a perturbacao; nao significa exatamente k inversoes.
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

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

void imprimir_vetor(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i == n - 1) ? "\n" : " ");
    }
}

int main(void) {
    const int n = 20;
    const int ks[] = {1, 5, 50, 500};
    int v[n];

    srand(42);

    printf("Atividade de ordenacao: fill_nearly_sorted + is_sorted + qsort\n\n");

    for (size_t i = 0; i < sizeof(ks) / sizeof(ks[0]); i++) {
        int k = ks[i];
        fill_nearly_sorted(v, n, k);

        printf("k = %d\n", k);
        printf("Antes: ");
        imprimir_vetor(v, n);

        qsort(v, n, sizeof(int), cmp_int);

        printf("Depois: ");
        imprimir_vetor(v, n);
        printf("is_sorted = %s\n\n", is_sorted(v, n) ? "SIM" : "NAO");
    }

    printf("Resposta conceitual:\n");
    printf("Quanto maior k, maior tende a ser a perturbacao do vetor ordenado.\n");
    printf("Isso aumenta a quantidade de inversoes e tende a dificultar algoritmos\n");
    printf("adaptativos, como o Insertion Sort. As trocas sao uma aproximacao da\n");
    printf("dificuldade: k nao garante exatamente k inversoes.\n");

    return 0;
}
