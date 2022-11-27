#include "prototipos.h"



struct no{
  TAluno aluno;
	NO *proximo, *anterior;
};

NO *inserirInicio(NO *lista, TAluno aluno){			//FEITA
 
  if(!buscar(lista,aluno.matricula)){
    NO *novo = malloc(sizeof(NO));
    if(novo){
 
        novo->aluno = aluno;
        // próximo do novo nó aponta para o início da lista
        novo->proximo = lista;
        // o anterior é nulo pois é o primeiro nó
        novo->anterior = NULL;
        // se a lista não estiver vazia, o anterior do primeiro nó  aponta para o novo nó
        if(lista)
            lista->anterior = novo;
        // o novo nó passa a ser o início da lista (o primeiro nó da lista)
        lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
  }else
   printf("ESSA ALUNO JA ESTA NA LISTA!!!");
}



NO *criarLista(){							
	return NULL;
	//linhavazia
}

void mostrarLista(NO *lista){					
	if( lista == NULL){
		printf("Lista Vazia.\n");
	}else{
		printf("----------------LISTA----------------- ");
		for(NO *aux=lista; aux != NULL; aux= aux->proximo){
  
		printf("\nMatricula: %d", aux->aluno.matricula);
    printf("\nNome: %s", aux->aluno.nome);
    printf("\nEmail: %s", aux->aluno.email);
    printf("\n------------------------------------");
		}
		printf("\n");
	}
}



NO* buscar(NO *lista, int num){
    NO *aux, *no = NULL;

    aux = lista;
    while(aux && aux->aluno.matricula != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    return no;
}

int qtdElementos(NO *lista){					
	int qtd = 0;
	for(NO *aux=lista; aux != NULL; aux= aux->proximo){
		qtd++;
	}
	return qtd;
}

	
NO * removerElemento (NO* lista, TAluno *aluno) {
   /* Busca o elemento a ser removido da lista */
    NO* p;
   if( p= buscar(lista,aluno->matricula)){
     aluno=&p->aluno; //guarda aluno removido
   /* se não achou o elemento: retorna lista inalterada */
    if (p == NULL)
        return lista;
  
    if (lista == p){ 
        p->proximo->anterior = NULL;
        lista = p->proximo;}
    else{
        p->anterior->proximo = p->proximo;}

    if (p->proximo != NULL)
        p->proximo->anterior = p->anterior;
    free(p);
  }else
     printf("ALUNO NAO ESTA NA LISTA!!!");
     
  /* Retorna a lista atualizada */
    return lista;
}

