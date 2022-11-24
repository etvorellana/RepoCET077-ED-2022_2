#include <stdio.h>
#include "lilas.h"

void menu();
void options(int, TListAlunos*);
int main(){
  TListAlunos *lista;
  int option = 1;
  while(option){
    menu();
    printf("Digite a opção: ");
    scanf("%d", &option);
    options(option, lista);
  }
}

void menu(){
  printf("1- Criar Lista\n");
  printf("2- Adicionar aluno na lista\n");
  printf("3- Remover aluno da lista\n");
  printf("4- Ordenar Lista\n");
  printf("5- Buscar Aluno\n");
}


void options(int option, TListAlunos *lista){
  int cap, ord;
  int busca_option;
  int achou;
  TAluno aluno;
  int matricula;
  char nome[100], email[100];
  switch (option)
  {
  case 1:
    printf("Digite a capacidade: ");
    scanf("%d", &cap);
    printf("Digite 1 para ordenar 1 0  para não: ");
    scanf("%d", &ord);
    lista = initListaAluno(cap, ord);
    break;
  case 2:
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno.nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno.numMatricula);
    incAluno(aluno, lista);
    break;
  case 3:
    remAluno(&aluno, lista);
    printf("Aluno: %s removido\n", aluno.nome);
    break;
  case 4:
    ordenarLista(lista);
    break;
  case 5:
    printf("1- Busca por nome\n2- Busca por email\n 3- Busca por matricula\n Opção: ");
    scanf("%d", &busca_option);
    switch (busca_option)
    {
    case 1:
      printf("Digite o nome: ");
      scanf("%s", nome);
      break;
      buscaPorNome(nome, lista);
      if(achou == -1){
        printf("Não encontrado");
      }else{
        printf("Aluno: %s", lista->aluno[achou].nome);
      }
    case 2:
      printf("Digite o email: ");
      scanf("%s", email);
      buscaPorEMail(email, lista);
      if(achou == -1){
        printf("Não encontrado");
      }else{
        printf("Aluno: %s", lista->aluno[achou].nome);
      }
      break;
    case 3:
      printf("Digite o matricula: ");
      scanf("%i", &matricula);
      buscaAluno(matricula, lista);
      if(achou == -1){
        printf("Não encontrado");
      }else{
        printf("Aluno: %s", lista->aluno[achou].nome);
      }
      break;
    default:
      break;
    }
    break;
  default:
    printf("Opção invalida\n BYE\n");
    exit(-1);
  }
}