#include <stdio.h>
#include <float.h>

int main(void)
{ 
	printf("Declaração de Variáveis\n");
	float x;		// declarando uma variável de ponto flutuante
    // declarando e inicializando uma variável de ponto flutuante
    float y = 3.14f;
	x = (float)1.0; // inicializando a com casting explícito
    float z = 0.12; // inicializando a com casting implícito

	printf("O tamanho de um float: %d\n", sizeof(float));
	printf("Valor máximo de um float = %f\n", FLT_MAX);
	printf("Valor mínimo de um float = %.24e\n", FLT_MIN);
    printf("FLT_ROUNDS = %d\n", FLT_ROUNDS);
    printf("FLT_MANT_DIG = %d\n", FLT_MANT_DIG);
    printf("FLT_DIG = %d\n", FLT_DIG);
    printf("FLT_MIN_EXP = %d\n", FLT_MIN_EXP);
    
    
    printf("DBL_MANT_DIG = %d\n", DBL_MANT_DIG);
    printf("DBL_DIG = %d\n", DBL_DIG);
    printf("DBL_MIN_EXP = %d\n", DBL_MIN_EXP);

    printf("LDBL_MANT_DIG = %d\n", LDBL_MANT_DIG);
    printf("LDBL_DIG = %d\n", LDBL_DIG);
    printf("LDBL_MIN_EXP = %d\n", LDBL_MIN_EXP);

	//printf("Número de dígitos de um float = %f\n", FLT_MANT_DIG);
    /*
	double y = 2.0; // declarando e inicializando
	printf("double: %d\n", sizeof(double));
	printf("Valor máximo de um double = %.10e\n", DBL_MAX);
	printf("Valor mínimo de um double = %.10e\n", DBL_MIN);
	printf("Número de dígitos de um double = %.10e\n", DBL_MANT_DIG);
	// Modificadores
	printf("long double: %d\n", sizeof(long double));
	printf("Valor máximo de um long double = %Le\n", LDBL_MAX);
	printf("Valor mínimo de um long double = %Le\n", LDBL_MIN);
	printf("Número de dígitos de um double = %Lf\n", LDBL_MANT_DIG);
	long double z = 4.0;

	printf("Para continuar entre com um float: ");
	scanf("%f", &x);

	// Lembrandop da necessidade de inicializar as variáveis

	printf("Declaração e Inicialização de Variáveis\n");
	printf("Variáveis float: %.2f, %.2f, %.2Lf\n", x, y, z);
	printf("________________________________________\n");
	//Operadores com int
	printf("Operadores con float\n");
	printf("________________________________________\n");
	printf("Operador de atribuição\n");
	y = 5.0; // Operador de atribuição
	double y1, y2, y3, y4, y5;
	//atribuições múltiplas em um único comando
	y1 = y2 = y3 = y4 = y5 = y;
	printf("y = %f, y1 = %f, y2 = %f\n", y, y1, y2);
	printf("y3 = %f, y4 = %f, y5 = %f\n", y3, y4, y5);
	printf("________________________________________\n");

	printf("Para continuar entre com um float: ");
	scanf("%f", &x);

	//Operadores Aritméticos
	printf("Operadores binarios\n");
	// Operadores binários
	y = y1 + y2; //adição
	printf("%f + %f = %f\n", y1, y2, y);
	y3 = y2 - y4; //substração
	printf("%f - %f = %f\n", y2, y4, y3);
	y4 = -y5; // utilizado como operador unario
	printf("-%f = %f\n", y5, y4);
	y2 = y1 * y3; //multiplicação
	printf("%f * %f = %f\n", y1, y3, y2);
	y = 4 / 2.0; //Divisão 
	printf("4 / 2.0 = %f\n", y);
	y = 5.0 / 2; //Divisão 
	printf("5.0 / 2 = %f\n", y);
	printf("________________________________________\n");

	printf("Para continuar entre com um float: ");
	scanf("%f", &x);

	//Operadores compostos
	printf("Operadores de Compostos\n");
	printf("y = %f\n", y);
	y += 5.3; //y = y + 5.3
	printf("y += 5.3 -> y = %f\n", y);
	y -= 3.14; //y = y - 3.14
	printf("y -= 3.14 -> y = %f\n", y);
	y *= 4.7; //y = y*4
	printf("y *= 4.7 -> y = %f\n", y);
	y /= 2; //y = y/2
	printf("y /= 2 -> y = %f\n", y);
	printf("________________________________________\n");

	printf("Para continuar entre com um float: ");
	scanf("%f", &x);

	//Operadores Relacionais
	printf("Operadores de Relacionais\n");
	printf("%f > %f = %d\n", y1, y2, y1 > y2);
	printf("%f >= %f = %d\n", y2, y3, y2 >= y3);
	printf("%f < %f = %d\n", y3, y4, y3 < y4);
	printf("%f <= %f = %d\n", y4, y5, y4 <= y5);
	printf("%f == %f = %d\n", y5, y1, y5 == y1);
	printf("%f != %f = %d\n", y5, y1, y5 != y1);
	printf("________________________________________\n");

    */

	return 0;
}