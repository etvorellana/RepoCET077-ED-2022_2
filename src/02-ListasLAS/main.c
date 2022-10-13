#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NSIZE 100
#define TRUE 1
#define FALSE 0

typedef struct{
    int numMatricula;
    char nome[100];
    char email[100];
}TAluno;

TAluno* alocaListaAlunos(int n);
void geraAluno(TAluno *aluno);
int busca(int nm, TAluno *lista);
void printAluno(TAluno aluno);
void selectionSort(TAluno *lista, int tam);
void bubbleSort(TAluno *lista, int tam);

int main()
{
    TAluno *lista;
    TAluno aluno;
    lista = alocaListaAlunos(NSIZE + 1);
    srand(time(NULL));
    geraAluno(&aluno);
    for(int i = 0; i< 10; i++)
    {
        geraAluno(&lista[i]);
    }
    int sample = rand()%10;
    printAluno(lista[sample]);
    int pos = busca(lista[sample].numMatricula, lista); 
    if (pos < 10)
    {
        printf("Achei o elemento na lista\n");
        printAluno(lista[pos]);
    }else{
        printf("Não achei o elemento na lista\n");
    }
    printAluno(aluno);
    lista[10].numMatricula = aluno.numMatricula;
    pos = busca(aluno.numMatricula, lista); 
    if (pos < 10)
    {
        printf("Achei o elemento na lista\n");
    }else{
        printf("Não achei o elemento na lista\n");
    }
    printf("====Lista====");
    for(int i = 0; i < 10; i++)
        printAluno(lista[i]);
    
    selectionSort(lista, 10);
    //bubbleSort(lista, 10);

    printf("====Lista Ordenada====");
    for(int i = 0; i < 10; i++)
        printAluno(lista[i]);
    
    return 0;
}

int busca(int nm, TAluno *lista)
{
    if(lista[0].numMatricula ==  nm)
        return 0;
    return 1 + busca(nm, &lista[1]);
}

int buscaNR(int nm, TAluno *lista)
{
    int i = 0;
    while(lista[i].numMatricula !=  nm)
        i++;
    return i;
}

int incAluno(TAluno aluno, TAluno *lista, int *tam, int cap)
{
    if(*tam >= cap)
        return 0;
    int pos = buscaNR(aluno.numMatricula, lista);
    if(pos == *tam){
        lista[pos] = aluno;
        *tam += 1;
        return 1;
    }else{
        return 0;
    }


}


int remAluno(int nm, TAluno *lista, int *tam)
{
    if(tam == 0)
        return 0;
    int pos = buscaNR(nm, lista);
    if(pos < tam){
        *tam--;
        lista[pos] = lista[*tam];
        /*
        for(int i = pos; i < *tam-1; i++)
        {
            lista[i] = lista[i+1];
        }
        */
        return 1;
    }else{
        return 0;
    }

}

void geraAluno(TAluno *aluno)
{
    int numMatricula = 2000 + rand()%23;
    numMatricula *= 10;
    numMatricula += (1+rand()%2);
    numMatricula *= 10000;
    numMatricula += (rand()%10000);
    aluno->numMatricula = numMatricula;
    //gerar um nome
    strcpy(aluno->nome,"Teste Nome Aluno");
    //aluno->nome = "Teste Nome Aluno";
    //gerar um e-mail
    strcpy(aluno->email, "TNAluno@uesc.br"); 
    //aluno->email = "TNAluno@uesc.br";
}

TAluno* alocaListaAlunos(int n)
{
    TAluno *p = (TAluno*) malloc(n*sizeof(TAluno));
    return p;
}

void printAluno(TAluno aluno)
{
    printf("Aluno:\n Nome: %s\n", aluno.nome);
    printf("Matricula: %d\n Email: %s\n", aluno.numMatricula, aluno.email);
}


void selectionSortR(TAluno *lista, int tam)
{
    if (tam > 1)
    {
        int pos = 0;
        int nm = lista[0].numMatricula;
        for(int i = 1; i < tam; i++)
        {
            if(nm > lista[i].numMatricula)
            {
                nm = lista[i].numMatricula;
                pos = i;
            }
        }
        if (pos != 0)
        {
            TAluno aluno;
            aluno = lista[0];
            lista[0] = lista[pos];
            lista[pos] = aluno;
        }
        selectionSortR(&lista[1], tam - 1);
    }
}

void selectionSort(TAluno *lista, int tam)
{
    for(int i= 0; i < tam - 1; i++ )
    {
        int pos = i;
        int nm = lista[i].numMatricula;
        for(int j = i+1; j < tam; j++)
        {
            if(nm > lista[j].numMatricula)
            {
                nm = lista[j].numMatricula;
                pos = j;
            }
            if (pos != i)
            {
                TAluno aluno;
                aluno = lista[i];
                lista[i] = lista[pos];
                lista[pos] = aluno;
            }
        }
    }
}

void bubbleSort(TAluno *lista, int tam)
{
    int trocou = 0;
    if(tam > 1)
    {   
        TAluno aluno;
        for(int i = 0; i < (tam - 1); i++)
        {
            if(lista[i].numMatricula > lista[i+1].numMatricula)
            {
                aluno = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = aluno;
                trocou = 1;
            }
        }
        if (trocou == 1)
            bubbleSort(lista, tam - 1);
    }

}