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