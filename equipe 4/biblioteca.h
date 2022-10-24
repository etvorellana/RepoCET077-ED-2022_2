#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int matricula;
  char *nome;
  char *email;
} TAluno;

// lista lineares de alocaçao sequencial

typedef struct {
  TAluno *aluno; // para alocação dinamica de memoria
  int cap;       // capacidade ou tamanho da lista, inicialmente 0
  int tam;       // Tamanho da lista, inicalmente 0
  int eOrd;      // A lista é ordenada (true e false);

} TListaAlunos; // tam = 0 -> lista-vazia; tam = cap - > lista cheia

TListaAlunos *initListaAluno(int cap, int eOrd);
void ordenarListaAlunos(TListaAlunos *lista, int esquerda, int direita);
void gerarDadosAlunos(TListaAlunos *lista);
void imprimir_listaAlunos(TListaAlunos *lista);
int removerAluno(TAluno aluno, TListaAlunos *lista);
int incAluno(TAluno aluno, TListaAlunos *lista);
int buscaAluno(int nm, TListaAlunos *lista, TListaAlunos tam);
int buscaAlunoBin(int nm, TListaAlunos *lista, TListaAlunos tam);
int buscaPorNome(char nome[], TListaAlunos *lista);
int buscaPorEmail(char email[], TListaAlunos *lista);
void menu();

#endif