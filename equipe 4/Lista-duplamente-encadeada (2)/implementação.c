#include "prototipos.h"

struct no {
  TAluno aluno;
  NO *prox, *anterior;
};

NO *inserirInicio(NO *lista, TAluno aluno) { // FEITA

  if (!buscar(lista, aluno.matricula)) {
    NO *novo = malloc(sizeof(NO));
    if (novo) {

      novo->aluno = aluno;
      // próximo do novo nó aponta para o início da lista
      novo->prox = lista;
      // o anterior é nulo pois é o primeiro nó
      novo->anterior = NULL;
      // se a lista não estiver vazia, o anterior do primeiro nó  aponta para o
      // novo nó
      if (lista)
        lista->anterior = novo;
      // o novo nó passa a ser o início da lista (o primeiro nó da lista)
      lista = novo;
    } else
      printf("Erro ao alocar memoria!\n");
  } else
    printf("ESSA ALUNO JA ESTA NA LISTA!!!");
}

NO *criarLista() {
  return NULL;
  // linhavazia
}

void mostrarLista(NO *lista) {
  if (lista == NULL) {
    printf("Lista Vazia.\n");
  } else {
    printf("----------------LISTA----------------- ");
    int i = 0;
    for (NO *aux = lista; aux != NULL; aux = aux->prox) {
      i++;
      printf("\n[%d]Matricula: %d", i, aux->aluno.matricula);
      printf("\nNome  : %s", aux->aluno.nome);
      printf("\nEmail: %s", aux->aluno.email);
      printf("\n------------------------------------");
    }
    printf("\n");
  }
}

NO *buscar(NO *lista, int num) {
  NO *aux, *no = NULL;

  aux = lista;
  while (aux && aux->aluno.matricula != num)
    aux = aux->prox;
  if (aux)
    no = aux;
  return no;
}

int qtdElementos(NO *lista) {
  int qtd = 0;
  for (NO *aux = lista; aux != NULL; aux = aux->prox) {
    qtd++;
  }
  return qtd;
}

NO *removerElemento(NO *lista, TAluno *aluno) {
  /* Busca o elemento a ser removido da lista */
  NO *p;
  if (p == buscar(lista, aluno->matricula)) {
    aluno = &p->aluno; // guarda aluno removido
    /* se não achou o elemento: retorna lista inalterada */
    if (p == NULL)
      return lista;

    if (lista == p) {
      p->prox->anterior = NULL;
      lista = p->prox;
    } else {
      p->anterior->prox = p->prox;
    }

    if (p->prox != NULL)
      p->prox->anterior = p->anterior;
    free(p);
  } else {
    printf("ALUNO NAO ESTA NA LISTA!!!");
    return NULL;
  }
  /* Retorna a lista atualizada */
  return lista;
}
void empilhar(TAluno *aluno, Tpilha *pilha) {
  TAluno *novo = (TAluno *)malloc(sizeof(TAluno));
  novo->matricula = aluno->matricula;
  strcpy(novo->nome, aluno->nome);
  strcpy(novo->email, aluno->email);
  novo->proximo = pilha->topo;
  pilha->topo = novo;
  pilha->tam++;
}

void imprime_pilha(Tpilha *pilha) {
  TAluno *aux = pilha->topo;
  int i = 1;
  while (aux != NULL) {
    printf("---------------Aluno[%d]--------------\n", i);
    printf("Matricula: %d\n", aux->matricula);
    printf("Nome: %s\n", aux->nome);
    printf("Email: %s\n", aux->email);
    aux = aux->proximo;
    i++;
  }
}
void empilharDaFila(NO *no, Tpilha *pilha) {
  TAluno *novo = (TAluno *)malloc(sizeof(TAluno));
  while (no->prox != NULL) {
    novo->matricula = no->prox->aluno.matricula;
    strcpy(novo->nome, no->prox->aluno.nome);
    strcpy(novo->email, no->prox->aluno.email);
    empilhar(novo, pilha);
    no = no->prox;
  }
}
/*NO *RemoverTodosElemento(NO *lista) {
  for (NO *aux = lista; aux != NULL; aux = aux->prox) {
    aux->prox->anterior = NULL;
    lista = aux->prox;
  }
}*/
void imprime_fila(Tfila *fila) {

  TAluno *aux = fila->inicio;
  while (aux != NULL) {
    printf("Matricula: %d\n", aux->matricula);
    printf("Nome: %s\n", aux->nome);
    printf("Email: %s\n", aux->email);
    aux = aux->proximo;
  }
}
void enfileirarDaPilha(Tpilha *pilha, Tfila *fila) {
  TAluno *aluno =
      (TAluno *)malloc(sizeof(TAluno));      // aloca pilha e pega a estrutura
  aluno->matricula = pilha->topo->matricula; //
  strcpy(aluno->nome, pilha->topo->nome);
  strcpy(aluno->email, pilha->topo->email);
  TAluno *novo =
      (TAluno *)malloc(sizeof(TAluno)); // aloca fila e recebe a estrutura
  novo->matricula = aluno->matricula;
  strcpy(novo->nome, aluno->nome);
  strcpy(novo->email, aluno->email);
  if (fila->inicio == NULL) { // checa o tamanho da fila e incrementa
    fila->inicio = novo;
    fila->fim = novo;
    fila->tam++;
  } else {
    fila->fim->proximo = novo;
    fila->fim = novo;
    fila->tam++;
  }
  pilha->topo = pilha->topo->proximo;
  pilha->tam--;
}
void preencheLista(TAluno *aluno, NO *no) {
  NO *aux = (NO *)malloc(sizeof(NO));
  aux->aluno.matricula = aluno->matricula;
  strcpy(aux->aluno.nome, aluno->nome);
  strcpy(aux->aluno.email, aluno->email);
  aux->prox = no->prox;
  aux->anterior = no;
  no->prox = aux;
  if (aux->prox != NULL) {
    aux->prox->anterior = aux;
  }
}

void desifileirar(Tfila *fila, NO *lista) {
  while (fila->inicio != NULL) {
    TAluno *aluno = (TAluno *)malloc(sizeof(TAluno));
    aluno->matricula = fila->inicio->matricula;
    strcpy(aluno->nome, fila->inicio->nome);
    strcpy(aluno->email, fila->inicio->email);
    preencheLista(aluno, lista);
    fila->inicio = fila->inicio->proximo;
    fila->tam--;
  }
}