#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TAluno{
  int matricula; // chave com 9 dígitos (INT_MAX +2147483647)
  char nome[100];   // nome com até 99 caracteres
  char email[100];  // eMail com até 99 caracteres
  struct TAluno *prox;
  
} TAluno;

void empilha(TAluno**, char[], int, char[]);
void desempilha(TAluno**);
void imprime_pilha(TAluno*);
void enfileira(TAluno**, char[], int, char[]);
void desenfileira(TAluno**);
void imprime_fila(TAluno*);
void menu();

int main(){
    TAluno *pilha = NULL;
    TAluno *fila = NULL;
    int opcao;
    char nome[100];
    int matricula;
    char email[100];
    do{
        menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite o nome: ");
                scanf("%s", nome);
                printf("Digite a matricula: ");
                scanf("%d", &matricula);
                printf("Digite o email: ");
                scanf("%s", email);
                empilha(&pilha, nome, matricula, email);
                break;
            case 2:
                desempilha(&pilha);
                break;
            case 3:
                imprime_pilha(pilha);
                break;
            case 4:
                printf("Digite o nome: ");
                scanf("%s", nome);
                printf("Digite a matricula: ");
                scanf("%d", &matricula);
                printf("Digite o email: ");
                scanf("%s", email);
                enfileira(&fila, nome, matricula, email);
                break;
            case 5:
                desenfileira(&fila);
                break;
            case 6:
                imprime_fila(fila);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opcao != 7);
    return 0;
}

void empilha(TAluno **pilha, char nome[], int matricula, char email[]){
    TAluno *novo = (TAluno*)malloc(sizeof(TAluno));
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    strcpy(novo->email, email);
    novo->prox = *pilha;
    *pilha = novo;
}

void desempilha(TAluno **pilha){
    if(*pilha == NULL){
        printf("Pilha vazia!\n");
    }else{
        TAluno *aux = *pilha;
        *pilha = (*pilha)->prox;
        free(aux);
    }
}

void imprime_pilha(TAluno *pilha){
    if(pilha == NULL){
        printf("Pilha vazia!\n");
    }else{
        TAluno *aux = pilha;
        while(aux != NULL){
            printf("Nome: %s\n", aux->nome);
            printf("Matricula: %d\n", aux->matricula);
            printf("Email: %s\n", aux->email);
            aux = aux->prox;
        }
    }
}

void enfileira(TAluno **fila, char nome[], int matricula, char email[]){
    TAluno *novo = (TAluno*)malloc(sizeof(TAluno));
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    strcpy(novo->email, email);
    novo->prox = NULL;
    if(*fila == NULL){
        *fila = novo;
    }else{
        TAluno *aux = *fila;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void desenfileira(TAluno **fila){
    if(*fila == NULL){
        printf("Fila vazia!\n");
    }else{
        TAluno *aux = *fila;
        *fila = (*fila)->prox;
        free(aux);
    }
}

void imprime_fila(TAluno *fila){
    if(fila == NULL){
        printf("Fila vazia!\n");
    }else{
        TAluno *aux = fila;
        while(aux != NULL){
            printf("Nome: %s\n", aux->nome);
            printf("Matricula: %d\n", aux->matricula);
            printf("Email: %s\n", aux->email);
            aux = aux->prox;
        }
    }
}



void menu(){
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("3 - Imprimir pilha\n");
    printf("4 - Enfileirar\n");
    printf("5 - Desenfileirar\n");
    printf("6 - Imprimir fila\n");
    printf("7 - Sair\n");
    printf("Digite a opcao: ");
}