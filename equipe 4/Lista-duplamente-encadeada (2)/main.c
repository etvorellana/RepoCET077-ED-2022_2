#include "prototipos.h"
#include <string.h>
int main() {
  NO *lista, *busca;
  TAluno aluno, *retorno;
  lista = criarLista();
  int num, aux;
  int numMatricula = 2000 + rand() % 23;
  Tpilha pilha;
  Tfila fila;
  pilha.topo = NULL;
  pilha.tam = 0;

  while (1 == 1) {
    printf("\n************ MENU **************\n");
    printf("  [0] - SAIR\n");
    printf("  [1] - Inserir no Inicio\n");
    printf("  [2] - Exibir lista \n");
    printf("  [3] - Buscar Elemento\n");
    printf("  [4] - Quantidade de Elemento\n");
    printf("  [5] - Remover Elemento\n");
    printf("  [6] - Remover os Elementos e empilhar\n");
    printf("  [7] - Imprimi a pilha\n");
    printf("  [8] - Desimpilhar e enfileirar\n");
    printf("  [9] - Imprime a fila\n");
    printf("  [10] - Desinfileirar os elementos e colocar na lista\n");
    printf("  [11] - Exibir a lista Final\n");
    printf("*********************************\n");
    int op_menu;
    printf("Escolha uma opção: ");
    scanf("%d", &op_menu);

    switch (op_menu) {
    case 0:
      exit(1);
    case 1:
      printf("Quantos alunos deseja inserir?");
      scanf("%d", &aux);
      for (int i = 0; i < aux; i++) {
        numMatricula *= 10;
        numMatricula += (1 + rand() % 2);
        numMatricula *= 10000;
        numMatricula += (rand() % 10000);
        aluno.matricula = numMatricula;
        strcpy(aluno.nome, "Teste Nome Aluno");
        strcpy(aluno.email, "TNAluno@uesc.br");

        lista = inserirInicio(lista, aluno);
      }

      break;

    case 2: // MOSTRAR LISTA DE ALUNOS
      mostrarLista(lista);
      break;

    case 3: // BUSCAR ALUNOS
      printf("Número: ");
      scanf("%d", &num);
      if (retorno == buscar(lista, num)) {
        printf("\nAluno encontrado:");
        printf("\n\nMatricula: %d", retorno->matricula);
        printf("\nNome: %s", retorno->nome);
        printf("\nEmail: %s", retorno->email);
      } else
        printf("ALUNO NAO ESTA NA LISTA!!!");

      break;
    case 4: // QUANTIDADE DE ALUNOS
      printf("Número de Elementos: %d", qtdElementos(lista));
      break;
    case 5: // REMOVER ALUNO
      printf("Número a remover: ");
      scanf("%d", &aluno.matricula);
      if (lista == removerElemento(lista, &aluno)) {
        printf("\nAluno removido:");
        printf("\n\nMatricula: %d", aluno.matricula);
        printf("\nNome: %s", aluno.nome);
        printf("\nEmail: %s", aluno.email);
      }
      break;
    case 6:
      printf("Empilhando os elementos da lista...\n");
      empilharDaFila(lista, &pilha);
      // RemoverTodosElemento(lista);
      break;
    case 7:
      printf("Imprimindo a pilha...\n");
      imprime_pilha(&pilha);
      break;
    case 8:
      printf("\nDesimpilhando e enfilerando...");
      enfileirarDaPilha(&pilha, &fila);
    case 9:
      imprime_fila(&fila);
      break;
    default:
      printf(" -- Opção Inválida --\n");
      break;
    case 10:
      preencheLista(&aluno, lista);
      break;
    case 11:
      mostrarLista(lista);
    }
  }
  return 0;
}