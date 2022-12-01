#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TAluno{
    int matricula;
    char nome[200];
    char email[200];
    struct TAluno *prox;
} TAluno;

typedef struct TNo{
    TAluno *aluno;
    struct TNo *prox, *ant;
} TNo;

typedef struct Pilha{
    TAluno *topo;
    int tam;
} Pilha;

typedef struct Fila{
    TAluno *inicio;
    TAluno *fim;
    int tam;
} Fila;

void preencher(TAluno *aluno, TNo *no);
void empilhar_no(TNo *no, Pilha *pilha);
void enfileirar_pilha(Pilha *pilha, Fila *fila);
void desifileirar(Fila *fila, TNo *no);
void imprime_fila(Fila *fila);
void imprime_pilha(Pilha *pilha);
void imprime_no(TNo *no);
TNo buscar_aluno(TNo *no, int matricula);
void menu();

int main(){
    menu();
    return 0;
}


void preencher(TAluno *aluno, TNo *no){
    TNo taluno = buscar_aluno(no, aluno->matricula);

    if (taluno.aluno->matricula == aluno->matricula){
        printf("Aluno ja cadastrado!\n");
        return;
    }
    taluno.aluno->matricula = aluno->matricula;
    strcpy(taluno.aluno->nome, aluno->nome);
    strcpy(taluno.aluno->email, aluno->email);
    printf("Aluno cadastrado com sucesso!\n");
    printf("%d", taluno.aluno->matricula);
    taluno.prox = NULL;
}


void empilha_no(TNo *no, Pilha *pilha){
    while(no->prox != NULL){
        TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
        novo->matricula = no->aluno->matricula;
        strcpy(novo->nome, no->aluno->nome);
        strcpy(novo->email, no->aluno->email);
        novo->prox = pilha->topo;
        pilha->topo = novo;
        pilha->tam++;
        no = no->prox;
        free(no->ant);
    }
}

void enfileirar_pilha(Pilha *pilha, Fila *fila){
    while(pilha->tam != 0){
        TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
        novo->matricula = pilha->topo->matricula;
        strcpy(novo->nome, pilha->topo->nome);
        strcpy(novo->email, pilha->topo->email);
        novo->prox = NULL;
        if (fila->inicio == NULL){
            fila->inicio = novo;
            fila->fim = novo;
        }else{
            fila->fim->prox = novo;
            fila->fim = novo;
        }
        fila->tam++;
        pilha->topo = pilha->topo->prox;
        pilha->tam--;
    }
    free(pilha);
}

void desifileirar(Fila *fila, TNo *no){
    TNo *aux;
    while(fila->tam != 0){
        TNo *novo = (TNo*) malloc(sizeof(TNo));
        novo->aluno->matricula = fila->inicio->matricula;
        strcpy(novo->aluno->nome, fila->inicio->nome);
        strcpy(novo->aluno->email, fila->inicio->email);
        novo->prox = no->prox;
        no->prox = novo;
        aux = no;
        no = no->prox;
        no->ant = aux;
        fila->inicio = fila->inicio->prox;
        fila->tam--;
    }
    free(fila);
}

void imprime_fila(Fila *fila){
    TAluno *aux = fila->inicio;
    while(aux != NULL){
        printf("Matricula: %d\n", aux->matricula);
        printf("Nome: %s\n", aux->nome);
        printf("Email: %s\n", aux->email);
        aux = aux->prox;
    }
}

void imprime_pilha(Pilha *pilha){
    TAluno *aux = pilha->topo;
    while(aux != NULL){
        printf("Matricula: %d\n", aux->matricula);
        printf("Nome: %s\n", aux->nome);
        printf("Email: %s\n", aux->email);
        aux = aux->prox;
    }
}


void imprime_no(TNo *no){
    TNo *aux = no->prox;
    while(aux != NULL){
        printf("Matricula: %d\n", aux->aluno->matricula);
        printf("Nome: %s\n", aux->aluno->nome);
        printf("Email: %s\n", aux->aluno->email);
        aux = aux->prox;
    }
}


TNo buscar_aluno(TNo *no, int matricula){
    TNo *aux = no, *aux2;
    while(aux->aluno != NULL){
        if (aux->aluno->matricula == matricula){
            return *aux;
        }
        aux2 = aux;
        aux = aux->prox;
    }
    aux = (TNo*) malloc(sizeof(TNo));
    aux->aluno = (TAluno*) malloc(sizeof(TAluno));
    aux->prox = NULL;
    aux->ant = aux2;
    aux2->prox = aux;
    return *aux;
}


void menu(){
    int opcao;
    TNo *no = (TNo*) malloc(sizeof(TNo));
    no->prox = NULL;
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->tam = 0;
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;

    do{
        printf("1 - Cadastrar aluno\n");
        printf("2 - Empilhar alunos\n");
        printf("3 - Enfileirar pilha\n");
        printf("4 - Desifileirar fila\n");
        printf("5 - Imprimir fila\n");
        printf("6 - Imprimir pilha\n");
        printf("7 - Imprimir lista\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                TAluno *aluno = (TAluno*) malloc(sizeof(TAluno));
                printf("Matricula: ");
                scanf("%d", &aluno->matricula);
                printf("Nome: ");
                scanf("%s", aluno->nome);
                printf("Email: ");
                scanf("%s", aluno->email);
                preencher(aluno, no);
                break;
            }
            case 2:{
                empilha_no(no, pilha);
                break;
            }
            case 3:{
                enfileirar_pilha(pilha, fila);
                break;
            }
            case 4:{
                no = (TNo*) malloc(sizeof(TNo));
                desifileirar(fila, no);
                break;
            }
            case 5:{
                imprime_fila(fila);
                break;
            }
            case 6:{
                imprime_pilha(pilha);
                break;
            }
            case 7:{
                imprime_no(no);
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("Opcao invalida!\n");
                break;
            }
        }
    }while(opcao != 0);
}