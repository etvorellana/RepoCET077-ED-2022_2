#define TRUE 1
#define FALSE 0
#define LSIZE 10
#include <stdlib.h>

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX +2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

// Listas Lineares de Alocação Sequencial
typedef struct{
	TAluno* aluno; 	// Para alocação dinâmica
	int cap;		// Capacidade ou tamanho máximo da lista
	int tam;		// Tamanho da lista, inicialmente 0
    int eOrd;		// A lista é ordenada (TRUE ou FALSE)
} TListAlunos; // tam = 0 -> lista vazia; tam = cap -> lista cheia

TListAlunos* initListaAluno(int cap, int eOrd);
int buscaAluno(int nm, TListAlunos lista);
int incAluno(TAluno aluno, TListAlunos *lista);
int remAluno(int nm, TListAlunos *lista);
TAluno geraAluno(TAluno aluno);
int ordenaLista(TListAlunos *lista);
TListAlunos* interListas(TListAlunos *listaA, TListAlunos *listaB);
TListAlunos* diferListas(TListAlunos *listaA, TListAlunos *listaB);

void liberaMem(TListAlunos *lista);
void limpa_linha();
int busca_binaria(TListAlunos lista, int numMatricula);
