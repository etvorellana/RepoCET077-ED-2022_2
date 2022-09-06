#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NSIZE 100

typedef struct{
    int numMatricula;
    char nome[100];
    char email[100];
}TAluno;

TAluno* alocaListaAlunos(int n);
void geraAluno(TAluno *aluno);
void printAluno(TAluno aluno);

int main(void)
{
    TAluno *lista;
    lista = alocaListaAlunos(NSIZE);
    srand(time(NULL));
    for(int i = 0; i< NSIZE; i++)
    {
        geraAluno(&lista[i]);
    }
    printf("Verificando o Resultado: \n");
    printAluno(lista[rand()%NSIZE]);
    return 0;
}

void geraAluno(TAluno *aluno)
{
    int numMatricula = 2000 + rand()%23;
    numMatricula *= 10;
    numMatricula += (1+rand()%2);
    numMatricula *= 10000;
    numMatricula += (rand()%10000);


}

void printAluno(TAluno aluno)
{
    printf("Aluno:\n Nome: %s\n", aluno.nome);
    printf("Matricula: %d\n Email: %s\n", aluno.numMatricula, aluno.email);
}

TAluno* alocaListaAlunos(int n)
{
    TAluno *p = (TAluno*) malloc(n*sizeof(TAluno));
    return p;
}