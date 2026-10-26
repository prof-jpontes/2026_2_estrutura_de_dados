# Unidade Temática #5 — Filas e Pilhas


Senhores estudantes,

Esta é a unidade temática #5 da disciplina de Estrutura de Dados, ministrada no curso superior de tecnologia em Sistemas para Internet do Ifac/Campus Rio Branco. Nesta unidade, estudaremos **filas** e **pilhas**, dois tipos fundamentais de estruturas de dados. 

Para se aprofundar neste roteiro, acesse o livro **Estruturas de dados**: algoritmos, análise da complexidade e implementações em Java e C/C++, de Ascencio e Araújo, disponível na biblioteca virtual do Ifac, acessível por meio do link [https://plataforma.bvirtual.com.br/Acervo/Publicacao/1995](https://plataforma.bvirtual.com.br/Acervo/Publicacao/1995). No livro, estude o capítulo 4. 


## 📑 Sumário

- [Introdução](#introdução)
- [Filas](#filas)
  - [Operações fundamentais](#operações-fundamentais)
  - [Implementação com lista encadeada](#implementação-com-lista-encadeada)
  - [Representação conceitual](#representação-conceitual)
  - [Vantagens e desvantagens](#vantagens-e-desvantagens-de-filas)
  - [Exemplo prático](#exemplo-prático-fila-de-pessoas)
  - [Exercícios](#exercícios-de-filas)
- [Pilhas](#pilhas)
  - [Operações fundamentais](#operações-fundamentais-1)
  - [Implementação com lista encadeada](#implementação-com-lista-encadeada-1)
  - [Representação conceitual](#representação-conceitual-1)
  - [Vantagens e desvantagens](#vantagens-e-desvantagens-de-pilhas)
  - [Exemplo prático 1](#exemplo-prático-1-pilha-de-livros)
  - [Exemplo prático 2](#exemplo-prático-2-verificação-de-expressões-balanceadas)
  - [Exercícios](#exercícios-de-pilhas)
- [Fila × Pilha: comparação](#fila--pilha-comparação)


>> 📅 Segunda-feira, 19/10/2026 

## Introdução

Após compreender listas simplesmente encadeadas, duplamente encadeadas e circulares, é hora de conhecer duas estruturas fundamentais amplamente utilizadas em algoritmos, sistemas operacionais, compiladores, redes e bancos de dados. Essas estruturas são:

- Filas (*queues*); e
- Pilhas (*stacks*).

Ambas podem ser implementadas usando uma abordagem estática, por meio de vetores, mas em aplicações reais são frequentemente implementadas com listas encadeadas, pois isso permite tamanho dinâmico e operações mais eficientes. Neste caso de implementação, tem-se filas e pilhas dinâmicas.

Filas e pilhas são consideradas **listas especializadas**: são listas com **regras de acesso restritas**. Em uma lista comum, é possível inserir, remover e consultar elementos em qualquer posição. Já em filas e pilhas:

- em uma **fila**, os elementos entram por uma extremidade (o fim) e saem pela outra (o início);
- em uma **pilha**, os elementos entram e saem pela mesma extremidade (o topo).

É justamente essa restrição que torna as operações simples e rápidas, em `O(1)`, e que dá a essas estruturas o seu significado. Por isso, **não se acessa o elemento do meio** de uma fila ou de uma pilha: se isso for necessário, a estrutura mais adequada é uma lista.

Em comum, filas e pilhas são lineares e, em caso de implementação dinâmica, essa linearidade é definida pelo ponteiro em um nó que aponta para o próximo.

## Filas

Uma fila é uma estrutura de dados linear que segue o conceito de **FIFO** — *First In, First Out*, ou seja, o *primeiro a entrar é o primeiro a sair*.

São exemplos reais de aplicação de filas:

- Fila de banco;
- fila de impressão;
- processos aguardando execução no sistema operacional; e
- requisições aguardando atendimento em um servidor web.

### Operações fundamentais

- `enfileirar(x)` ou *enqueue(x)*: insere o elemento `x` no final da fila (não existe o conceito de inserir no início da fila);
- `desenfileirar()` ou *dequeue()*: remove o primeiro elemento da fila (o primeiro a ter chegado);
- `frente()` ou *front()*: consulta o primeiro elemento, sem removê-lo; e
- `ehvazia()` ou *isEmpty()*: verifica se a fila é vazia.

Operações auxiliares comuns: `contar()` (quantidade de elementos) e `limpar()` (esvazia a fila, liberando a memória).

### Implementação com lista encadeada

Para que **tanto a inserção quanto a remoção sejam `O(1)`**, recomenda-se manter dois ponteiros:

- `inicio` → primeiro elemento (de onde se remove); e
- `fim` → último elemento (onde se insere).

Assim:

- `enfileirar(x)` insere no fim; e
- `desenfileirar()` remove do início.

> Se mantivéssemos apenas o ponteiro `inicio`, o `enfileirar` precisaria percorrer toda a lista até o último nó, custando `O(n)`.

```c
typedef struct Pessoa {
    char nome[50];
    int idade;
} Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No *prox;
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;
```

Note que o dado (`Pessoa`) é separado do nó (`No`). Dessa forma, o mesmo `No` e as mesmas funções servem para qualquer tipo de dado: basta trocar o conteúdo da `struct` do dado.

### Representação conceitual

Uma fila com as pessoas Ana, Bia e Caio, que chegaram nessa ordem, é representada assim:

```
     inicio                               fim
       │                                   │
       ▼                                   ▼
  ┌─────────┐     ┌─────────┐     ┌─────────┐
  │   Ana   │────▶│   Bia   │────▶│  Caio   │────▶ NULL
  └─────────┘     └─────────┘     └─────────┘
  (sai primeiro)                  (entrou por último)
```

Ao desenfileirar, `inicio` passa a apontar para Bia. Ao enfileirar Duda, `fim->prox` aponta para o novo nó e `fim` passa a apontar para Duda.

**Casos especiais a tratar:**

- **Enfileirar em fila vazia:** `inicio` e `fim` passam a apontar para o novo nó;
- **Desenfileirar o último elemento:** a fila fica vazia, e é preciso fazer `fim = NULL` também (senão `fim` ficaria apontando para memória já liberada);
- **Desenfileirar em fila vazia:** deve ser tratado (não há o que remover).

### Vantagens e desvantagens de filas

**1. Vantagens**
- Estrutura simples e de comportamento previsível;
- Inserção e remoção em `O(1)`;
- Respeita a ordem de chegada (justiça no atendimento);
- Cresce e diminui conforme necessário.

**2. Desvantagens**
- Acesso restrito: só se consulta o primeiro elemento;
- Buscar um elemento qualquer exige percorrer a fila, em `O(n)`;
- Remover um elemento do meio da fila foge ao conceito da estrutura.

### Exemplo prático: fila de pessoas

O programa abaixo, que será desenvolvido em sala de aula, implementa uma fila dinâmica de pessoas.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    char nome[50];
    int idade;
} Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No *prox;
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;

Fila *criar_fila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

Pessoa criar_pessoa(char nome[], int idade) {
    Pessoa nova;
    snprintf(nova.nome, sizeof(nova.nome), "%s", nome);  /* cópia segura: não ultrapassa 50 bytes */
    nova.idade = idade;
    return nova;
}

/* enfileirar: insere no fim, O(1) */
void enfileirar(Fila *f, Pessoa p) {
    No *novo = (No*) malloc(sizeof(No));
    novo->pessoa = p;
    novo->prox = NULL;

    if (f->inicio == NULL) {        /* fila vazia: o novo nó é também o primeiro */
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

/* desenfileirar: remove do início, O(1) */
void desenfileirar(Fila *f) {
    if (f->inicio != NULL) {
        No *aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
        if (f->inicio == NULL) {    /* a fila ficou vazia */
            f->fim = NULL;
        }
    }
}

int ehvazia(Fila *f) {
    if (f->inicio == NULL) return 1;
    else return 0;
}

int contar(Fila *f) {
    int cont = 0;
    No *aux = f->inicio;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void imprimir(Fila *f) {
    No *aux = f->inicio;
    while (aux != NULL) {
        printf("{Nome: %s, %d anos}", aux->pessoa.nome, aux->pessoa.idade);
        aux = aux->prox;
        if (aux != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

/* limpar: desenfileira todos os elementos, liberando a memória */
void limpar(Fila *f) {
    while (!ehvazia(f)) {
        desenfileirar(f);
    }
}

int main() {
    Fila *fila = criar_fila();

    Pessoa p = criar_pessoa("De Arrascaeta", 30);
    enfileirar(fila, p);

    p = criar_pessoa("Jorginho", 35);
    enfileirar(fila, p);

    p = criar_pessoa("Rossi", 32);
    enfileirar(fila, p);

    imprimir(fila);
    printf("Pessoas na fila: %d\n", contar(fila));

    printf("\nApos desenfileirar uma vez:\n");
    desenfileirar(fila);
    imprimir(fila);
    printf("Pessoas na fila: %d\n", contar(fila));

    printf("\nApos limpar:\n");
    limpar(fila);
    imprimir(fila);

    free(fila);     /* libera a própria struct Fila */
    return 0;
}
```

**Saída esperada:**

```
{Nome: De Arrascaeta, 30 anos} -> {Nome: Jorginho, 35 anos} -> {Nome: Rossi, 32 anos}
Pessoas na fila: 3

Apos desenfileirar uma vez:
{Nome: Jorginho, 35 anos} -> {Nome: Rossi, 32 anos}
Pessoas na fila: 2

Apos limpar:

```

**Para discutir em sala:**

1. Por que `desenfileirar` precisa fazer `fim = NULL` quando a fila fica vazia?
2. Qual é a complexidade de `enfileirar`, `desenfileirar` e `contar`? Como fazer `contar` em `O(1)`?
3. Quem libera a memória de cada nó? E a da `struct Fila`?

### Exercícios de filas

#### 🟢 Aquecimento

**1. Frente e tamanho.** Acrescente à fila do exemplo:
   - uma função `frente(Fila *f)` que retorne a pessoa do início da fila **sem removê-la**; e
   - um campo `tamanho` na `struct Fila`, atualizado em `enfileirar` e `desenfileirar`, de modo que `contar` passe a ser `O(1)`.

**2. Gerador de senhas.** Implemente um programa com menu para a recepção de uma clínica:
   1. Retirar senha (enfileira o próximo número, começando em 1);
   2. Chamar próxima senha (desenfileira e exibe: *"Senha 3, compareça ao guichê"*);
   3. Ver fila de espera;
   0. Sair.

   Trate o caso de chamar uma senha quando a fila está vazia.

#### 🟡 Prática

**3. Fila de banco com tempos de atendimento.** Considere que não há prioridades e que há um único caixa. Cada cliente tem `senha`, `chegada` (instante em que chegou) e `duracao` (tempo do atendimento), ambos em minutos. Simule o atendimento (sem tempo real, apenas somando os valores) e calcule:
   - o **tempo médio de espera na fila**: média de (início do atendimento − chegada);
   - o **tempo médio para finalizar o atendimento**: média de (fim do atendimento − chegada).

   *Teste com a entrada abaixo:*

   | Cliente | Chegada | Duração | Início | Fim | Espera | Total |
   |---------|---------|---------|--------|-----|--------|-------|
   | A       | 0       | 5       | 0      | 5   | 0      | 5     |
   | B       | 1       | 3       | 5      | 8   | 4      | 7     |
   | C       | 2       | 4       | 8      | 12  | 6      | 10    |

   Resultado esperado: espera média ≈ **3,33** min; tempo médio para finalizar ≈ **7,33** min.

   > *Dica:* o início do atendimento de um cliente é o maior valor entre a sua chegada e o fim do atendimento do cliente anterior.

**4. Fila de impressão.** Cada documento tem `nome` e `paginas`. A impressora leva 2 segundos por página. Enfileire vários documentos, processe a fila e, a cada documento, mostre o instante em que ele terminou de ser impresso (*"relatorio.pdf: 12 páginas, concluído em 24 s"*). Ao final, informe o tempo total.

**5. Batata quente.** Um grupo de pessoas forma uma roda e passa uma "batata" de mão em mão. Simule isso com uma fila: a cada rodada, faça `k` passes (desenfileire a pessoa da frente e a enfileire de volta no fim); depois, a pessoa que estiver na frente é **eliminada** (desenfileirada e não volta). Repita até sobrar um só participante.

   *Teste:* `Ana, Bia, Caio, Duda, Edu`, com `k = 3`.
   Ordem de eliminação esperada: **Duda, Caio, Edu, Bia**. Vencedora: **Ana**.

**6. Atendimento preferencial.** Usando a `struct Pessoa` do exemplo, altere `enfileirar` para que pessoas com **60 anos ou mais** entrem na fila logo depois do último preferencial que já está nela, e antes de todos os demais (os demais continuam entrando no fim). Insira `Ana (25)`, `Bruno (70)`, `Carla (40)`, `Dora (65)` e imprima a fila.
   - Resultado esperado: `Bruno -> Dora -> Ana -> Carla`.
   - Discuta: essa estrutura ainda é FIFO? (Pesquise o conceito de **fila de prioridade**.)

#### 🔴 Desafio (fazer após estudar pilhas, na próxima seção)

**7. Inverter uma fila.** Use uma pilha auxiliar (veja a próxima seção) para inverter a ordem dos elementos de uma fila.

**9. Fila com duas pilhas.** Implemente `enfileirar` e `desenfileirar` usando **apenas duas pilhas** (sem usar nenhuma lista ou vetor diretamente). Qual é o custo no pior caso de cada operação?

## Pilhas

Uma pilha é uma estrutura de dados linear que segue o princípio **LIFO** — *Last In, First Out*, ou seja, o *último a entrar é o primeiro a sair*.

São exemplos reais de aplicação de pilhas:

- Uma pilha de pratos a serem lavados na pia após um churrasco de família;
- uma pilha de livros a serem lidos, colocados sobre uma escrivaninha na ordem de compra; e
- a navegação do navegador de internet, referente ao botão "voltar".

### Operações fundamentais

- `empilhar(x)` ou *push(x)*: insere o elemento `x` no topo da pilha (não existe o conceito de inserir na parte de baixo da pilha);
- `desempilhar()` ou *pop()*: remove e retorna o elemento do topo;
- `topo()` ou *top()*: retorna o elemento do topo sem removê-lo; e
- `ehvazia()` ou *isEmpty()*: verifica se a pilha está vazia.

### Implementação com lista encadeada

Uma pilha pode ser implementada com uma lista simplesmente encadeada, onde o topo da pilha corresponde ao início da lista:

- `empilhar` → insere no início; e
- `desempilhar` → remove do início.

Essa escolha reduz o custo das operações para `O(1)`. Veja que **não é necessário um ponteiro para o fim**: toda a atividade acontece em uma única extremidade, o topo.

```c
typedef struct Livro {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
} Livro;

typedef struct No {
    Livro livro;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;
```

### Representação conceitual

Uma pilha em que foram empilhados, nessa ordem, *Olhos prateados*, *O código da Vinci* e *O hobbit* é representada assim:

```
   topo
    │
    ▼
┌──────────┐     ┌──────────────────┐     ┌──────────────────┐
│ O hobbit │────▶│ O codigo da Vinci│────▶│ Olhos prateados  │────▶ NULL
└──────────┘     └──────────────────┘     └──────────────────┘
(sai primeiro)                            (entrou primeiro,
                                           sai por último)
```

Ao desempilhar, `topo` passa a apontar para *O código da Vinci*. Ao empilhar um novo livro, ele se torna o novo `topo`, apontando para o antigo.

**Atenção:** desempilhar em uma pilha vazia é um erro clássico (*stack underflow*). Sempre verifique `ehvazia()` antes de remover ou consultar o topo.

### Vantagens e desvantagens de pilhas

**1. Vantagens**
- Estrutura simples;
- Operações rápidas (`O(1)`);
- Ótima para cenários de retrocesso (*backtracking*);
- Cresce e diminui conforme necessário.

**2. Desvantagens**
- Acesso restrito: só se alcança o elemento do topo;
- Para chegar a um elemento do fundo, é preciso desempilhar todos os que estão acima;
- Buscar um elemento qualquer é `O(n)`.

**Aplicações práticas:**

- Funções recursivas (pilha de execução do programa);
- Checagem de expressões (parênteses balanceados);
- Desfazer/Refazer em editores de texto;
- Histórico de navegação (botão "voltar"); e
- Algoritmos de busca em profundidade.

### Exemplo prático 1: pilha de livros

O programa abaixo, que será desenvolvido em sala de aula, implementa uma pilha dinâmica de livros.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Livro {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
} Livro;

typedef struct No {
    Livro livro;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

Pilha *criar_pilha() {
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

Livro criar_livro(char titulo[], char autor[], int ano) {
    Livro novo;
    snprintf(novo.titulo, sizeof(novo.titulo), "%s", titulo);   /* cópia segura */
    snprintf(novo.autor, sizeof(novo.autor), "%s", autor);
    novo.ano_publicacao = ano;
    return novo;
}

int ehvazia(Pilha *p) {
    if (p->topo == NULL) return 1;
    return 0;
}

/* empilhar: insere no topo (início da lista), O(1) */
void empilhar(Livro l, Pilha *p) {
    No *novo = (No*) malloc(sizeof(No));
    novo->livro = l;
    novo->prox = p->topo;
    p->topo = novo;
}

/* desempilhar: remove o topo, O(1) */
void desempilhar(Pilha *p) {
    if (ehvazia(p)) {                       /* evita acessar NULL (stack underflow) */
        printf("Pilha vazia: nada a desempilhar.\n");
        return;
    }
    No *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
}

void imprimir(Pilha *p) {
    No *aux = p->topo;
    while (aux != NULL) {
        printf("Titulo: %s, de %s, publicado em %d\n",
               aux->livro.titulo, aux->livro.autor, aux->livro.ano_publicacao);
        if (aux->prox != NULL) printf("\t\t\t\\/\n");
        aux = aux->prox;
    }
}

int contar(Pilha *p) {
    No *aux = p->topo;
    int cont = 0;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

/* limpar: desempilha tudo, liberando a memória */
void limpar(Pilha *p) {
    while (!ehvazia(p)) {
        desempilhar(p);
    }
}

int main() {
    Pilha *pilha = criar_pilha();

    Livro livro = criar_livro("Olhos prateados", "Scott Cawthon", 2016);
    empilhar(livro, pilha);

    livro = criar_livro("O codigo da Vinci", "Dan Brown", 2003);
    empilhar(livro, pilha);

    livro = criar_livro("O hobbit", "J.R.R Tolkien", 1937);
    empilhar(livro, pilha);

    imprimir(pilha);
    printf("A pilha contem %d livro(s)\n", contar(pilha));

    printf("\nApos desempilhar duas vezes:\n");
    desempilhar(pilha);
    desempilhar(pilha);
    imprimir(pilha);
    printf("A pilha contem %d livro(s)\n", contar(pilha));

    limpar(pilha);
    free(pilha);
    return 0;
}
```

**Saída esperada:**

```
Titulo: O hobbit, de J.R.R Tolkien, publicado em 1937
			\/
Titulo: O codigo da Vinci, de Dan Brown, publicado em 2003
			\/
Titulo: Olhos prateados, de Scott Cawthon, publicado em 2016
A pilha contem 3 livro(s)

Apos desempilhar duas vezes:
Titulo: Olhos prateados, de Scott Cawthon, publicado em 2016
A pilha contem 1 livro(s)
```

**Para discutir em sala:**

1. O livro impresso primeiro é o último que foi empilhado. Por quê?
2. O que acontece se chamarmos `desempilhar` mais vezes do que o número de livros empilhados? Teste, com e sem a verificação de `ehvazia`.
3. Por que a pilha não precisa de um ponteiro para o fim?

### Exemplo prático 2: verificação de expressões balanceadas

Um dos usos clássicos de pilhas é verificar se os delimitadores `( )`, `[ ]` e `{ }` de uma expressão estão **balanceados**, isto é, se cada abertura tem o seu fechamento correspondente, na ordem correta. Compiladores e editores de código fazem esse tipo de verificação o tempo todo.

**Algoritmo:**

1. Percorra a expressão caractere por caractere;
2. Se encontrar uma **abertura** (`(`, `[` ou `{`), **empilhe**-a;
3. Se encontrar um **fechamento** (`)`, `]` ou `}`), o topo da pilha deve ser a abertura **correspondente**; se for, desempilhe; senão, a expressão **não está balanceada**;
4. Os demais caracteres (números, operadores, letras) são ignorados;
5. Ao final, a pilha deve estar **vazia**. Se sobrou alguma abertura, a expressão não está balanceada.

**Exemplo:** acompanhe a expressão `{[(a+b)*c]-d}`:

| Caractere | Ação                         | Pilha (topo à esquerda) |
|-----------|------------------------------|-------------------------|
| `{`       | empilha                      | `{`                     |
| `[`       | empilha                      | `[ {`                   |
| `(`       | empilha                      | `( [ {`                 |
| `a+b`     | ignora                       | `( [ {`                 |
| `)`       | topo é `(`: desempilha       | `[ {`                   |
| `*c`      | ignora                       | `[ {`                   |
| `]`       | topo é `[`: desempilha       | `{`                     |
| `-d`      | ignora                       | `{`                     |
| `}`       | topo é `{`: desempilha       | vazia                   |

Ao final, a pilha está vazia: a expressão **está balanceada**.

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No {
    char c;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

Pilha *criar_pilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int is_empty(Pilha *p) {
    if (p->topo == NULL) return 1;
    return 0;
}

void push(Pilha *p, char c) {
    No *novo = (No*) malloc(sizeof(No));
    novo->c = c;
    novo->prox = p->topo;
    p->topo = novo;
}

/* Desempilha somente se o topo for o caractere esperado.
   Retorna 1 se desempilhou e 0 caso contrário (pilha vazia ou topo diferente). */
int pop(Pilha *p, char esperado) {
    if (p->topo != NULL && p->topo->c == esperado) {
        No *aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
        return 1;
    }
    return 0;
}

int verificar(char expressao[], Pilha *p) {
    int i;
    int tam = strlen(expressao);     /* calculado uma única vez, fora do laço */

    for (i = 0; i < tam; i++) {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            push(p, expressao[i]);
        } else if (expressao[i] == ')') {
            if (pop(p, '(') == 0) return 0;
        } else if (expressao[i] == '}') {
            if (pop(p, '{') == 0) return 0;
        } else if (expressao[i] == ']') {
            if (pop(p, '[') == 0) return 0;
        }
    }
    return is_empty(p);              /* sobrou abertura sem fechamento? */
}

void clear(Pilha *p) {
    No *aux;
    while (p->topo != NULL) {
        aux = p->topo;               /* guarda o nó atual ANTES de avançar o topo */
        p->topo = p->topo->prox;
        free(aux);
    }
}

int main() {
    Pilha *p = criar_pilha();
    char expressao[500];

    printf("Escreva uma expressao numerica sem espacos: \n");
    scanf("%499s", expressao);       /* %499s limita a leitura ao tamanho do vetor */

    if (verificar(expressao, p)) printf("A expressao esta balanceada.\n");
    else printf("A expressao nao esta balanceada.\n");

    clear(p);
    free(p);
    return 0;
}
```

**Testes sugeridos:**

| Entrada            | Resultado          | Por quê                                    |
|--------------------|--------------------|--------------------------------------------|
| `(2+3)*[4-1]`      | balanceada         | todos os pares fecham na ordem correta     |
| `{[(a+b)*c]-d}`    | balanceada         | aninhamento correto                        |
| `((2+3)`           | não balanceada     | sobrou um `(` na pilha                     |
| `2+3)`             | não balanceada     | `)` sem `(` correspondente (pilha vazia)   |
| `(2+3]`            | não balanceada     | o topo é `(`, mas o fechamento é `]`       |

**Para discutir em sala:**

1. Por que a pilha é a estrutura ideal para esse problema? (Pense no aninhamento: o último delimitador aberto é o primeiro que precisa ser fechado.)
2. Por que não basta contar a quantidade de aberturas e fechamentos?
3. Observe que `verificar` pode retornar `0` no meio do percurso. Como garantimos que a memória da pilha seja liberada mesmo assim?

### Exercícios de pilhas

#### 🟢 Aquecimento

**1. Topo e desempilhar com retorno.** Na pilha de livros, implemente:
   - `topo(Pilha *p)`: retorna o livro do topo sem removê-lo;
   - uma versão de `desempilhar` que **retorne** o livro removido (e uma forma de sinalizar que a pilha estava vazia).

**2. Inverter palavra.** Leia uma palavra, empilhe cada caractere e, depois, desempilhe todos para formar a palavra invertida. Exemplo: `ifac` → `cafi`.

**3. Decimal para binário.** Converta um número inteiro positivo para binário dividindo sucessivamente por 2 e **empilhando os restos**. Ao desempilhar, os restos saem na ordem correta.
   - Exemplo: `13` → `1101`.

#### 🟡 Prática

**4. Palíndromo com pilha e fila.** Uma palavra é um palíndromo se é igual à sua inversa (`arara`, `ovo`, `radar`). Empilhe e enfileire os caracteres da palavra e, a seguir, compare, um a um, o que sai da pilha com o que sai da fila. Se todos forem iguais, é palíndromo.
   - Por que essa comparação funciona? O que cada estrutura entrega primeiro?

**5. Verificador de expressões turbinado.** Melhore o programa de expressões balanceadas:
   - (a) aceite expressões **com espaços**, usando `fgets` no lugar de `scanf("%s")`;
   - (b) informe **por que** e **onde** a expressão está errada, exibindo a posição do caractere (a partir de 1):
     - `(2+3]` → *"Erro na posição 5: esperava `)`, mas encontrou `]`"*;
     - `2+3)` → *"Erro na posição 4: `)` sem abertura correspondente"*;
     - `((2+3)` → *"Erro: o `(` da posição 1 não foi fechado"*.

   > *Dica:* para informar a posição do `(` não fechado, a pilha pode guardar, além do caractere, o índice em que ele apareceu.

**6. Histórico de navegação.** Simule o "voltar" e o "avançar" de um navegador usando **duas pilhas** (`voltar` e `avancar`) e uma variável `paginaAtual`. Comandos:
   - `visitar <site>`: empilha a página atual em `voltar`, define a nova página atual e **esvazia** `avancar`;
   - `voltar`: empilha a página atual em `avancar` e retorna ao topo de `voltar`;
   - `avancar`: faz o inverso do `voltar`.

   *Teste:* `visitar ifac.edu.br` → `visitar google.com` → `visitar youtube.com` → `voltar` → `voltar` → `avancar`. A página atual deve ser `google.com`.
   - Por que `visitar` precisa esvaziar a pilha `avancar`?

**7. Desfazer e refazer.** Implemente um mini editor de texto de linha de comando que mantém um texto e aceita:
   - `escrever <palavra>`: acrescenta a palavra ao texto;
   - `desfazer`: remove a última palavra escrita;
   - `refazer`: reinsere a última palavra desfeita;
   - `mostrar`: exibe o texto.

   Use duas pilhas de palavras. Escrever uma nova palavra deve invalidar o "refazer".

**8. Calculadora pós-fixa (RPN).** Na notação pós-fixa, o operador vem depois dos operandos, e não são necessários parênteses. Avalie expressões lidas com números separados por espaço, usando uma **pilha de inteiros**: ao ler um número, empilhe; ao ler um operador, desempilhe dois operandos, calcule e empilhe o resultado.
   - `8 2 / 3 +` → `7`
   - `5 1 2 + 4 * + 3 -` → `14`

   > Atenção à ordem dos operandos: em `8 2 /`, o primeiro a sair da pilha é o `2` (divisor).

#### 🔴 Desafio

**9. Torre de Hanói.** Implemente o jogo com **três pilhas** (as hastes A, B e C) e `n` discos numerados. Cada movimento só pode colocar um disco sobre outro **maior**. Primeiro, faça a versão em que o usuário informa os movimentos e o programa valida. Depois, a versão automática, que resolve para um `n` qualquer, imprimindo cada movimento e o estado das três pilhas.

**10. Pilha com mínimo em `O(1)`.** Estenda a pilha de inteiros com uma operação `minimo()` que devolva o menor valor presente na pilha em tempo `O(1)`, sem percorrê-la. Ela deve continuar correta depois de cada `desempilhar`. (Dica: pense em uma segunda pilha auxiliar.)

**11. Calculadora completa.** Converta uma expressão comum (infixa), como `3 + 4 * (2 - 1)`, para a forma pós-fixa usando uma pilha de operadores (algoritmo de *Shunting-yard*, de Dijkstra) e, em seguida, avalie-a com o programa do exercício 8. Respeite a precedência (`*` e `/` antes de `+` e `-`) e os parênteses.

## Fila × Pilha: comparação

| Característica          | Fila                                   | Pilha                                    |
|-------------------------|----------------------------------------|------------------------------------------|
| Princípio               | FIFO (primeiro a entrar, primeiro a sair) | LIFO (último a entrar, primeiro a sair) |
| Inserção                | no **fim**                             | no **topo**                              |
| Remoção                 | no **início**                          | no **topo**                              |
| Ponteiros necessários   | `inicio` e `fim`                       | apenas `topo`                            |
| Inserir / remover       | `O(1)`                                 | `O(1)`                                   |
| Consultar               | `frente()`                             | `topo()`                                 |
| Exemplos                | fila de banco, impressão, processos    | desfazer, "voltar", chamadas de função   |

> **Para pensar:** os dois tipos têm as mesmas operações em `O(1)`, mas resolvem problemas opostos. A fila preserva a **ordem de chegada**; a pilha **inverte** essa ordem. Por isso, "inverter" algo é sempre um bom indício de que uma pilha pode ajudar.
