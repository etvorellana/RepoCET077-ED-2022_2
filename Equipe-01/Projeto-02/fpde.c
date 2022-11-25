#include <stdio.h>
#include <stdlib.h>
#include "fpde.h"

void inicializarPilha(PilhaAluno *pilha){
    pilha->topo = NULL;
}

void inicializarFila(FilaAluno *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

void empilhar(PilhaAluno *pilha, Taluno aluno){
    NoAluno *novo = (NoAluno*) malloc(sizeof(NoAluno));
    novo->aluno = aluno;
    novo->prox = pilha->topo;
    novo->ant = NULL;
    if(pilha->topo != NULL){
        pilha->topo->ant = novo;
    }
    pilha->topo = novo;
}

void enfileirar(FilaAluno *fila, Taluno aluno){
    NoAluno *novo = (NoAluno*) malloc(sizeof(NoAluno));
    novo->aluno = aluno;
    novo->prox = NULL;
    novo->ant = fila->fim;
    if(fila->fim != NULL){
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    if(fila->inicio == NULL){
        fila->inicio = novo;
    }
}

Taluno desempilhar(PilhaAluno *pilha){
    Taluno aluno;
    NoAluno *aux;
    if(pilha->topo == NULL){
        printf("Pilha vazia!");
    }else{
        aluno = pilha->topo->aluno;
        aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        if(pilha->topo != NULL){
            pilha->topo->ant = NULL;
        }
        free(aux);
    }
    return aluno;
}

Taluno desenfileirar(FilaAluno *fila){
    Taluno aluno;
    NoAluno *aux;
    if(fila->inicio == NULL){
        printf("Fila vazia!");
    }else{
        aluno = fila->inicio->aluno;
        aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        if(fila->inicio != NULL){
            fila->inicio->ant = NULL;
        }else{
            fila->fim = NULL;
        }
        free(aux);
    }
    return aluno;
}

void imprimirPilha(PilhaAluno pilha){
    NoAluno *aux = pilha.topo;
    while(aux != NULL){
        printf("Matricula: %d - Nome: %s - Email: %s \n", aux->aluno.numMatricula, aux->aluno.nome, aux->aluno.email);
        aux = aux->prox;
    }
}

void imprimirFila(FilaAluno fila){
    NoAluno *aux = fila.inicio;
    while(aux != NULL){
        printf("Matricula: %d - Nome: %s - Email: %s \n", aux->aluno.numMatricula, aux->aluno.nome, aux->aluno.email);
        aux = aux->prox;
    }
}