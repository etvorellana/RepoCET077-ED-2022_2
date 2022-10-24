#include "biblioteca.h"

int main() {
  TListaAlunos *lista[3];
  TAluno aluno, *busca;
  int nm;
  char *nome, *email;

  int cap, ord, quant;

  printf("Quantidade de listas:");
  scanf("%d", &quant);

  for (int i = 0; i < quant; i++) {
    printf("\nLISTA %d", i + 1);
    printf("\nCapacidade da lista:");
    scanf("%d", &cap);
    do {
      printf("Desordenada[0]\nOrdenada[1]\n:");
      printf("Escolha:");
      scanf("%d", &ord);
      if (ord < 0 || ord > 1)
        printf("\nEscolha invalida!!\n\n");
    } while (ord < 0 || ord > 1);

    lista[i] = initListaAluno(cap, ord);
    gerarDadosAlunos(lista[i]);
    imprimir_listaAlunos(lista[i]);
  }
  while (1) {
    int escolha, i;
    menu();
    printf("\nEscolha:");
    scanf("%d", &escolha);
    printf("\nQual lista:");
    scanf("%d", &i);

    switch (escolha) {
    case 1:
      imprimir_listaAlunos(lista[i - 1]);
      break;
    case 2:
      ordenarListaAlunos(lista[i - 1], 0, lista[i - 1]->tam - 1);
      imprimir_listaAlunos(lista[i - 1]);
      break;
    case 3:
      printf("\nMatricula do aluno:");
      scanf("%d", &aluno.matricula);
      i = removerAluno(aluno, lista[i - 1]);
      if (i == 0)
        printf("\nAluno não esta na lista!!");
      break;
    case 4:
      printf("Digite o nm");
      scanf("%d", &nm);
      int buscaAluno(int nm, TListaAlunos *lista, TListaAlunos tam);
      imprimir_listaAlunos(lista[i - 1]);

      break;
    case 5:
      printf("Digite o nm");
      scanf("%d", &nm);
      break;
    case 6:
      printf("Digite o nome que deseja buscar");
      scanf("%s", nome);
      int buscaPorNome(char nome[], TListaAlunos *lista);
    case 7:
      printf("Digite o nome que deseja buscar");
      scanf("%s", email);
      int buscaPorEmail(char email[], TListaAlunos *lista);
    default:
      printf("Escolha invalida!!!");
    }
  }
  return 0;
}