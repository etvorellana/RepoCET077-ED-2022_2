#include <stdio.h>
#include <stdlib.h>

typedef struct TAluno {
  int matricula;
  char nome[200];
  char email[200];
  struct TAluno *proximo;
} TAluno;
typedef struct Tpilha {
  TAluno *topo;
  int tam;
} Tpilha;
typedef struct Fila {
  TAluno *inicio;
  TAluno *fim;
  int tam;
} Tfila;
typedef struct no NO;

NO *criarLista();

NO *inserirInicio(NO *lista, TAluno aluno);

void empilhar(TAluno *aluno, Tpilha *pilha);

void mostrarLista(NO *lista);

NO *buscar(NO *lista, int num);

int qtdElementos(NO *lista);
void empilharDaFila(NO *no, Tpilha *pilha);

NO *removerElemento(NO *lista, TAluno *aluno);
void imprime_pilha(Tpilha *pilha);
void imprime_fila(Tfila *fila);
void enfileirarDaPilha(Tpilha *pilha, Tfila *fila);
void desifileirar(Tfila *fila, NO *no);
void preencheLista(TAluno *aluno, NO *no);
