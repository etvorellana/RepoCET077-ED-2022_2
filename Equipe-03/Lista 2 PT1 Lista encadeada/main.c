#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TAluno{
  int matricula; // chave com 9 dígitos (INT_MAX +2147483647)
  char nome[100];   // nome com até 99 caracteres
  char email[100];  // eMail com até 99 caracteres
  struct TAluno *prox;
  
} TAluno;

typedef struct Tfila{
  TAluno *inicio;
  TAluno *fim;
  int tam;
} Tfila;

typedef struct Tpilha{
  TAluno *topo;
  int tam;
} Tpilha;

void empilhar(TAluno *aluno, Tpilha *pilha);
void desempilhar(TAluno *aluno, Tpilha *pilha);
void enfileirar(TAluno *aluno, Tfila *fila);
void desenfileirar(TAluno *aluno, Tfila *fila);
void imprime_pilha(Tpilha *pilha);
void imprime_fila(Tfila *fila);
void menu();

int main(){
    menu();
    return 0;
}



void empilhar(TAluno *aluno, Tpilha *pilha){
    TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
    novo->matricula = aluno->matricula;
    strcpy(novo->nome, aluno->nome);
    strcpy(novo->email, aluno->email);
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tam++;
}

void desempilhar(TAluno *aluno, Tpilha *pilha){
    if (pilha->tam == 0){
        printf("Pilha vazia!\n");
        return;
    }
    TAluno *aux = pilha->topo;
    pilha->topo = aux->prox;
    aluno->matricula = aux->matricula;
    strcpy(aluno->nome, aux->nome);
    strcpy(aluno->email, aux->email);
    free(aux);
    pilha->tam--;
}

void enfileirar(TAluno *aluno, Tfila *fila){
    TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
    novo->matricula = aluno->matricula;
    strcpy(novo->nome, aluno->nome);
    strcpy(novo->email, aluno->email);
    novo->prox = NULL;
    if(fila->fim == NULL){
        fila->inicio = novo;
    }else{
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    fila->tam++;
}

void desenfileirar(TAluno *aluno, Tfila *fila){
    if (fila->tam == 0){
        printf("Fila vazia!\n");
        return;
    }
    TAluno *aux = fila->inicio;
    fila->inicio = aux->prox;
    aluno->matricula = aux->matricula;
    strcpy(aluno->nome, aux->nome);
    strcpy(aluno->email, aux->email);
    free(aux);
    fila->tam--;
}

void imprime_pilha(Tpilha *pilha){
    TAluno *aux = pilha->topo;
    while(aux != NULL){
        printf("Matricula: %d\n", aux->matricula);
        printf("Nome: %s\n", aux->nome);
        printf("Email: %s\n", aux->email);
        aux = aux->prox;
    }
}

void imprime_fila(Tfila *fila){
    TAluno *aux = fila->inicio;
    while(aux != NULL){
        printf("Matricula: %d\n", aux->matricula);
        printf("Nome: %s\n", aux->nome);
        printf("Email: %s\n", aux->email);
        aux = aux->prox;
    }
}

void menu(){
    int opcao;
    Tpilha pilha;
    Tfila fila;
    TAluno aluno;
    pilha.topo = NULL;
    pilha.tam = 0;
    fila.inicio = NULL;
    fila.fim = NULL;
    fila.tam = 0;
    do{
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Enfileirar\n");
        printf("4 - Desenfileirar\n");
        printf("5 - Imprimir pilha\n");
        printf("6 - Imprimir fila\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Matricula: ");
                scanf("%d", &aluno.matricula);
                printf("Nome: ");
                scanf("%s", aluno.nome);
                printf("Email: ");
                scanf("%s", aluno.email);
                empilhar(&aluno, &pilha);
                break;
            case 2:
                desempilhar(&aluno, &pilha);
                break;
            case 3:
                printf("Matricula: ");
                scanf("%d", &aluno.matricula);
                printf("Nome: ");
                scanf("%s", aluno.nome);
                printf("Email: ");
                scanf("%s", aluno.email);
                enfileirar(&aluno, &fila);
                break;
            case 4:
                desenfileirar(&aluno, &fila);
                break;
            case 5:
                imprime_pilha(&pilha);
                break;
            case 6:
                imprime_fila(&fila);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }while(opcao != 0);
}

