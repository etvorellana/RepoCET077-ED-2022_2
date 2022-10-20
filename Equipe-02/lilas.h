
#ifndef LILAS_H_INCLUDED
#define LILAS_H_INCLUDED

#define TRUE 1
#define FALSE 0
#define LSIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Armazenando as informações de um aluno
typedef struct {
  int numMatricula; // chave com 9 dígitos (INT_MAX +2147483647)
  char nome[100];   // nome com até 99 caracteres
  char email[100];  // eMail com até 99 caracteres
} TAluno;

// Listas Lineares de Alocação Sequencial
typedef struct {
  TAluno *aluno; // Para alocação dinâmica
  int cap;       // Capacidade ou tamanho máximo da lista
  int tam;       // Tamanho da lista, inicialmente 0
  int eOrd;      // A lista é ordenada (TRUE ou FALSE)
} TListAlunos;   // tam = 0 -> lista vazia; tam = cap -> lista cheia

TListAlunos *initListaAluno(int cap, int eOrd);
int buscaAluno(int nm, TListAlunos *lista);
int incAluno(TAluno aluno, TListAlunos *lista);
int remAluno(TAluno *Taluno, TListAlunos *Tlista);
void criaheap(TAluno *lista, int i, int f);
void HeapSort(TListAlunos *infolistas, TAluno *lista, int tam);

TListAlunos *uniaoListas(TListAlunos *listaA, TListAlunos *listaB);
void interListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *listaC);
TListAlunos *diferListas(TListAlunos *listaA, TListAlunos *listaB);
int buscaPorNome(char nome[], TListAlunos *lista);
int buscaAlunoEmail(char *email, TListAlunos *lista);
void gerarAluno(TListAlunos *setTlistaAlunos, int tam);
void ExibirAluno(TListAlunos *getTlistaAlunoTaluno);

#endif // LILAS_H_INCLUDED
