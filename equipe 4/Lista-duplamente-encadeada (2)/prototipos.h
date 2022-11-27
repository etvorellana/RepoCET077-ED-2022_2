#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nome[200];
    char email[200];
} TAluno;
typedef struct no NO;

NO *criarLista();

NO *inserirInicio(NO *lista, TAluno aluno);


void mostrarLista(NO *lista);


NO *buscar(NO *lista, int num);

int qtdElementos(NO *lista);

NO* removerElemento(NO *lista, TAluno *aluno);

