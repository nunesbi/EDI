#include <stdio.h>

int soma_vetor(const int v[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma;
}

int maior_vetor(const int v[], int n) {
    if (n <= 0) return 0;

    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    return maior;
}

int busca_sequencial(const int v[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            return i;
        }
    }
    return -1;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inverte_vetor(int v[], int n) {
    int i = 0;
    int j = n - 1;

    while (i < j) {
        troca(&v[i], &v[j]);
        i++;
        j--;
    }
}

void imprimir(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], i == n - 1 ? "\n" : " ");
    }
}

int main(void) {
    int v[] = {5, 2, 9, 1, 7};
    int n = sizeof(v) / sizeof(v[0]);

    printf("soma_vetor = %d\n", soma_vetor(v, n));
    printf("maior_vetor = %d\n", maior_vetor(v, n));
    printf("busca_sequencial(9) = %d\n", busca_sequencial(v, n, 9));

    int a = 10, b = 20;
    troca(&a, &b);
    printf("troca: a=%d, b=%d\n", a, b);

    printf("antes de inverte_vetor: ");
    imprimir(v, n);
    inverte_vetor(v, n);
    printf("depois de inverte_vetor: ");
    imprimir(v, n);

    return 0;
}
