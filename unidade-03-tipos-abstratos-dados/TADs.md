# Unidade Temática #3 — Tipos Abstratos de Dados (TADs), Registros e Alocação de Memória


Senhores estudantes,

Esta é a unidade temática #3 da disciplina de Estrutura de Dados, ministrada no curso superior de tecnologia em Sistemas para Internet do Ifac/Campus Rio Branco. Nesta unidade, aprederemos sobre Tipos Abstratos de Dados, `structs` e alocação estática e dinâmica de memório e o uso de ponteiros. Vamos começar pelo último assunto. 


## 📑 Sumário

- [Ponteiros em C e Alocação de Memória](#ponteiros-em-c-e-alocação-de-memoria)
- [Estruturas (`structs`) em C](#estruturas-structs-em-c)
- [Tipos Abstratos de Dados (TADs)](#tipos-abstratos-de-dados-tads)

>> 📅 Quarta-feira, 16/09/2026 

## Ponteiros em C e Alocação de Memória

Todo programa precisa armazenar dados na memória. Em C, é possível trabalhar de duas formas:

- **Alocação Estática**: espaço definido em tempo de compilação (ex.: variáveis comuns e arrays fixos).
- **Alocação Dinâmica**: espaço solicitado e liberado *durante a execução*, quando e quanto o programador quiser.

A alocação dinâmica é fundamental quando:
- não sabe-se o tamanho dos dados com antecedência;
- deseja-se construir estruturas flexíveis (listas, pilhas, filas, árvores, grafos).


### 1. Revisão de ponteiro

Um ponteiro é **uma variável que armazena um endereço de memória**.  Se `x` guarda um valor, um ponteiro pode guardar **o endereço de x**, como na figura abaixo:

![Variáveis e ponteiros](https://github.com/user-attachments/assets/d99f11c5-7ac0-4a80-9694-eb7e99c8d0ea)

Assim, tem-se:
- variável `x` contém o valor 10;
- ponteiro `p` contém o endereço físico 0x61ff0c;
- o endereço físico de memória identificável por p (0x61ff0c) aponta para o local de memória que tem 100. 

> Uma variável do tipo ponteiro, como `p` do exemplo, não pode receber um valor numérico, como 14, mas apenas um endereço físico da memória. O endereço identificável por p, representado por `*p`, pode receber um valor. Nesse caso, diz-se que `p` aponta para o endereço onde está o valor. 



| Elemento | Significa |
|----------|-----------|
| `&x`     | endereço de `x` |
| `p`      | ponteiro que guarda um endereço |
| `*p`     | conteúdo armazenado no endereço apontado |

---

**Declaração**

```c
int *p; // p aponta para um int
float *q; // q aponta para um float
char *texto; // texto aponta para um char
```

**Inicialização**

```c
int x = 10;
int *p = &x;

printf("%d\n", *p);  // imprime 10
```

**Erro comum**

```c
int *p;
*p = 10; // ERRO: p não aponta para nada
```


**Operadores fundamentais**

| Operador | Função |
|----------|-----------|
| `&`     | obtém o endereço de uma variável |
| `*`      | acessa o conteúdo do endereço apontado |

```c
int a = 10; //Declaração de uma variável inteira e atribuição do valor 10
int *p = &a; // p aponta para o endereço de a
*p = *p + 1; // atualiza o valor de *p e, consequentemente de a, para 11
p = p + 1; //Faz p apontar para uma posição na memória seguinte a (diferença de um inteiro)
```


### 2. Alocação Dinâmica em C
Para gerenciar memória dinamicamente, usa-se funções da biblioteca <stdlib.h>:

| Função | O que faz |
|----------|-----------|
| `malloc`     | aloca memória não inicializada |
| `calloc`      | aloca memória zerada |
| `realloc`     | realoca memória já existente |
| `free`      | libera memória |

**malloc**
```c
int *p = malloc(5 * sizeof(int));
```
Aloca espaço para 5 inteiros.

**Atenção**: a memória vem com “lixo”.

**calloc**
```c
int *p = calloc(5, sizeof(int));
```
Faz o mesmo que malloc, porém inicializa tudo com zero.

**realloc**
```c
int *r = realloc(p, 10 * sizeof(int));
```
Redimensiona a memória sem perder os valores anteriores. No exemplo, está realocando o local de memória apontado por `r` para o onde `p` aponta. É desalocado para `p`;

**free**
```c
free(p);
p = NULL;
```
Sempre libere memória que não será mais usada e `p` para a apontar para *NULL*. 


### 3. Erros comuns
| Erro                           | Descrição                      |
| ------------------------------ | ------------------------------ |
| usar ponteiro não inicializado | causa comportamento indefinido |
| acessar memória já liberada    | “dangling pointer”             |
| esquecer `free()`              | **memory leak**                |
| dar `free()` duas vezes        | erro grave de execução         |


>> 📅 Segunda-feira, 21/09/2026
### 4. Ponteiros e Arrays

Arrays “decaem” para ponteiro:

**Vetores e ponteiros**
```c
int numeros_perfeitos[] = {496, 6, 28}; // Declaração de um vetor de tamanho 3
int *p = numeros_perfeitos[0]; // 'p' aponta para o início do vetor, ou seja, para o seu índice 0

printf("%d\n", *p);
*p = *p+1; // Incrementa o índice 0 do vetor em 1
p = p+1; // Faz 'p' apontar para índice 1 do vetor
*p = *(p+1); // Faz o local para o qual p aponta ter o seu valor atualizado para o valor em que *(p+1) aponta. 
// Logo, o vetor fica {497, 28, 28}
```

**Leitura de dados armazenamento em memória dinamicamente alocada**
```c
int i;
int *p = calloc(4,sizeof(int));
for(i=0; i<4; i++){
	scanf("%d", (p+i)); 
}
```
Sobre o scanf, `p` continuará a apontar para o índice 0. O incremento de `i` que faz o dado ser lido em todas as posições, uma de cada vez. Não pode por `&`, pois `(p+1)` já é um endereço, não uma variável.

---
### 5. Pratique:

1. Declare um ponteiro para inteiro e faça-o apontar para uma variável x. Imprima x usando `*p`.

2. Alocar um vetor dinâmico de `n` inteiros, preenchê-lo e, finalmente, imprimi-lo.

3. Reescrever o exercício 2 usando calloc.

4. Redimensionar o vetor usando realloc para o tamanho de `n`.

---

## Estruturas (`structs`) em C

Em muitos programas, precisamos representar *entidades que possuem várias informações relacionadas*.  
Por exemplo: um **aluno** tem `nome`, `idade` e `matrícula` e `CRA`; um **produto** tem `código`, `descrição` e `preço`.

Pode-se armazenar essas informações em variáveis separadas, mas isso rapidamente se torna confuso e difícil de manter.

A linguagem C resolve esse problema com as **estruturas** — também chamadas de registros —, declaradas pela palavra-chave `struct`.

### 1. O que é uma `struct`

Uma `struct` (ou registro) é um **tipo composto**, que agrupa vários dados, podendo ser de diferentes, em uma única entidade lógica.

### 2. Exemplo de `struct`

```c
struct Aluno {
    char nome[50];
    int idade;
    char matricula[20];
    double cra;
};
```
Essa declaração cria um novo tipo de dado, struct Aluno, com três campos:

- nome (cadeia de caracteres);

- idade (inteiro);

- matricula (cadeia de caracteres); e

- cra (double).

### 3. Declaração e uso de `struct`

Para criar uma variável do tipo struct Aluno, faz-se:
```c
struct Aluno a1;
```

Para atribuir um valor: 
```c
strcpy(a1.nome, "Scott Summers");
a1.idade = 17;
strcpy(a1.matricula, "mx95d");
a1.cra = 7.3;
printf("Nome: %s\nIdade: %d\nMatrícula: %s\nCRA: %.2lf\n", a1.nome, a1.idade, a1.matricula, a1.cra);
```

Para acessar os campos:
```c
printf("Nome: %s\nIdade: %d\nMatrícula: %s\nCRA: %.2lf\n", a1.nome, a1.idade, a1.matricula, a1.cra);
```

### 4. Uso do `typedef`

`typedef` é uma palavra-chave em C que cria um *alias*, ou apelido, para um tipo de dado existente, de modo a simplificar a sintaxe para tipos complexos. Ele não cria um novo tipo, mas fornece um nome mais curto ou mais significativo para um tipo já definido, melhorando a legibilidade e a organização do código. 

Por exemplo, pode-se criar um chamado `real` para representar números reais, com
```c
typedef double real;
```

```c
int main(){
    real numero;
    numero = 6.0;
    printf("%.2lf", numero + 4);

    return 0;
}
```

É possível usar `typedef` para simplificar o uso de `struct`, assim:

```c
typedef struct{
    char nome[50];
    int idade;
    char matricula[20];
    double cra;
}Aluno;
```

E na `main` não será mais necessário escrever `struct`:
```c
Aluno a1, a2;
```
### 5. Vetor de `structs`

Pode-se criar arrays de estruturas:
```c
Aluno turma[3];

strcpy(turma[0].nome, "Ana");
turma[0].idade = 18;
strcpy(turma[0].matricula, "an456b");
turma[0].cra = 9.8;

strcpy(turma[1].nome, "Bruno");
turma[1].idade = 20;
strcpy(turma[1].matricula, "br450c");
turma[1].cra = 6.1;

```

**Pratique**
 1. Implemente o código acima;
 2. Faça a leitura dos dados e guarde-os em um vetor;
 3. Crie uma função que imprima os alunos que estão com CRA menores do que 7.0;
 4. Crie uma função que ordene os alunos por CRA, com o maior valor primeiro;
 6. Crie uma função que ordene os alunos por ordem alfabética, de A a Z;
 7. Crie um menu que faça o usuário escolher entre uma das opções de 2 a 6.

---
>> 📅 Quarta-feira-feira, 23/09/2026 

### 6. `struct` dentro de `struct`

Pode-se aninhar estruturas, criando tipos mais complexos:

```c
typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    int idade;
    Data nascimento;
} Pessoa;

```

Como usar: 

```c
Pessoa p;
strcpy(p.nome, "Lucas");
p.idade = 24;
p.nascimento.dia = 10;
p.nascimento.mes = 8;
p.nascimento.ano = 2000;

```

### 7. Ponteiros para `struct`

Um ponteiro para struct permite acessar e modificar dinamicamente estruturas de dados.

```c
Aluno *p;
p = malloc(sizeof(Aluno));

strcpy(p->nome, "Carla");
p->idade = 22;
strcpy(p->matricula, "br450d");
p->cra = 9.1;

printf("%s - %d anos - %.2lf\n", p->nome, p->idade, p->cra);

free(p);

```

**O que é ->? Que tipo de acesso é este?**

1. a1.idade → quando a1 é uma variável normal.

2. p->idade → quando p é um ponteiro para struct.

Lembre-se:
*p->idade é equivalente a (\*p).idade*. Portanto, usar `->` é um atalho para `(*p)`.

### 8. Passar `struct` para funções 

**Passagem por valor**

```c
void exibir(Aluno a) {
    printf("%s - %d anos\n", a.nome, a.idade);
}
```
E na chamada:
```c
exibir(a1);
```

**Passagem por referência**

```c
void exibir(Aluno *p) {
    printf("%s - %d anos\n", p->nome, p->idade);
}
```
E na chamada:
```c
exibir(&a); //Considere `a` uma variável do tipo aluno
```

---

## Tipos Abstratos de Dados (TADs)

### 1. Conceito: 
TAD é uma forma de organizar dados e operações sobre eles, escondendo os detalhes da implementação. Em outros palavras, define o que pode ser feito com os dados (as operações), e não como isso é feito.

### 2. Motivação: 
TAD é uma forma de organizar dados e operações sobre eles, escondendo os detalhes da implementação. Em outros palavras, define o que pode ser feito com os dados (as operações), e não como isso é feito.

Sem TADs, os programas crescem de forma desorganizada, e qualquer alteração em uma parte do código pode quebrar outras.

Com TADs, consegue-se:

- Modularizar o código (dividir em partes independentes);

- Proteger os dados (ocultando detalhes internos);

- Reutilizar código em outros programas;

- Facilitar a manutenção e testes.

### 3. Funcionamento: 

Um TAD tem duas camadas:
- **Interface (ou especificação):** define as operações disponíveis (funções públicas);
- **Implementação:** mostra como os dados e as operações são realmente realizados.

### 4. Exemplos clássicos de TAD
- **Lista:** sequência de elementos acessíveis em posições arbitrárias, com operações como `inserir`, `remover`, `acessar` e `tamanho`;
- **Fila:** conjunto de dados com acesso FIFO (primeiro a entrar, primeiro a sair) e operações para `inserir`, `remover`, `acessar` e `verificar se é vazia`;
- **Pilha:** conjunto de dados com acesso LIFO (último a entrar, primeiro a sair) e operações para `inserir`, `remover` e `verificar se é vazia`.

### 5. Exemplo prático em C: TAD Ponto (x, y)
- Criar uma `struct` que represente um ponto;
- Construir um TAD que representa um ponto no plano cartesiano, tendo como dados as coordenadas `(x, y)`, e as operações para criar ponto, obter `x`do ponto, obter `y`do ponto, calcular a distância entre dois pontos e mover o ponto para uma distância a partir de `x`e `y`.

### 5. Exemplo prático em C: TAD Conta Bancária


### 6. Exemplo prático em C: TAD Conta Bancária (com ponteiros)
Outro exemplo de TAD, que reforça a motivação de **proteger os dados**: um TAD que representa uma conta bancária, tendo como dados `numero` e `saldo`, e as operações para criar a conta, depositar, sacar (com validação de saldo), consultar saldo, imprimir e destruir a conta.
> Nesta versão, todas as operações recebem `Conta *` (ponteiro para a struct), inclusive as que apenas leem os dados — evitando cópias desnecessárias e mantendo a mesma convenção que será usada em listas, pilhas e filas.

**Sem TAD** — nada impede o acesso indevido:
- Criar uma `struct`que represente uma conta bancária, com número da conta e saldo;
- Acesse e manipule diretamente o saldo da conta.

**Interface do TAD Conta**

| Operação         | Assinatura em C                                                           |
| ----------------- | --------------------------------------------------------------------------- |
| Criar conta        | `Conta* criarConta(int numero, double saldoInicial)`                        |
| Depositar          | `void depositar(Conta *c, double valor)`                                    |
| Sacar               | `int sacar(Conta *c, double valor)` — 0 = sucesso, 1 = saldo insuficiente     |
| Consultar saldo     | `double consultarSaldo(Conta *c)`                                            |
| Imprimir conta       | `void imprimirConta(Conta *c)`                                              |
| Destruir conta       | `void destruirConta(Conta *c)` — libera a memória alocada                     |

**Pratique**

1. Implemente o TAD Conta exatamente como mostrado acima.
2. Crie a operação `int transferir(Conta *origem, Conta *destino, double valor)`, reaproveitando `sacar` e `depositar`.
3. Declare um vetor de ponteiros `Conta *banco[5]`, crie 5 contas com `criarConta` e implemente `void imprimirContasComSaldoBaixo(Conta *banco[], int n, double limite)`.
4. Acrescente o campo `char titular[50]` à struct e ajuste `criarConta` (agora recebendo o nome e usando `strcpy`) e `imprimirConta`.
5. Implemente `Conta* buscarConta(Conta *banco[], int n, int numero)`, que devolve o ponteiro da conta com o número procurado, ou `NULL` se não existir.
6. Ao final do programa, percorra o vetor `banco` e chame `destruirConta` para cada conta, evitando *memory leak*.

---

### 7. Encapsulamento real com tipo opaco (`.h` e `.c`)

Até aqui, separar o código em `.h` e `.c` ainda deixava a `struct` visível para quem usa o TAD — bastava incluir o `.h` para acessar `c->saldo` diretamente. É possível impedir esse acesso **em tempo de compilação**, usando um recurso da linguagem C chamado **tipo opaco** (*opaque pointer*).

No `.h`, declara-se apenas que o tipo `Conta` existe, sem dizer do que ele é feito (declaração incompleta). A definição completa da `struct` só aparece dentro do `.c` da implementação, onde ninguém de fora enxerga:

```
// No .h:
typedef struct Conta Conta;   // o compilador sabe que Conta existe,
                               // mas não conhece seus campos nem tamanho

// No .c:
struct Conta {                // definição completa: só existe aqui
    int numero;
    double saldo;
};
```

Quem inclui apenas o `.h` só pode ter um ponteiro para `Conta` (`Conta *c`) e chamar as funções da interface — nunca acessar `c->saldo` diretamente, pois o compilador não sabe que esse campo existe.

**`contabancaria.h`**

```
#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

// Tipo opaco: fora deste .h, ninguém sabe o que existe dentro de "struct Conta"
typedef struct Conta Conta;

Conta* criarConta(int numero, double saldoInicial);
void depositar(Conta *c, double valor);
int sacar(Conta *c, double valor);
double consultarSaldo(Conta *c);
void imprimirConta(Conta *c);
void destruirConta(Conta *c);

#endif
```

> O bloco `#ifndef` / `#define` / `#endif` é o *include guard*: evita que o mesmo `.h` seja processado duas vezes, caso mais de um `.c` o inclua.

**`contabancaria.c`**

```
#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

struct Conta {              // definição completa: só existe aqui
    int numero;
    double saldo;
};

Conta* criarConta(int numero, double saldoInicial) {
    Conta *c = malloc(sizeof(Conta));
    c->numero = numero;
    c->saldo = saldoInicial;
    return c;
}

void depositar(Conta *c, double valor) {
    if (valor > 0) c->saldo = c->saldo + valor;
}

int sacar(Conta *c, double valor) {
    if (valor > c->saldo) return 1;
    c->saldo = c->saldo - valor;
    return 0;
}

double consultarSaldo(Conta *c) { return c->saldo; }

void imprimirConta(Conta *c) {
    printf("Conta %d - Saldo: R$ %.2lf\n", c->numero, c->saldo);
}

void destruirConta(Conta *c) { free(c); }
```

**`main.c`**

Não se "importa" o `.c`: inclui-se apenas o `.h`, com aspas (indicando arquivo do projeto, não biblioteca padrão):

```
#include <stdio.h>
#include "contabancaria.h"

int main() {
    Conta *minhaConta = criarConta(1, 1000.0);

    depositar(minhaConta, 500.0);
    imprimirConta(minhaConta);

    // minhaConta->saldo = -999999;  <- NÃO COMPILA MAIS! Esse é o objetivo.

    if (sacar(minhaConta, 5000.0) == 1) {
        printf("Saque recusado: saldo insuficiente.\n");
    }

    destruirConta(minhaConta);
    return 0;
}
```

**Compilando com múltiplos arquivos**

O `.h` só entrega as assinaturas; quem entra de fato na montagem do executável é o `contabancaria.c`. Por isso os dois `.c` vão juntos no comando do `gcc`:

```
gcc main.c contabancaria.c -o programa
./programa
```

**Demonstração em aula: forçando o erro**

Para a turma sentir a proteção na prática, remova o comentário da linha `minhaConta->saldo = -999999;` no `main.c` e tente compilar novamente. O compilador recusa:

```
main.c: In function 'main':
main.c:8:15: error: invalid use of incomplete typedef 'Conta'
    8 |     minhaConta->saldo = -999999;
      |               ^~
```

> Sem tipo opaco, a proteção do saldo dependia só de `sacar()` ser "bem-comportado" — uma convenção. Com tipo opaco, é o próprio compilador que impede o acesso indevido. Essa é a forma como C se aproxima do encapsulamento que outras linguagens (Java, C++) oferecem nativamente com `private`.
