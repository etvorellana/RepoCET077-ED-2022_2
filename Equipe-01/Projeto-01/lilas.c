 #include <stdio.h>
#include <stdlib.h>
#include "lilas.h"

TListAlunos* initListaAluno(int cap, int eOrd)
{
    int i;
    TListAlunos *lista;
    lista = (TListAlunos*) malloc(sizeof(TListAlunos));
    lista->tam = 0;
    lista->cap = cap;
    lista->eOrd = eOrd;
    if(eOrd)
    {
        lista->aluno = (TAluno*) malloc(cap*sizeof(TAluno));
        for (i=0;i<cap;i++)
            lista->aluno[i].numMatricula=0;
    }else{
        lista->aluno = (TAluno*) malloc((cap+1)*sizeof(TAluno));
        for (i=0;i<cap+1;i++)
            lista->aluno[i].numMatricula=0;
    }
    return lista;
}

int busca_binaria(TListAlunos lista, int numMatricula){
    int inicio = 0;
    int fim = lista.tam-1, meio;
    while (inicio != fim) {  // Condicao de parada

        meio = (inicio + fim) / 2;  // Calcula o meio do sub-vetor
        if (lista.aluno[meio].numMatricula == numMatricula) {  // Item encontrado
            return meio;
        }

        else if (lista.aluno[meio].numMatricula < numMatricula) {  // Item est� no sub-vetor � direita
            inicio = meio + 1;
        } else if (lista.aluno[meio].numMatricula > numMatricula) {  // vector[i] > item. Item est� no sub-vetor � esquerda
            fim = meio - 1;
        }
    }
    return meio;
}

int buscaAluno(int nm, TListAlunos lista)
{

    if(lista.eOrd==0){ //INÍCIO DA BUSCA NÃO ORDENADA
        int i = 0;
        lista.aluno[lista.tam].numMatricula= nm;//adicionando o número de matricula que eu vou procurar depois da ultima posiçao da lista
        while(lista.aluno[i].numMatricula !=  nm)//percorrendo a lista até achar o número de matricula
            i++;
        lista.aluno[lista.tam].numMatricula= 0;//zerando o endereço o qual eu tinha colocado o número de matricula
        if(i!= lista.tam);
        else;
        return i;
    } //FIM DA BUSCA NÃO ORDENADA
    else{//INÍCIO DA BUSCA ORDENADA
        return busca_binaria(lista, nm);
    }//FIM DA BUSCA ORDENADA
}

TAluno* alocaListaAlunos(int n)
{
    TAluno *p = (TAluno*) malloc(n*sizeof(TAluno));
    return p;
}

TAluno geraAluno(TAluno aluno)
{
    int numMatricula = 2000 + rand()%23;
    numMatricula *= 10;
    numMatricula += (1+rand()%2);
    numMatricula *= 10000;
    numMatricula += (rand()%10000);
    aluno.numMatricula = numMatricula;
    //gerar um nome
    strcpy(aluno.nome,"Teste Nome Aluno");
    //aluno->nome = "Teste Nome Aluno";
    //gerar um e-mail
    strcpy(aluno.email, "TNAluno@uesc.br"); 
    //aluno->email = "TNAluno@uesc.br";
  return aluno;
}

int incAluno(TAluno aluno, TListAlunos *lista)
{
    int i,pos;
    if(lista->tam >= lista->cap)
        return 0;
    pos = buscaAluno(aluno.numMatricula, *lista);

    if(lista->aluno[pos].numMatricula != aluno.numMatricula){
      printf("numero de matricula do aluno[%d]= %d\n",pos,aluno.numMatricula);  
      lista->tam++;
        for(i=lista->tam-1; i > pos; i--){
            lista->aluno[i]= lista->aluno[i-1];
        }
        lista->aluno[pos] = aluno;
        printf(" aluno incluido/n");
        return 1;
        }
    else
        return 0;
}

int remAluno(int nm, TListAlunos *lista)
{
    int i,pos;
    if(!lista->tam)//verificando se a lista está vazia
        return 0;
    pos = buscaAluno(nm, *lista);

    if(lista->aluno[pos].numMatricula == nm || pos != lista->tam){// se aluno que eu quero remover esta na lista
        if(lista->eOrd){//se a lista é ordenada
            lista->tam--;
            for(i=pos; i <lista->tam; i++){//copiando a lista a partir do aluno que eu quero remover uma posição a esquerda.
                lista->aluno[i]= lista->aluno[i+1];
            }
        }
        else{//se a lista não for ordenada
            lista->tam--;
            lista->aluno[pos]= lista->aluno[lista->tam];//copiando o ultimo aluno da lista na posição do aluno que eu vou remover
        }

        lista->aluno[lista->tam].numMatricula = 0;//zerando o conteudo de matricula do aluno na posição tam
        return 1;
    }
    else // se o aluno nao tiver na lista
        return 0;
}

void marge(TListAlunos *lista,int inicio,int meio,int fim){
    TListAlunos *aux = initListaAluno(fim,1);
    int i=0,j=0,inicioL=inicio-1,inicioR=meio;
    
    while(inicioL<meio && inicioR<fim){//enquanto nenhuma lista chegou ao fim
        if(lista->aluno[inicioL].numMatricula < lista->aluno[inicioR].numMatricula){//verifica os primeiros elementos das listas (esquerda e direita) e poe o menor deles em aux
            aux->aluno[i++]= lista->aluno[inicioL++];
        }
        else{
            aux->aluno[i++]= lista->aluno[inicioR++];
        }
    }
    //termina de copiar elementos que faltaram
    while(inicioL<meio)
        aux->aluno[i++]= lista->aluno[inicioL++];

    while(inicioR<fim)
        aux->aluno[i++]= lista->aluno[inicioR++];

    //copia a lista aux ja organizada na lista original
    for(i=inicio-1,j=0; i<fim; i++,j++)
        lista->aluno[i]= aux->aluno[j];

}

void margesort(TListAlunos *lista,int inicio,int fim){
    if(fim>inicio){
        int meio= (fim+inicio)/2;
        //dividir e conquistar
        margesort(lista,inicio,meio); //primeira metade
        margesort(lista,meio+1,fim); //segunda metade
        marge(lista,inicio,meio,fim);//conquista
    }
}

int ordenaLista(TListAlunos *lista)
{
    if(!lista->eOrd){
        printf("vou ordenar\n");
        margesort(lista, 1, lista->tam);
        lista->eOrd=1;
        return 1;
    }
    else return 0;
}

TListAlunos* interListas(TListAlunos *listaA, TListAlunos *listaB){
    int i,posicao;
    TListAlunos *listaInter;

    //VERIFICANDO QUAL LISTA É MENOR
    if(listaA->tam < listaB->tam){//se listaA for menor
        listaInter = initListaAluno(listaA->tam, listaA->eOrd); //inicializa listaInter com capacidade do tamanho da listaA e eOrde igual o de listaA
        for(i=0; i < listaA->tam; i++){//percorre listaA verificando se tem alguem de listaA em listaB
            posicao= buscaAluno(listaA->aluno[i].numMatricula, *listaB);
            if(listaB->aluno[posicao].numMatricula == listaA->aluno[i].numMatricula || posicao != listaB->tam){
                incAluno(listaA->aluno[i], listaInter);//se tiver alguem em listaA e listaB ao mesmo tempo, inclue esse aluno em listaInter.
            }
        }
    }
    else{//se listab for menor
        listaInter = initListaAluno(listaB->tam, listaB->eOrd);//inicializa listaInter com capacidade do tamanho da listaB e eOrde igual o de listaB
        for(i=0; i < listaB->tam; i++){//percorre listaB verificando se tem alguem de listaB em listaA
            posicao=buscaAluno(listaB->aluno[i].numMatricula, *listaA);
            if(listaA->aluno[posicao].numMatricula == listaB->aluno[i].numMatricula || posicao == listaA->tam){
                incAluno(listaB->aluno[i], listaInter);//se tiver alguem em listaB e listaA ao mesmo tempo, inclue esse aluno em listaInter.
            }
        }
    }

    return listaInter;
}

TListAlunos* diferListas(TListAlunos *listaA, TListAlunos *listaB)
{
    int i,pos;
    TListAlunos *listaDif = initListaAluno(listaA->tam, listaA->eOrd);

    for(int i = 0; i < listaA->tam; i++)
    {
        pos= buscaAluno(listaA->aluno[i].numMatricula, *listaB);
        if(listaA->aluno[i].numMatricula != listaB->aluno[pos].numMatricula || pos==listaB->tam)
        {
            incAluno(listaA->aluno[i], listaDif);
        }
    }

    return listaDif;
}

void liberaMem(TListAlunos *lista)
{
  free(lista->aluno);
  free(lista);
}

void limpa_linha() {
    scanf("%*[^\n]"); /* Lê todos os caracteres "indesejados" e descarta os mesmos, exceto o '\n' */
    scanf("%*c"); /* Lê o caractere '\n' e descarta o mesmo, limpando assim o stdin */
}
