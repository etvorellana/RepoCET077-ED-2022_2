# Exemplo construído em sala de aula.

## O que foi já foi feito

* Declaração do tipo TAluno na forma de um registro de aluno;
* Declaração e implementação da função alocaListaAluno que recebe um inteiro n 
e aloca uma array de tipo TAluno com n posições. Esta função retorna o ponteiro
para o array criado;
* Declaração e implementação da função printAluno que imprime o registro de um
aluno, fornecido na forma de um parâmetro de tipo TAluno;
* Declaração da função geraAluno que preenche o registro do aluno, alocado no
endereço de memória fornecido via parâmetro, com um número de matrícula, nome e
email gerados de forma aleatória.
* Declaração e implementação de uma versão inicial da função main() que:
    * Declara e aloca a variável lista como um array de tipo TAluno;
    * Preenche o array com registros gerados de forma aleatória;
    * Escolhe uma posição aleatória do array e imprime o registro de aluno;

## O que precisa ser feito 
* O registro gerado pela função geraAluno deve satisfazer:
    * O número de matrícula no formato aaaasxxxx onde:
        * aaaa é um ano tal que 2000 <= aaaa <= 2022;
        * s é o número de semestre, ou seja 1 ou 2;
        * xxxx representa uma sequência de quatro dígitos;
    * O nome deve ser composto por:
        * Nome e Sobrenome contendo formado apenas por letras;
        * A primeira letra do nome e do sobrenome tem que ser maiúscula;
        * Pode ser uma sequência aleatória de caracteres sempre que
        satisfaça a condição anterior;
        * Todos os caracteres podem ser letras maiúsculas;
    * O email de ser construído com:
        * Um identificador que pode conter letras e/ou números;
        * finalizar com a string "@uesc.br""
* Modificar, na função main(), o preenchimento do array lista para garantir que
não contenha número de matrícula repetidos;
* Procurar se na lista tem um registro com o número de matrícula 201523256. Se existir imprimir a posição no array em que se encontra o registro, assim com as informações nele armazenado. Caso não tenha um registro com este identificador imprimir "Registro não encontrado";
* Se o número anterior não estiver na lista (dificilmente vai), tente repetir o teste com um número de matrícula que esteja na lista (pode usar o de um elemento qualquer da lista);
* Procurar se na lista tem um registro com o nome de matrícula "Fulano Silva". Se existir imprimir a posição no array em que se encontra o registro, assim com as informações nele armazenado. Caso não tenha um registro com este identificador imprimir "Registro não encontrado";
* Se o nome anterior não estiver na lista (dificilmente vai), tente repetir o teste com um número de matrícula que esteja na lista (pode usar o de um elemento qualquer da lista);     