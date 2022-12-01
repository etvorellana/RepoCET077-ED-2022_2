#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int numMatricula;
    char nome[100];
    char email[100];
}Taluno;

typedef struct no
{
  Taluno aluno;
  struct no *proximoNo;
} No;

No *inicializar();

void inserir(No *head, int valor, char *nome, char *email);

void menu();

void imprimir(No *lista);

No *buscar(No *lista, int id);

Taluno remover(No *head, int valor);

int main(void)
{
  setlocale(LC_ALL,"Portuguese");
  No *lista, *rem, *pos;
  int op;
  int numMatricula;
  char nome[100];
  char email[100];
  int valor;
  lista = inicializar();
  srand(time(NULL));

  do
  {
    menu();
    scanf("%d", &op);
    switch (op)
    {

    case 1:
      valor = 2000 + rand()%23;
      valor *= 10;
      valor += (1 + rand() % 1);
      valor *= 10000;
      valor += (rand() % 10000);
      const char alf[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
      sprintf(nome, "%c%c%c%c%c %c%c%c%c%c%c",
              alf[rand() % 27], alf[rand() % 27], alf[rand() % 27],
              alf[rand() % 27], alf[rand() % 27], alf[rand() % 27],
              alf[rand() % 27], alf[rand() % 27], alf[rand() % 27],
              alf[rand() % 27], alf[rand() % 27]);
      sprintf(email, "%d@uesc.br", valor);
      inserir(lista, valor, nome, email);
      printf ("Elemento incluido\n");
      break;

    case 2:
      imprimir(lista);
      break;

    case 3:
      printf("\nDigite o numMatricula:");
      scanf("%d", &numMatricula);

      pos = buscar(lista, numMatricula);
      if (pos)
      {
        printf("ENCONTRADO");
      }
      else
        printf("Nao encontrado!\n");
      break;

    case 4:
      printf("\nInforme o numMatricula Para Remover:");
      scanf("%d", &numMatricula);

      remover(&lista, numMatricula);
      if (rem)
      {
        printf("\nElemento Removido: %d\n", numMatricula);
      }
      else
        printf("\nElemento Não Encontrado!\n");
      free(rem);
      break;

    case 5:
      exit(0);
      break;

    default:
      printf("Opção invalida\n");
      break;
    }
  } while (op);
}

No *inicializar()
{
  No *head = (No *)malloc(sizeof(No));
    head->proximoNo = NULL;
    return head;
}

void inserir(No *head, int mat, char *nome, char *email)
{
    No *busca = buscar(head, mat); 
    if (busca == NULL){

        No *aux, *node = (No *)malloc(sizeof(No));
        if (head->proximoNo == NULL)
        {
            node->aluno.numMatricula = mat;
            strcpy(node->aluno.email, email);
            strcpy(node->aluno.nome, nome);
            node->proximoNo = NULL;
            head->proximoNo = node;
        }
        else
        {
            node->aluno.numMatricula = mat;
            strcpy(node->aluno.email, email);
            strcpy(node->aluno.nome, nome);
            aux = head->proximoNo;
            head->proximoNo = node;
            node->proximoNo = aux;
        }
    } else {
        printf ("Este aluno ja esta na lista");
        return;
    }
}

void imprimir(No *lista)
{
  int pos = 0;
  lista = lista->proximoNo;
  while (lista != NULL)
  {
    printf("\n[%d] - Matricula = %d\nNome = %s\nEmail = %s\n", pos, lista->aluno.numMatricula, lista->aluno.nome, lista->aluno.email);
    lista = lista->proximoNo;
    pos++;
  }
}

No *buscar(No *lista, int id)
{
  No *local;
  int pos = 0;
  while (lista != NULL)
  {
    if (lista->aluno.numMatricula == id)
    {
      printf("id: %d\n", lista->aluno.numMatricula);
      local = lista;
      return local;
    }
    lista = lista->proximoNo;
    pos++;
  }
  return NULL;
}

Taluno remover(No *head, int valor) {
  if (head->proximoNo == NULL) {
    printf("Lista vazia");
    return;
  }

  Taluno rem;
  No *aux;

  while (head->proximoNo->proximoNo != NULL && head->proximoNo != NULL) {
    if (head->proximoNo->aluno.numMatricula == valor) {
        printf ("\n%d sera removido\n", valor);
        rem = head->proximoNo->aluno;
        aux = head->proximoNo;
        head->proximoNo = head->proximoNo->proximoNo;
        free(aux);
        return rem;
    }
    else {
        head = head->proximoNo;
    }
  }
  return;
}
