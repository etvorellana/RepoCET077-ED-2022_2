#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("Imprimindo um caractere: %c\n", 'a');
    printf("As variáveis de tipos char armazenam valores numéricos:\n");
    printf("O caractere %c é representado pelo valor %d\n", 'A', 'A');
    printf("O caractere %c é representado pelo valor %d\n", 'Z', 'Z');
    printf("O caractere %c é representado pelo valor %d\n", 'a', 'a');
    printf("O caractere %c é representado pelo valor %d\n", 'z', 'z');
    printf("O caractere %c é representado pelo valor %d\n", '0', '0');
    printf("O caractere %c é representado pelo valor %d\n", '9', '9');

    printf(" __________________________________\n");
    printf("| Declaração de Variáveis char    |\n");
    printf(" __________________________________\n");
    char ch; // declarando uma variável de tipo char
    ch = 65; // inicializando utilizando um valor inteiro
    // string formatada para imprimir um char
    printf("A variável int ch = %c\n", ch);
    printf("O tamanho de um char: %d bytes\n", sizeof(char));
    printf("Da biblioteca limits.h temos");
    printf("CHAR_BIT - Número de bits em um byte: %d\n", CHAR_BIT);
    printf("SCHAR_MIN -	Valor mínimo para um caractere com sinal: %d\n", SCHAR_MIN);
    printf("SCHAR_MAX -	Valor máximo para um caractere com sinal: %d\n", SCHAR_MAX);
    printf("UCHAR_MAX -	Valor máximo para um caractere sem sinal: %u\n", UCHAR_MAX);
    printf("CHAR_MIN -	Valor mínimo para um caractere: %d\n", CHAR_MIN);
    printf("CHAR_MAX -	Valor máximo para um caractere: %d\n", CHAR_MAX);
    
    // INT_MIN e INT_MAX estão definidos em limits.h
    printf("Menor e maior valor representável com um int.\n");
    printf("INT_MIN= %d, INT_MAX= %d\n", INT_MIN, INT_MAX);
    
    char ch_A = 'A', ch_Z = 'Z', ch_a = 'a', ch_z = 'z';
    char ch_0 = '0', ch_9 = '9';
    // Operadores com char

    printf(" ____________________\n");
    printf("| Operadores con char |\n");
    printf(" ____________________\n");
    printf("Operador de atribuição\n");
    // Lembrando da necessidade de inicializar as variáveis

    ch = '('; // Operador de atribuição
    printf("ch = %d - %c\n", ch, ch);
    printf("ch_A = %d - %c, ch_Z = %d - %c, ch_a = %d - %c, ch_z = %d - %c\n", 
            ch_A, ch_A, ch_Z, ch_Z, ch_a, ch_a, ch_z, ch_z);
    // Operadores Aritméticos
    printf(" _____________________\n");
    printf("| Operadores binários |\n");
    printf(" _____________________\n");
    // Operadores binários
    ch = ch_a + 1; // adição
    printf("Adição (+) ");
    printf("%c + %d = %c\n", ch_a, 1, ch);
    ch = ch_Z - 1; // substração
    printf("Substração (-) ");
    printf("%c - %d = %c\n", ch_Z, 1, ch);
    ch = ch_A * 2; // multiplicação
    printf("Multiplicação (*) ");
    printf("%c * %d = %c\n", ch_A, 2, ch);
    printf("Divisão inteira (/) \n");
    ch = ch_z / 2; // Divisão inteira
    printf("%c / %d = %c\n", ch_z, 2, ch);
    
    // Operadores de incremento e decremento
    printf(" ________________________________________\n");
    printf("| Operadores de Incremento e decremento: |\n");
    printf(" ________________________________________\n");
    ch = ch_A;
    printf("ch = %d - %c\n", ch, ch);
    //++a; // a = a + 1
    printf("++ch = %c\n", ++ch);
    printf("ch++ = %c\n", ch++);
    printf("ch = %c\n", ch);
    //--a;
    ch = ch_Z;
    printf("--ch = %c\n", --ch);
    printf("ch-- = %c\n", ch--);
    printf("ch = %c\n", ch);
    
    // Operadores compostos
    printf(" __________________________\n");
    printf("| Operadores de Compostos: |\n");
    printf(" __________________________\n");
    ch = ch_a;
    printf("ch = %d - %c\n", ch, ch);
    ch += 5; // ch = ch + 5
    printf("ch += 5 -> ch = %c\n", ch);
    ch -= 3; // ch = ch - 3
    printf("ch -= 3 -> ch = %c\n", ch);
    ch *= 1; // ch = ch*1
    printf("ch *= 1 -> ch = %c\n", ch);
    ch /= 2; // ch = ch/2
    printf("ch /= 2 -> ch = %c\n", ch);
    
    // Operadores Relacionais
    printf(" ____________________________\n");
    printf("| Operadores de Relacionais: |\n");
    printf(" ____________________________\n");
    printf("Retornam 0 quando falso e 1 quando verdadeiro\n");
    printf("A > B -> %d\n", 'A' > 'B');
    printf("B > A -> %d\n", 'B' > 'A');
    printf("Maior que (>) \n");
    printf("%c > %c = %d\n", ch_A, ch_Z, ch_A > ch_Z);
    printf("%c > %c = %d\n", ch_Z, ch_A, ch_Z > ch_A);
    printf("Maior ou igual que (>=) \n");
    printf("%c >= %c = %d\n", ch_a, ch_Z, ch_a >= ch_Z);
    printf("%c >= %c = %d\n", ch_Z, 'Z', ch_Z >= 'Z');
    /*
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
    */
    return 0;
}