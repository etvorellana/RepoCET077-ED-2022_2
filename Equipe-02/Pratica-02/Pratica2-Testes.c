#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
typedef struct {
    int numMatricula;
    char nome[100];
    char email[100];
}Taluno;

typedef struct no
{
  Taluno aluno;
  struct no *proximoNo;
} No;


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
No *inicializar();
void inserir(No *head, int mat, char *nome, char *email);
void imprimir(No *lista);
No *buscar(No *lista, int id);
Taluno remover(No *head, int valor);

int main (void) {
    No *head = inicializar();
    PilhaAluno pilha;
    inicializarPilha(&pilha);
    FilaAluno fila;
    inicializarFila(&fila);
    Taluno vetLinked[5], vetPilha[5], vetFila[5];

    inserir(head, 202010243,"Solana", "sablemos.cic@uesc.br");
    inserir(head, 201820050,"Caio", "caio@uesc.br");
    inserir(head, 201829548,"Julia", "julia@uesc.br");
    inserir(head, 201910001,"Paulo", "paulo@uesc.br");
    inserir(head, 202010560,"Joao", "joao@uesc.br");
    inserir(head, 202210200,"Carla", "carla@uesc.br");
    imprimir(head);
    
    vetLinked [0]= remover(head, 201820050);
    vetLinked [1]= remover(head, 201829548);
    vetLinked [2]= remover(head, 201910001);
    vetLinked [3]= remover(head, 202010560);
    vetLinked [4]= remover(head, 202210200);

    for (int i =0; i<5; i++) {
        empilhar(&pilha, vetLinked[i]);
    }
    imprimirPilha(pilha);

    for (int i = 0; i<5; i++) {
        vetPilha[i] = desempilhar(&pilha);
    }

    for (int i =0; i<5; i++) {
        enfileirar(&fila, vetPilha[i]);
    }

    imprimirFila(fila);

    for (int i =0; i<5; i++) {
        vetFila[i] = desenfileirar(&fila);
    }


    for (int i =0; i<5; i++) {
        inserir(head, vetFila[i].numMatricula, vetFila[i].nome, vetFila[i].email);
    }
    imprimir(head);

    return 0;
}

No *inicializar()
{
  No *head = (No *)malloc(sizeof(No));
    head->proximoNo = NULL;
    return head;
}

void inserir(No *head, int mat, char *nome, char *email)
{
    No *busca = buscar(head, mat); 
    if (busca == NULL){

        No *aux, *node = (No *)malloc(sizeof(No));
        if (head->proximoNo == NULL)
        {
            node->aluno.numMatricula = mat;
            strcpy(node->aluno.email, email);
            strcpy(node->aluno.nome, nome);
            node->proximoNo = NULL;
            head->proximoNo = node;
        }
        else
        {
            node->aluno.numMatricula = mat;
            strcpy(node->aluno.email, email);
            strcpy(node->aluno.nome, nome);
            aux = head->proximoNo;
            head->proximoNo = node;
            node->proximoNo = aux;
        }
    } else {
        printf ("Este aluno ja esta na lista");
        return;
    }
}

void imprimir(No *lista)
{
  int pos = 0;
  lista = lista->proximoNo;
  while (lista != NULL)
  {
    printf("\n[%d] - Matricula = %d\nNome = %s\nEmail = %s\n", pos, lista->aluno.numMatricula, lista->aluno.nome, lista->aluno.email);
    lista = lista->proximoNo;
    pos++;
  }
}

No *buscar(No *lista, int id)
{
  No *local;
  int pos = 0;
  while (lista != NULL)
  {
    if (lista->aluno.numMatricula == id)
    {
      printf("id: %d\n", lista->aluno.numMatricula);
      local = lista;
      return local;
    }
    lista = lista->proximoNo;
    pos++;
  }
  return NULL;
}

Taluno remover(No *head, int valor) {
  if (head->proximoNo == NULL) {
    printf("Lista vazia");
    return;
  }

  Taluno rem;
  No *aux;

  while (head->proximoNo->proximoNo != NULL && head->proximoNo != NULL) {
    if (head->proximoNo->aluno.numMatricula == valor) {
        printf ("\n%d sera removido\n", valor);
        rem = head->proximoNo->aluno;
        aux = head->proximoNo;
        head->proximoNo = head->proximoNo->proximoNo;
        free(aux);
        return rem;
    }
    else {
        head = head->proximoNo;
    }
  }
  return;
}

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
