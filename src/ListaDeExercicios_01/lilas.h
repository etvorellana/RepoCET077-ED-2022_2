#define TRUE 1
#define FALSE 0
#define LSIZE 10
#include <stdlib.h>

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX +2147483647)
    char nome[]100];   // nome com até 99 caracteres
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
int remAluno(TAluno *aluno, TListAlunos *lista);
void ordenaLista(TListAlunos *lista);

TListAlunos* initListaAluno(int cap, int eOrd)
{
    TListAlunos *lista;
    lista = (TListAlunos*) malloc(sizeof(TListAlunos));
    lista->tam = 0;
    lista->cap = cap;
    lista->eOrd = eOrd;
    if(eOrd)
    {
        lista->aluno = (TAluno*) malloc(cap*sizeof(TAluno));
    }else{
        lista->aluno = (TAluno*) malloc((cap+1)*sizeof(TAluno));
    }
    return lista;
}
