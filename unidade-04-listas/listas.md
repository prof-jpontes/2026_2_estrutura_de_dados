# Unidade Temática #4 — Listas


Senhores estudantes,

Esta é a unidade temática #4 da disciplina de Estrutura de Dados, ministrada no curso superior de tecnologia em Sistemas para Internet do Ifac/Campus Rio Branco. Nesta unidade, apresentaremos a estrutura de dados **lista** nas formas simplesmente encadeada, duplamente encadeada e circular. 

Para se aprofundar neste roteiro, acesse o livro **Estruturas de dados**: algoritmos, análise da complexidade e implementações em Java e C/C++, de Ascencio e Araújo, disponível na biblioteca virtual do Ifac, acessível por meio do link [https://plataforma.bvirtual.com.br/Acervo/Publicacao/1995](https://plataforma.bvirtual.com.br/Acervo/Publicacao/1995). No livro, estude o capítulo 3. 


## 📑 Sumário

- [Listas](#listas)
  - [O que são listas](#o-que-são-listas)
  - [Vantagens e desvantagens de listas dinâmicas](#vantagens-e-desvantagens-de-listas-dinâmicas)
  - [Operações fundamentais](#operações-fundamentais)
  - [Quando usar listas](#quando-usar-listas)
  - [Criação de um nó em C](#criação-de-um-nó-em-c)
- [Listas simplesmente encadeadas](#listas-simplesmente-encadeadas)
  - [Representação conceitual](#representação-conceitual)
  - [Vantagens e desvantagens](#vantagens-e-desvantagens-de-listas-simplesmente-encadeadas)
  - [Operações fundamentais](#operações-fundamentais-1)
  - [Exemplo prático](#exemplo-prático)
  - [Exercícios](#exercícios)
  - [Prática](#prática)
- [Listas duplamente encadeadas](#listas-duplamente-encadeadas)
  - [Representação conceitual](#representação-conceitual-1)
  - [Vantagens e desvantagens](#vantagens-e-desvantagens-de-listas-duplamente-encadeadas)
  - [Operações fundamentais](#operações-fundamentais-2)
  - [Exemplo prático](#exemplo-prático-1)
  - [Exercícios](#exercícios-1)
- [Listas circulares](#listas-circulares)
  - [Representação conceitual](#representação-conceitual-2)
  - [Vantagens e desvantagens](#vantagens-e-desvantagens-de-listas-circulares)
  - [Operações fundamentais](#operações-fundamentais-3)
  - [Exemplo prático](#exemplo-prático-2)
  - [Lista duplamente circular](#lista-duplamente-circular)
  - [Exercícios](#exercícios-2)

>> 📅 Segunda-feira, 5/10/2026 

## Listas
### O que são listas

Listas são estruturas de dados fundamentais que representam coleções de elementos, nas quais cada elemento possui uma posição específica. Listas permitem diversas operações, tais como inserção, remoção e busca. Listas podem ser implementadas por meio de estratégias diferentes, de modo que elas podem ser estáticas ou dinâmicas.

- **Listas estáticas**: podem ser implementadas por meio de vetores, têm tamanho máximo fixo, permitem acesso rápido a elementos por meio de índices e têm como limitação a impossibilidade de crescimento em tempo de execução;
- **Listas dinâmicas**: guardam elementos encadeados, têm tamanho variável e os elementos são alocados dinamicamente, de modo que permitem inserções e remoções eficientes. 

Uma lista estática implementada por meio de um vetor ocupa um tamanho `x` na memória, independente da quantidade de elementos que efetivamente ela tem. Ademais, a quantidade de elementos na lista não pode exceder o tamanho previamente definido para o vetor. A figura abaixo mostra dois exemplos de listas implementadas via vetor. A primeira, que é uma lista estática de dados homogêneos, tem cinco números inteiros e pode armazenar, no máximo, oito. A segunda — que é uma lista estática de dados heterogêneos — guarda três `structs` que contêm um texto e um inteiro; ela pode armazenar, no máximo, oito. Independentemente da quantidade de elementos guardados na lista, o espaço de memória reservado para cada lista é `8 vezes a quantidade de memória necessária para armazenar um elemento`. 

![Listas armazenadas em vetores](https://github.com/user-attachments/assets/c0169ab8-147b-4afc-a531-af725b1350aa)

Por outro lado, uma lista implementada dinamicamente ocupa na memória o espaço mínimo suficiente para guardar a quantidade de elementos que estão na lista em um determinado espaço de tempo. Na figura abaixo, há duas listas implementadas de maneira dinâmica, uma com dados homogêneos e outra com dados heterogêneos. A primeira guarda números inteiros, ao passo que a segunda armazena `structs` com texto e número. Nesse tipo de lista, cada nó guarda um valor (número na primeira lista e `struct` na segunda) e um ponteiro para o próximo nó. O último nó tem um ponteiro que aponta para `NULL`.

![Listas armazenadas dinamicamente](https://github.com/user-attachments/assets/9a2192b1-28a5-4bcb-bac0-f9e194ae91bd)

> Nesta unidade, atentar-nos-emos apenas a listas dinâmicas.

### Vantagens e desvantagens de listas dinâmicas

**1. Vantagens:**

- Cresce conforme necessário;
- Inserir ou remover no início é muito eficiente computacionalmente;
- Não há necessidade de mover elementos.

Por exemplo, para inserir um elemento de valor 30 na lista dinâmica homogênea da figura acima, entre o 2 e o 14, basta fazer o ponteiro do nó que contém o elemento 2 apontar para o novo nó com o valor 30 e fazer o ponteiro do nó que tem o valor 30 apontar para o nó que tem o valor 14, assim: 

![Inserção em lista dinâmica](https://github.com/user-attachments/assets/dbbb94b5-3dd4-4617-a1fb-d70182c3cb93)

**2. Desvantagens:**

- Acesso sequencial
  - Não há acesso direto por índice;
  - Não existe busca binária;
- Usa mais memória (ponteiros);
- Mais complexa de implementar.

### Operações fundamentais

- Criar lista (inicialmente vazia);
- Inserir elemento;
- Remover elemento;
- Buscar elemento;
- Percorrer a lista.

### Quando usar listas

- Quando não se conhece o tamanho final dos dados;
- Quando inserções e remoções frequentes são necessárias;
- Quando economia de deslocamento de elementos é importante.


### Criação de um nó em C

O exemplo abaixo apresenta a criação de um nó, que contém um número inteiro e um ponteiro para o próximo nó.

```c
typedef struct No {
    int valor;
    struct No *prox;
} No;
```

> **Atenção:** dentro da `struct`, o ponteiro para o próximo nó deve ser declarado como `struct No *prox`, pois o apelido `No` (criado pelo `typedef`) ainda não existe nesse ponto da declaração. Por isso, a `struct` recebe o nome `No` logo após a palavra `struct`.

>> 📅 Quarta-feira, 7/10/2026  

## Listas simplesmente encadeadas

Uma lista simplesmente encadeada é uma estrutura de dados dinâmica composta por **nós**, em que cada um deles armazena:

- um valor (nesta aula, um inteiro);

- um ponteiro para o próximo nó;

* *O código acima em C representa a estrutura de um nó, o qual será usado nesta aula*.

Essa estrutura é recomendada quando o número de elementos não é conhecido previamente ou quando inserções e remoções são frequentes.

Em uma lista simplesmente encadeada, cada nó guarda um elemento (no exemplo, um inteiro, mas pode ser uma `struct` ou qualquer outro tipo) e o endereço do próximo nó (um ponteiro, geralmente chamado de `prox`). Se `prox == NULL`, significa que aquele é o último nó da lista.

### Representação Conceitual

Uma lista com os elementos 6 → 2 → 14 → 17 → 17 é representada assim:

![Lista simplesmente encadeada](https://github.com/user-attachments/assets/a2d76d03-91cf-4da4-ab99-fd2e6a10dc3b)

O ponteiro inicial da lista, que podemos chamar de `raiz`, aponta para o primeiro nó.

### Vantagens e desvantagens de listas simplesmente encadeadas

**1. Vantagens**
- Crescem e diminuem conforme necessário;
- Inserções e remoções são eficientes no início da lista, ou seja, em `O(1)`;
- Não há necessidade de deslocar elementos.

**2. Desvantagens**
- Não possuem acesso direto por índice;
- Para acessar o elemento n, é preciso percorrer n nós.

### Operações Fundamentais

1. Criar uma lista vazia;
2. Inserir no início;
3. Inserir no final;
4. Buscar um elemento;
5. Remover um elemento;
6. Percorrer/imprimir;
7. Liberar memória

### Exemplo prático

O programa abaixo implementa as operações fundamentais de uma lista simplesmente encadeada de inteiros. Observe que as funções que podem alterar a `raiz` (inserir no início e remover) **retornam a nova raiz**, e o `main` a atualiza.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

/* 1. Criar lista vazia: uma lista vazia é simplesmente um ponteiro NULL */
No* criarLista() {
    return NULL;
}

/* 2. Inserir no início: O(1) */
No* inserir_inicio(No *raiz, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return raiz;
    }
    novo->valor = valor;
    novo->prox = raiz;      /* o novo nó aponta para o antigo primeiro */
    return novo;            /* o novo nó passa a ser a raiz */
}

/* 3. Inserir no final: O(n), pois é preciso percorrer a lista */
No* inserir_fim(No *raiz, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return raiz;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (raiz == NULL) return novo;    /* lista vazia: o novo nó é a raiz */        

    No *aux = raiz;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    return raiz;
}

/* 4. Buscar: retorna o nó encontrado ou NULL */
No* buscar(No *raiz, int valor) {
    No *aux = raiz;
    while (aux != NULL) {
        if (aux->valor == valor) return aux;

        aux = aux->prox;
    }
    return NULL;
}

/* 5. Remover a primeira ocorrência de um valor */
No* remover(No *raiz, int valor) {
    No *ant = NULL;
    No *atual = raiz;

    while (atual != NULL && atual->valor != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return raiz;           /* valor não encontrado */
        

    if (ant == NULL) raiz = atual->prox;      /* o nó removido é o primeiro */
        
    else ant->prox = atual->prox;             /* o nó removido está no meio ou no fim */

    free(atual);
    return raiz;
}

/* 6. Percorrer/imprimir */
void imprimir(No *raiz) {
    No *aux = raiz;
    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf(" |\n");
}

/* 7. Liberar memória */
void liberar(No *raiz) {
    No *aux;
    while (raiz != NULL) {
        aux = raiz;
        raiz = raiz->prox;
        free(aux);
    }
}

int main() {
    No *raiz = criarLista();

    raiz = inserir_inicio(raiz, 2);
    raiz = inserir_inicio(raiz, 6);   
    raiz = inserir_fim(raiz, 14);     
    raiz = inserir_fim(raiz, 17);     
    imprimir(raiz);

    if (buscar(raiz, 14) != NULL) {
        printf("14 esta na lista.\n");
    }

    raiz = remover(raiz, 2);        
    imprimir(raiz);

    liberar(raiz);
    return 0;
}
```

**Saída esperada:**

```
6 -> 2 -> 14 -> 17 -> |
14 esta na lista.
6 -> 14 -> 17 -> |
```

>> 📅 Sábado, 10/10/2026 

### Exercícios

1. Faça uma função que inclua um elemento no fim da lista em `O(1)`;
   > *Dica:* mantenha, além da `raiz`, um ponteiro `fim` para o último nó. Agrupe os dois em uma `struct Lista { No *inicio; No *fim; }`.
2. Faça uma função que receba um número e exclua esse número da lista;
3. Faça uma função que exclua o elemento do fim da lista;
4. Faça uma função que exclua o elemento do início da lista.

### Prática

Utilize o código do exemplo prático como ponto de partida e implemente as funções abaixo.

1. **Contar nós:** faça uma função que retorne a quantidade de elementos da lista;
2. **Somar:** faça uma função que retorne a soma de todos os valores da lista;
3. **Maior valor:** faça uma função que retorne o maior valor armazenado na lista (trate o caso da lista vazia);
4. **Contar ocorrências:** faça uma função que receba um número `x` e retorne quantas vezes ele aparece na lista. Teste com a lista `6 → 2 → 14 → 17 → 17` e `x = 17`;
5. **Inserir após:** faça uma função que receba dois números, `x` e `y`, e insira `y` logo depois do primeiro nó que contém `x`. Se `x` não existir, a lista não deve ser alterada;
6. **Remover todas as ocorrências:** faça uma função que receba um número e remova **todos** os nós que contêm esse valor;
7. **Inverter a lista:** faça uma função que inverta a ordem dos nós **sem criar novos nós**, apenas alterando os ponteiros `prox`. Por exemplo, `6 → 2 → 14` deve se tornar `14 → 2 → 6`;
8. **Menu interativo:** monte um programa com um menu (inserir no início, inserir no fim, remover, buscar, imprimir e sair) que use as funções criadas.

## Listas duplamente encadeadas

Uma lista duplamente encadeada é uma estrutura de dados dinâmica composta por **nós**, em que cada um deles armazena:

- um valor (nesta aula, um inteiro), ou vários dados, no caso de `structs`;

- um ponteiro para o próximo nó (`prox`);

- um ponteiro para o nó anterior (`ant`).

Essa abordagem permite o encadeamento da lista em ambas as direções e mantém a estrutura linear. Assim, é possível: 

- Navegar para frente e para trás;
- Inserir e remover de forma mais eficiente em posições intermediárias da lista.

É uma estrutura bastante utilizada em sistemas que exigem manipulação flexível de elementos, como editores de texto, histórico de navegação e buffers de dados.

Em uma lista duplamente encadeada, cada nó guarda um elemento e os endereços do próximo e do anterior. Se `prox == NULL`, aquele é o último nó da lista; se `ant == NULL`, aquele é o primeiro.

### Estrutura da lista

```c
typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;
```

Para tornar as operações nas duas extremidades eficientes, é comum agrupar os ponteiros de início e de fim em uma `struct` própria:

```c
typedef struct {
    No *inicio;
    No *fim;
} Lista;
```

### Representação conceitual

A lista com os elementos 6 ⇄ 2 ⇄ 14 ⇄ 17 ⇄ 17 é representada assim:

![Lista duplamente encadeada](https://github.com/user-attachments/assets/ec8e9fd7-a6d5-4d8c-969d-d949e105d4f3)

O ponteiro `inicio` da lista aponta para o primeiro nó, e o ponteiro `fim` aponta para o último. O primeiro nó tem `ant` igual a `NULL`. Já o último tem `prox` igual a `NULL`.

### Vantagens e desvantagens de listas duplamente encadeadas

**1. Vantagens**
- Navegação bidirecional;
- Inserção antes/depois de qualquer nó é simples, ou seja, em `O(1)`;
- Inserções e remoções são eficientes no início **e no fim** da lista, ou seja, em `O(1)`, desde que se mantenha o ponteiro `fim`;
- Remover um nó cujo endereço já se conhece é `O(1)`, pois não é preciso procurar o anterior.

**2. Desvantagens**
- Ocupam mais memória (duas referências por nó);
- Implementação mais complexa que a lista simples;
- Maior risco de erros de ponteiros (é preciso atualizar `prox` **e** `ant`);
- Assim como na lista simples, não possuem acesso direto por índice.

### Operações fundamentais

As operações aplicáveis a listas duplamente encadeadas são as mesmas que podem ser usadas em listas simplesmente encadeadas, acrescentando que pode-se percorrer não somente para frente, mas também para trás.

1. Criar uma lista vazia;
2. Inserir no início;
3. Inserir no final;
4. Buscar um elemento;
5. Remover um elemento;
6. Percorrer/imprimir (para frente e para trás);
7. Liberar memória

### Exemplo prático

O programa abaixo implementa as operações fundamentais de uma lista duplamente encadeada de inteiros. Diferentemente do exemplo da lista simples, aqui a lista é passada **por referência** (ponteiro para `Lista`), de modo que as funções atualizam `inicio` e `fim` diretamente.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Lista;

/* 1. Criar lista vazia */
void criarLista(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

/* 2. Inserir no início: O(1) */
void inserir_inicio(Lista *l, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = l->inicio;

    if (l->inicio != NULL) {
        l->inicio->ant = novo;   /* o antigo primeiro passa a ter um anterior */
    } else {
        l->fim = novo;           /* lista estava vazia: o novo nó também é o último */
    }
    l->inicio = novo;
}

/* 3. Inserir no final: O(1), graças ao ponteiro fim */
void inserir_fim(Lista *l, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = l->fim;

    if (l->fim != NULL) {
        l->fim->prox = novo;
    } else {
        l->inicio = novo;        /* lista estava vazia */
    }
    l->fim = novo;
}

/* 4. Buscar: retorna o nó encontrado ou NULL */
No* buscar(Lista *l, int valor) {
    No *aux = l->inicio;
    while (aux != NULL) {
        if (aux->valor == valor) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

/* 5. Remover a primeira ocorrência de um valor. Retorna 1 se removeu, 0 caso contrário */
int remover(Lista *l, int valor) {
    No *aux = buscar(l, valor);
    if (aux == NULL) {
        return 0;
    }

    if (aux->ant != NULL) {
        aux->ant->prox = aux->prox;
    } else {
        l->inicio = aux->prox;   /* removeu o primeiro */
    }

    if (aux->prox != NULL) {
        aux->prox->ant = aux->ant;
    } else {
        l->fim = aux->ant;       /* removeu o último */
    }

    free(aux);
    return 1;
}

/* 6. Percorrer/imprimir */
void imprimirFrente(Lista *l) {
    No *aux = l->inicio;
    printf("| <-> ");
    while (aux != NULL) {
        printf("%d <-> ", aux->valor);
        aux = aux->prox;
    }
    printf("|\n");
}

void imprimirTras(Lista *l) {
    No *aux = l->fim;
    printf("| <-> ");
    while (aux != NULL) {
        printf("%d <-> ", aux->valor);
        aux = aux->ant;
    }
    printf("|\n");
}

/* 7. Liberar memória */
void liberar(Lista *l) {
    No *aux = l->inicio;
    while (aux != NULL) {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    l->inicio = NULL;
    l->fim = NULL;
}

int main() {
    Lista lista;
    criarLista(&lista);

    inserir_fim(&lista, 2);
    inserir_inicio(&lista, 6);    /* 6 <-> 2 */
    inserir_fim(&lista, 14);      /* 6 <-> 2 <-> 14 */
    inserir_fim(&lista, 17);      /* 6 <-> 2 <-> 14 <-> 17 */

    imprimirFrente(&lista);
    imprimirTras(&lista);

    remover(&lista, 2);          /* 6 <-> 14 <-> 17 */
    imprimirFrente(&lista);

    liberar(&lista);
    return 0;
}
```

**Saída esperada:**

```
NULL <-> 6 <-> 2 <-> 14 <-> 17 <-> NULL
NULL <-> 17 <-> 14 <-> 2 <-> 6 <-> NULL
NULL <-> 6 <-> 14 <-> 17 <-> NULL
```

### Exercícios

1. Faça uma função que exclua o elemento do início da lista, atualizando corretamente `inicio` (e `fim`, se a lista ficar vazia);
2. Faça uma função que exclua o elemento do fim da lista em `O(1)`;
3. Faça uma função que insira um novo valor **antes** de um nó dado (ponteiro para o nó), em `O(1)`;
4. Faça uma função que insira um novo valor **depois** de um nó dado (ponteiro para o nó), em `O(1)`;
5. Faça uma função que imprima a lista do fim para o início **sem usar o ponteiro `fim`** (dica: percorra até o último nó e volte usando `ant`);
6. Faça uma função que receba um número e remova **todas** as ocorrências dele na lista;
7. Faça uma função que verifique se os valores da lista formam um **palíndromo** (ex.: `1 ⇄ 2 ⇄ 3 ⇄ 2 ⇄ 1`), comparando um ponteiro que anda para frente com outro que anda para trás.

**Desafio:** Implementar uma lista duplamente encadeada ordenada e aplicar nela as operações de criação, inserção, remoção e impressão dos valores (nos dois sentidos).

## Listas circulares

Uma lista circular é uma estrutura de dados dinâmica em que **o último nó aponta de volta para o primeiro**, formando um ciclo. Assim, **não existe `NULL` ao final da lista**: se o percurso não for controlado, ele nunca termina.

As listas circulares podem ser:

- **simplesmente encadeadas circulares**: cada nó tem um ponteiro `prox`, e o `prox` do último nó aponta para o primeiro;
- **duplamente encadeadas circulares**: cada nó tem `prox` e `ant`; o `prox` do último aponta para o primeiro e o `ant` do primeiro aponta para o último.

Essa estrutura é recomendada quando os dados precisam ser percorridos **repetidamente, de forma cíclica**, como em:

- escalonamento de processos por *round-robin* (cada processo recebe uma fatia de tempo, e, ao final da fila, volta-se ao primeiro);
- playlists em modo de repetição;
- jogos de turnos, em que a vez dos jogadores se repete;
- buffers circulares.

### Estrutura da lista

O nó de uma lista circular simples é **idêntico** ao de uma lista simples; o que muda é a forma como os nós são ligados:

```c
typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *fim;    /* aponta para o último nó; fim->prox é o primeiro */
} Lista_circular;
```

> **Por que guardar o ponteiro para o último nó, e não para o primeiro?** Como `fim->prox` é o primeiro nó, com **um único ponteiro** temos acesso às duas extremidades. Dessa forma, inserir no início **e** no fim da lista é `O(1)`, sem a necessidade de manter dois ponteiros.

### Representação conceitual

Uma lista circular com os elementos 6 → 2 → 14 → 17 é representada assim:

```
        ┌───────────────────────────────────────┐
        ▼                                       │
     ┌──────┐    ┌──────┐    ┌──────┐    ┌──────┴┐
     │  6   │───▶│  2   │───▶│  14  │───▶│  17   │
     └──────┘    └──────┘    └──────┘    └───────┘
     (início)                              ▲
                                           │
                                          fim
```

O ponteiro `fim` aponta para o último nó (17), e o `prox` desse nó aponta para o primeiro (6). Em uma lista com **um único nó**, o `prox` aponta para o próprio nó. Em uma lista vazia, `fim == NULL`.

### Vantagens e desvantagens de listas circulares

**1. Vantagens**
- Permitem percorrer a lista inteira a partir de **qualquer nó**, sem precisar voltar ao início;
- Com o ponteiro `fim`, inserir no início e no fim é `O(1)`;
- Ideal para processos cíclicos e repetitivos;
- Não há ponteiro `NULL` ao final da lista.

**2. Desvantagens**
- Risco de **laço infinito** se a condição de parada do percurso não for bem definida;
- Os casos especiais (lista vazia, lista com um único nó) exigem atenção redobrada;
- Não possuem acesso direto por índice;
- Para a lista simples circular, não é possível voltar ao nó anterior sem percorrer a lista.

### Operações fundamentais

1. Criar uma lista vazia;
2. Inserir no início;
3. Inserir no final;
4. Buscar um elemento;
5. Remover um elemento;
6. Percorrer/imprimir (uma volta completa);
7. Liberar memória

**Atenção ao percurso:** como não há `NULL`, o laço de repetição deve parar quando o percurso **voltar ao nó de partida**. Por isso, usa-se `do { ... } while (aux != inicio);`, que garante que o primeiro nó seja visitado pelo menos uma vez.

### Exemplo prático

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *fim;
} Lista_circular;

/* 1. Criar lista vazia */
void criarLista(Lista_circular *l) {
    l->fim = NULL;
}

/* 2. Inserir no início: O(1) */
void inserir_inicio(Lista_circular *l, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }
    novo->valor = valor;

    if (l->fim == NULL) {            /* lista vazia: o nó aponta para si mesmo */
        novo->prox = novo;
        l->fim = novo;
    } else {
        novo->prox = l->fim->prox;   /* novo aponta para o antigo primeiro */
        l->fim->prox = novo;         /* o último passa a apontar para o novo primeiro */
    }
}

/* 3. Inserir no final: O(1) */
void inserir_fim(Lista_circular *l, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }
    novo->valor = valor;

    if (l->fim == NULL) {
        novo->prox = novo;
    } else {
        novo->prox = l->fim->prox;   /* novo aponta para o primeiro */
        l->fim->prox = novo;         /* antigo último aponta para o novo */
    }
    l->fim = novo;                   /* o novo nó é o último */
}

/* 4. Buscar: retorna o nó encontrado ou NULL */
No* buscar(Lista_circular *l, int valor) {
    if (l->fim == NULL) {
        return NULL;
    }
    No *inicio = l->fim->prox;
    No *aux = inicio;
    do {
        if (aux->valor == valor) {
            return aux;
        }
        aux = aux->prox;
    } while (aux != inicio);
    return NULL;
}

/* 5. Remover a primeira ocorrência de um valor. Retorna 1 se removeu, 0 caso contrário */
int remover(Lista_circular *l, int valor) {
    if (l->fim == NULL) {
        return 0;                    /* lista vazia */
    }

    No *ant = l->fim;
    No *atual = l->fim->prox;        /* começa pelo primeiro nó */

    do {
        if (atual->valor == valor) {
            if (atual == ant) {      /* único nó da lista */
                l->fim = NULL;
            } else {
                ant->prox = atual->prox;
                if (atual == l->fim) {
                    l->fim = ant;    /* removeu o último: o anterior passa a ser o fim */
                }
            }
            free(atual);
            return 1;
        }
        ant = atual;
        atual = atual->prox;
    } while (ant != l->fim);         /* para depois de examinar o último nó */

    return 0;
}

/* 6. Percorrer/imprimir: uma volta completa */
void imprimir(Lista_circular *l) {
    if (l->fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    No *inicio = l->fim->prox;
    No *aux = inicio;
    do {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    } while (aux != inicio);
    printf("(volta ao inicio)\n");
}

/* 7. Liberar memória: primeiro "quebra" o círculo, depois libera como lista simples */
void liberar(Lista_circular *l) {
    if (l->fim == NULL) {
        return;
    }
    No *aux = l->fim->prox;
    l->fim->prox = NULL;             /* quebra o ciclo */
    while (aux != NULL) {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    l->fim = NULL;
}

int main() {
    Lista_circular lista;
    criarLista(&lista);

    inserir_fim(&lista, 2);
    inserir_inicio(&lista, 6);        /* 6 -> 2 */
    inserir_fim(&lista, 14);          /* 6 -> 2 -> 14 */
    inserir_fim(&lista, 17);          /* 6 -> 2 -> 14 -> 17 */
    imprimir(&lista);

    remover(&lista, 17);             /* remove o último: 6 -> 2 -> 14 */
    remover(&lista, 6);              /* remove o primeiro: 2 -> 14 */
    imprimir(&lista);

    liberar(&lista);
    return 0;
}
```

**Saída esperada:**

```
6 -> 2 -> 14 -> 17 -> (volta ao inicio)
2 -> 14 -> (volta ao inicio)
```

### Lista duplamente circular

Na lista duplamente circular, o nó é o mesmo da lista duplamente encadeada (`valor`, `prox` e `ant`), mas as pontas são ligadas entre si:

- o `prox` do último nó aponta para o primeiro;
- o `ant` do primeiro nó aponta para o último.

```c
typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;

typedef struct {
    No *inicio;   /* inicio->ant é o último nó */
} ListaDC;
```

```
      ┌────────────────────────────────────────────────┐
      │  ┌─────────────────────────────────────────┐   │
      ▼  ▼                                         │   │
   ┌──────┐ ⇄ ┌──────┐ ⇄ ┌──────┐ ⇄ ┌──────┐       │   │
   │  6   │   │  2   │   │  14  │   │  17  │───────┘   │
   └──┬───┘   └──────┘   └──────┘   └──────┘           │
      └─────────────────────────────────────────────────┘
```

Como `inicio->ant` é o último nó, tanto o início quanto o fim são acessíveis em `O(1)` com apenas um ponteiro. O trecho abaixo mostra a inserção no fim:

```c
void inserir_fim(ListaDC *l, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }
    novo->valor = valor;

    if (l->inicio == NULL) {            /* lista vazia: o nó aponta para si mesmo nos dois sentidos */
        novo->prox = novo;
        novo->ant = novo;
        l->inicio = novo;
    } else {
        No *ultimo = l->inicio->ant;
        novo->prox = l->inicio;         /* o novo aponta para o primeiro */
        novo->ant = ultimo;             /* e para o antigo último */
        ultimo->prox = novo;
        l->inicio->ant = novo;          /* o primeiro passa a ter o novo como anterior */
    }
}
```

> Para **inserir no início**, o procedimento é o mesmo; a única diferença é atualizar também `l->inicio = novo` ao final.

### Exercícios

1. Faça uma função que **conte** a quantidade de nós de uma lista circular simples;
2. Faça uma função que exclua o elemento do início da lista circular simples em `O(1)`;
3. Faça uma função que exclua o elemento do fim da lista circular simples (dica: é preciso encontrar o penúltimo nó; qual é a complexidade?);
4. Faça uma função que receba um número `k` e **avance** o ponteiro `fim` `k` posições, simulando uma rotação da lista (por exemplo, `6 → 2 → 14 → 17` rotacionada em 1 posição vira `2 → 14 → 17 → 6`);
5. Faça uma função que verifique se uma lista (com possível `NULL` no final) é **circular**. Dica: percorra a lista com dois ponteiros, um avançando de um em um nó e outro de dois em dois; se eles se encontrarem, há um ciclo;
6. Implemente a versão de inserção no início e remoção da **lista duplamente circular**;
7. **Escalonador round-robin:** crie uma lista circular em que cada nó guarda o identificador de um processo e o tempo restante de execução (`struct`). A cada rodada, o processo da vez executa por um quantum de 2 unidades de tempo; se terminar, é removido da lista; caso contrário, passa-se ao próximo. Repita até a lista ficar vazia.

**Desafio:** Resolver o **Problema de Josefo**: `n` pessoas estão em círculo e, partindo da primeira, a cada `k`-ésima pessoa contada é eliminada, até restar apenas uma. Utilize uma lista circular para simular o processo e imprimir a ordem de eliminação e a pessoa sobrevivente.
