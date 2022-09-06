# Exemplo - 02: Declarando e utilizando variáveis para representar números inteiros. #

Um identificador válido e composto por um ou mais caracteres consistentes em letras, dígitos e sublinhados, sendo que:
* O identificador não pode começar com dígito;
* O identificador não pode ser uma palavra reservada da linguagem;
* Apenas letras do alfabeto inglês podem ser utilizadas;
* um identificador pode ter qualquer quantidade de caracteres
    * apenas os 31 primeiros caracteres são reconhecidos;
* a linguagem C é case sensitive, ou seja:
    * variáveis que se diferenciam por utilizarem caracteres minúsculos e maiúsculos, são diferentes;
    (NoMe diferente de Nome diferente de NOME diferente de nome)
* Escolha nomes significativos para suas variáveis;
Existem diversas estratégias utilizadas para escolher os nomes das variáveis:
https://youtu.be/MtQoWQForqE
1. CamelCase: é uma maneira de separar as palavras em uma frase colocando a primeira letra de cada palavra em maiúscula e não usando espaços. A primeira letra pode ou não ser maiúscula no CamelCase. Essa diferença é chamada UpperCamelCase e lowerCamelCase. Em C, quando adotada esta estrategia, se recomenda utilizar lowerCamelCase;
__Exemplos__: 
    a. NomeEmCamelCase
    b. nomeEmCamelCase
    c. NAOCAMELCASE
    d. tambem_nao_camel_case
__Limitações__:
    a. NASAFiles
    b. NasaFiles
2. Snake Case: é uma maneira de separar as palavras em uma frase utilizando sublinhado (underscore) no lugar do espaço. 
__Exemplos__:
    a. nome_em_snake_case
    b. NOME_EM_SNAKE_CASE
3. Kebab Case: é uma maneira de separar as palavras em uma frase utilizando traço (sinal menos) no lugar do espaço. __Em C não é possível utilizar este caractere especial no nome de uma variável, apenas o sublinhado.__
__Exemplos__:
    a. nome-em-kebab-case
    b. NOME-EM-KEBAB-CASE 
Nos exemplos utilizamos camel case. 

Veja alguns aspectos abordado no exemplo desta pasta:

* Para imprimir valores literais o variáveis de tipo ```int``` se utiliza o formatador ```%d``` ou ```%i```.
* O operador ```sizeof``` retorna o tamanho de uma variável ou de um tipo, em bytes.
* O arquivo de cabeçalhos ```limits.h``` define alguns símbolos e funções para manipulação de valores inteiros.
* O modificador unsigned se aplica ao tipo ```int``` e duplica o intervalo dos números positivos que podem ser representados eliminando o sinal na representação;
* Para imprimir valores literais o variáveis de tipo unsigned int se utiliza o formatador ```%u```.
* O modificador ```long``` se aplica ao tipo ```int`` e duplica a quantidade de bytes utilizados na representação.
* Para imprimir valores literais o variáveis de tipo long ```int``` se utiliza o formatador ```%ld```.
* O modificador ```short``` se aplica ao tipo ```int`` e diminui pela metade a quantidade de bytes utilizados na representação.
* Os modificadores ```long```e ```short```podem ser combinados com ```unsigned```.
