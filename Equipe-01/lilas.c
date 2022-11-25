#include <stdio.h>
#include <stdlib.h>
#include "lilas.h"

TListAlunos* initListaAluno(int cap, int eOrd)
{
    TListAlunos *lista;
    lista = (TListAlunos*) malloc(sizeof(TListAlunos));
    lista->tam = 0;
    lista->cap = cap;
    lista->eOrd = eOrd;
    if(eOrd)
    {
        lista->aluno = (TAluno*) malloc(cap*sizeof(TAluno));
    }else{
        lista->aluno = (TAluno*) malloc((cap+1)*sizeof(TAluno));
    }
    return lista;
}


int busca_binaria(TListAlunos lista, int numMatricula){
    int inicio = 0;
    int fim = lista.cap - 1, meio;

    while (inicio <= fim) {  // Condi��o de parada

        int meio = (inicio + fim) / 2;  // Calcula o meio do sub-vetor

        if (lista.aluno[meio].numMatricula == numMatricula) {  // Item encontrado
            return meio;
        }

        if (lista.aluno[meio].numMatricula < numMatricula) {  // Item est� no sub-vetor � direita
            inicio = meio + 1;
        } else {  // vector[i] > item. Item est� no sub-vetor � esquerda
            fim = meio;
        }
    }

    return meio;
}

int buscaAluno(int nm, TListAlunos lista)
{
    if(lista.eOrd==0){
            int i = 0;
        while(lista.aluno[i].numMatricula !=  nm)
            i++;
        if(i==lista.tam)
            return i;
        else
            return 0;
    } //FIM DA BUSCA N�O ORDENADA
    else{
        return busca_binaria(lista, nm);
    }
}

int incAluno(TAluno aluno, TListAlunos *lista)
{
    int i,pos;
    if(lista->tam >= lista->cap)
        return 0;
    pos = buscaAluno(aluno.numMatricula, lista);

    if(lista.aluno[pos].numMatricula != aluno.numMatricula || pos != lista.tam){
        lista.tam++;
        for(i=lista.tam-1; i > pos; i--){
            lista.aluno[i]= lista.aluno[i-1];
        }
        lista.aluno[pos] = aluno;
        return 1;
        }
    else
        return 0;
}

void marge(TListAlunos *lista,int inicio,int meio,int fim){
    TListaAlunos *aux = initListaAluno(fim,1);
    int i=0,j=0,inicioL=inicio,inicioR=meio+1;

    wlhile(inicioL<=meio&&inicioR<=fim)//enquanto nenhuma lista chegou ao fim
        if(lista.aluno[inicioL].numMatricula< lista.aluno[inicioR].numMatricula)//verifica os primeiros elementos das listas (esquerda e direita) e poe o menor deles em aux
            aux.aluno[i++]= lista.aluno[inicioL++];
        else
            aux.aluno[i++]= lista.aluno[inicioR++];
    //termina de copiar elementos que faltaram
    while(inicioL<=meio)
        aux.aluno[i++]=lista.aluno[inicioL++]
    while(inicioR<=fim)
        aux.aluno[i++]=lista.aluno[inicioR++]
    
    //copia a lista aux ja organizada na lista original
    for(i=inicio,j=0; i<=fim; i++,j++)
        lista.aluno[i]= aux.aluno[j];
}

void margesort(TListAlunos *lista, int inicio, int fim){
    if(fim>inicio){
      int meio= (fim+inicio)/2;
      //dividir e conquistar
      margesort(&lista,inicio,meio); //primeira metade
      margesort(&lista,meio+1,fim); //segunda metade
      marge(&lista,inicio,meio,fim);//conquista
    }
}

int ordenaLista(TListAlunos *lista)
{
    if(!lista->eOrd){
       margesort(TListAlunos *lista, 1, tam);
       eOrd= 1;
       return 1;
    }
    else return 0;
}

TListAlunos* interListas(TListAlunos *listaA, TListAlunos *listaB){
    if(listaA->tam < listaB->tam){
        TListAlunos listaC = initListaAluno(listaA->tam, listaA->eOrd);

        for(i=0; i < listaA->tam; i++){
            posicao=buscaAluno(listaA.aluno[i].numMatricula, listaB)
            if(listaB.aluno[posicao].numMatricula == listaA.aluno[i].numMatricula || posicao == listaB->tam){
                incAluno(listaA.aluno[i], &listaC);
                listaC[0].tam ++;
            }
        }
    }
    else{
        TListAlunos listaC = initListaAluno(listaB->tam, listaB->eOrd);

        for(i=0; i < listaB->tam; i++){
            posicao=buscaAluno(listaB.aluno[i].numMatricula, listaA)
            if(listaA.aluno[posicao].numMatricula == listaB.aluno[i].numMatricula || posicao == listaA->tam){
                incAluno(listaB.aluno[i], &listaC);
                listaC[0].tam ++;
            }
        }
    }

    return listaC;
}

int remAluno(int nm, TListAlunos *lista)
{

}

TListAlunos* diferListas(TListAlunos *listaA, TListAlunos *listaB)
{
    TListAlunos *dif;
    dif = initListaAluno(listaA->cap + listaB->cap, listaA->eOrd);
    for(int i = 0; i < listaA->tam; i++)
    {
        for(int j = 0; j < listaB->tam; j++)
        {
            if(listaA->aluno[i].numMatricula != listaB->aluno[j].numMatricula)
            {
                incAluno(listaA->aluno[i], dif[0]);
            }
        }
    }
    return dif;
}
