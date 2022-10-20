#include "lilas.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  srand(time(NULL));
  TListAlunos *listaA, *listaB, *listaC;
  listaA = initListaAluno(LSIZE, FALSE);
  listaB = initListaAluno(LSIZE, TRUE);
  listaC = initListaAluno(listaA->cap, listaA->eOrd);
  gerarAluno(listaA, 4);
  gerarAluno(listaB, 4);
  printf("\n\nLISTA A DESORDENADA\n\n");
  ExibirAluno(listaA);
  printf("\n\nLISTA B ORDENADA\n\n");
  ExibirAluno(listaB);
  HeapSort(listaA, listaA->aluno, listaA->tam);
  printf("\n\nLISTA A ORDENADA\n\n");
  ExibirAluno(listaA);
  if (incAluno(listaB->aluno[0], listaA)) {
    printf("Aluno adicionado\n");
  } else {
    printf("Aluno não adiconado, lista cheia\n");
  }
  printf("\n\nLISTA A COM B[0] ORDENADO\n\n");
  ExibirAluno(listaA);

  if (remAluno(&listaB->aluno[1], listaB)) {
    printf("Aluno removido\n");
  } else {
    printf("Aluno não removido, lista vazia ou aluno não esta na lista\n");
  }
  printf("\n\nLISTA B COM B[0] EXCLUIDO\n\n");
  ExibirAluno(listaB);

  int pos = buscaAlunoEmail(listaB->aluno[0].email, listaA);
  if (pos == listaA->tam) {
    printf("Aluno não encontrado!\n");
  } else {
    printf("\n\nALUNO B[0] PROCURADO NA LISTA A\n\n%s\n",
           listaA->aluno[pos].email);
  }
  
  interListas(listaA, listaB, listaC);
  ExibirAluno(listaC);

  return 0;
}
