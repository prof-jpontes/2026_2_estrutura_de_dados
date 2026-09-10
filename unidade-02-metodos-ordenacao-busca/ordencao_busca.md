# Unidade Temática #2 — Métodos de Ordenação e Busca


Senhores estudantes,

Esta é a unidade temática #2 da disciplina de Estrutura de Dados, ministrada no curso superior de tecnologia em Sistemas para Internet do Ifac/Campus Rio Branco. Nesta unidade, estudaremos sobre algoritmos de ordenção (Bubblesort, Selection Sort, Insertion Sort e Mergesort) e buscas sequencial e binária. 


## 📑 Sumário

- [Método Bolha ou Bubblesort](#método-bolha-ou-bubblesort)
- [Método de Seleção ou Selection Sort](#método-de-seleção-ou-selection-sort)
- [Método de Inserção ou Insertion Sort](#método-de-inserção-ou-insertion-sort)
- [Noção de Complexidade dos Algoritmos de Ordenação](#noção-de-complexidade-dos-algoritmos-de-ordenação)
- [Algoritmos de Busca](#algoritmos-de-busca)
- [Um Algoritmo de Ordenação sofisticado: Merge Sort](#um-algoritmo-de-ordenação-sofisticado-merge-sort)


>> 📅 Quarta-feira, 26/08/2026 

## Método Bolha ou Bubblesort

O método Bubblesort, também conhecido como método Bolha, realiza a ordenação comparando os elementos, dois a dois, e trocando-os de posição, de acordo com o critério estabelecido de ordem crescente ou decrescente. Seu nome se deve à ideia de que os elementos flutuam como uma bolha até encontrar as posições corretas. Na ordenação crescente, considere que as bolhas que representam os números maiores flutuam mais e vão "subindo" para a parte de cima do vetor.

O Bubblesort pode ser implementado de forma iterativa, em que a execução das instruções ocorre sucessivamente, controlada por duas estruturas de laço aninhados (um dentro do outro). Ao final da primeira iteração do laço externo, tem-se a garantia que a última posição do vetor está com o elemento correto, isto é, com o maior valor para ordenação crescente ou o menor elemento em ordenação decrescente. Ao final da segunda iteração do laço externo, tem-se a garantia que as duas últimas posições contêm os elementos corretos, e assim sucessivamente. Ao término do laço externo, o vetor estará completamente ordenado.

A figura abaixo ilustra o processo de ordenação de um vetor de inteiros formado pelos elementos *70, 21, 63, 50, 70, 82, 19, 9*, nessa ordem, considerando a ordenação crescente. Na figura, o elemento destacado em verde está sendo sempre comparado com o próximo, em amarelo. Eles trocam de ordem se o verde for maior que o amarelo. Sendo ou não, a posição que estava amarela passa a ser verde e próxima assume a cor amarela. O destaque em cinza indica a região do vetor que já está ordenada, ou seja, não precisa ser mais avaliada.


![Bubblesort - 1ª iteração](https://github.com/user-attachments/assets/e4869ab5-261a-44fb-86f0-6fa8f3fc8258)

Como é posível observar na imagem acima, na primeira iteração do laço externo, foi necessário percorrer até a última posição do vetor. Ao término, tem-se que a última posição já está com o maior elemento. Portanto, na segunda iteração não será mais verificada a última posição — afinal ela já tem o elemento ideal —, mas somente até a penúltima. A figura a seguir mostra a segunda iteração. O esquema de cores continua o mesmo.

![Bubblesort - 2ª iteração](https://github.com/user-attachments/assets/dc4f0047-3bb8-42cb-b1a8-86f1ff56f768)


Ao término dessa ação, os dois maiores elementos, 70 e 82, encontram-se, respectivamente, na penúltima e na última posições do vetor. Na próxima iteração, portanto, não será mais necessário visitar essa parte do vetor. As figuras a seguir apresentam os demais passos da ordenação.


![Bubblesort - 3ª iteração](https://github.com/user-attachments/assets/7adfde38-6366-4496-8e00-e9077dce302b)

![Bubblesort - 4ª iteração](https://github.com/user-attachments/assets/f9d4d7c8-b3f1-4c98-8aff-e05a764b09e6)

![Bubblesort - 5ª iteração](https://github.com/user-attachments/assets/461ca4fe-a709-415e-8418-c95daaeac054)

![Bubblesort - 6ª iteração](https://github.com/user-attachments/assets/7529b8a3-2111-45c6-8e23-e18045bdadf7)

![Bubblesort - 7ª iteração](https://github.com/user-attachments/assets/14523cf9-cc8d-4d32-841d-838a3ccf40b1)


Observa-se que ao final da sétima iteração para o vetor em questão (tamanho 8), temos marcado em cinza (ordenado) os índices de 1 a 7. Apesar do primeiro índice não conter essa marcação, não é possível comparar o elemento que nele se encontra com o próximo (a comparação é sempre dois a dois), pois o próximo já está na posição correta. Assim, esse elemento também já está na posição correta, o que implica que o vetor está completamente ordenado.

A listagem a seguir apresenta um programa em C que declara, inicializa e ordena o vetor de inteiros apresentado nas figuras acima. A função main invoca as funções de impressão do vetor (2 vezes) e ordenação.
A função de impressão apenas imprime o vetor na sua ordem atual e a função bubblesort(...) implementa o algoritmo Bubblesort.
Nesta função, o laço de repetição externo controla a área não cinza da representação do vetor, ao passo que o iterador interno representa a cor verde, limitado à área não cinza.

```c
#include <stdio.h>

void bubblesort(int v[], int t){
    int i, j, aux;
    for(i=t-1; i>0; i--){ //acesso ao vetor do último elemento até o segundo
        for(j=0; j<i; j++){
            if(v[j] > v[j + 1]){ //se verdade, troca
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }

}

void mostrar(int v[], int t){
    printf("Vet:");
    int i;
    for(i=0; i<t; i++) printf(" %d", v[i]);
}


int main(){
    int vet[] = {70, 21, 63, 50, 70, 82, 19, 48}; //declaração do vetor. Usa declaração do tamanho implícito com inicialização dos valores
    printf("Vetor original:\n");
    mostrar(vet, 8);
    bubblesort(vet, 8);
    printf("\nVetor ordenado:\n");
    mostrar(vet, 8);
    return 0;
}

```

A implementação de ordenação decrescente com o Bubblesort também é muito simples, sendo necessária apenas a troca do símbolo > (maior que) para < (menor que) no programa acima.

No exemplo acima, estava definido que o vetor teria tamanho 8, tendo inclusive inicializado seus valores. Nos problemas reais, geralmente não é isso que ocorre: a quantidade de dados normalmente depende de um valor informado pelo usuário, de modo que não pode ser definida pelo programador, mas sim em tempo de execução. 

Importante que as funções mostrar(...) e bubblesort(...) recebem o vetor. A referência *v[]* recebe o vetor *vet* declarado na função main(). Essa abordagem é chamada de passagem de parâmetro por referência. Na verdade, ao passar *vet* para a função bubblesort(...), por exemplo, o que está sendo efetivamente passado é o endereço do primeiro elemento do vetor. A função usa esse endereço para acessar e modificar os elementos do vetor original.

A passagem de parâmetro por referencia permite a alteração direta: qualquer modificação feita nos elementos do vetor dentro da função é refletida no vetor original, pois está sendo acessado o mesmo local na memória, não com uma cópia de valores. Essa abordagem é eficiente, especialmente para vetores grandes, pois evita a necessidade de copiar todos os elementos do vetor para a função. 

---

## Método de Seleção ou Selection Sort

O método Selection Sort, também chamado de método de ordenação por Seleção, é uma forma simples de fazer ordenação de vetores. 
Assim como no Bubblesort, são necessários dois laços de repetição. Para cada valor do iterador externo, há a execução de outra estrutura de repetição.

Considerando a ordenação crescente, o Seleciton Sort assume como menor elemento aquele que está no índice do vetor apontado pelo valor atual da variável de controle do iterador externo. Então, o iterador interno percorre o restante do vetor à procura de um elemento menor que aquele. 
Caso encontre, a variável responsável por guardar o índice do menor passa a apontar para esse índice encontrado.

Diferentemente do Bubblesort — que ao final da primeira iteração externa a última posição do vetor já estava ordenada —, o Selection Sort garante que ao final da primeira iteração externa o menor valor estará na primeira posição do vetor.

De forma ilustrativa, as figuras a seguir apresentam a ordenação crescente de um vetor de inteiros de tamanho 7. Considere um vetor de inteiros formado pelos elementos *70, 21, 63, 50, 70, 82, 19*. Cada figura representa uma iteração do laço externo. Nelas, a cor amarela representa o suposto menor valor, a cor verde é a procura por um valor menor que aquele suposto (cor amarela) e a cor cinza representa a área já ordenada.

![Selection Sort - 1ª iteração](https://github.com/user-attachments/assets/3bffe608-c869-4883-9fb6-997b97c848ad)

![Selection Sort - 2ª iteração](https://github.com/user-attachments/assets/adf14868-b617-47e6-a1c0-5c66ff76bd32)

![Selection Sort - 3ª iteração](https://github.com/user-attachments/assets/28bff0bb-f10b-43d2-8ea5-67194fc9ff8d)

![Selection Sort - 4ª iteração](https://github.com/user-attachments/assets/2d36930a-62c6-4cd1-a60f-30c7d9f31f9c)

![Selection Sort - 5ª iteração](https://github.com/user-attachments/assets/a6b545ac-4d44-4357-b64c-849abeaa63fd)

![Selection Sort - 6ª iteração](https://github.com/user-attachments/assets/f4f3f66f-956e-4fe0-82f1-056198433f1e)


Vale uma observação na última figura: os seis primeiros elementos estão marcados em cinza, a indicar que já se encontram em suas posições corretas. O último elemento, 82, não está marcado. Entretanto, de forma similar ao que ocorre com o Bubblesort, se todos os elementos estão em suas posições corretas, exceto um, isso implica que este também está na posição correta. Dessa forma, o vetor está ordenado.

A listagem a seguir apresenta a função selection_sort(int v[], int t). As funções main() e mostrar(int v[], int t) não são mostradas, mas são as mesmas usadas na listagem acima que apresenta o Bubblesort. 

```c
void selection_sort(int v[], int t){
    int i, j, aux;
    int iMinimo; //controlará o índice do menor elemento entre os que estão sendo ordenados
    for(i=0; i<t-1; i++){ //percorre o vetor do índice 0 até o penúltimo
        iMinimo = i; //assume que o menor elemento é o primeiro entre os não ordenados
        for(j=i+1; j<t; j++){ //percorre o vetor a partir do segundo entre os não ordenados com objetivo de encontrar um que seja menor do que aquele que foi assumido como menor.
            if(v[j] < v[iMinimo]){ //troca o valor de iMinimo
                iMinimo = j;
            } 
        }
        if(iMinimo != i){ //só troca se o menor já não estiver na posição correta
            aux=v[iMinimo];
            v[iMinimo]=v[i];
            v[i]=aux;
        }
    }
}
```

Para que este algoritmo seja adaptado para ordenação decrescente, basta mudar a comparação <  para > no *if* do *for* interno. 

---

>> 📅 Segunda-feira, 31/08/2026
## Método de Inserção ou Insertion Sort

O método de ordenação por inserção, ou Insertion Sort, consiste em “inserir” um elemento em uma posição tal que não haja, à sua esquerda, nenhum elemento maior do que ele, no caso de ordenação crescente. Diferentemente do Bubble Sort e do Selection Sort, em que, após a primeira iteração do laço externo, tem-se a garantia de que a última ou a primeira posição, respectivamente, está com o valor correto, não há essa garantia no Insertion Sort. Entretanto, há a certeza de que não existirão elementos à esquerda da posição analisada que sejam maiores do que ela (em caso de ordenação crescente) ou menores (em caso de ordenação decrescente).

Esse método é muito similar à forma como jogadores ordenam cartas na mão. Suponha que um jogador, após receber suas cartas em um jogo, deseje ordená-las da menor para a maior. De forma geral, ele pega uma carta e procura um espaço para inseri-la de modo que, à sua esquerda, não haja cartas maiores que ela.
Para isso, desloca outras cartas para a direita, “abrindo espaço” para a inserção. Em seguida, ele pega outra carta e executa o mesmo processo. Vamos chamar essa carta que ele deseja inserir de *chave*.
Em determinado momento, todas as cartas estarão ordenadas na mão do jogador. Esse é, também, o princípio do algoritmo tratado aqui.

As figuras abaixo apresentam o passo a passo da ordenação por inserção. Nelas, a cor verde indica o valor da chave em cada iteração; as partes verde e branca (somente a partir da verde) indicam as regiões de atuação do laço externo; a seta vermelha indica a posição atual apontada pelo laço interno; a cor amarela marca o espaço aberto para inserção da chave; e a cor cinza representa a parte já ordenada, embora ainda possam ser inseridos elementos entre quaisquer de seus valores.

As figuras a seguir apresentam a ordenação crescente de um vetor de inteiros de tamanho 7, formado pelos números *70, 21, 63, 50, 70, 82, 19*, utilizando o método de inserção. Cada figura representa uma iteração do laço externo.


![Insertion Sort - 1ª iteração](https://github.com/user-attachments/assets/65a764e9-f6ce-4ca2-9744-69586cb3c9cf)

![Insertion Sort - 2ª iteração](https://github.com/user-attachments/assets/aadfcab2-8469-438e-8a09-2476ade45f08)

![Insertion Sort - 3ª iteração](https://github.com/user-attachments/assets/736c21bc-5213-40ff-a345-462b2f9636c9)

![Insertion Sort - 4ª iteração](https://github.com/user-attachments/assets/63a6ce3e-143d-4afd-a99c-e5541af414b8)

![Insertion Sort - 5ª iteração](https://github.com/user-attachments/assets/7191306b-d2d8-4d6e-a39d-a54ad0a9c3f4)

![Insertion Sort - 6ª iteração](https://github.com/user-attachments/assets/c1719365-fd96-46c2-9eef-9917dd1db047)


A listagem a seguir apresenta a função insertion_sort(int v[], int t). As funções main() e mostrar(int v[], int t) não são apresentadas — elas são as mesmas usadas na listagem acima que apresenta o Bubblesort. 

```c
void insertion_sort(int v[], int t){
    int i, j, chave;

    for(i=1; i<t; i++){
        chave = v[i];
        j = i-1;

        while(j>=0 && v[j]>chave){ //só para quando j aponta para um local inexistente do vetor ou quando for encontrado um valor maior que a chave.
            v[j+1] = v[j]; //"abre um espaço" no índice j para a inserção da chave.
            j--;
        } 
        v[j+1] = chave; //como j sempre decrementa de 1, é necessário somar 1 a j para inserir a chave.
    }
}
```

---

>> 📅 Quarta-feira, 02/09/2026 

## Noção de Complexidade dos Algoritmos de Ordenação

Ao estudar algoritmos de ordenação (como os vistos anteriormente), é fundamental compreender como medir o seu desempenho. Para isso, utiliza-se a **análise de complexidade**, que estima o custo de execução de um algoritmo em função do tamanho da entrada (geralmente indicado por `n`, o número de elementos do vetor).

> A análise da complexidade de algoritmos é um disciplina dos cursos de bacharelado em computação, geralmente chamado de Projeto e Análise de Algoritmos (PAA). Essa análise não será feita na disciplina de Estrutura de Dados. 

Na análise de um algoritmo, é comum comparar:

- Número de comparações;
- Número de trocas (ou movimentações);
- Crescimento da complexidade conforme `n`(a quantidade dados) aumenta;

O principal objetivo dessa análise é responder:  
> *“Quão bem esse algoritmo escala?”*

Para isso, utiliza-se a comumente a notação **Big-O**, que descreve o comportamento assintótico do algoritmo — ou seja, como o custo cresce para valores grandes de `n`.


### Crescimento Quadrático — O(n²)

Os três algoritmos básicos vistos anteriormente possuem, no pior caso, uma característica comum: eles executam **dois laços aninhados**, cada um percorrendo o vetor (ou parte dele). Isso leva a uma quantidade de operações proporcional a:

$f(n) = n \\times n$, isto é, $f(n) = n^2$

Assim, podemos dizer que esses algoritmos pertecem à classe $O(n^2)$. 


Esse crescimento quadrático significa que, ao dobrar o tamanho da entrada, o tempo de execução cresce **quatro vezes**. Para `n` grande, isso se torna rapidamente ineficiente.


### Demonstração

Considere um laço duplo como nos algoritmos Bubblesort e Selection Sort:

```c
for(i=0; i<n; i++){
    for(j=0; j<n; j++){
        //código
    }
}
```

O número total de comparações pode ser aproximado pela soma:
$S = (n − 1) + (n − 2) + (n − 3) + ... + 1$

Essa soma é uma **progressão aritmética**, que pode ser escrita como $S = \\frac{n(n − 1)}{2}$, ou ainda, $S = \\frac{n^2 - n}{2}$.



Embora o valor exato seja $S = \\frac{n^2 - n}{2}$, na notação Big-O considera-se apenas a ordem de crescimento — e o termo dominante é $n^2$, ou seja, $O(n^2)$.

É importante destacar que a classe a qual um algoritmo pertence diz respeito ao seu custo no pior caso, que no caso de muitos algoritmos de ordenação ocorre quando o vetor está ordenado na ordem inversa àquela desejada. 

> Algoritmos de ordem quadrática não são adequados para grandes volumes de dados, sendo necessário utilizar abordagens mais sofisticadas. 

---

## Algoritmos de Busca

Muitas aplicações computacionais dependem da recuperação eficiente de informações. Encontrar o nome de um contato no celular, localizar um produto em um sistema de estoque, identificar um registro em um banco de dados ou determinar se um elemento pertence a uma coleção — todas essas ações envolvem **algoritmos de busca**.

O objetivo de um algoritmo de busca é *localizar um elemento específico*, dentro de uma estrutura de dados, como por exemplo, vetores. Dependendo da técnica utilizada, essa busca pode ser mais rápida, mais simples ou exigir condições especiais, como um conjunto previamente ordenado.

Entre os métodos mais conhecidos estão:

- **Busca Sequencial (ou Linear)** — simples, não exige ordenação e percorre os elementos um a um.
- **Busca Binária** — muito mais eficiente, porém exige que os dados estejam ordenados.

Nesta seção, estudaremos o método mais básico: a **busca sequencial**.


### Busca Sequencial

O método de **busca sequencial**, também conhecido como busca linear, consiste em verificar cada elemento da estrutura, um após o outro, até que a chave de busca seja encontrada ou que o fim do vetor seja alcançado.

Seu funcionamento é direto: a chave com o primeiro elemento; se forem diferentes, a chave é comparada com o segundo; e assim sucessivamente. Caso haja coincidência, o algoritmo retorna a posição do elemento. Se o vetor chegar ao fim sem encontrar a chave, conclui-se que ela não está presente.

>**Exemplo:** um jogador está procurando uma carta específica em um monte desorganizado. Ele observa a primeira, depois a segunda, depois a terceira, até encontrar o valor desejado ou chegar ao final do monte. Esse é exatamente o comportamento da busca sequencial.


**Características:**

- Não exige estrutura ordenada;
- Implementação simples;
- Pode encerrar antes do fim, caso encontre a chave;
- Custos variáveis conforme a posição da chave;
- Ineficiente para vetores grandes.

Consideremos o vetor de inteiros formado pelos números *70, 21, 63, 50, 70, 82, 19* e chave 50. O algoritmo fará as seguintes iterações: 

1. `70` → diferente;  
2. `21` → diferente  
3. `63` → diferente  
4. `50` → **encontrado**

A busca encerra na 4ª comparação e retornará o índice `3`. 

A listagem abaixo apresenta a implementação da busca sequencial, escrita em linguagem C.

```c
int busca_sequencial(int v[], int t, int chave){

    int i;
    for(i=0; i<t; i++){ //pode percorrer todo o vetor;
        if(v[i] == chave) return i; //a chave foi encotrada, logo, retorno o índice onde ela foi encontrada. Observa-se que se a chave estiver repetida no vetor, o algoritmo retornará a primeira ocorrência. 
    }
    return -1; //-1 indica que a chave não foi encontrada.
}

```

### Busca Binária

Embora a busca sequencial seja simples e funcione em qualquer vetor, ela pode ser pouco eficiente em estruturas grandes. Em cenários nos quais o conjunto de dados está **ordenado**, é possível utilizar métodos muito mais rápidos — e o mais clássico deles é a **Busca Binária**.

A ideia central da busca binária é reduzir drasticamente o espaço de busca a cada passo. Em vez de analisar elemento por elemento, o algoritmo divide o vetor ao meio e verifica em qual das metades a chave de busca pode estar, descartando a outra metade imediatamente. Como essa eliminação ocorre a cada iteração, o método se torna extremamente eficiente.

> **Condição obrigatória**: o vetor deve estar ordenado. Sem essa condição, a busca binária não funciona.

> **Exemplo de aplicação:** imagine procurar um número em uma lista telefônica impressa. Ninguém lê página por página como na busca sequencial; em vez disso, abre-se o livro aproximadamente no meio e verifica-se se o nome procurado estaria antes ou depois daquela página. Em seguida, repete-se o processo apenas com a metade relevante. Esse é exatamente o princípio da busca binária, chamado **dividir para conquistar**.

**Funcionamento geral:** (considere um vetor ordenado de forma crescewnte)

1. Defina duas posições: `esquerda` (início) e `direita` (fim do vetor);
2. Calcule o índice do `meio`.
3. Compare o elemento do meio com a `chave` de busca:
   - Se forem iguais, significa que a chave foi encontrada e encerre, com o retorno do índice;
   - Se a chave for menor, descarte a metade direita;
   - Se a chave for maior, descarte a metade esquerda;
4. Repita o processo até encontrar o valor ou até que não haja mais elementos para pesquisar.

Consideremos o vetor de inteiros ordenado (necessariamene) formado pelos números *19, 21, 50, 63, 70, 70, 82* e chave 50. As imagens a seguir apresentam os passos dessa busca. O índice destacado em verde representa a posição apontada no momento atual, ao passo que a parte cinza é descarcatada pelo algoritmo.

![Busca binária - 1ª iteração](https://github.com/user-attachments/assets/b2d36819-713f-40ae-9f9f-2e67ec29b34a)

Como o meio é maior que a chave (50), descarta-se todas as posições do meio para a direita e segue para a próxima iteração. 

![Busca binária - 2ª iteração](https://github.com/user-attachments/assets/884619ee-368e-45be-b08b-334d61e518c6)

Como o meio é menor que a chave (50), descarta-se todas as posições do meio para a esquerda e segue para a próxima iteração. As posições que já haviam sido descartadas continuam no mesmo estado.

![Busca binária - 3ª iteração](https://github.com/user-attachments/assets/12e2cddf-17ff-4471-94c9-b15339b1906e)

A variável `meio` aponta para um índice que guarda exatamente a um valor igual à chave. Assim, o algoritmo retorna esse índice (no exemplo é o 2). 

Observa-se que se a chave fosse um valor que não estivesse no vetor, por exemplo 48, a variável `fim` seria atualizada para apontar para o índice `meio - 1`, o seja, `1`, enquanto a variável `início` continuaria a apontar para o índice `2`. Com `fim` menor do que `início`, chega-se à conclusão que a chave não está no vetor. 


A listagem abaixo apresenta a implementação da busca binária, escrita em linguagem C.

```c
int busca_binaria(int v[], int t, int chave){
    int inicio = 0, fim = t-1, meio;

    while(inicio <= fim){ // O código será executado enquanto inicio e fim não se cruzarem ou enquanto não for encontrado o returno.
        meio = (inicio + fim) / 2; // Cálculo do meio;
        if(v[meio] == chave) return meio; // Verificação se o meio aponta para o índice onde está a chave. Se sim, retorna;

        if(v[meio] > chave) fim = meio - 1; // Senão e se o meio aponta para  um índice que tem um número maior que a chave, então a chave está para a esquerda
        else inicio = meio + 1; // Caso contário, a chave estará para a direita. 
    }
    return -1; //-1 indica que a chave não foi encontrada.
}
```

A busca binária também pode ser facilmente implementada usado a abordagem recursiva, da seguinte forma: 
```c
int busca_binaria_recursiva(int v[], int inicio, int fim, int chave){
    
    if(inicio > fim) return -1;

    int meio = (inicio + fim) / 2;

    if(v[meio] == chave) return meio;

    if(v[meio] > chave) return busca_binaria_recursiva(v, inicio, meio - 1, chave);

    return busca_binaria_recursiva(v, meio + 1, fim, chave);
}
```

*Desafio:* (i) leia ou gere um vetor de 1000 posições; (ii) ordene esse vetor; (iii) utilize as abordagem de busca sequencial e busca binária, contando quantas iterações são necessárias. Use números distintos, inclusive com valores que não estão no vetor.   

---

>> 📅 Quarta-feira, 09/09/2026 

## Um Algoritmo de Ordenação sofisticado: Merge Sort

O **Merge Sort** é um algoritmo de ordenação baseado na estratégia **Dividir para Conquistar**. Sua ideia central consiste em dividir o vetor em partes cada vez menores, ordenar essas partes e, em seguida, **intercalar** (*merge*) os subvetores ordenados até reconstruir o vetor final em ordem crescente (ou decrescente, dependendo da aplicação).

Enquanto algoritmos vistos até aqui realizam o processo diretamente no vetor, o Merge Sort adota uma abordagem mais estruturada: **primeiro divide, depois ordena**.


### Estratégia “Dividir para Conquistar”

O Merge Sort segue três etapas principais:

| Etapa | Ação |
|---------|------|
| **Dividir** | Particionar o vetor ao meio recursivamente até restarem vetores de 1 elemento |
| **Conquistar** | Ordenar cada metade (recursivamente) |
| **Combinar** | Juntar (intercalar) os vetores menores em um vetor maior e ordenado |




> **Exemplo de aplicação:** imagine dividir uma pilha de cartas repetidamente em duas até que cada pilha tenha apenas uma carta. Uma carta sozinha já está ordenada. Depois, você começa a juntar as pilhas duas a duas, sempre mantendo a ordem ao intercalar. No final, todas as junções terão sido feitas, e as cartas estarão ordenadas.


**Funcionamento passo a passo:** as figuras a seguir apresentam a ordenação crescente de um vetor de inteiros de tamanho 7, formado pelos números *70, 21, 63, 50, 70, 82, 19*, utilizando o Merge. A primeira figura apresenta a fase de divisão.


![Merge Sort - fase de divisão](https://github.com/user-attachments/assets/0dc2ced1-3978-4dd6-b8ed-6e605b1d06e3)

O vetor é dividido em subvetores até que se tornem vetores unitários, ou seja, são divididos enquanto `início` for menor do que o `fim`. Deve-se lembrar que um vetor unitário está necessariamente ordenado, por definição. 

Após o vetor se dividido em vetores unitários, segue para a fase de mescla (*merge*), que é feito intercalando os vetores resultantes.

![Merge Sort - fase de merge](https://github.com/user-attachments/assets/d409fc3e-4ccf-435f-8b4c-2de03adf8690)

A listagem a seguir apresenta as funções merge_sort(int v[], int inicio, int fim) e merge(int v[], int inicio, int meio, int fim).

```c
void merge(int v[], int inicio, int meio, int fim) {
    int com1 = inicio, com2 = meio+1, comAux = 0, tam = fim-inicio+1;
    int vetAux[tam];

    while(com1 <= meio && com2 <= fim){
        if(v[com1] < v[com2]) {
            vetAux[comAux] = v[com1];
            com1++;
        } else {
            vetAux[comAux] = v[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = v[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = v[com2];
        comAux++;
        com2++;
    }

    for(comAux = inicio; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        v[comAux] = vetAux[comAux-inicio];
    }
}

void merge_sort(int v[], int inicio, int fim){
    if (inicio < fim) {
        int meio = (fim+inicio)/2;

        merge_sort(v, inicio, meio);
        merge_sort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}

```

### Considerações sobre a Complexidade do Merge Sort

O Merge Sort apresenta uma das análises de complexidade mais elegantes entre os algoritmos de ordenação. Isso se deve ao fato de sua estrutura recursiva seguir fielmente o paradigma Dividir para Conquistar. Seu desempenho é resultado direto do modo como o algoritmo:

1. **divide** o vetor repetidamente ao meio;
2. **resolve** recursivamente cada subparte; e
3. **combina** (intercala) os subvetores ordenados.

#### Quantidade de divisões

A cada chamada recursiva, o Merge Sort divide o vetor em 2 partes iguais. Esse processo continua até que cada subvetor tenha apenas 1 elemento, o que representa a condição base da recursão (pois um elemento já está ordenado).

Dado `n` o número de elementos, a quantidade de divisões até chegar a subvetores unitários é: $$\log_{2}(n)$$ (por que a divisão é binária).


Portanto, a recursão tem **profundidade logarítmica**.

### Custo em cada nível da recursão

Após dividir, o algoritmo precisa intercalar os subvetores para reconstruir o vetor ordenado. Em cada nível da árvore recursiva, a fusão (merge) percorre todos os elementos do vetor, realizando comparações e cópias. Assim, o custo de cada nível é proporcional a `n`. 


Como há $\log_{2}(n)$ níveis e cada nível custa aproximadamente `n`, o custo total é a multiplicação: $n \times \log_{2}(n)$. Como a conversão da base do logaritmo pode ser feita com a multiplicação do próprio logarítimo por uma constante `c`. Assim, a complexidade do Merge Sort é $O(n\log(n))$.





