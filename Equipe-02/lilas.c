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
    if (strcmp(email, lista->aluno[i].email) == 0) {
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
      printf("aluno encontrado!!!\n");
      return i;
    }

    if (lista->aluno[i].numMatricula < matricula) {
      inicio = i + 1;
    } else {
      fim = i;
    }
  }
  
  printf("Estou no loop");
  
  return i;
}


/*
** Retorna True=1 se o aluno for incluido e False=0 se não for incluido na lista
*/
int incAluno(TAluno registro, TListAlunos *Tlista) {
  int posicao = buscaAluno(registro.numMatricula, Tlista), tam = Tlista->tam;

  // Verifica se a lista está cheia
  if(Tlista->tam == Tlista->cap) return 0;
  else {
    // Verifica se a lista está ordenada
    if(Tlista->eOrd){
      // Verifica se o aluno já existe na lista
      if(Tlista->aluno[posicao].numMatricula == registro.numMatricula) return 0;
      else {
        // Insertion Sort //

        // Recua uma posição das matriculas que forem maiores a do registro
        // enquanto não precorre a lista completa ou não encontra uma matricula
        // menor
        while ((tam-1) >= posicao /*tam > 0 && Tlista->aluno[tam-1].numMatricula > registro.numMatricula*/){
          Tlista->aluno[tam] = Tlista->aluno[tam-1];
          tam--;
        }
                
        // Adiciona o aluno ao registro na posição correta
        Tlista->aluno[posicao] = registro;
        Tlista->tam++;
      }
    } else {
      // Verifica se o aluno já exite na lista
      if(posicao != Tlista->tam) return 0;
      else {
        // Adiciona o aluno ao final da lista e aumenta o seu tamanho
        Tlista->aluno[posicao] = registro;
        Tlista->tam++;
      }
    }

    return 1;
  }
}


/*
** Retorna True=1 se o aluno for excluido e False=0 se não for excluido na lista
*/
int remAluno(TAluno *Taluno, TListAlunos *Tlista) {
  if (Tlista->tam == 0) {
    return FALSE;
  }

  int posicao, j;

  posicao = buscaAluno(Taluno->numMatricula, Tlista);
  printf("\n\nPOSICAO %d\n\n", posicao);

  // Caso o aluno não seja encontrado na lista
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


// Retorna uma lista que tem como elementos os elementos da listaA presentes
// também na listaB
void interListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *listaC) {
  // a intersecção "herda" a cap e eOrd da listaA, pois se for ordenada ela
  // procura os elementos em ordem e a cap dela não pode ser maior que a da
  // listaA (a cap seria atingida caso todos so elementos de A estejam em B)
  for (int i = 0; i < listaA->tam; i++) {
    int pos = buscaSeq(listaA->aluno[i].numMatricula, listaB);
      
    // se a lista não for ordenada ela retorna pos = tam caso o elemento não
    // esteja na lista, então é só verificar se pos<tam, caso seja o elemento
    // de A está em B
    if (pos < listaB->tam) {
      listaC->aluno[listaC->tam] = listaA->aluno[i];
      listaC->tam++;
    }
  }
}


void gerarAluno(TListAlunos *setTlistaAlunos, int tam) {
  // Registrar a matricula gerada na lista
  // Registrar a matricula gerada na lista
  printf("Gerando matricula");
  
  for (int i = 0; i < tam; i++) {
    int numMatricula = 2000 + rand() % 23;
    numMatricula *= 10;
    numMatricula += (1 + rand() % 2);
    numMatricula *= 10000;
    numMatricula += (rand() % 10000);

    setTlistaAlunos->aluno[i].numMatricula = numMatricula;

    // Registrando o email criar algoritmo para gera email;
    const char alf[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    sprintf(setTlistaAlunos->aluno[i].nome, "%c%c%c%c%c %c%c%c%c%c%c",
            alf[rand() % 25], alf[rand() % 25], alf[rand() % 25],
            alf[rand() % 25], alf[rand() % 25], alf[rand() % 25],
            alf[rand() % 25], alf[rand() % 25], alf[rand() % 25],
            alf[rand() % 25], alf[rand() % 25]);
    
    // aqui eu posso decidir como precherei o a lista
    sprintf(setTlistaAlunos->aluno[i].email, "%d@uesc.br",
            setTlistaAlunos->aluno[i].numMatricula);
    
    printf(".");
  }

  setTlistaAlunos->tam = tam;

  if (setTlistaAlunos->eOrd) {
    HeapSort(setTlistaAlunos, setTlistaAlunos->aluno, setTlistaAlunos->tam);
  }
}


void ExibirAluno(TListAlunos *getTlistaAlunoTaluno) {

  for (int i = 0; i < getTlistaAlunoTaluno->tam; i++) {
    printf("\n----------------%d--------------------\n", i);
    printf("Matricula: %d\n", getTlistaAlunoTaluno->aluno[i].numMatricula);
    printf("Nome: %s\n", getTlistaAlunoTaluno->aluno[i].nome);
    printf("Email: %s\n", getTlistaAlunoTaluno->aluno[i].email);
    printf("--------------------------------------\n");
  }
}


void HeapSort(TListAlunos *infolistas, TAluno *lista, int tam) {
  TAluno aluno;
  int i;
  
  for (i = (tam - 1) / 2; i >= 0;
       i--) {                // Voltando da metade do vetor até o começo dele
    criaheap(lista, i, tam); // Cria um heap dos dados
  }
  
  for (i = tam - 1; i >= 1; i--) { // Pega o maior elemento da heap e coloca na
                                   // ultima posição do vetor
    aluno = lista[0];
    lista[0] = lista[i];
    lista[i] = aluno; // Reconstruir heap ordenada
    criaheap(lista, 0, i - 1);
  }
  
  infolistas->eOrd = TRUE;
}


void criaheap(TAluno *lista, int i, int f) { // Vetor, Inicio, Final.
  TAluno aluno;
  
  aluno = lista[i]; // 1º posição
  int j = i * 2 + 1;
  
  while (j <= f) { // Dentro do vetor
    if (j < f) {
      if (lista[j].numMatricula <
          lista[j + 1].numMatricula) { // Verifica quem é maior
        j = j + 1;                     // Se [j+1] maior. então soma + 1 no j
      }                                // Se não for, continua no lista[j]
    }
    
    if (aluno.numMatricula < lista[j].numMatricula) {
      lista[i] = lista[j];
      i = j; // Se j for maior inverto as posições
      j = 2 * i + 1;
    } else { // Repete o processo até que aluno seja maior
      j = f + 1;
    }
  }
  
  lista[i] = aluno; // Finalizo e a ultima pos coloco no aluno.
}
