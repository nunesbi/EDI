#include <stdio.h>

// 1. Retorna o maior entre dois inteiros.
int maximo(int a, int b) {
    return (a > b) ? a : b;
}

// 2. Troca dois inteiros usando ponteiros.
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3. Busca um valor no vetor e retorna seu indice.
// Retorna -1 caso o valor nao seja encontrado.
int buscar(int v[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            return i;
        }
    }
    return -1;
}

// 4. Inverte o vetor usando dois ponteiros/indices.
void inverter(int v[], int n) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio < fim) {
        trocar(&v[inicio], &v[fim]);
        inicio++;
        fim--;
    }
}

// 5. Conta quantas vezes um valor aparece no vetor.
int contar_ocorrencias(int v[], int n, int valor) {
    int contador = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            contador++;
        }
    }

    return contador;
}

// Desafio-relampago da aula: media de tres notas.
double media(double n1, double n2, double n3) {
    return (n1 + n2 + n3) / 3.0;
}

void imprimir_vetor(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main(void) {
    int a = 10;
    int b = 20;
    int v[] = {4, 7, 2, 7, 9, 7};
    int n = sizeof(v) / sizeof(v[0]);

    printf("1. maximo(10, 20) = %d\n", maximo(a, b));

    trocar(&a, &b);
    printf("2. troca: a = %d, b = %d\n", a, b);

    printf("3. buscar 9: indice = %d\n", buscar(v, n, 9));
    printf("   buscar 10: indice = %d\n", buscar(v, n, 10));

    printf("4. vetor original: ");
    imprimir_vetor(v, n);
    inverter(v, n);
    printf("   vetor invertido: ");
    imprimir_vetor(v, n);

    // O vetor foi invertido; o valor 7 continua aparecendo 3 vezes.
    printf("5. ocorrencias de 7 = %d\n", contar_ocorrencias(v, n, 7));

    printf("\nDesafio: media(70, 80, 90) = %.2f\n", media(70, 80, 90));

    return 0;
}
