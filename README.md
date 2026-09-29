# GCT053 - Estruturas de Dados I - Exercicios Resolvidos

Solucoes em C baseadas nas atividades presentes nos PDFs da disciplina.

## Organizacao

- `funcoes/`: atividade da aula de Funcoes + desafio da media + mini-projeto da aula.
- `recursividade/`: atividade de recursividade, MDC recursivo/iterativo e analises.
- `ordenacao_conceitos/`: atividade de `fill_nearly_sorted`, `is_sorted` e `qsort`.
- `insertion_sort/`: atividade de comparacao de entradas e metricas do Insertion Sort.
- `selection_sort/`: implementacao e instrumentacao apresentada na aula; o PDF nao traz uma atividade final separada.
- `merge_sort/`: Merge Sort + comparacao com Insertion Sort.

## Como compilar

Dentro de cada pasta, no terminal do VS Code:

```bash
gcc -Wall -Wextra -std=c11 main.c -o programa
./programa
```

No Windows, pelo terminal MinGW/GCC, normalmente:

```powershell
gcc -Wall -Wextra -std=c11 main.c -o programa.exe
./programa.exe
```

## Exercicios e respostas

### 1. Funcoes

A atividade pede cinco funcoes:

1. maximo entre dois inteiros;
2. troca de dois inteiros por ponteiros;
3. busca de um valor em vetor;
4. inversao de vetor;
5. contagem de ocorrencias.

O desafio anterior pede uma funcao para media de tres notas. A implementacao usa `double` para preservar a parte decimal.

### 2. Recursividade

**Pilha de `fatorial(4)`:**

```text
main
  -> fatorial(4)
      -> fatorial(3)
          -> fatorial(2)
              -> fatorial(1)  // caso-base
              <- 1
          <- 2
      <- 6
  <- 24
```

**`fib(6)`:**

`fib(6) = 8` e `fib(2)` aparece **3 vezes** na arvore de chamadas.

**MDC:**

O algoritmo recursivo usa `mdc(a,b) = mdc(b, a % b)` ate `b == 0`. A versao iterativa executa a mesma ideia usando um `while`, sem criar novos frames recursivos.

**Custo:**

- Fatorial recursivo: tempo `Theta(n)` e stack `Theta(n)`.
- MDC de Euclides: tempo `O(log(min(a,b)))` no caso usual e stack proporcional ao numero de chamadas na versao recursiva.
- Fibonacci recursivo simples: tempo exponencial e stack `Theta(n)`.

### 3. Conceitos de ordenacao

A atividade pede `fill_nearly_sorted(v,n,k)`, um `main` para gerar/testar vetor e verificacao com `is_sorted`.

A implementacao cria um vetor ordenado e faz `k` trocas aleatorias. Assim, `k` controla a perturbacao do vetor: quanto maior `k`, maior tende a ser a quantidade de inversoes. Nao ha garantia de que `k` trocas produzam exatamente `k` inversoes.

### 4. Insertion Sort

A atividade usa:

- `n = {50, 200, 1000, 5000}`;
- `k = {1, 5, 20, 200}`;
- entradas aleatoria, ordenada, reversa e quase ordenada;
- metricas de comparacoes e movimentacoes.

A conclusao esperada e:

- melhor caso: `Theta(n)`;
- pior caso: `Theta(n^2)`;
- quanto mais perto de ordenado, menor tende a ser o custo do Insertion Sort;
- movimentacoes estao relacionadas ao numero de inversoes.

### 5. Selection Sort

O PDF apresenta a implementacao e instrumentacao, mas nao traz uma atividade final numerada separada. O codigo desta pasta implementa exatamente a versao instrumentada para treino/teste.

Propriedades:

- comparacoes: `Theta(n^2)` em qualquer entrada;
- movimentacoes/escritas: `O(n)`;
- in-place: sim;
- padrao apresentado: nao estavel;
- nao adaptativo.

### 6. Merge Sort

A atividade pede:

1. implementar Merge Sort e validar com `is_sorted`;
2. comparar com Insertion Sort para `n = 10^3, 10^4, 10^5` e entradas aleatoria, reversa e quase ordenada;
3. registrar tempo e/ou comparacoes;
4. discutir quando Merge Sort passa a ter vantagem.

O programa executa Merge Sort nos tres tamanhos. Para evitar uma execucao impraticavelmente longa, o Insertion Sort e executado apenas ate `n = 10000`; para `n = 100000`, o programa mede o Merge Sort. O ponto de cruzamento exato deve ser medido no computador usado no laboratorio.

