# Unidade Temática #1 - Revisão e Fundamentos


Senhores estudantes,

Sejam bem-vindos à disciplina de Estrutura de Dados, ministrada no curso superior de tecnologia em Sistemas para Internet do Ifac/Campus Rio Branco. Eu sou o professor Jonas Pontes e estarei convosco nesse componente curricular.

## 📑 Sumário

- [Iniciar](#️-iniciar)
- [Estrutura Sequencial](#estrutura-sequencial)
  - [1. Introdução à Sintaxe C](#1-introdução-à-sintaxe-c) 
  - [2. Entrada e Saída](#2-entrada-e-saída)
  - [3. Operadores Aritméticos](#3-operadores-aritméticos)
  - [4. Casting de Dados](#4-casting-de-dados)
  - [5. Exercícios de Fixação](#-5-exercícios-de-fixação)
- [Desvios Condicionais](#-desvios-condicionais)
  - [1. Estrutura do `if`, `else if` e `else`](#-1-estrutura-do-if-else-if-e-else)
  - [2. Estrutura switch](#-2-estrutura-switch)
  - [3. Exercícios de Fixação](#-3-exercícios-de-fixação)
- [Laços de Repetição](#-laços-de-repetição)
  - [1. Laço `for`](#-1-laço-for)
  - [2. Laço `while`](#-2-laço-while)
  - [3. Laço do/while](#-3-laço-dowhile)
  - [4. Exercícios Práticos](#-4-exercícios-práticos)
- [Estruturas de dados homogêneas — vetores e matrizes](#-estruturas-de-dados-homogêneas--vetores-e-matrizes)
  - [1. Arranjos](#1-arranjos)
  - [2. Declaração de vetores](#2-declaração-de-vetores)
  - [3. Atribuição e leitura de elementos](#3-atribuição-e-leitura-de-elementos)
  - [4. Manipulação de elementos do vetor](#4-manipulação-de-elementos-do-vetor)
  - [5. Matrizes — conceito](#5-matrizes--conceito)
  - [6. Declaração de matrizes](#6-declaração-de-matrizes)
  - [7. Manipulação de matrizes](#7-manipulação-de-matrizes)
  - [8. Exercícios de Fixação](#-8-exercícios-de-fixação)







>> 📅 Segunda-feira, 3/8/2026 

## ▶️ Iniciar

**Se necessário, proceda da seguinte forma:**
> *Faça o download do GCC* — 🔗 [MinGW](https://sourceforge.net/projects/mingw/);

> *Instale o compilador e faça a configuração das variáveis do ambiente*;

```plaintext
1. Clique com o botão direito em "Este Computador" e vá em "Propriedades";
2. Clique em "Configurações Avançadas do Sistema";
3. Clique em "Variáveis de Ambiente".
4. Abra a variável Path e acrescente o caminho "C:\MinGW\bin" (ou o equivalente).
8. Clique em OK.
```

> *Faça o download do [Visual Studio Code](https://code.visualstudio.com/download) e instale-o*.

#### Você tem um ambiente de desenvolvimento configurado 

## 👩🏻‍💻 Primeiro programa em C

---
> *Crie um arquivo com a extensão .c com o nome hello_word e coloque este conteúdo:*
```c
#include <stdio.h>

int main(){
    printf("Hello world\n");
    return 0;
}
```
> Experimente mudar o conteúdo da mensagem

> Agora vamos estudar a anatomia desse programa em C, ou seja, o que cada parte representa.
---

>> 📅 Quarta-feira, 5/8/2026 

Façamos um pequeno diagóstico. Para isso, acesse o juiz online [Beecrowd](https://judge.beecrowd.com) e complete o seu cadastro. Ato contínuo, acesse a disciplina Estrutura de Dados, de ID 016082 (a chave de acesso será dada pelo professor em sala de aula). Dentro da disciplina, acesse a lista de exercícios **Diagóstico**, ID 162198. Faça essa lista. 

Caso não seja possível se inscrever na lista, resolva diretamente na plataforma os seguintes problemas: 
 - [1002    Área do Círculo](https://judge.beecrowd.com/pt/problems/view/1002);
 - [1004    Produto Simples](https://judge.beecrowd.com/pt/problems/view/1004);
 - [1013    O Maior](https://judge.beecrowd.com/pt/problems/view/1013);
 - [1014    Consumo](https://judge.beecrowd.com/pt/problems/view/1014);
 - [1019    Conversão de Tempo](https://judge.beecrowd.com/pt/problems/view/1019);
 - [1024    Criptografia](https://judge.beecrowd.com/pt/problems/view/1024);
 - [1168    LED](https://judge.beecrowd.com/pt/problems/view/1168);
 - [1238    Combinador](https://judge.beecrowd.com/pt/problems/view/1238).

> Após a resolução o término, responda ao formulário de consolidação do diagnóstico, disponível [neste formulário](https://forms.gle/qK7wnaHjJsnibMdWA).

Procederemos com a revisão acompanhada de discussão e correção dos desafios.

---

>> 📅 Segunda-feira, 10/8/2026 

 ## Estrutura Sequencial

### 1. Introdução à sintaxe C

**🎯 Objetivo:** 
  Apresentar a estrutura básica de um programa C e os conceitos fundamentais.

#### Estrutura Básica
- Declaração de funções;
- A função `main` como ponto de entrada;
- Saída formatada em C.


#### Variáveis e Tipos de Dados
- Tipos inteiros: `int`, e `char`;
- Modificadores de `int`: `short`, `long`,`signed` e `unsigned`;
- Tipos de ponto flutuante:   `float` e `double`;
- Modificador de `double`: `long`.
- Tabela de tipos, tamanho do dado (em bits) e intervalo numérico (principais).

| Palavra       | Tipo                          | Tamanho (bits) | Valor Mínimo     | Valor Máximo   |
|---------------|-------------------------------|----------------|------------------|----------------|
| `char`        | Caractere                     | 8              | -128             | 127            |
| `int`         | Inteiro                       | 16             | -32.768          | 32.767         |
| `long int`    | Inteiro                       | 32             | -2.147.483.648   | 2.147.483.647  |
| `float`       | Real com precisão simples     | 32             | 3,4E-38          | 3,4E+38        |
| `double`      | Real com precisão dupla       | 64             | 1,7E-308         | 1,7E+308       |


>> De modo geral, o modificador `long` dobra a capacidade do tipo de dados e o modificador `unsigned` faz a variável ocupar somente valores positivos. Por exemplo, `unsigned int` armazena valores entre 0 e 65.535.

- Declaração e inicialização de variáveis.

#### Exemplo Prático
- Escrever um programa simples que declare variáveis de diferentes tipos.

### 2. Entrada e Saída

**🎯 Objetivo:**
Ensinar como interagir com o usuário, receber dados e exibir informações.

A entrada e a saída de dados em C é feita por meio das funções scanf e e printf, respectivamente. Essas funções pertencem à biblioteca stdio.h.

As funções para entradas e saídas precisam de um código que indica o tipo de dado a ser lido ou apresentado. 

**Códigos utilizados:**


| Código   | Significado |
|----------|-------------|
| %c       | Leitura e escrita de caractere |
| %d       | Leitura e escrita de inteiro em formato decimal |
| %i       | Leitura e escrita de inteiro |
| %x ou %X | Leitura e escrita de número inteiro em hexadecimal |
| %o       | Leitura e escrita de Número inteiro no formato octal |
| %e       | Leitura e escrita de número em notação científica (com `e` minúsculo) |
| %E       | Leitura e escrita de número em notação científica (com `E` maiúsculo) |
| %f       | Leitura e escrita de número de ponto flutuante com precisão simples |
| %lf      | Leitura e escrita de número de ponto flutuante com precisão dupla |
| %zu      | Escrita do tamanho de um dado, ou seja, quando usa-se `sizeof()` |
| %s       | Leitura e escrita de string |
| %p       | Leitura e escrita de endereço de memória |
| %%       | Código usado para mostrar o caracter % |

---

>> 📅 Quarta-feira, 12/8/2026 

### 3. Operadores Aritméticos

**🎯 Objetivo:**  
Apresentar os operadores aritméticos básicos da linguagem C e como utilizá-los em expressões matemáticas.

#### Operadores Disponíveis

| Operador | Descrição        | Exemplo      | Resultado |
|----------|------------------|----------------------|-----------|
| `+`      | Adição            | `5 + 3`              | `8`       |
| `-`      | Subtração         | `5 - 3`              | `2`       |
| `*`      | Multiplicação     | `5 * 3`              | `15`      |
| `/`      | Divisão           | `6 / 3`              | `2`       |
| `%`      | Módulo (resto)    | `5 % 2`              | `1`       |

> ⚠️ A divisão entre inteiros retorna apenas a parte inteira do resultado.

> ℹ️ Quando deseja-se o resultado real, é necessário que o dividendo ou o divisor seja real.


### 4. Operadores Relacionais

| Operador | Significado      | Exemplo (a = 5, b = 10)| 
|----------|------------------|------------------------|
| `==`     | Igual a          | `a == b` → 0           |
| `!=`     | Diferente de     | `a != b` → 1           |
| `>`      | Maior que        | `b > a`  → 1           |
| `<`      | Menor que        | `a < b`  → 1           |
| `>=`     | Maior ou igual a | `a >= b` → 0           |
| `<=`     | Menor ou igual a | `a <= b` → 1           | 

---

#### Exemplos Práticos  
- Criar um programa que solicita dois números ao usuário, realiza a soma e exibe o resultado.

- Criar um programa que calcula e mostre o resultado das quatro operações básicas entre duas variáveis declaradas e inicializadas com valores lidos do teclado.

- Escreva um programa que solicita um número inteiro e mostra:

  - O dobro desse número.

  - A metade (utilizando divisão inteira).

  - O quadrado do número.

- Modifique o programa para que ele aceite números double e observe as diferenças nos resultados das divisões.

**Questões de prova diagnóstica:**
- Problema [1002](https://judge.beecrowd.com/pt/problems/view/1002);
- Problema [1004](https://judge.beecrowd.com/pt/problems/view/1004);
- Problema [1013](https://judge.beecrowd.com/pt/problems/view/1013);
- Problema [1014](https://judge.beecrowd.com/pt/problems/view/1014);
- Problema [1019](https://judge.beecrowd.com/pt/problems/view/1019);

---

### 4. Casting de Dados

#### O que é Casting?
Casting ou conversão de tipo é o processo de transformar um tipo de dado em outro. Essa conversão pode ser:

> **Implícita (automática):** Quando não há perda de dados.

> **Explícita (manual):** Quando há possibilidade de perda de dados ou quando se converte de um tipo maior para um tipo menor.

#### Exemplos de Conversão implícita
```c
int numeroInteiro = 10;
float numeroDecimal = numeroInteiro; // Conversão implícita de int para double
printf("%.1f"numeroDecimal); // Saída: 10.0
```
**Tabela de casting de dados**
# Tabela de Casting de Dados em C

| De | Para | Tipo de conversão | Exemplo | Resultado/Observação |
|---|---|---|---|---|
| `int` | `float` | Implícita | `float x = 10;` | `10.0` |
| `int` | `double` | Implícita | `double x = 10;` | `10.0` |
| `float` | `double` | Implícita | `double x = 10.5f;` | `10.5` |
| `char` | `int` | Implícita | `int x = 'A';` | `65` (ASCII) |
| `int` | `char` | Explícita | `char c = (char) 65;` | `'A'` |
| `float` | `int` | Explícita | `int x = (int) 10.8;` | `10` — parte decimal descartada |
| `double` | `int` | Explícita | `int x = (int) 10.99;` | `10` — parte decimal descartada |
| `double` | `float` | Explícita | `float x = (float) 10.5;` | `10.5f` — possível perda de precisão |
| `int` | `short` | Explícita | `short x = (short) 1000;` | `1000`, se couber no tipo |
| `long` | `int` | Explícita | `int x = (int) 100000L;` | `100000`, se couber |
| `unsigned int` | `int` | Explícita | `int x = (int) u;` | Pode produzir valor inesperado se não couber |
| `int` | `double` | Explícita | `double x = (double) 10;` | `10.0` |
| `char` | `float` | Implícita | `float x = 'A';` | `65.0` |
| `int` | `float` | Explícita | `float x = (float) 10;` | `10.0f` |

Casting implícitos são automáticos, sem a necessidade do programador fazê-lo, como nos exemplos acima. 


#### Conversão Explícita (Casting Manual)

> Escrever um programa que leia quatro números inteiros, calcule e mostra a média entre eles, sem casting explícito.

> Adicionar casting explícito. 

> Tente atribuir um *float* a uma variável inteira sem casting explícito. Isso resultará em erro.

> Observe o exemplo a seguir:

```c
float valorDecimal = 9.7;
int valorInteiro = (int) valorDecimal; // Casting explícito
printf("%d", valorInteiro); // Saída: 9 (parte decimal é descartada)
```
Em casting explícito, um valor não é arredondado; ele é "truncado".

> ⚠️ *Atenção:* Ao converter de double para int, a parte fracionária é perdida!

---

### 📝 5. Exercícios de Fixação

> Exercícios sobre estrutura sequencial: entrada, processamento e saída.

**Exercício 00**
  
Escrever um programa que mostre o nome de uma pessoa e sua idade em 31 de dezembro de um determinado ano. Para isso, leia o nome da pessoa, seu ano de nascimento e o ano para o qual deseje calcular a idade.

**Exercício 01**

Desenvolver um programa que peça a base e altura de um triângulo e calcula a sua área.


**Exercício 02**

Faça um programa para ler dois valores inteiros, e depois mostrar na tela a soma desses números com uma mensagem explicativa, conforme exemplos.

Exemplos:

*Entrada:*
```
10  
30
```

*Saída:*
```
SOMA = 40
```

**Exercício 03**

Faça um programa para ler o valor do raio de um círculo, e depois mostrar o valor da área deste círculo com **quatro casas decimais** conforme exemplos.

Fórmula da área:** `area = π * raio²`  

Considere:** `π = 3.14159`

Exemplo:

*Entrada:*
```
2.00
```

*Saída:*
```
A=12.5664
```

**Exercício 04**

Fazer um programa para ler quatro valores inteiros A, B, C e D. A seguir, calcule e mostre a diferença do produto de A e B pelo produto de C e D segundo a fórmula:  
`DIFERENCA = (A * B - C * D)`

Exemplo:

*Entrada:*
```
5  
6  
7  
8
```

*Saída:*
```
DIFERENCA = -26
```

**Exercício 05**

Fazer um programa que leia o número de um funcionário, seu número de horas trabalhadas, o valor que recebe por hora e calcule o salário desse funcionário. A seguir, mostre o número e o salário do funcionário, com **duas casas decimais**.

Exemplo:

*Entrada:*
```
25  
100  
5.50
```

*Saída:*
```
NUMBER = 25  
SALARY = U$ 550.00
```

**Exercício 06**

Fazer um programa para ler o código de uma peça 1, o número de peças 1, o valor unitário de cada peça 1, o código de uma peça 2, o número de peças 2 e o valor unitário de cada peça 2. Calcule e mostre o valor a ser pago.

Exemplo:

*Entrada:*
```
12 1 5.30  
16 2 5.10
```

*Saída:*
```
VALOR A PAGAR: R$ 15.50
```


**Exercício 07**

Fazer um programa que leia três valores com ponto flutuante de dupla precisão: `A`, `B` e `C`. Em seguida, calcule e mostre:

- a) a área do triângulo retângulo que tem A por base e C por altura.
- b) a área do círculo de raio C. (π = 3.14159)
- c) a área do trapézio que tem A e B por bases e C por altura.
- d) a área do quadrado que tem lado B.
- e) a área do retângulo que tem lados A e B.

Exemplo:

*Entrada:*
```
3.0 4.0 5.2
```

*Saída:*
```
TRIANGULO: 7.800  
CIRCULO: 84.949  
TRAPEZIO: 18.200  
QUADRADO: 16.000  
RETANGULO: 12.000
```

**Exercício 08**

Problema **Divisão do Tesouro (OBI)**:  
  [https://olimpiada.ic.unicamp.br/pratique/pj/2020/f1/tesouro/](https://olimpiada.ic.unicamp.br/pratique/pj/2020/f1/tesouro/).

**Exercício 09**

Problema **Piso da escola (OBI)**:  
  [https://olimpiada.ic.unicamp.br/pratique/p2/2018/f1/piso/](https://olimpiada.ic.unicamp.br/pratique/p2/2018/f1/piso/).

**Exercício 10**

Problema **Acelerador de partículas (OBI)**:  
  [https://olimpiada.ic.unicamp.br/pratique/p2/2020/f1/acelerador/](https://olimpiada.ic.unicamp.br/pratique/p2/2020/f1/acelerador/).


---

>> 📅 Segunda-feira, 17/8/2026 

## 🔀 Desvios Condicionais

**🎯 Objetivo:**
Apresentar as estruturas de decisão, permitindo que o programa tome diferentes caminhos com base em condições lógicas.


### 🧱 1. Estrutura do `if`, `else if` e `else`

```c
if (condição) {
    // bloco executado se condição for verdadeira
} else if (outraCondição) {
    // bloco executado se a outraCondição for verdadeira
} else {
    // bloco executado se nenhuma das condições for verdadeira
}
```
#### Exemplo

```c
int idade = 18;

if (idade < 18) {
    printf("Menor de idade\n");
} else if (idade == 18) {
    printf("Tem exatamente 18 anos\n");
} else {
    printf("Maior de idade\\n");
}
```


#### 🔁 Encadeamento de condições

> É possível encadear várias condições usando os **operadores lógicos**:

- && (E lógico)

- || (OU lógico)

- ! (NÃO lógico)

```c
if (idade >= 18 && idade < 60) {
    printf("Adulto não idoso\n");
}
```

---

### 📦 2. Estrutura switch

Boa alternativa ao if-else quando temos várias comparações simples com o mesmo valor. É necessário que o resultado da comparação não seja um intervalo, mas sim em um valor específico. 

### Exemplo
```c
int dia = 3;

switch (dia) {
    case 1:
        printf("Domingo\n");
        break;
    case 2:
        printf("Segunda-feira\n");
        break;
    case 3:
        printf("Terça-feira\n");
        break;
    case 4:
        printf("Quarta-feira\n");
        break;
    case 5:
        printf("Quinta-feira\n");
        break;
    case 6:
        printf("Sexta-feira\n");
        break;
    case 7:
        printf("Sábado-feira\n");
        break;
    default:
        printf("Dia inválido\n");
}
```

---

### 📝 3. Exercícios de Fixação

- Criar um programa que recebe três notas, calcula a média e imprime:

  - "Aprovado" se média ≥ 7,

  - "Recuperação" se média entre 5 e 7,

  - "Reprovado" caso contrário.

- Problema **A idade de Dona Mônica**: [https://olimpiada.ic.unicamp.br/pratique/pj/2019/f1/idade/](https://olimpiada.ic.unicamp.br/pratique/pj/2019/f1/idade/).

 ---

 ## 🔁 Laços de Repetição

 **🎯 Objetivo:**
Apresentar as estruturas de repetição em C: `while`, `do/while` e `for`, explicando sua sintaxe, funcionamento e diferenças, com exemplos práticos.

---

### 🔄 1. Laço `for`

O laço for é usado quando sabemos exatamente quantas vezes queremos repetir algo. É muito comum para contagens e percursos em sequências.

#### Sintaxe:
```c
for (inicialização; condição; atualização) {
    // bloco de código
}
```

#### Exemplo

```c
int contador;
for (int contador = 1; contador <= 5; contador++) {
    printf("Contando: " + contador);
}
```
>> 📌 Útil para quando o número de repetições é conhecido de antemão.

#### Prática
> Escrever um programa em C que mostre os números pares entre 0 e 100.
> Modifique o programa anterior para interromper a execução quando encontrar um número múltiplo de 19.
> Modifique o programa para mostrar os números pares, desde que não sejam múltiplos de 7. 


---

### 🔄 2. Laço `while`

O laço `while` executa um bloco de código **enquanto** uma condição for verdadeira. A **verificação ocorre antes da execução**.

#### Sintaxe:
```c
while (condição) {
    // bloco de código
}
```

#### Exemplo

```c
int contador = 1;

while (contador <= 5) {
    printf("Contando: " + contador);
    contador++;
}
```
>> 📌 O bloco será executado enquanto contador <= 5 for verdadeiro.

>> 🛑 Se a condição for falsa no início, o laço não será executado nenhuma vez.

#### Prática
> Escreva um programa em C que leia uma quantidade indeterminada pesos de bois de uma fazenda. Quando for lido o valor 0 (zero), a leitura deve ser encerrada e os valores do boi mais pesado, mais leve e a média de massa dos dois devem ser apresentados.

---

### 🔁 3. Laço do/while

O laço do/while executa o bloco de código pelo menos uma vez, e verifica a condição depois. 

#### Sintaxe:
```c
do{
  //bloco de código
}while (condição);
```

#### Exemplo

```c
int contador = 1;
do{
  printf("Contando: " + contador);
  contador++;
} while(contador <=5);
```
>> ✅ O laço sempre executa ao menos uma vez, mesmo que a condição seja falsa logo após a primeira execução.

#### Prática
> Escrever um programa em C que leia uma quantidade indefinida de números inteiros. Para cada número lido, indicar o dia da semana correspondente, se houver. Senão, indicar isso através de uma mensagem de valor inválido. Caso o usuário digite 0, a aplicação será encerrada. Usar o labelled loop. 

---

### 📝 4. Exercícios Práticos
- Imprimir os números de 1 a 10 usando while, do/while e for.

- Ler um número inteiro `n` e imprimir todos os números pares de 1 até `n`.

- Criar um programa que peça ao usuário para digitar senhas até que a senha correta seja informada.

- Fazer um programa que leia 5 números inteiros e calcule a média deles usando um laço.

---

>> 📅 Quarta-feira, 19/8/2026 

## 🔁 Estruturas de dados homogêneas — vetores e matrizes

### 1. Arranjos  

Um **arranjo** é uma variável estruturada formada por agrupamentos de variáveis do **mesmo tipo** (por exemplo: inteiro, caractere, número de ponto flutuante).  
Por isso, são também chamados de **estruturas de dados homogêneas**.

Uma estrutura é identificada por **um único nome**, e cada uma das variáveis que a compõem é identificada por um **índice**, que indica sua posição no agrupamento.  
Por usarem índices, essas estruturas também são chamadas de **estruturas indexadas**.

---

### 🔢 Índices e acesso aos elementos  

Usamos números inteiros para representar os índices, geralmente iniciando em **0** (0, 1, 2, 3, 4, ...).  

É importante notar que **não existe vinculação direta** entre a variável usada como índice e o arranjo em si.  
Por exemplo, podemos usar uma variável `i` para percorrer o arranjo e, em outro momento, usar outra variável qualquer para acessar suas posições.

📌 O essencial é que a variável usada como índice **assuma valores numéricos compatíveis** com os índices válidos do arranjo.

---

### ⚙️ Acesso direto aos elementos  

Uma característica importante das estruturas indexadas é que **o acesso aos elementos não precisa ser sequencial**.  
Ou seja, é possível acessar diretamente qualquer posição do arranjo sem precisar passar pelas anteriores.  

> Exemplo: para acessar o terceiro elemento de um arranjo, não é necessário acessar o primeiro e o segundo antes.

---

### 🧠 Operações sobre os elementos  

Cada posição de um arranjo pode ser entendida como **uma variável simples** — daquelas que já aprendemos a declarar, ler, atribuir valores, usar em expressões e exibir na tela.  

Assim, todas as operações que fazemos com variáveis simples também podem ser realizadas com **os elementos de um arranjo**.

---

### 💡 Quando usar arranjos?

Arranjos são usados sempre que precisamos **armazenar grande quantidade de valores do mesmo tipo** em um programa.  
Essa quantidade, muitas vezes, **não é conhecida pelo programador**, mas sim definida pelo **usuário**.

📘 **Exemplos práticos:**  
Imagine uma adaptação ao problema apresentado anterior, que trata de um programa que calcula as massas dos bois de uma fazenda. Nessa adaptação, assuma que será necessário guardar a massa de cada. Nesse caso, certamente o programa usará uma **estrutura indexada** para armazenar esses valores.  
Cada animal será representado por um **índice** dentro dessa estrutura.

📗 **Outro exemplo:**  
Em uma sala de aula com 40 alunos, podemos criar um arranjo chamado `aluno` para armazenar os **nomes de todos os estudantes**.  
Cada nome estará associado a um **índice** desse arranjo.

---

### 🧮 Tipos de arranjos  

Um arranjo pode ser:  
- **Unidimensional**, quando utiliza **apenas um índice** (também chamado de **vetor**).  
- **Multidimensional**, quando utiliza **dois ou mais índices** (chamado de **matriz**).

> 🧩 Este material contempla o estudo de arranjos de **até duas dimensões**.  


### 2. Declaração de vetores

**🎯 Objetivo:**
Apresentar a sintaxe de declaração de vetores em C e as diferentes formas de definir seu tamanho e seus valores iniciais.

#### Sintaxe geral

Um vetor é declarado escrevendo o **tipo** dos dados que ele vai armazenar, o **nome** e o **tamanho** entre colchetes, finalizando com `;`.

```c
tipo nome[tamanho];
```

```c
int arr[1000];
double lista[100];
char letras[tam];
float dinheiro[10*x];
```

> ℹ️ O tamanho pode ser um valor constante, uma variável já definida ou até uma expressão aritmética.

#### Formas de declaração

**a) Tamanho definido pelo programador**
```c
int arr[1000];
```

**b) Tamanho definido pelo usuário**
```c
int arr[n]; // é preciso que o valor de n já tenha sido definido (ex.: lido do usuário)
```

**c) Tamanho explícito e todos os valores definidos pelo programador**
```c
int arr[10] = {18, 17, 20, 26, 32, 29, 15, 12, 16, 21};
```

**d) Tamanho implícito (o compilador conta os valores) e todos os valores definidos pelo programador**
```c
int arr[] = {18, 17, 20, 26, 32, 29, 15};
```

**e) Tamanho implícito e valores definidos pelo usuário**
```c
int arr[] = {a, b, c, d}; // a, b, c e d são valores lidos anteriormente do usuário
```

**f) Tamanho explícito e apenas alguns valores definidos pelo programador**
```c
int arr[10] = {18, 17}; // as demais posições recebem 0 automaticamente
```

> ⚠️ Ao declarar um vetor com tamanho implícito, é **obrigatório** informar a lista de valores entre chaves — é a partir dela que o compilador calcula o tamanho.

---

### 3. Atribuição e leitura de elementos

**🎯 Objetivo:**
Mostrar como atribuir, ler e exibir valores em posições específicas de um vetor, usando o índice.

Cada posição do vetor é acessada pelo **nome** seguido do **índice** entre colchetes:

```c
arr[0] = 10;            // atribuição direta
scanf("%d", &arr[i]);   // leitura de um valor digitado pelo usuário
printf("%d", arr[i]);   // exibição do valor armazenado
```

Como normalmente não sabemos, ao escrever o código, todos os valores que serão armazenados, é comum atribuir ou ler elementos **dentro de um laço de repetição**:

```c
int notas[40];

for (int i = 0; i < 40; i++) {
    printf("Digite a nota do aluno %d: ", i + 1);
    scanf("%f", &notas[i]);
}
```

> 📌 O laço `for` é o mais utilizado ao trabalhar com vetores, pois já controla naturalmente o índice de 0 até o tamanho do vetor.

---

### 4. Manipulação de elementos do vetor

Todas as operações possíveis com uma **variável simples** — atribuição, leitura, exibição, operações aritméticas ou lógicas — também podem ser realizadas com um **elemento de vetor**, bastando referenciá-lo pelo nome e pelo índice.

```c
soma = soma + notas[i];     // usar um elemento em uma expressão
if (notas[i] >= 7) { ... }  // usar um elemento em uma condição
```

#### Prática
> Declare um vetor de 10 posições, preencha-o com valores lidos do usuário e, em seguida, exiba todos os valores na ordem inversa.

> Declare um vetor de 20 números inteiros, leia os valores e calcule a soma e a média deles.

> Leia 10 números inteiros em um vetor e exiba apenas os valores pares.

---

### 5. Matrizes — conceito

Estruturas indexadas que necessitam de **mais de um índice** para identificar um de seus elementos são chamadas de **matrizes de dimensão n**, sendo `n` o número de índices necessários.

Uma **matriz de dimensão 2** (a mais comum) exige, portanto, **dois índices** para identificar um elemento: um para a **linha** e outro para a **coluna**.

> 📘 Exemplo: em uma matriz `matr`, o elemento localizado na linha de índice 1 e coluna de índice 2 é acessado por `matr[1][2]`.

---

### 6. Declaração de matrizes

**🎯 Objetivo:**
Apresentar a sintaxe de declaração de matrizes (arranjos bidimensionais) em C.

#### Sintaxe geral

Uma matriz é declarada escrevendo o tipo dos dados que ela vai armazenar, o nome e sua dimensão bidimensional, entre colchetes.

```c
tipo nome[linhas][colunas];
```

```c
int ma[1000][10];
double lista[100][5];
char letras[tam][20];
float dinheiro[10*x][x];
```

#### Formas de declaração

**a) Dimensões definidas pelo programador**
```c
int ma[1000][10];
```

**b) Dimensões definidas pelo usuário**
```c
int ma[n][n]; // é preciso que o valor de n já tenha sido definido pelo usuário
```

**c) Dimensões explícitas e todos os valores definidos pelo programador**
```c
int ma[2][5] = {{18, 17, 20, 26, 32}, {29, 15, 12, 16, 21}};
```

**d) Dimensões implícitas (nas linhas) e todos os valores definidos pelo programador**
```c
int ma[][3] = {{18, 17, 20}, {4, 5, 8}, {26, 32, 29}};
```

**e) Dimensões explícitas e apenas alguns valores definidos pelo programador**
```c
int ma[10][10] = {{18, 17}}; // as demais posições recebem 0 automaticamente
```

> ⚠️ Diferente do vetor, ao declarar uma matriz com dimensão implícita **somente a primeira dimensão (linhas)** pode ficar em aberto — o número de colunas precisa ser sempre informado.

---

### 7. Manipulação de matrizes

Todo o processo de manipulação de uma matriz é **semelhante ao de um vetor** — a diferença está no uso de **dois índices** em vez de apenas um, o que normalmente exige **dois laços de repetição aninhados**: um para percorrer as linhas e outro para as colunas.

```c
int ma[3][3];

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("Digite o valor da posição [%d][%d]: ", i, j);
        scanf("%d", &ma[i][j]);
    }
}
```

#### Prática
> Declare uma matriz 3x3, preencha-a com valores lidos do usuário e exiba a soma de todos os elementos.

> Declare uma matriz 4x4 e exiba apenas os elementos da diagonal principal (posições em que o índice da linha é igual ao da coluna).

---

### 📝 8. Exercícios de Fixação

**Desafio — Álbum da Copa (OBI)**

Em ano de Copa do Mundo de Futebol, o álbum de figurinhas oficial contém espaços numerados de 1 a N, e cada figurinha, também numerada de 1 a N, corresponde a um desses espaços. As figurinhas são vendidas em envelopes fechados, sem que o comprador saiba quais está adquirindo — por isso, pode ocorrer de comprar uma figurinha repetida.

Dado o número total de espaços/figurinhas do álbum (N), o número de figurinhas já compradas (M) e a lista dessas M figurinhas (que pode conter repetições), determine **quantas figurinhas ainda faltam** para completar o álbum.

- **Entrada:** um inteiro N (número total de figurinhas/espaços); em seguida um inteiro M (figurinhas já compradas); depois M linhas, cada uma com um inteiro X (uma figurinha comprada).
- **Saída:** uma única linha com um inteiro — a quantidade de figurinhas que faltam.
- **Restrições:** 1 ≤ N ≤ 100; 1 ≤ M ≤ 300; 1 ≤ X ≤ N.

🔗 [Enunciado completo (OBI)](https://olimpiada.ic.unicamp.br/pratique/pj/2018/f1/album/)

> 💡 Dica: use um vetor de tamanho N+1 para marcar quais figurinhas já foram coladas, percorrendo-o ao final para contar as que faltam.

**Lista Beecrowd — vetores e matrizes**

> Problema [1174](https://judge.beecrowd.com/pt/problems/view/1174);

> Problema [1175](https://judge.beecrowd.com/pt/problems/view/1175);

> Problema [1176](https://judge.beecrowd.com/pt/problems/view/1176) — obs: fazer sem recalcular posições já calculadas;

> Problema [1179](https://judge.beecrowd.com/pt/problems/view/1179);

> Problema [1435](https://judge.beecrowd.com/pt/problems/view/1435);

> Problema [1183](https://judge.beecrowd.com/pt/problems/view/1183);

> Problema [1184](https://judge.beecrowd.com/pt/problems/view/1184);

> Problema [1185](https://judge.beecrowd.com/pt/problems/view/1185);

> Problema [1186](https://judge.beecrowd.com/pt/problems/view/1186);

> Problema [1187](https://judge.beecrowd.com/pt/problems/view/1187);

> Problema [3428](https://judge.beecrowd.com/pt/problems/view/3428).


>> 📅 Sábado, 22/8/2026

## 🧩 Modularização — Funções

### 1. Por que modularizar?

**🎯 Objetivo:**
Apresentar o conceito de modularização e justificar o uso de funções na organização de um programa.

Até aqui, todos os nossos programas foram escritos inteiramente dentro da função `main`. Isso funciona bem para programas pequenos, mas se torna inviável à medida que o programa cresce.

**Modularizar** um programa significa dividi-lo em blocos menores e independentes — as **funções** — cada um responsável por uma tarefa específica.

#### Motivos para usar funções

- Permitir o **reaproveitamento** de código já construído (por você ou por outros programadores);
- Evitar que um trecho de código se **repita várias vezes** dentro do mesmo programa;
- Permitir a **alteração** de um trecho de código de forma mais rápida — com uma função, basta alterar apenas dentro dela;
- Evitar que os blocos do programa fiquem **grandes demais** e, por consequência, mais difíceis de entender;
- Facilitar a **leitura** do programa-fonte;
- Separar o programa em partes que possam ser **compreendidas isoladamente**.

> 📌 Pense em uma função como uma "caixa-preta": quem a utiliza não precisa saber *como* ela faz o que faz, apenas *o que* ela recebe e *o que* ela devolve.

---

### 2. Formato geral de uma função em C

```c
tipo_do_retorno nomeDaFuncao(lista_de_parametros) {
    // corpo da função
    return valor; // obrigatório se tipo_do_retorno for diferente de void
}
```

| Parte | Significado |
|---|---|
| `tipo_do_retorno` | Tipo do dado devolvido pela função (`int`, `float`, `char`, etc.). Use `void` quando a função **não** devolve valor. |
| `nomeDaFuncao` | Identificador usado para chamar a função. |
| `lista_de_parametros` | Variáveis que a função recebe como entrada, separadas por vírgula. Pode ser vazia. |
| `corpo da função` | Bloco de instruções executado quando a função é chamada. |
| `return` | Encerra a função e devolve um valor a quem a chamou. |

#### Exemplo — função com retorno

```c
float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}
```

#### Exemplo — função sem retorno (`void`)

```c
void mostrarMensagem() {
    printf("Bem-vindo à disciplina de Estrutura de Dados!\n");
}
```

> ⚠️ Uma função `void` pode usar `return;` (sem valor) para encerrar sua execução antecipadamente, mas nunca `return valor;`.

---

### 3. Declaração (protótipo), definição e chamada

**🎯 Objetivo:**
Mostrar como declarar, definir e chamar uma função, incluindo o uso de protótipos.

Em C, uma função precisa ser **conhecida pelo compilador antes de ser usada**. Isso é feito de duas formas:

- Escrevendo a função **completa antes** da `main`;
- Ou escrevendo apenas o **protótipo** (a "assinatura" da função) antes da `main`, e a função completa depois.

```c
tipo_do_retorno nomeDaFuncao(tipo1, tipo2, ...); // protótipo — note o ; no final
```

#### Exemplo completo

```c
#include <stdio.h>

float calcularMedia(float n1, float n2, float n3); // protótipo

int main() {
    float media = calcularMedia(8.5, 7.0, 9.0); // chamada
    printf("Média: %.2f\n", media);
    return 0;
}

float calcularMedia(float n1, float n2, float n3) { // definição
    return (n1 + n2 + n3) / 3;
}
```

> 📌 O protótipo é especialmente útil quando a função é definida **depois** de onde é chamada, ou em arquivos separados — situação comum em projetos maiores.

---

### 4. Parâmetros e retorno de valores

**🎯 Objetivo:**
Explicar a diferença entre funções com e sem retorno, e como os parâmetros são utilizados.

| | Com retorno | Sem retorno (`void`) |
|---|---|---|
| Tipo declarado | `int`, `float`, `char`, etc. | `void` |
| Usa `return valor;`? | Sim, obrigatório | Não (pode usar `return;` sozinho) |
| Uso típico | Calcular e devolver um resultado | Executar uma ação (imprimir, alterar algo) |

```c
int quadrado(int n) {          // com retorno
    return n * n;
}

void exibirLinha(int tamanho) { // sem retorno
    for (int i = 0; i < tamanho; i++) {
        printf("-");
    }
    printf("\n");
}
```

---

### 5. Passagem de parâmetros por valor

**🎯 Objetivo:**
Demonstrar que, em C, os parâmetros são passados **por valor** por padrão — a função recebe uma **cópia**, não a variável original.

```c
void tentaTrocar(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    tentaTrocar(x, y);
    printf("%d %d\n", x, y); // ainda imprime 5 10 — a troca NÃO afetou x e y
    return 0;
}
```

> ⚠️ Dentro de `tentaTrocar`, `a` e `b` são variáveis **novas**, independentes de `x` e `y`. Qualquer alteração feita nelas é perdida ao final da função.

> 💡 Para que uma função consiga alterar de fato as variáveis originais, é necessário usar **ponteiros** — assunto da nossa próxima aula.

---

### 6. Escopo de variáveis

**🎯 Objetivo:**
Diferenciar variáveis locais e globais.

- **Variável local:** declarada dentro de uma função (ou bloco); só existe e só pode ser acessada **dentro** dela.
- **Variável global:** declarada fora de todas as funções; pode ser acessada por **qualquer** função do programa.

```c
int contadorGlobal = 0; // variável global

void incrementar() {
    int passo = 1;       // variável local — só existe dentro de incrementar()
    contadorGlobal += passo;
}
```

> ⚠️ O uso excessivo de variáveis globais dificulta o entendimento do programa, pois qualquer função pode alterá-las. Prefira sempre variáveis locais e passe dados entre funções por meio de parâmetros e retorno.

---

### 📝 Exercícios de Fixação

**Exercício 00**

Escreva uma função `int quadrado(int n)` que retorna o quadrado de um número, e um `main` que a utiliza para exibir o quadrado de um valor lido do usuário.

**Exercício 01**

Escreva uma função `void exibirTabuada(int n)` que imprime a tabuada de `n` (de 1 a 10).

**Exercício 02**

Crie uma função `float calcularMedia(float n1, float n2, float n3)` que recebe três notas e retorna a média. Utilize-a para refazer o exercício de aprovação/recuperação/reprovação visto anteriormente.

**Exercício 03**

Crie uma função `int ehPar(int n)` que retorna `1` se `n` for par e `0` caso contrário. Utilize-a para ler 10 números e classificar cada um como par ou ímpar.

**Exercício 04**

Reescreva o programa que calcula a área de um triângulo, círculo, trapézio, quadrado e retângulo (exercícios da unidade de Estrutura Sequencial), criando **uma função para cada área**.

---

## 🔁 Recursividade

### 1. O que é uma função recursiva?

**🎯 Objetivo:**
Apresentar o conceito de recursividade e seus dois elementos essenciais: caso base e caso recursivo.

Uma função é **recursiva** quando ela chama a si mesma, direta ou indiretamente, para resolver um problema menor do mesmo tipo.

Toda função recursiva precisa de dois elementos:

- **Caso base:** a condição que interrompe as chamadas recursivas e devolve um resultado direto, sem nova chamada.
- **Caso recursivo:** a parte em que a função chama a si mesma, aplicada a uma versão menor (ou mais simples) do problema.

> ⚠️ Uma função recursiva **sem caso base**, ou com um caso base que nunca é alcançado, chama a si mesma indefinidamente — isso esgota a memória reservada para as chamadas (a **pilha**) e o programa é encerrado com erro (*stack overflow*).

---

### 2. Exemplo clássico: fatorial

Vamos pensar em uma função para calcular o fatorial de um número inteiro `n`. O fatorial de `n` é definido como:
- `n! = n × (n − 1)!`, para todo `n ≥ 1` e `0! = 1`.

Se pensamos em escrever uma função para calcular o fatorial de `n`, faremos: 
```c
int fatorial(int n){
    if (n==0 || n == 1) return 1;

    for(int i=n-1; i>1; i--){
        n *= i;
    }
    return n;
}
```

Este caso é possível ser facilmente reescrito na forma: 

```c
int fatorial(int n) {
    if (n == 0) {            // caso base
        return 1;
    }
    return n * fatorial(n - 1); // caso recursivo
}
```

#### Como as chamadas acontecem (rastreamento de `fatorial(4)`)

| Chamada | Resultado |
|---|---|
| `fatorial(4)` | `4 * fatorial(3)` |
| `fatorial(3)` | `3 * fatorial(2)` |
| `fatorial(2)` | `2 * fatorial(1)` |
| `fatorial(1)` | `1 * fatorial(0)` |
| `fatorial(0)` | `1` *(caso base — não chama mais ninguém)* |

> 📌 As chamadas "empilham" até alcançar o caso base e, então, os resultados vão sendo multiplicados de volta, na ordem inversa, até `fatorial(4)` retornar `24`.

---

### 3. Exemplo: sequência de Fibonacci

```c
int fibonacci(int n) {
    if (n == 0) return 0;   // 1º caso base
    if (n == 1) return 1;   // 2º caso base
    return fibonacci(n - 1) + fibonacci(n - 2); // caso recursivo
}
```

> ⚠️ Essa versão recursiva do Fibonacci é didática, mas **ineficiente**: o número de chamadas cresce exponencialmente, pois o mesmo valor é recalculado várias vezes (por exemplo, `fibonacci(n-2)` é calculado tanto pela chamada de `fibonacci(n-1)` quanto diretamente).

---

### 4. Recursão vs. iteração

Todo problema resolvido com recursão também pode ser resolvido com um laço (`for`/`while`), e vice-versa.

| | Recursão | Iteração |
|---|---|---|
| Legibilidade | Costuma ser mais próxima da definição matemática do problema | Costuma exigir controle explícito de variáveis auxiliares |
| Uso de memória | Cada chamada ocupa espaço na pilha de execução | Não cresce com o tamanho da entrada |
| Desempenho | Pode ser mais lento por causa do custo de cada chamada | Geralmente mais eficiente |
| Quando preferir | Problemas naturalmente recursivos (divisão de um problema em subproblemas menores do mesmo tipo) | Quando o desempenho e o uso de memória são críticos |

---

### 📝 Exercícios de Fixação

**Exercício 00**

Escreva uma função recursiva `int somaAte(int n)` que retorna a soma dos inteiros de `1` até `n`.

**Exercício 01**

Escreva uma função recursiva `int potencia(int base, int expoente)` que calcula `base` elevado a `expoente`.

**Exercício 02**

Escreva uma função recursiva `int mdc(int a, int b)` que calcula o máximo divisor comum entre `a` e `b`, usando o algoritmo de Euclides (`mdc(a, b) = mdc(b, a % b)`, com caso base `mdc(a, 0) = a`).

**Exercício 03**

Escreva uma função recursiva `int contarDigitos(int n)` que retorna a quantidade de dígitos de um número inteiro.

**Exercício 04 — Fibonacci, How Many Calls?**

Problema **Fibonacci, How Many Calls?**: implemente a função recursiva de Fibonacci contando quantas vezes ela é chamada para calcular `fib(n)`.

🔗 [Beecrowd 1029](https://judge.beecrowd.com/pt/problems/view/1029)

---


## 📍 Ponteiros

### 1. O que é um ponteiro?

**🎯 Objetivo:**
Apresentar o conceito de endereço de memória e de ponteiro.

Toda variável, ao ser declarada, ocupa um espaço na memória do computador, identificado por um **endereço**. Até agora, sempre acessamos esse espaço **pelo nome** da variável — mas também é possível acessá-lo **pelo endereço**.

Um **ponteiro** é uma variável especial que, em vez de armazenar um valor comum (um número, um caractere, etc.), armazena o **endereço de memória** de outra variável.

---

### 2. Operadores `&` e `*`

| Operador | Nome | O que faz |
|---|---|---|
| `&variavel` | Operador de endereço | Obtém o **endereço de memória** onde `variavel` está armazenada |
| `*ponteiro` | Operador de indireção (dereferência) | Acessa o **valor armazenado** no endereço apontado por `ponteiro` |

> ℹ️ Você já usou o operador `&` diversas vezes, sem perceber: em `scanf("%d", &idade);`, estamos passando o **endereço** de `idade` para que a função `scanf` possa escrever o valor lido diretamente naquela posição de memória.

```c
int idade = 25;
int *pIdade = &idade;   // pIdade armazena o endereço de idade

printf("%d\n", idade);    // 25              -> valor de idade
printf("%p\n", &idade);   // 0x7ffe...        -> endereço de idade
printf("%p\n", pIdade);   // 0x7ffe... (igual) -> mesmo endereço, guardado em pIdade
printf("%d\n", *pIdade);  // 25              -> valor apontado por pIdade
```

---

### 3. Declaração e inicialização de ponteiros

Um ponteiro é declarado indicando o **tipo do dado apontado**, seguido de `*` e do nome da variável.

```c
tipo *nome;
```

```c
int *p;      // ponteiro para int
float *pf;   // ponteiro para float
char *pc;    // ponteiro para char
```

> ⚠️ Um ponteiro declarado e **não inicializado** aponta para um endereço indefinido ("lixo de memória"). Usar `*p` nesse estado (ler ou escrever) é um erro grave — sempre inicialize um ponteiro com `&variavel` antes de usá-lo, ou com `NULL` se ele ainda não deve apontar para nada.

```c
int *p = NULL; // ponteiro que ainda não aponta para nenhuma variável válida
```

---

### 4. Ponteiros e passagem de parâmetros por referência

Lembra da função `tentaTrocar`, na aula de funções, que não conseguia trocar os valores de `x` e `y`? Usando ponteiros, a função passa a receber o **endereço** das variáveis, e pode alterá-las de fato.

```c
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    trocar(&x, &y);            // passamos os endereços de x e y
    printf("%d %d\n", x, y);   // agora imprime 10 5 — a troca funcionou
    return 0;
}
```

> 📌 Passar um parâmetro **por referência** (via ponteiro) permite que a função modifique a variável original do chamador — diferente da passagem por valor, que trabalha sobre uma cópia.

---

### 5. Ponteiros e vetores

O nome de um vetor, sozinho, já se comporta como um ponteiro para sua primeira posição:

```c
int notas[5] = {10, 8, 7, 9, 6};
int *p = notas; // equivalente a: int *p = &notas[0];

for (int i = 0; i < 5; i++) {
    printf("%d\n", *(p + i)); // equivalente a notas[i]
}
```

| Notação com índice | Notação com ponteiro | Significado |
|---|---|---|
| `notas[0]` | `*(p + 0)` ou `*p` | Valor da 1ª posição |
| `notas[i]` | `*(p + i)` | Valor da posição `i` |
| `&notas[i]` | `p + i` | Endereço da posição `i` |

> ℹ️ Essa equivalência é a razão pela qual, ao passar um vetor como parâmetro de uma função em C, na prática estamos sempre passando um **ponteiro** para sua primeira posição — por isso uma função pode alterar os elementos de um vetor recebido como parâmetro, mesmo sem usar `&`.

---

### 📝 Exercícios de Fixação

**Exercício 00**

Escreva uma função `void dobrar(int *n)` que dobra o valor da variável apontada por `n`. Teste com uma variável lida do usuário.

**Exercício 01**

Reescreva a função `trocar` usando ponteiros e teste-a com dois valores lidos do usuário, exibindo os valores antes e depois da troca.

**Exercício 02**

Escreva uma função `int somaVetor(int *v, int tam)` que recebe um vetor (via ponteiro) e seu tamanho, e retorna a soma de seus elementos.

**Exercício 03**

Escreva uma função `void inverter(int *v, int tam)` que inverte a ordem dos elementos de um vetor, alterando-o diretamente (sem criar um novo vetor).

**Exercício 04**

Escreva uma função `int maiorElemento(int *v, int tam)` que retorna o maior valor de um vetor, recebendo-o via ponteiro.
