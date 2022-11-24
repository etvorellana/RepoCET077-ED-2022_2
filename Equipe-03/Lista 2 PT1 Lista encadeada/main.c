#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
    float altura;
    struct Pessoa *prox;
} Pessoa;

void empilha(Pessoa**, char[], int, float);
void desempilha(Pessoa**);
void imprime_pilha(Pessoa*);
void enfileira(Pessoa**, char[], int, float);
void desenfileira(Pessoa**);
void imprime_fila(Pessoa*);
void menu();

int main(){
    Pessoa *pilha = NULL;
    Pessoa *fila = NULL;
    int opcao;
    char nome[50];
    int idade;
    float altura;
    do{
        menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite o nome: ");
                scanf("%s", nome);
                printf("Digite a idade: ");
                scanf("%d", &idade);
                printf("Digite a altura: ");
                scanf("%f", &altura);
                empilha(&pilha, nome, idade, altura);
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
                printf("Digite a idade: ");
                scanf("%d", &idade);
                printf("Digite a altura: ");
                scanf("%f", &altura);
                enfileira(&fila, nome, idade, altura);
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


void empilha(Pessoa **pilha, char nome[], int idade, float altura){
    Pessoa *novo = (Pessoa*) malloc(sizeof(Pessoa));
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->altura = altura;
    novo->prox = *pilha;
    *pilha = novo;
}

void desempilha(Pessoa **pilha){
    if(*pilha == NULL){
        printf("Pilha vazia!\n");
    }else{
        Pessoa *aux = *pilha;
        *pilha = (*pilha)->prox;
        free(aux);
    }
}

void imprime_pilha(Pessoa *pilha){
    if(pilha == NULL){
        printf("Pilha vazia!\n");
    }else{
        Pessoa *aux = pilha;
        while(aux != NULL){
            printf("Nome: %s\n", aux->nome);
            printf("Idade: %d\n", aux->idade);
            printf("Altura: %.2f\n", aux->altura);
            aux = aux->prox;
        }
    }
}


void enfileira(Pessoa **fila, char nome[], int idade, float altura){
    Pessoa *novo = (Pessoa*) malloc(sizeof(Pessoa));
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->altura = altura;
    novo->prox = NULL;
    if(*fila == NULL){
        *fila = novo;
    }else{
        Pessoa *aux = *fila;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}


void desenfileira(Pessoa **fila){
    if(*fila == NULL){
        printf("Fila vazia!\n");
    }else{
        Pessoa *aux = *fila;
        *fila = (*fila)->prox;
        free(aux);
    }
}


void imprime_fila(Pessoa *fila){
    if(fila == NULL){
        printf("Fila vazia!\n");
    }else{
        Pessoa *aux = fila;
        while(aux != NULL){
            printf("Nome: %s\n", aux->nome);
            printf("Idade: %d\n", aux->idade);
            printf("Altura: %.2f\n", aux->altura);
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