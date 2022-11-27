#include "prototipos.h"

int main(){
    NO *lista,*busca;
    TAluno aluno,*retorno;
    lista = criarLista();
    int num;

    while(1==1){
        printf("\n************ MENU **************\n");
        printf("  [0] - SAIR\n");
        printf("  [1] - Inserir no Inicio\n");
        printf("  [2] - Exibir\n");
        printf("  [3] - Buscar Elemento\n");
        printf("  [4] - Quantidade de Elemento\n");
        printf("  [5] - Remover Elemento\n");
        printf("*********************************\n");
        int op_menu;
        printf("Escolha uma opção: ");
        scanf("%d", &op_menu);

        switch (op_menu){
            case 0:
                exit(1);
            case 1:
                printf("\nMatricula:");
                scanf("%d",&aluno.matricula);
                getchar();
                printf("\nNome:");
                scanf("%[^\n]s",aluno.nome);
                getchar();
                printf("\nEmail:");
                scanf("%[^\n]s",aluno.email);
                
                
                lista = inserirInicio(lista, aluno);
                break;
          
          
            case 2://MOSTRAR LISTA DE ALUNOS
                mostrarLista(lista);
                break;
           
           
            case 3: //BUSCAR ALUNOS
                printf("Número: ");
                scanf("%d", &num);
                if(retorno = buscar(lista, num)){
                printf("\nAluno encontrado:");
                printf("\n\nMatricula: %d", retorno->matricula);
                printf("\nNome: %s", retorno->nome);
                printf("\nEmail: %s", retorno->email);
               }else
                  printf("ALUNO NAO ESTA NA LISTA!!!");
                
                break;
            case 4://QUANTIDADE DE ALUNOS
                printf("Número de Elementos: %d", qtdElementos(lista));
                break;
            case 5://REMOVER ALUNO
                printf("Número a remover: ");
                scanf("%d", &aluno.matricula);
                lista = removerElemento(lista,&aluno);
              
                printf("\nAluno removido:");
                printf("\n\nMatricula: %d", aluno.matricula);
                printf("\nNome: %s", aluno.nome);
                printf("\nEmail: %s", aluno.email);
                break;
          
            default:
                printf(" -- Opção Inválida --\n");
                break;
        } 
    }

    return 0;
}