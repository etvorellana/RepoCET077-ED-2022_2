#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lilas.h"

TListAlunos* initListaAluno(int cap, int eOrd)
{
    TListAlunos *lista;
    lista = (TListAlunos*) malloc(sizeof(TListAlunos));
    lista->tam = 0;
    lista->cap = cap;
    lista->eOrd = eOrd;
    if(eOrd)
    {
        lista->aluno = (TAluno*) malloc(cap*sizeof(TAluno));
    }else{
        lista->aluno = (TAluno*) malloc((cap+1)*sizeof(TAluno));
    }
    return lista;
}

int buscaAluno(int nm, TListAlunos *lista){
    int i = 0;

    for(i = 0; i < lista->tam; i++){
        if(lista->aluno[i].numMatricula == nm){
            return i;
        }
    }
    return -1;
}

int incAluno(TAluno aluno, TListAlunos *lista){
    int tam = lista->tam;
    if (lista->cap < tam + 1){
        printf("Lista cheia\n!!!!");
        return 0;
    }
    lista->aluno[tam + 1] = aluno;
    if(lista->eOrd){
        ordenarLista(lista);
    }
    return 1;
}


int remAluno(TAluno *aluno, TListAlunos *lista){
    if(lista->tam == 0){
        printf("Lista Vazia");
        return 0;
    }
    aluno = &lista->aluno[lista->tam + 1];
    lista->tam--;
    return 1;
}

int buscaPorNome(char nome[], TListAlunos *lista){
    int i = 0;

    for(i = 0; i < lista->tam; i++){
        if(!strcmp(nome, lista->aluno[i].nome)){
            return i;
        }
    }
    return -1;

}

int buscaPorEMail(char email[], TListAlunos *lista){
    int i = 0;

    for(i = 0; i < lista->tam; i++){
        if(!strcmp(email, lista->aluno[i].email)){
            return i;
        }
    }
    return -1;
}


TListAlunos* uniaoListas(TListAlunos *listaA, TListAlunos *listaB){
    TListAlunos *ListaUnida;
    int tam = listaA->tam + listaB->tam, i, j = 0;
    ListaUnida = malloc(tam * sizeof(TListAlunos));
    for(i = 0; i < listaA->tam; i++){
        ListaUnida->aluno[i] = listaA->aluno[i];
    }
    for(i = 0; i < tam; i++, j++){
        ListaUnida->aluno[i] = listaB->aluno[j];
    }
    ListaUnida->tam = tam;
    ListaUnida->cap = listaA->cap + listaB->cap;
    return ListaUnida;
}


void ordenarLista(TListAlunos *lista){
  int i, j;
  TAluno aluno;
  for(i = 0; i < lista->tam; i++){
    for(j = 0; j < lista->tam; j++){
      if(lista->aluno[j].numMatricula > lista->aluno[j + 1].numMatricula){
        aluno = lista->aluno[j];
        lista->aluno[j] = lista->aluno[j + 1];
        lista->aluno[j + 1] = aluno;
      }
    }
  }
}