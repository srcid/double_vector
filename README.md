# DoubleVector

Atividade da disciplina de estrutura de dados

## Lista sequêncial dupla

Na Lista Sequencial Dupla, os elementos da lista são armazenados do meio para os extremos no vetor *m_list*, de forma que teremos espaço para inserirmos um elemento tanto no final como no inicio da lista sem a necessidade de realizarmos um deslocamento dos elementos do vetor. Logo, a complexidade dessas funções serão $O(1)$.

Para isso, essa nova estrutura de dados (ED) terá dois novos atributos, dois inteiros *m_head* e *m_tail*. *m_head* e *m_tail* irão indicar qual ı́ndice do vetor iremos adicionar o próximo elemento quando a função push f ront e push back for executada, respectivamente.

Vejamos a configuração inicial dessa lista. m capacity será inicialmente igual a 16 e *m_head* será igual a 7 e *m_tail* igual a 8. Toda vez que push f ront for executada, o elemento será adicionado no ı́ndice *m_head* e, depois ele será decrementado. De forma semelhante, toda vez que push back for executada, o elemento será adicionado no ı́ndice *m_tail* e, depois ele será incrementado. Dessa forma, os elementos serão adicionados do meio para os extremos do vetor e a complexidade média das operações push front e push back será $O(1)$.

![Figura 1 - Configuração inicial da lista sequencial dupla][list_init]

Suponha que as funções sejam executadas nesta sequência: $push\_back(78)$, $push\_front(55)$, $push\_back(93)$,$push\_back(20)$, então o vertor da lista ficará comforme a figura abaixo:

![Figura 2 - Lista após inserções][list_first_insertions]

> [!NOTE]
> Como citado anteriormente, na lista sequencial normal, o índice do elemento na lista é o mesmo do vetor, ou seja, o elemento de índice 4 na lista está armazenado no índice 7 do vetor. O mesmo não ocorre na lista sequencial dupla. Tirando como exemplo a figura acima, o elemento de indice 0 da lista é o valor 55, que deve estar no índice 7 do vetor. O elemento de índice 3 da lista é o valor 20, que está no indice 10 do vetor.

Continuaremos a ter as operações de deslocamento e redirecionamento. Elas serão executadas nas seguintes situações.

## Deslocamento

Teremos duas operações de deslocamento, que chamaremos de deslocamento completo e deslocamento parcial. Vejam abaixo a descrição de ambas e quando usa-las.

### Deslocamento copleto

A operação de deslocamento completo será executada quando ainda existir espaço disponı́vel no vetor, e quando uma das seguintes situações abaixo ocorrer:

1. Quando a operação de push_front for executada e não tiver espaço disponı́vel no inı́cio do vetor;
2. Quando a operação de push_back for executada e não houver espaço disponı́vel no final do vetor.

Então, a operação de deslocamento deve ser feito para dividir igualmente (se posı́vel) os espaços livres entre o inicio e final do vetor.

### Deslocamento parcial

O deslocamento parcial será executada quando um elemento da lista for removido. Nesse caso, desvemos deslocar em uma posição apenas uma parte dos elementos do vetor, os elementos que estão a esquerda ou direita do elemento a ser removido. Observe que dentro do contexto da lista sequencial dupla, podemos deslocar esses elementos tanto
para a esquerda quanto para a direita.

O deslocamento será feito na direção que tiver menos espaços disponı́veis, ou seja, se na frente do vetor tiver menos espaços disponı́veis do que atrás, então iremos deslocar os elementos que estão a esquerda do elemento removido para a direita em uma posição. Caso contrário, se for atrás do vetor que tiver menos espaço, então iremos deslocar os elementos que estão a direita do elemento removido para a esquerda em uma posição. 

### Redimensionamento

Devemos alocar um novo vetor, duplicando a capacidade da lista. Depois copiamos os elementos do vetor antigo para o novo, deixando a quantidade iguais (se possı́vel) de espaços disponı́vel na frente e atrás do vetor.

## Metódos

A sua estrutura de dados deve ser encapsulada por uma classe chamada __DoubleVector__, que suporta as seguintes operações.

- `DoubleVector()`: Construtor da classe. Deve iniciar todos os atributos da classe de acordo com a descrição acima da lista.

- `DoubleVector(int n)`: Construtor da classe. Aloca o vetor com capacidade n, deixando espaços disponı́veis na frente e atrás iguais.

- `∼DoubleVector()`: Destrutor da classe. Libera memória previamente alocada.

- `int size()`: Retorna o numero de elementos na lista.

- `bool empty()`: Retorna true se a lista estiver vazia e false caso contrário.

- `void push back(int value)`: Insere o inteiro value ao final da lista.

- `int pop back()`: Remove elemento do final da lista e retorna seu valor.

- `void push front(int value)`: Insere o inteiro value no inicio da lista.

- `int pop front()`: Remove elemento do inicio da lista e retorna seu valor.

- `int at(int k)`: Retorna o elemento da lista de ı́ndice k (Cuidado, é o ı́ndice da lista e não do vetor). A função verifica se k esta dentro dos limites de elementos
validos. Caso contrário, retorna -1. Obrigatoriamente deve ser O(1).

- `void shift()`: Realiza o deslocamento completo, seja para a direita ou esquerda, de acordo a descrição na Seção 1.1.1. Caso desejem, podem dividir em duas funções lef t shif t e right shif t.

- `void rezise()`: Realiza o redimensionamento, de acordo a descrição na Seção 1.2.

- `void remove(int k)`: Remove o elemento de ı́ndice k da lista (Cuidado, é o ı́ndice da lista e não do vetor) de acordo a descrição na Seção 1.1.2. A ordem dos demais elementos da lista devem se manter.

- `void removeAll(int value)`: Remove da lista todas as ocorrências de value. A ordem dos demais elementos da lista entre se devem se manter.

- `void print()`: Imprime os elementos da lista.

- `void printReverse()`: Imprime os elementos da lista em ordem reversa.

- `void concat(DoubleVector& lst)`: Concatena a lista atual com a lista lst passada por parâmetro. A lista lst não é modificada nessa operação. Os elementos de lst serão adicionados na ordem no final da lista do objeto da função.

- `bool equal(DoubleVector& lst)`: Determina se a lista passada por parâmetro é igual à lista em questão. Duas listas são iguais se elas possuem o mesmo tamanho e o valor do k-ésimo elemento da primeira lista é igual ao k-ésimo elemento da segunda lista


[list_init]: ./assets/atividade_mae-configuracao_inicial.svg
[list_first_insertions]: ./assets/atividade_mae-primeiras_insercoes.svg