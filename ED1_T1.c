//Arthur Sena
//Matricula 180030345

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FUNCIONARIO{
    char *nome;
    char *email;
    int idade;
}funcionario;

void cadastro(funcionario *funcionarios, int n,int n2){

    int i;

    for(i = n2; i < (n2+n); i++){
        printf("\nCadastrando funcionario %d", i+1);

        printf("\nNome: ");
        funcionarios[i].nome = (char*)malloc(sizeof(char) * 60);
        scanf(" %[^\n]",funcionarios[i].nome);

        printf("Email: ");
        funcionarios[i].email = (char*)malloc(sizeof(char) * 60);
        scanf(" %[^\n]",funcionarios[i].email);

        printf("Idade: ");
        scanf("%d", &funcionarios[i].idade);
    }

    printf("Cadastro Realizado!\n");

}

void listagem(funcionario *funcionarios, int n2){

	int i = 0;
    printf("Ok, listando funcionarios cadastrados:\n\n");

        for(i = 0; i < n2; i++){
            printf("Funcionario %d: \n   ", (i+1));
            printf("%s - ", funcionarios[i].nome);
            printf("%s - ", funcionarios[i].email);
            printf("%d\n", funcionarios[i].idade);
            printf("---------------------------\n");
    }
}

void edicao(funcionario *funcionarios, int n2){

    int op, editfunc, procura, editind;
    char *edit;

    edit = (char*)malloc(80 * sizeof(char));

    printf("Deseja buscar pelo seu funcionario por nome, email ou indice?");
    printf("\n(1)Nome\n(2)Email\n(3)Indice\nOpcao: ");
    scanf("%d", &op);
    getchar();

    switch(op){

    case 1:

        printf("\nQual o nome do funcionario a ser editado?\n");
        scanf("%[^\n]", edit);

        for(int i = 0; i < n2; i++){
            if(strcasecmp(funcionarios[i].nome, edit)== 0){

                procura = 0;

                editfunc = i;

                break;
            }
        }

        if(procura == 0){
            printf("Novo Nome: ");
            scanf(" %[^\n]",funcionarios[editfunc].nome);
            printf("Novo Email: ");
            scanf(" %[^\n]",funcionarios[editfunc].email);
            printf("Nova Idade: ");
            scanf("%d",&funcionarios[editfunc].idade);
            printf("\nFuncionario Editado Com Sucesso!\n");
        }else{
            printf("\nFuncionário Não Encontrado!\n");
        }

    break;

    case 2:

        printf("\nQual o email do funcionario a ser editado?\n");
        scanf("%[^\n]", edit);

        for(int i = 0; i < n2; i++){
            if(strcasecmp(funcionarios[i].email, edit) == 0){

                procura = 0;

                editfunc = i;

                break;
            }
        }

        if(procura == 0){
            printf("Novo Nome: ");
            scanf(" %[^\n]",funcionarios[editfunc].nome);
            printf("Novo Email: ");
            scanf(" %[^\n]",funcionarios[editfunc].email);
            printf("Nova Idade: ");
            scanf("%d",&funcionarios[editfunc].idade);
            printf("\nFuncionario Editado Com Sucesso!\n");
        }else{
            printf("\nFuncionário Não Encontrado!\n");
        }

    break;

    case 3:

        printf("\nQual o indice do funcionario a ser editado?\n");
        scanf("%d", &editind);

        printf("Novo Nome: ");
        scanf(" %[^\n]",funcionarios[editind].nome);
        printf("Novo Email: ");
        scanf(" %[^\n]",funcionarios[editind].email);
        printf("Nova Idade: ");
        scanf("%d",&funcionarios[editind].idade);
        printf("\nFuncionario Editado Com Sucesso!\n");

    break;

    }

}

void exclui(funcionario *funcionarios, int n2){

    int opcao, indexclui, buscaind;
    char *exclui;

    printf("\nBuscar funcionario por indice ou por nome?\n");
    printf("\n(1)Indice\n(2)Nome\nOpcao: ");
    scanf("%d", &opcao);
    getchar();

    exclui = (char*)malloc(50 * sizeof(char));

    switch(opcao){

    case 1:

        printf("\nIndice: ");
        scanf("%d", &indexclui);

        for(int i = indexclui; i < n2; i++){
            funcionarios[i] = funcionarios[i + 1];
        }

        funcionarios = (funcionario*)realloc(funcionarios, sizeof(funcionario)*(n2));

        printf("\nFuncionario Excluido!\n");

    break;

    case 2:

        printf("\nNome: ");
        scanf("%[^\n]", exclui);

        for(int i = 0; i < n2; i++){
            if(strcasecmp(funcionarios[i].nome, exclui) == 0){
                buscaind = i;
            }
        }

        for(int i = buscaind; i < (n2-1); i++){
                funcionarios[i] = funcionarios[i + 1];
        }

        funcionarios = (funcionario*)realloc(funcionarios, sizeof(funcionario)*(n2));

        printf("\nFuncionario Excluido!\n");

    break;

    }
}

int main(){

    funcionario *funcionarios;

    int mantem = 1, n2 = 0 , n;

    while(mantem != 0){


       printf("\nMenu - Gerenciamento de Funcionarios\n");
       printf("\n(1)Cadastrar Novo Funcionario\n");
       printf("(2)Listar Funcionarios\n");
       printf("(3)Editar Cadastro de Algum Funcionario\n");
       printf("(4)Excluir Funcionario\n");
       printf("(0)Encerrar Programa\n");
       printf("Opcao: ");
       scanf("%d", &mantem);
       system("clear");
       printf("\n");

       switch(mantem){

         case 1:

          printf("Quantos funcionarios serao inclusos?\n");
          scanf("%d", &n);

          if(n2 == 0){

            funcionarios = (funcionario*)malloc(sizeof(funcionario) * n);
            cadastro(funcionarios, n, n2);

          }else{

            funcionarios = (funcionario*)realloc(funcionarios, sizeof(funcionario)*(n + n2));
            cadastro(funcionarios, n, n2);

          }

          n2 += n;

        break;

        case 2:

        listagem(funcionarios, n2);

        break;

        case 3:

        edicao(funcionarios, n2);

        break;

        case 4:

          if(n2 != 0){
            exclui(funcionarios, n2);
            n2--;
          }else{
            printf("\nSem Funcionarios Cadastrados.\n");
          }

        break;

       }

    }

    free(funcionarios);

    return 0;
}
