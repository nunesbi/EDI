#include <stdio.h>

// Fatorial recursivo.
long long fatorial(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    return (long long)n * fatorial(n - 1);
}

// Fibonacci recursivo, conforme a definicao da aula.
long long fib(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

// Conta quantas vezes fib(2) aparece na arvore de chamadas de fib(n).
int conta_fib2(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    return conta_fib2(n - 1) + conta_fib2(n - 2);
}

// 3. MDC de Euclides na forma recursiva.
int mdc_recursivo(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0) return a;
    return mdc_recursivo(b, a % b);
}

// 4. Versao iterativa de Euclides.
int mdc_iterativo(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

void imprimir_chamada_fatorial(int n) {
    printf("fatorial(%d)", n);
    if (n > 1) {
        printf(" -> ");
        imprimir_chamada_fatorial(n - 1);
    }
}

int main(void) {
    // 1. Trace da pilha de chamadas de fatorial(4).
    printf("1. Pilha de chamadas: ");
    imprimir_chamada_fatorial(4);
    printf(" -> caso-base fatorial(1) = 1\n");
    printf("   Desempilhando: 1 -> 2 -> 6 -> 24\n");
    printf("   fatorial(4) = %lld\n", fatorial(4));

    // 2. fib(6) e quantidade de ocorrencias de fib(2).
    printf("\n2. fib(6) = %lld\n", fib(6));
    printf("   fib(2) aparece %d vezes na arvore de chamadas.\n", conta_fib2(6));

    // 3 e 4. MDC recursivo e iterativo.
    int pares[][2] = {{48, 18}, {270, 192}, {17, 5}, {100, 25}, {81, 27}};
    int qtd = sizeof(pares) / sizeof(pares[0]);

    printf("\n3/4. MDC recursivo x iterativo:\n");
    for (int i = 0; i < qtd; i++) {
        int a = pares[i][0];
        int b = pares[i][1];
        printf("   mdc(%d, %d): recursivo = %d | iterativo = %d\n",
               a, b, mdc_recursivo(a, b), mdc_iterativo(a, b));
    }

    return 0;
}
