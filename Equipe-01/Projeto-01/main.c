#include <stdio.h>
#include <stdlib.h>
#include "lilas.h"
#include <string.h>



int escolheLista(){
    int opcao;
    do{
        printf("Em qual lista:(1 p/ lista A, 0 p/ lista B)");
        scanf("%d",&opcao);
        limpa_linha();
    }while(opcao<0 || opcao>1);
    return opcao;
}
TAluno recebeNumMatri(TAluno aux){
    printf("insira o numero de matricula:\n");
    scanf("%d",&aux.numMatricula);
    printf("%d\n",aux.numMatricula);
    limpa_linha();
    return aux;
}
void mostraAluno(TAluno aluno){
    if(aluno.numMatricula!=0)
        printf("numero de matricula:%d nome:%s email:%s\n",aluno.numMatricula,aluno.nome,aluno.email);
    else printf("aluno nao existe!\n");
}

TAluno recebeAluno(TAluno aux){
    printf("insira o numero de matricula:\n");
    scanf("%d",&aux.numMatricula);
    limpa_linha();
    printf("insira o nome:\n");
    scanf("%100[^\n]",aux.nome);
    limpa_linha();
    printf("insira o email:\n");
    scanf("%100[^\n]",aux.email);
    limpa_linha();
    return aux;
}


int main()
{
    int opcao=0,posicao,capacidade=10, i;
    TListAlunos *listaA,*listaB,*listaDifer,*listaInter;
    TAluno aux;
    
    /* teste- geraçao de alunos aleatorios
    listaA = initListaAluno(capacidade, 1);
    for(i=0; i<5; i++){//gerando numeros de matricula aleatrorio
    aux= geraAluno(aux);
    incAluno(aux, listaA);//incluindo aluno aleatorio na listaA
    posicao=buscaAluno(aux.numMatricula, *listaA);
    mostraAluno(listaA->aluno[posicao]);//mostrando o aluno na lista
    }

    for(i=0;i<listaA->tam; i++){//mostra numero de matricula e indice de todos os alunos da lista
      printf("[%d]: %d\n", i, listaA->aluno[i].numMatricula);
    }

    printf("digite o numero de matricula que quer buscar: ");
    scanf("%d", &aux.numMatricula);
    posicao=busca_binaria(*listaA, aux.numMatricula);
    printf("aluno na pos:%d",posicao);
    mostraAluno(listaA->aluno[posicao]);*/
  
      
  /* 
    //inicializando listaA com cap=10 e eOrd=1
    listaA = initListaAluno(capacidade, 1);
    //printf("listaA\ncapacidade=%d eord=%d tam =%d\n\n",listaA->cap,listaA->eOrd,listaA->tam);

    //inicializando listaB com cap=10 e eOrd=1
    listaB = initListaAluno(capacidade, 1);
    printf("listaB\ncapacidade=%d eord=%d tam =%d\n\n",listaB->cap,listaB->eOrd,listaB->tam);

    //recebendo 3 alunos em lista A
    listaA->aluno[0].numMatricula=1000;listaA->aluno[1].numMatricula=2000;listaA->aluno[2].numMatricula=3000;
    strcpy(listaA->aluno[0].nome,"gu"); strcpy(listaA->aluno[1].nome,"su"); strcpy(listaA->aluno[2].nome,"dan");
    strcpy(listaA->aluno[0].email,"gu@"); strcpy(listaA->aluno[1].email,"su@"); strcpy(listaA->aluno[2].email,"dan@");
    listaA->tam=3;

    //recebendo 3 alunos em lista B
    listaB->aluno[0].numMatricula=1000;listaB->aluno[1].numMatricula=2000;listaB->aluno[2].numMatricula=3000;
    strcpy(listaB->aluno[0].nome,"gu"); strcpy(listaB->aluno[1].nome,"su"); strcpy(listaB->aluno[2].nome,"dan");
    strcpy(listaB->aluno[0].email,"gu@"); strcpy(listaB->aluno[1].email,"su@"); strcpy(listaB->aluno[2].email,"dan@");
    listaB->tam=3;*/

    /* teste- buscabinaria
    posicao=busca_binaria(*listaA,1400);
    printf("aluno na pos:%d\n",posicao);
    mostraAluno(listaA->aluno[posicao]);*/


  /*teste- ordenaçao
    if(ordenaLista(listaA))
        for(i=0;i<listaA->tam;i++)
            mostraAluno(listaA->aluno[i]);
    else printf("nao ordenou");*/


    /*teste- add aluno e rem aluno
    aux=recebeAluno(aux);//recebendo um novo aluno na variavel TAluno auxiliar
    incAluno(aux,listaA);
    posicao=buscaAluno(aux.numMatricula,*listaA);
    mostraAluno(listaA->aluno[posicao]);//conferindo se o aluno esta na lista
    remAluno(aux.numMatricula,listaA);//tentando excluir o aluno recebido
    posicao=buscaAluno(aux.numMatricula,*listaA);
    if(listaA->aluno[posicao].numMatricula!=aux.numMatricula)//conferindo se o aluno realmente nao esta na lista
        printf("excluido com suceso!");
    mostraAluno(listaA->aluno[posicao]);*/
//_______________________________________//
  /*  int opcao,posicao,capacidade;
    TListAlunos *listaA,*listaB,*listaDifer,*listaInter;
    TAluno aux;
    //recebendo dados da lista A
    printf("digite a capacidade de alunos da lista A:");
    scanf("%d",&capacidade);
    do{
        printf("digite 1 para uma lista ordenada e 0 para uma lista nao ordenada:");
        scanf("%d",&opcao);
    }while(opcao<0 || opcao>1);
    listaA = initListaAluno(capacidade, opcao);
     printf("capacidade=%d eord=%d\n",listaA->cap,listaA->eOrd);

    //recebendo dados da lista B
    printf("digite a capacidade de alunos da lista B:");
    scanf("%d",&capacidade);
    do{
        printf("digite 1 para uma lista ordenada e 0 para uma lista nao ordenada:");
        scanf("%d",&opcao);
    }while(opcao<0 || opcao>1);
    listaB = initListaAluno(capacidade, opcao);
    printf("capacidade=%d eord=%d\n",listaB->cap,listaB->eOrd);
    printf("matri ref=%d\n",listaA->aluno[0].numMatricula);
    printf("tam ref=%d\n",listaA->tam);


    //menu
    do{

        printf("_____MENU_____\n");
        printf("0- Encerrar programa.\n");
        printf("1- Incluir novo aluno.\n");
        printf("2- Mostrar um aluno.\n");
        printf("3- Excluir um aluno.\n");
        printf("4- Criar intercess�o das listas.\n");
        printf("5- Criar diferen�a das listas.\n");
        printf("6- Ordenar lista.\n\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
            case 0://encerrando
                liberaMem(listaA);
                liberaMem(listaB);
                printf("Encerrando...");
                return 0;

            case 1://incluindo

                opcao=escolheLista(); //verificando em qual lista vai ser feita a opera��o
                 if(opcao==1){
                     //recebendo informa��es do aluno
                     aux=recebeAluno(aux);

                     /*if((incAluno(aux,listaA))==0)//verificando se a inclus�o foi bem sucedida
                        printf("Erro ao incluir aluno.\n");
                     else printf("aluno inclu�do com sucesso!");
                 }
                 else{
                     //recebendo informa��es do aluno
                     aux=recebeAluno(aux);
                     if(incAluno(aux,listaB)==0)//verificando se a inclus�o foi bem sucedida
                        printf("Erro ao incluir aluno.\n");
                     else printf("aluno inclu�do com sucesso!");

                 }
                 break;

            case 2://mostrar aluno
                 opcao=escolheLista();//verificando em qual lista vai ser feita a opera��o
                 if(opcao==1){
                     recebeNumMatri(aux);//recebendo informa�ao do aluno a ser buscado
                     posicao= buscaAluno(aux.numMatricula,*listaA);
                     if(aux.numMatricula != listaA->aluno[posicao].numMatricula)//verificando se o aluno est� na posi��o retornada pela fun��o buscaAluno
                        printf("Aluno n�o encontrado!");
                     else
                        mostraAluno(listaA->aluno[posicao]);
                        //printf("Nome: %s\nNumero de matricula: %d\nEmail: %s\n",listaA->aluno[posicao].nome,listaA->aluno[posicao].numMatricula,listaA->aluno[posicao].email);
                 }
                 else {
                     recebeNumMatri(aux);//recebendo informa�ao do aluno a ser buscado
                     posicao= buscaAluno(aux.numMatricula,*listaB);
                     if(aux.numMatricula != listaB->aluno[posicao].numMatricula)//verificando se o aluno est� na posi��o retornada pela fun��o buscaAluno
                        printf("Aluno n�o encontrado!");
                     else
                        mostraAluno(listaB->aluno[posicao]);
                        //printf("Nome: %s\nNumero de matricula: %d\nEmail: %s\n",listaB->aluno[posicao].nome,listaB->aluno[posicao].numMatricula,listaB->aluno[posicao].email);
                 }
                 break;

            case 3://excluir aluno
                 opcao=escolheLista();//verificando em qual lista vai ser feita a operaçâo
                 if(opcao==1){
                     recebeNumMatri(aux);//recebendo informa�ao do aluno a ser buscado
                     if(remAluno(aux.numMatricula,listaA)== 1 )//verificando se o aluno foi exclu�do
                         printf("Excluindo com sucesso\n");
                     else
                         printf("falha ao excluir aluno!\n");
                 }
                 else {
                     recebeNumMatri(aux);//recebendo informa�ao do aluno a ser buscado
                     if(remAluno(aux.numMatricula,listaB)== 1 )//verificando se o aluno est� na posi��o retornada pela fun��o buscaAluno
                         printf("Excluindo com sucesso\n");
                     else
                         printf("Aluno n�o encontrado!\n");
                 }
                 break;

            case 4://intercessao das listas
                 listaInter= interListas(&listaA, &listaB);
                 break;

            case 5:diferença entre listas
                 do{
                    printf("digite 1 p/ lista A diferen�a lista B ou 0 p/ lista B diferen�a lista A:\n");
                    scanf("%d",&opcao);
                 }while(opcao<0 && opcao>1);
                 if(opcao==1)
                    listaDifer= diferListas(listaA,listaB);
                 else
                    listaDifer= diferListas(listaA,listaB);
                 break;

            case 6://ordenação
                 opcao= escolheLista(); //verificando em qual lista vai ser feita a opera��o
                 if(opcao==1)
                    ordenaLista(listaA);
                 else
                    ordenaLista(listaB);
                 break;

            default: printf("Erro! opçâo invalida.\ndigitenovamente...\n\n");
        }
    }while(opcao!=0);

    printf("\n");*/
    return 0;
}
