/*
    Um identificador válido e composto por um ou mais caracteres
    consistentes em letras, dígitos e sublinhados, sendo que:
    - não pode começar com dígito;
    - não pode ser uma palavra reservada da linguagem;
    - apenas letras do alfabeto inglês podem ser utilizadas;
    - um identificador pode ter qualquer cumprimento 
         - apenas os 31 primeiros caracteres são reconhecidos;
    - a linguagem C é case sensitive, ou seja:
        - variáveis que se diferenciam por utilizarem 
        caracteres minúsculos e maiúsculos, são diferentes;
        (NoMe diferente de Nome diferente de NOME diferente de nome)
*/

#include <stdio.h>
#include <limits.h>

/*
    Exemplo - 02:
    Declarando e utilizando variáveis para representar números
    inteiros.
    * Para imprimir valores literais o variáveis de tipo int se
    utiliza o formatador %d ou %i.
    * O operador sizeof retorna o tamanho de uma variável ou de 
    um tipo, em bytes.
    * O arquivo de cabeçalhos limits.h define alguns símbolos e
    funções para manipulação de valores inteiros.
    * O modificador long se aplica ao tipo int e duplica a 
    quantidade de bytes utilizados na representação.
    * Para imprimir valores literais o variáveis de tipo long int se
    utiliza o formatador %ld.
    * O modificador unsigned se aplica ao tipo int e duplica o 
    intervalo dos números positivos que podem ser representados,
    eliminando o sinal na representação;
    * Para imprimir valores literais o variáveis de tipo unsigned int se
    utiliza o formatador %u.

*/

int main(void)
{   
    printf(" __________________________________\n");
    printf("| Declaração de Variáveis Inteiras |\n");
    printf(" __________________________________\n");
    int x; // declarando uma variável de tipo inteiro
    x = 1; // inicializando o valor da variável
    // string formatada para imprimir um int
    printf("A variável int x = %d\n", x);
    printf("O tamanho de um int: %d bytes\n", sizeof(int));
    // INT_MIN e INT_MAX estão definidos em limits.h
    printf("Menor e maior valor representável com um int.\n");
    printf("INT_MIN= %d, INT_MAX= %d\n", INT_MIN, INT_MAX);
    
    
    // Modificadores
    printf(" ________________\n");
    printf("| Modificadores: |\n");
    printf(" ________________\n");

    printf("\nInteiro sem sinal: \n ");
    printf("O tamanho de um unsigned int: %d bytes\n", sizeof(unsigned int));
    printf("O maior valor representável com um unsigned int.\n");
    // string formatada para imprimir um unsigned int
    printf("UINT_MAX= %u\n", UINT_MAX);
    unsigned int ux, uy; // declarando múltiplas variáveis
    // operadores são detalhados mais na frente
    ux = INT_MAX/2;
    uy = INT_MAX + ux; 
    printf("A variável unsigned ux = %u\n", ux);
    printf("A variável unsigned uy = %u\n", uy);

    printf("\nInteiro longo: \n ");
    printf("O tamanho de um long int: %d bytes\n", sizeof(long int));
    // LONG_MIN e LONG_MAX estão definidos em limits.h
    printf("Menor e maior valor representável com um long.\n");
    // string formatada para imprimir um long int
    printf("LONG_MIN= %ld, LONG_MAX= %ld\n", LONG_MIN, LONG_MAX);
    // operadores são detalhados mais na frente
    long int lx = uy + ux; // declarando e inicializando
    printf("A variável long int lx = %ld\n", lx);

    printf("\nInteiro curto: \n ");
    printf("O tamanho de um short int: %d bytes\n", sizeof(short int));
    printf("Menor e maior valor representável com um short.\n");
    // string formatada para imprimir um short int
    printf("SHRT_MIN= %d, SHRT_MAX= %d\n", SHRT_MIN, SHRT_MAX);
    // operadores são detalhados mais na frente
    short int sx = SHRT_MAX/2;
    printf("A variável short int sx = %d\n", sx);

    printf("\nInteiro curto sem sinal: \n ");
    unsigned short int usx;
    printf("O tamanho de um unsigned short int: %d bytes\n", sizeof(usx));
    printf("O maior valor representável com um unsigned short.\n");
    // string formatada para imprimir um  unsigned short int
    printf("USHRT_MAX= %u\n", USHRT_MAX);
    // operadores são detalhados mais na frente
    usx = SHRT_MAX + sx;
    printf("A variável unsigned short int usx = %u\n", usx);

    printf("\nInteiro longo sem sinal: \n ");
    unsigned long int ulx;
    printf("O tamanho de um unsigned long int: %d bytes\n", sizeof(ulx));
    printf("O maior valor representável com um unsigned long.\n");
    // string formatada para imprimir um  unsigned long int
    printf("ULONG_MAX= %lu\n", ULONG_MAX);
    ulx = usx + ux;
    printf("A variável unsigned long int ulx = %u\n", ulx);

    // Escolha nomes significativos para suas variáveis
    int somaTotal, maiorValor, menorValor, valorMedio;
    // Operadores com int

    printf(" ____________________\n");
    printf("| Operadores con int |\n");
    printf(" ____________________\n");
    printf("Operador de atribuição\n");
    // Lembrando da necessidade de inicializar as variáveis

    x = 5; // Operador de atribuição
    int x1, x2, x3, x4, x5;
    printf("x = %d\n", x);
    // atribuições múltiplas em um único comando
    x1 = x2 = x3 = x4 = x5 = x;
    printf("x1 = %d, x2 = %d, x3 = %d, x4 = %d, x5 = %d,\n", 
            x1, x2, x3, x4, x5);
    // Operadores Aritméticos
    printf(" _____________________\n");
    printf("| Operadores binários |\n");
    printf(" _____________________\n");
    // Operadores binários
    x1 = x2 + x3; // adição
    printf("Adição (+) ");
    printf("%d + %d = %d\n", x2, x3, x1);
    x2 = x3 - x4; // substração
    printf("Substração (-) ");
    printf("%d - %d = %d\n", x3, x4, x2);
    printf("O operador (-) também pode ser utilizado como\n");
    printf("operador unário\n");
    printf("x3 = %d \n", x3);
    printf("-x3 = %d \n", -x3); // utilizado como operador unário
    x5 = x1 * x4; // multiplicação
    printf("Multiplicação (*) ");
    printf("%d * %d = %d\n", x1, x4, x5);
    printf("Divisão inteira (/) \n");
    x = 4 / 2; // Divisão inteira
    printf("4 / 2 = %d\n", x);
    x = 5 / 2; // Divisão inteira (truncada)
    printf("5 / 2 = %d\n", x);
    printf("Resto da divisão (\%%) \n");
    x = 4 % 2; // Resto da divisão
    printf("4 \%% 2 = %d\n", x);
    x = 5 % 2; // Resto da divisão
    printf("5 \%% 2 = %d\n", x);
    printf(" _____________________________________\n");
    printf("| Expressão com múltiplos operadores: |\n");
    printf(" _____________________________________\n"); 
    somaTotal = x1 + x2 - x3 * x4 / x5 % x;
    printf("%d + %d - %d * %d / %d \%% %d = %d\n", x1, x2, x3, x4, x5, x, somaTotal);
    printf("Usando parêntesis para criar uma expressão equivalente: \n");
    somaTotal = ((x1 + x2) - (((x3 * x4) / x5) % x));
    printf("( (%d + %d) - ( ( (%d * %d) / %d) \%% %d) ) = %d\n", x1, x2, x3, x4, x5, x, somaTotal);
    printf("Usando parêntesis para gerar uma expressão diferente: \n");
    somaTotal = ((x1 + x2) - (x3 * (x4 / x5))) % x;
    printf("( (%d + %d) - (%d * (%d / %d)) \%% %d) ) = %d\n", x1, x2, x3, x4, x5, x, somaTotal);
    somaTotal = x1 + x2 + x3 + x4 + x5;
    printf("%d + %d + %d + %d + %d = %d\n", x1, x2, x3, x4, x5, somaTotal);

    // Operadores de incremento e decremento
    printf(" ________________________________________\n");
    printf("| Operadores de Incremento e decremento: |\n");
    printf(" ________________________________________\n");
    printf("x = %d\n", x);
    //++a; // a = a + 1
    printf("++x = %d\n", ++x);
    printf("x++ = %d\n", x++);
    printf("x = %d\n", x);
    //--a;
    printf("--x = %d\n", --x);
    printf("x-- = %d\n", x--);
    printf("x = %d\n", x);
    
    // Operadores compostos
    printf(" __________________________\n");
    printf("| Operadores de Compostos: |\n");
    printf(" __________________________\n");
    printf("x = %d\n", x);
    x += 5; // x = x + 5
    printf("x += 5 -> x = %d\n", x);
    x -= 3; // x = x - 3
    printf("x -= 3 -> x = %d\n", x);
    x *= 4; // x = x*4
    printf("x *= 4 -> x = %d\n", x);
    x /= 2; // x = x/2
    printf("x /= 2 -> x = %d\n", x);
    x %= 3; // x = x%3
    printf("x %%= x -> x = %d\n", x);

    // Operadores Relacionais
    printf(" ____________________________\n");
    printf("| Operadores de Relacionais: |\n");
    printf(" ____________________________\n");
    printf("Retornam 0 quando falso e 1 quando verdadeiro\n");
    printf("1 > 2 -> %d\n", 1 > 2);
    printf("2 > 1 -> %d\n", 2 > 1);
    printf("Maior que (>) \n");
    printf("%d > %d = %d\n", x1, x2, x1 > x2);
    printf("%d > %d = %d\n", x2, x1, x2 > x1);
    printf("Maior ou igual que (>=) \n");
    printf("%d >= %d = %d\n", x3, x4, x3 >= x4);
    printf("%d >= %d = %d\n", x2, x4, x2 >= x4);
    printf("Menor que (<) \n");
    printf("%d < %d = %d\n", x1, x2, x1 < x2);
    printf("%d < %d = %d\n", x2, x1, x2 < x1);
    printf("Menor ou igual que (<=) \n");
    printf("%d <= %d = %d\n", x3, x4, x3 <= x4);
    printf("%d <= %d = %d\n", x4, x2, x4 <= x2);
    printf("Igual a (==) \n");
    printf("%d == %d = %d\n", x3, x4, x3 == x4);
    printf("%d == %d = %d\n", x2, x4, x2 == x4);
    printf("Diferente de (!=) \n");
    printf("%d != %d = %d\n", x3, x4, x3 != x4);
    printf("%d != %d = %d\n", x2, x4, x2 != x4);

    printf(" ________________________\n");
    printf("| Operadores de Lógicos: |\n");
    printf(" ________________________\n");
    int v_ = 1, f_ = 0;
    printf("Retornam 0 quando falso e 1 quando verdadeiro\n");
    printf("1 && 1 -> %d\n", 1 && 1);
    printf("0 || 0 -> %d\n", 0 || 0);
    printf("Tabela da Verdade\n");
    printf("  \t   \t AND \t\t OR \t\t NOT\n");
    printf("a \t b \t a&&b \t\t a||b \t\t !a\n");
    printf("%d \t %d \t %d \t\t %d \t\t %d\n", f_, f_, f_ && f_, f_ || f_, !f_);
    printf("%d \t %d \t %d \t\t %d \t\t %d\n", f_, v_, f_ && v_, f_ || v_, !f_);
    printf("%d \t %d \t %d \t\t %d \t\t %d\n", v_, v_, v_ && v_, v_ || v_, !v_);
    printf("%d \t %d \t %d \t\t %d \t\t %d\n", v_, f_, v_ && f_, v_ || f_, !v_);
    
    return 0;
}
