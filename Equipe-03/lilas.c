#include "lilas.h"
#include <stdio.h>
#include <stdlib.h>

TListAlunos *initListaAluno(int cap, int eOrd) {
  TListAlunos *lista;
  
  lista = (TListAlunos *)malloc(sizeof(TListAlunos));
  
  lista->tam = 0;
  lista->cap = cap;
  lista->eOrd = eOrd;
  
  if (eOrd) {
    lista->aluno = (TAluno *)malloc(cap * sizeof(TAluno));
  } else {
    lista->aluno = (TAluno *)malloc((cap + 1) * sizeof(TAluno));
  }
  
  return lista;
}


int buscaAluno(int nm, TListAlunos *lista) {
  if (lista->eOrd) {
    return buscaBin(nm, lista);
  } else {
    return buscaSeq(nm, lista);
  }
}


int buscaSeq(int matricula, TListAlunos *lista) {
  for (int i = 0; i < lista->tam; i++) {
    if (lista->aluno[i].numMatricula == matricula) {
      return i;
    }
  }

  return lista->tam;
}


int buscaAlunoEmail(char *email, TListAlunos *lista) {
  for (int i = 0; i < lista->tam; i++) {
    if (!(strcmp(email, lista->aluno[i].email))) {
      return i;
    } 
  }
  
  return lista->tam;
}


int buscaBin(int matricula, TListAlunos *lista) {
  int inicio = 0;
  int fim = lista->tam - 1;
  int i;

  while (inicio <= fim) {
    i = (inicio + fim) / 2;
    
    if (lista->aluno[i].numMatricula == matricula) {
      return i;
    }

    if (lista->aluno[i].numMatricula < matricula) {
      inicio = i + 1;
    } else {
      fim = i;
    }
  }

  
  return i;
}



int incAluno(TAluno registro, TListAlunos *Tlista) {
  int posicao = buscaAluno(registro.numMatricula, Tlista), tam = Tlista->tam;


  if(Tlista->tam == Tlista->cap) return 0;
  else {

    if(Tlista->eOrd){
      if(Tlista->aluno[posicao].numMatricula == registro.numMatricula) {
        return 0;
      }else {
        while ((tam-1) >= posicao){
          Tlista->aluno[tam] = Tlista->aluno[tam-1];
          tam--;
        }
        Tlista->aluno[posicao] = registro;
        Tlista->tam++;
      }
    } else {
      if(posicao != Tlista->tam) {
        return 0;
      }else {
        Tlista->aluno[posicao] = registro;
        Tlista->tam++;
      }
    }

    return 1;
  }
}


int remAluno(TAluno *Taluno, TListAlunos *Tlista) {
  if (Tlista->tam == 0) {
    return FALSE;
  }

  int posicao, j;

  posicao = buscaAluno(Taluno->numMatricula, Tlista);

  if (Tlista->eOrd) {
    if (Tlista->aluno[posicao].numMatricula == Taluno->numMatricula) {
      for (j = posicao; j < (Tlista->tam - 1); j++) Tlista->aluno[j] = Tlista->aluno[j + 1];
        
      Tlista->tam--;
        
      return TRUE;
    } else {
      return FALSE;
    }
  } else {
    if (posicao < Tlista->tam) {
      Tlista->aluno[posicao] = Tlista->aluno[Tlista->tam-1];
      Tlista->tam--;
      return TRUE;
    } else {
      return FALSE;
    }
  }
}

void interListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *listaC) {

  for (int i = 0; i < listaA->tam; i++) {
    int pos = buscaSeq(listaA->aluno[i].numMatricula, listaB);
      
    if (pos < listaB->tam) {
      listaC->aluno[listaC->tam] = listaA->aluno[i];
      listaC->tam++;
    }
  }
}



void HeapSort(TListAlunos *infolistas, TAluno *lista, int tam) {
  TAluno aluno;
  int i;
  
  for (i = (tam - 1) / 2; i >= 0;
       i--) {                
    criaheap(lista, i, tam); 
  }
  
  for (i = tam - 1; i >= 1; i--) {
    aluno = lista[0];
    lista[0] = lista[i];
    lista[i] = aluno; 
    criaheap(lista, 0, i - 1);
  }
  
  infolistas->eOrd = TRUE;
}


void criaheap(TAluno *lista, int i, int f) { 
  TAluno aluno;
  
  aluno = lista[i]; 
  int j = i * 2 + 1;
  
  while (j <= f) { 
    if (j < f) {
      if (lista[j].numMatricula <
          lista[j + 1].numMatricula) { 
        j = j + 1;                    
      }     
    }
    
    if (aluno.numMatricula < lista[j].numMatricula) {
      lista[i] = lista[j];
      i = j;
      j = 2 * i + 1;
    } else {
      j = f + 1;
    }
  }
  
  lista[i] = aluno;
}
