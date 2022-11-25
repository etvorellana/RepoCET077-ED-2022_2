#define TRUE 1
#define FALSE 0
#define LSIZE 10
#include <stdlib.h>

// Armazenando as informa��es de um aluno
typedef struct
{
    int numMatricula; //chave com 9 d�gitos (INT_MAX +2147483647)
    char nome[100];   // nome com at� 99 caracteres
    char email[100];  // eMail com at� 99 caracteres
} TAluno;

// Listas Lineares de Aloca��o Sequencial
typedef struct{
	TAluno* aluno; 	// Para aloca��o din�mica
	int cap;		// Capacidade ou tamanho m�ximo da lista
	int tam;		// Tamanho da lista, inicialmente 0
    int eOrd;		// A lista � ordenada (TRUE ou FALSE)
} TListAlunos; // tam = 0 -> lista vazia; tam = cap -> lista cheia

TListAlunos* initListaAluno(int cap, int eOrd);
int buscaAluno(int nm, TListAlunos lista);
int incAluno(TAluno aluno, TListAlunos *lista);
int remAluno(int nm, TListAlunos *lista);
int ordenaLista(TListAlunos *lista);

TListAlunos* interListas(TListAlunos *listaA, TListAlunos *listaB);
TListAlunos* diferListas(TListAlunos *listaA, TListAlunos *listaB);
int busca_binaria(TListAlunos lista, int numMatricula);
void marge(TListAlunos *lista,int inicio,int meio,int fim);
void margesort(TListAlunos *lista, int inicio, int fim);
