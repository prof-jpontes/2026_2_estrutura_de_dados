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


>> 📅 Segunda-feira, 3/8/2026 

## ▶️ Iniciar

Vamos iniciar fazendo um pequeno diagóstico. Para isso, acesse o juiz online [Beecrowd](https://judge.beecrowd.com) e complete o seu cadastro. Ato contínuo, acesse a disciplina Estrutura de Dados, de ID XXXX (a chave de acesso será dada pelo professor em sala de aula). Dentro da disciplina, acesse a lista de exercícios **Diagóstico**. Faça essa lista. 

Procederemos com a revisão acompanada de discussão e correção dos desafios.

>> 📅 Quarta-feira, 5/8/2026 

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
 
