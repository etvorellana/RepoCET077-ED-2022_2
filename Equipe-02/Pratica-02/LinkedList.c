#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct no
{
  int numMatricula;
  char email[100];
  char nome[100];
  struct no *proximoNo;
} No;

No *inicializar();

void inserir(No *head, int valor, char *nome, char *email);

void menu();

void imprimir(No *lista);

No *buscar(No *lista, int id);

No *remover(No **lista, int valor);

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

      rem = remover(&lista, numMatricula);
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
  int valor = 2022;
  valor *= 10;
  valor += (1 + rand() % 1);
  valor *= 10000;
  valor += (rand() % 10000);

  const char alf[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  sprintf(head->nome, "%c%c%c%c%c %c%c%c%c%c%c",
          alf[rand() % 26], alf[rand() % 26], alf[rand() % 26],
          alf[rand() % 26], alf[rand() % 26], alf[rand() % 26],
          alf[rand() % 26], alf[rand() % 26], alf[rand() % 26],
          alf[rand() % 26], alf[rand() % 26]);
  sprintf(head->email, "%d@uesc.br", head->numMatricula);
  if (head)
  {
    head->numMatricula = valor;
    head->proximoNo = NULL;
    return head;
  }
  else
  {
    printf("erro\n");
    return NULL;
  }
  return NULL;
}
void inserir(No *head, int valor, char *nome, char *email)
{
  No *aux, *node = (No *)malloc(sizeof(No));
  if (head->proximoNo == NULL)
  {
    node->numMatricula = valor;
    strcpy(node->email, email);
    strcpy(node->nome, nome);
    node->proximoNo = NULL;
    head->proximoNo = node;
  }
  else
  {
    node->numMatricula = valor;
    strcpy(node->email, email);
    strcpy(node->nome, nome);
    aux = head->proximoNo;
    head->proximoNo = node;
    node->proximoNo = aux;
  }
}

void menu()
{
  printf("\n1 - Inserir Elemento na Lista\n");
  printf("2 - Mostra Lista\n");
  printf("3 - Buscar\n");
  printf("4 - Remover\n");
  printf("5 - Sair\n");
  printf("Opção: \n");
}

void imprimir(No *lista)
{
  int pos = 0;
  while (lista != NULL)
  {
    printf("\n[%d] - Matricula = %d\nNome = %s\nEmail = %s\n", pos, lista->numMatricula, lista->nome, lista->email);
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
    if (lista->numMatricula == id)
    {
      printf("id: %d\n", lista->numMatricula);
      local = lista;
      return local;
    }
    lista = lista->proximoNo;
    pos++;
  }
  return NULL;
}

No *remover(No **lista, int valor)
{
  No *aux, *pos = NULL;

  if (*lista)
  {
    if ((*lista)->numMatricula == valor)
    {
      pos = *lista;
      *lista = pos->proximoNo;
    }
    else
    {
      aux = *lista;
      while (aux->proximoNo && aux->proximoNo->numMatricula != valor)
        aux = aux->proximoNo;
      if (aux->proximoNo)
      {
        pos = aux->proximoNo;
        aux->proximoNo = pos->proximoNo;
      }
    }
  }
  return pos;
}
