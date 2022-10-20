#include <stdio.h>
#include <stdlib.h>
#include "lilas.h"

#define CAP 10
#define CAPSTRING 100
TListAlunos* initListaAluno(int cap, int eOrd);
int buscaAluno(int nm, TListAlunos lista);
int incAluno(TAluno aluno, TListAlunos *lista);
int remAluno(TAluno *aluno, TListAlunos *lista);
void ordenaLista(TListAlunos *lista);



int main()
{
    int opcao,posicao,capacidade,ordenada;
    printf("digite a capacidade de alunos:");
    scanf("%d",&capacidade);
    do{
        printf("digite 1 para uma lista ordenada e 0 para uma lista nao ordenada:");
        scanf("%d",&ordenada);
      }
    while(ordenada>=0 && ordenada<=1);

    TListAlunos *lista = initListaAluno(int capacidade, int ordenada);



    do{
        printf("_____MENU_____\n");
        printf("0- Encerrar programa.\n");
        printf("1- Incluir novo aluno.\n");
        printf("2- Mostrar um aluno.\n");
        printf("3- Excluir um aluno.\n\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
            case 0:
                liberaMem(1);
                printf("Encerrando...");
                return 0;
            case 1:
                 printf("insira o numero de matricula:\n");
                 scanf("%d",&lista[].aluno[lista.tam].numMatricula);
                 printf("insira o nome:\n");
                 scanf("%100[^\n]",lista.aluno[lista.tam].nome);
                 printf("insira o email:\n");
                 scanf("%100[^\n]",lista.aluno[lista.tam].email);
                 if(incAluno(aluno[lista.tam],&lista==0))
                    printf("Erro ao incluir aluno.\n");
                 break;
            case 2:
                 printf("insira o numero de matricula:\n");
                 scanf("%d",&lista[].aluno[lista.tam].numMatricula);
                 posicao= buscaAluno(aluno[lista.tam],&lista);
                 if(lista[].aluno[lista.tam].numMatricula != lista[].aluno[posicao].matricula)
                    printf("Aluno n�o encontrado!");
                 else
                    printf("Nome: %s\nNumero de matricula: %d\nEmail: %s\n",lista[].aluno[posicao].nome,lista[].aluno[posicao].matricula,lista[].aluno[posicao].email);

                 break;
            case 3:
                 printf("insira o numero de matricula:\n");
                 scanf("%d",&lista[].aluno[lista.tam].numMatricula);
                 posicao= buscaAluno(aluno[lista.tam],&lista);
                 if(lista[].aluno[lista.tam].numMatricula != lista[].aluno[posicao].matricula)
                    printf("Aluno n�o encontrado!");
                 else
                    printf("Excluindo...");
                 break;
            default: printf("Erro! op��o invalida.");
         }
      }
    while(opcao!=0);

    printf("\n");
    return 0;
}