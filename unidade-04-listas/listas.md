# Unidade Temática #4 — Listas


Senhores estudantes,

Esta é a unidade temática #4 da disciplina de Estrutura de Dados, ministrada no curso superior de tecnologia em Sistemas para Internet do Ifac/Campus Rio Branco. Nesta unidade, apresentaremos a estrutura de dados **lista** nas formas simplesmente encadeada, duplamente encadeada e circular. 

Para se aprofundar neste roteiro, acesse o livro **Estruturas de dados**: algoritmos, análise da complexidade e implementações em Java e C/C++, de Ascencio e Araújo, disponível na biblioteca virtual do Ifac, acessível por meio do link [https://plataforma.bvirtual.com.br/Acervo/Publicacao/1995](https://plataforma.bvirtual.com.br/Acervo/Publicacao/1995). No livro, estude o capítulo 3. 


## 📑 Sumário

- [O que são listas](#o-que-são-listas)

>> 📅 Sexta-feira, 14/11/2025 

## Listas
### O que são listas

Listas são estruturas de dados fundamentais que representam coleções de elementos, nas quais cada elemento possui uma posição específica. Listas permitem diversas operações, tais como inserção, remoção e busca. Listas podem ser implementadas por meio de estratégias diferentes, de modo que elas podem ser estáticas ou dinâmicas.

- **Listas estáticas**: podem ser implementadas por meio de vetores, têm tamanho máximo fixo, permitem acesso rápido a elementos por meio de índices e têm como limitação a impossibilidade de crescimento em tempo de execução;
- **Listas dinâmicas**: guardam elementos encadeados, têm tamanho variável e os elementos são alocados dinamicamente, de modo que permitem inserções e remoções eficientes. 

Uma lista estática implementada por meio de um vetor ocupa uma tamanho `x` na memória, independente da quantidade de elementos que efetivamente ela tem. Ademais, a quantidade de elementos na lista não pode exceder o tamanho previamente definido para o vetor. A figura abaixo mostra dois exemplos de listas implementadas via vetor. A primeira, que é uma lista estática de dados homogêneos, tem cinco números inteiros e pode armazenar, no máximo oito. A segunda — que uma lista estática de dados heterogêneos, guarda três `structs` que contém um texto e um inteiro; ela pode armazenar, no máximo oito. Independentemente da quantidade de elementos guardado na lista, o espaço de memória reservado para cada lista é `8 vezes a quantidade de memória necessária para armazenar um elemento`. 

![Listas armazenadas em vetores](https://github.com/user-attachments/assets/cee9d772-4fb0-47b1-bac8-79f79ffa9e1e)

Por outro lado, uma lista implementada dinamicamente ocupa na memória o espaço mínimo suficiente para guardar a quantidade de elementos que estão na lista em um determinado espaço de tempo. Na figura abaixo, há duas listas implementadas de maneira dinâmica, um com dados homogêneos e outr acom dados heterogêneos. A primeira guarda números inteiros, ao passo que a segunda armazena `structs` com texto e número. Nesse tipo de lista, cada nó guarda um valor (número na primeira lista e `struct` na segunda) e um ponteiro para o próximo nó. O último nó tem um ponteiro que aponta para `NULL`.

![Listas armazenadas dinamicamente](https://github.com/user-attachments/assets/79e96d59-1f03-4f56-84a8-a2e8eb0ee19d)

> Nesta unidade, atentar-nos-emos apenas a listas dinâmicas.

### Vantagens e desvantagens de listas dinâmicas

**1. Vantagens:**

- Cresce conforme necessário;
- Inserir ou remover no início é muito eficiente computacionalmente;
- Não há necessidade de mover elementos.

Por exemplo, para inserir um elemento de valor 30 na lista dinâmica homogênea da figura acima, entre o 2 e o 14, basta fazer o ponteiro do nó que contém o elemento 2 apontar para o novo nó com o valor 30 e fazer o ponteiro do nó que tem o valor 30 para o nó que tem o valor 14, assim: 

![Inserção em lista dinâmica](https://github.com/user-attachments/assets/fa561693-afa0-4dae-8a24-8f0f43facd7c)

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
typedef struct{
    int valor;
    No *prox;
}No;
```

>> 📅 Quarta-feira, 19/11/2025 

## Listas simplesmente encadeadas

Uma lista simplesmente encadeada é uma estrutura de dados dinâmica composta por **nós**, em que cada um deles armazena:

- um valor (nesta aula, um inteiro);

- um ponteiro para o próximo nó;

* *O código acima em C representa a estrutura de um nó, o qual será usado nesta aula*.

Essa estrutura é recomendada quando o número de elementos não é conhecido previamente ou quando inserções e remoções são frequentes.

Em uma lista simplesmente encadeada, cada nó guarda um elemento (no exemplo, um inteiro, mas pode ser uma `struct` ou qualquer outro tipo) e o endereço do próximo nó (um ponteiro, geralmente chamado de `prox`). Se `prox == NULL`, significa que aquele é o último nó da lista.

### Representação Conceitual

Uma lista com os elementos 6 → 2 → 14 → 17 → 17 é representada assim:

![Lista simplesmente encadeada](https://github.com/user-attachments/assets/79e96d59-1f03-4f56-84a8-a2e8eb0ee19d)

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

**Exercícios:**

1. Faça uma função que inclua um elemento no fim da lista em `O(1)`;
2. Faça um função que receba um número e exclua essa número da lista;
3. Faça uma função que exclua o alemento do fim da lista;
4. Faça uma função que exclua o elemento do início da lista.

**Desafio:** Implementar uma lista simplesmente encadeada ordenada e aplicar nela as operações de criação, inserção, remoção e impressão dos valores. 

## Listas duplamente encadeadas

Nesse tipo de estrutura, cada nó armazena um ou vários dados (dados homogêneos ou `structs`, respectivamente) e dois ponteiros — um para o próximo elemento e outro para o elemento anterior. Essa abordagem permite o encadeamento da lista em ambas as direções e mantém a estrutura linear. Assim, é posível: 
- Navegar para frente e para trás;
- Inserir e remover de forma mais eficiente em posições intermediárias da lista.

É uma estrutura bastante utilizada em sistemas que exigem manipulação flexível de elementos, como editores de texto, histórico de navegação e buffers de dados.

### Estrutura da lista
```c
typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;
```

### Representação conceitual

A lista com os elementos 6 ⇄ 2 ⇄ 14 ⇄ 17 ⇄ 17 é representada assim:

![Lista duplamente encadeada](https://github.com/user-attachments/assets/13473afd-ff18-4c92-882c-56ad98a7e24f)

O início aponta para o primeiro nó. O primeiro tem `ant` igual a `NULL`. Jáo último tem `prox` igual a `NULL`.

### Vantagens e desvantagens de listas simplesmente encadeadas

**1. Vantagens**
- Navegação bidirecional;
- Inserção antes/depois de qualquer nó é simples, ou seja, em `O(1)`;

**2. Desvantagens**
- Ocupam mais memória (duas referências por nó);
- Implementação mais complexa que a lista simples;
- Maior risco de erros de ponteiros.

### Operações fundamentais

As operações aplicáveis a listas duplamente encadeadas são as mesmas que podem ser usadas em listas simplesmente encadeadas, acrescentando que pode-se percorrer não somente para frente, mas também para trás.


