// Carregando arquivos de cabeçalho
#include <stdio.h>

/*
    Exemplo - 01: 
    Estrutura de um programa em C: a função main();
    O programa utiliza a função printf(), definida no
    arquivo de cabeçalho stdio.h, para imprimir uma
    mensagem na saída padrão do sistema.

    Como compilar?
    Utilize sua IDE preferida e, se ela não tiver uma 
    ferramenta disponível para compilar e executar, 
    compile na linha de comando:

    gcc -o exemplo_01 main.c 
*/
int main(void) { // Ponto de entrada do Programa 
  printf("Hello World!\n"); // imprimindo na saída padrão
  return 0; // "Aconteceu alguma falha na execução? 0 - significa falso"
}

