#include "biblioteca.h"
#include <string.h>
#include <time.h>

TListaAlunos *initListaAluno(int cap, int eOrd) {
  TListaAlunos *Tlista;
  Tlista = (TListaAlunos *)malloc(sizeof(TListaAlunos));
  TListaAlunos *initListaAluno;
  Tlista->tam = 0;
  Tlista->cap = cap;
  Tlista->eOrd = eOrd;

  if (eOrd) {
    // se é ordenada aloca assim
    Tlista->aluno = (TAluno *)malloc((cap) * sizeof(TAluno));
  } else {
    // se não é ordenada aloc cap + 1;
    Tlista->aluno = (TAluno *)malloc((cap + 1) * sizeof(TAluno));
  }
  return Tlista;
}

void ordenarListaAlunos(TListaAlunos *lista, int esquerda, int direita) {
  int i, j, x, y;

  i = esquerda;
  j = direita;
  x = lista->aluno[esquerda + direita / 2].matricula;

  while (i <= j) {
    while (lista->aluno[i].matricula < x && i < direita) {
      i++;
    }
    while (lista->aluno[j].matricula > x && j > esquerda) {
      j--;
    }
    if (i <= j) {
      y = lista->aluno[i].matricula;
      lista->aluno[i].matricula = lista->aluno[j].matricula;
      lista->aluno[j].matricula = y;
      i++;
      j--;
    }
  }

  if (j > esquerda) {
    ordenarListaAlunos(lista, esquerda, j);
  }
  if (i < direita) {
    ordenarListaAlunos(lista, i, direita);
  }
}

char *gerar_str() {
  char *novastr, *validos1 = "bcdfghjklmnpqrstvwxz";
  char *validos2 = "aeiou";
  int tam;

  // tamanho da string entre 4 e 2
  tam = (4 + rand() % 3);

  // aloca memoria
  novastr = (char *)malloc((tam + 1) * sizeof(char));

  // Atribuir caracteres alternados entre consoantes e vogais a um vetor
  for (int i = 0; i < tam; i++) {
    if (i % 2 == 0) {
      novastr[i] = validos1[rand() % strlen(validos1)];
    } else {
      novastr[i] = validos2[rand() % strlen(validos2)];
    }
  }
  return novastr;
}

char *gerar_email() {
  char *novastr;
  novastr = gerar_str();
  strcat(novastr, "@uesc.com.br");

  return novastr;
}
char *gerar_nome() {
  char *nome, *sobrenome;
  nome = gerar_str();
  strcat(nome, " ");
  sobrenome = gerar_str();
  strcat(nome, sobrenome);
  strcat(nome, " ");
  sobrenome = gerar_str();
  strcat(nome, sobrenome);

  return nome;
}

int Matricula() {
  srand(time(NULL));
  int a;
  a = 2000 + rand() % 23;
  a = a * 10;
  a += 1 + rand() % 2;
  a *= 10000;
  a += rand() % 10000;
  return a;
}

int gerarMatricula(TListaAlunos *lista) {
  int b = 0, a;

  a = Matricula();
  do {
    b = 0;
    for (int i = 0; i < lista->tam; i++) {
      if (lista->aluno[i].matricula == a)
        b++;
    }
    if (b != 0) {
      a = Matricula();
    }

  } while (b != 0);
  return a;
}

void gerarDadosAlunos(TListaAlunos *lista) {
  int matricula, tam;
  char *nome, *email;
  printf("\nQuantos alunos você quer gerar?");
  scanf("%d", &tam);

  if (tam < lista->cap) {
    lista->tam = tam;
    for (int i = 0; i < tam; i++) {
      matricula = gerarMatricula(lista);
      nome = gerar_nome();
      email = gerar_email();

      lista->aluno[i].matricula = matricula;
      lista->aluno[i].nome = nome;
      lista->aluno[i].email = email;
    }
  }
  if (lista->eOrd == 1)
    ordenarListaAlunos(lista, 0, lista->tam - 1);
}

void imprimir_listaAlunos(TListaAlunos *lista) {
  printf("\n+++++++++++++++++++INICIO++++++++++++++++");
  for (int i = 0; i < lista->tam; i++) {

    printf("\nMatricula: %d", lista->aluno[i].matricula);
    printf("\nNome: %s", lista->aluno[i].nome);
    printf("\nEmail: %s", lista->aluno[i].email);
    printf("\n------------------------------------");
  }
  printf("\n+++++++++++++++++++FIM+++++++++++++++++++");
}

int removerAluno(TAluno aluno, TListaAlunos *lista) {
  if (lista->eOrd) {
    int i, j;

    for (i = 0; i < lista->tam; i++) {

      if (lista->aluno[i].matricula == aluno.matricula) {

        for (j = i; j < lista->tam - 1; j++)
          lista->aluno[j] = lista->aluno[j + 1];

        lista->tam--;

        return 1;
      }
      return 0;
    }
  } else {
    int i;
    lista->aluno[lista->tam].matricula = aluno.matricula;
    while (lista->aluno[i].matricula != aluno.matricula) {

      i++;
    }
    if (i < lista->tam) {
      lista->aluno[i] = lista->aluno[lista->tam - 1];
      lista->tam--;
      return 1;
    } else
      return 0;
  }
  return 0;
};

int buscaAluno(int nm, TListaAlunos *lista, TListaAlunos tam) {
  for (int i = 0; i < lista->tam; i++) {
    if (nm == lista->aluno[i].matricula) {
      printf("\t\n %d -- Matricula: %d", i + 1, lista->aluno[i].matricula);
      printf("\t nome: %s", lista->aluno[i].nome);
      printf("\tEmail: %s", lista->aluno[i].email);
      printf("\t\n-----------------------------------------\n");
    } else {
      printf("\nO aluno não está na lista");
    }
  }
}
int buscaAlunoBin(int nm, TListaAlunos *lista, TListaAlunos tam) {
  int menor = 0;
  int maior = lista->tam - 1;
  int meio=0;
  for (int i = 0; i < lista->tam; i++) {
    meio = (maior + menor) / 2;
    if (lista->aluno[meio].matricula == lista->aluno[i].matricula) {
      return meio;
    }
    if (lista->aluno[meio].matricula == lista->aluno[i].matricula) {
      maior = meio - 1;
    }
    if (lista->aluno[meio].matricula == lista->aluno[i].matricula) {
      menor = meio + 1;
    }
  }
}
int incAluno(TAluno aluno, TListaAlunos *lista) { // Desordenada
  if (lista->eOrd==0) {
    int n = 0;
    printf("Quantos alunos voce deseja incluir?");
    scanf("%d", &n);
    int aux = lista->tam;
    lista->tam += n;
    for (int i = aux; i < lista->tam + n; i++) {
      printf("Digite a matricula do aluno");
      scanf("%d", &lista->aluno[i].matricula);
      printf("Digite o nome do aluno");
      scanf("%s", lista->aluno[i].nome);
      printf("Digite o email do aluno");
      scanf("%s", lista->aluno[i].email);
    }
  } else {
  }
}
int buscaPorNome(char nome[],
                 TListaAlunos *lista) { // se as string são iguais retorna 0.
  for (int i = 0; i < lista->tam; i++) {
    if (strcmp(nome, lista->aluno[i].nome) == 0) {
      printf("\t\n %d -- Matricula: %d", i + 1, lista->aluno[i].matricula);
      printf("\t nome: %s", lista->aluno[i].nome);
      printf("\tEmail: %s", lista->aluno[i].email);
      printf("\t\n-----------------------------------------\n");
    } else {
      printf("\nO aluno não está na lista");
    }
  }
}
int buscaPorEmail(char email[], TListaAlunos *lista) {
  // se as string são iguais retorna 0.
  for (int i = 0; i < lista->tam; i++) {
    if (strcmp(email, lista->aluno[i].nome) == 0) {
      printf("\t\n %d -- Matricula: %d", i + 1, lista->aluno[i].matricula);
      printf("\t nome: %s", lista->aluno[i].nome);
      printf("\tEmail: %s", lista->aluno[i].email);
      printf("\t\n-----------------------------------------\n");
    } else {
      printf("\nO aluno não está na lista");
    }
  }
}

void menu() {
  printf("\nImprimir lista[1]");
  printf("\nOrdenar lista [2]");
  printf("\nRemover aluno [3]");
  printf("\nBusca sequencial [4]");
  printf("\nBusca binaria[5]");
  printf("\nBusca por nome[6]");
  printf("\nBusca por email[7]");
  printf("\nIncluir aluno[8]");
}