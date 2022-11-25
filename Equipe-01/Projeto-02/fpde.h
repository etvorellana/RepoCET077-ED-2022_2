#include <stdlib.h>

typedef struct {
    int numMatricula;
    char nome[30];
    char email[30];
}Taluno;

typedef struct {
    Taluno aluno;
    struct no *prox;
    struct no *ant;
}NoAluno;

typedef struct {
    NoAluno *topo;
}PilhaAluno;

typedef struct {
    NoAluno *inicio;
    NoAluno *fim;
}FilaAluno;

void inicializarPilha(PilhaAluno *pilha);
void inicializarFila(FilaAluno *fila);
void empilhar(PilhaAluno *pilha, Taluno aluno);
void enfileirar(FilaAluno *fila, Taluno aluno);
Taluno desempilhar(PilhaAluno *pilha);
Taluno desenfileirar(FilaAluno *fila);
void imprimirPilha(PilhaAluno pilha);
void imprimirFila(FilaAluno fila);
