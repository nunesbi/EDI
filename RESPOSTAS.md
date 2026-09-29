# Respostas conceituais

## Funcoes

### Desafio: media de tres notas

```c
double media(double n1, double n2, double n3) {
    return (n1 + n2 + n3) / 3.0;
}
```

`double` e adequado porque a media pode possuir casas decimais.

### Atividade

1. `maximo(a,b)` retorna o maior dos dois inteiros.
2. `trocar(&a,&b)` altera as variaveis do chamador porque recebe seus enderecos.
3. `buscar(v,n,valor)` percorre o vetor e retorna o indice encontrado, ou `-1`.
4. `inverter(v,n)` troca os elementos das extremidades ate chegar ao meio.
5. `contar_ocorrencias(v,n,valor)` percorre o vetor e incrementa o contador quando encontra o valor.

### Mini-projeto

Foram implementadas `soma_vetor`, `maior_vetor`, `busca_sequencial`, `troca` e `inverte_vetor` em `funcoes/mini_projeto.c`.

## Recursividade

### 1. Pilha de `fatorial(4)`

```text
main
  -> fatorial(4)
      -> fatorial(3)
          -> fatorial(2)
              -> fatorial(1)
                  -> retorna 1
              -> retorna 2
          -> retorna 6
      -> retorna 24
```

Portanto, `fatorial(4) = 24`.

### 2. Quantas vezes `fib(2)` aparece em `fib(6)`?

`fib(2)` aparece **5 vezes** na arvore de chamadas.

### 3. MDC recursivo

Usa a relacao de Euclides:

```text
mdc(a,b) = mdc(b, a % b)
```

ate `b == 0`.

### 4. Euclides iterativo

A mesma relacao e executada com um `while`, evitando novas chamadas recursivas.

### Custos

- Fatorial: `Theta(n)` tempo e `Theta(n)` de stack.
- Fibonacci recursivo simples: tempo exponencial e stack `Theta(n)`.
- MDC de Euclides: tempo logaritmico no caso usual; a versao recursiva usa stack proporcional a profundidade das chamadas.

## Ordenacao - atividade de quase ordenado

`fill_nearly_sorted` primeiro cria `[0,1,2,...,n-1]` e depois realiza `k` trocas aleatorias.

Quanto maior `k`, maior tende a ser a perturbacao e o numero de inversoes. Por isso, `k` funciona como uma medida pratica de dificuldade para um algoritmo adaptativo. Nao significa exatamente `k` inversoes, pois duas trocas podem desfazer parcialmente efeitos anteriores.

## Insertion Sort

### Como o custo cresce com `n`?

- Vetor ordenado: aproximadamente `Theta(n)`.
- Vetor reverso: `Theta(n^2)`.
- Vetor aleatorio: comportamento medio quadratico.

### Como `k` afeta o quase ordenado?

Poucas trocas produzem poucas inversoes e o Insertion Sort tende a executar poucas movimentacoes. Aumentar `k` normalmente aumenta o custo.

### Comparacao `Theta(n)` x `Theta(n^2)`

Os testes mostram crescimento quase linear no melhor caso e quadratico no pior caso, conforme apresentado na aula.

## Selection Sort

A implementacao padrao apresentada no PDF realiza sempre:

```text
n(n-1)/2
```

comparacoes, independentemente da entrada.

As trocas sao poucas: no maximo `n-1` trocas, com duas escritas no vetor por troca na instrumentacao usada aqui.

## Merge Sort

O Merge Sort divide o vetor em metades, ordena recursivamente e depois faz o `merge` das duas partes ordenadas.

A recorrencia e:

```text
T(n) = 2T(n/2) + Theta(n)
```

Logo:

```text
T(n) = Theta(n log n)
```

O vetor auxiliar usa `O(n)` de memoria.

### Quando ele passa a ter vantagem sobre o Insertion Sort?

Nao existe um valor universal de `n`: depende da maquina, compilador, implementacao e tipo de entrada. Nos testes realizados neste projeto, o Merge Sort ja apresentou vantagem clara em `n=10000` para entradas aleatorias e reversas. Em entradas quase ordenadas, o Insertion Sort pode ser competitivo por aproveitar a baixa quantidade de inversoes.
