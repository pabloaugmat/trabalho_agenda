#include <stdio.h>
#include <stdlib.h>


//TODO (1) Cadastrar uma pessoa no fim da agenda
//TODO (2) Excluir uma pessoa a partir da identidade
//TODO (3) Listar o nome de todas as pessoas que fazem aniversário em uma determinada data
//TODO (4) Alterar os dados de uma pessoa a partir da identidade.
//identidade, nome, data de nascimento (dia, mês e ano), email e telefone

void limparTela(){
    #ifdef __linux__
        system("clear");
    #elif __WIN32
        system("cls");
    #else

    #endif
}

typedef struct data{
    int dia, mes, ano;
} tdata;

typedef struct pessoa{
    int id, telefone;
    char nome[100], email[100];
    tdata dataNascimento;
} tpessoa;

void cadastrar(tpessoa *pessoa){

    limparTela();
    printf("Identidade:");
    scanf("%d", &pessoa->id);
    printf("Nome:");
    fflush(stdin);
    scanf("%[^\n]%*c", pessoa->nome);
    printf("Dia de nascimento:");
    scanf("%d", &pessoa->dataNascimento.dia);
    printf("Mes de nascimento:");
    scanf("%d", &pessoa->dataNascimento.mes);
    printf("Ano de nascimento:");
    scanf("%d", &pessoa->dataNascimento.ano);
    printf("e-mail:");
    fflush(stdin);
    scanf("%s", pessoa->email);
    printf("Telefone:");
    scanf("%d", &pessoa->telefone);
}

int excluir(tpessoa *pessoa, int id, FILE *agenda){
    agenda = fopen("agenda.txt", "r+");

    fread(pessoa, sizeof (pessoa), 1, agenda);
    if(pessoa->id == id){
        pessoa = NULL;
        fwrite(pessoa, sizeof(pessoa), 1, agenda);
        fclose(agenda);
        return 0;
    }
    while(!(feof(agenda))){
        if(pessoa->id == id){
            pessoa = NULL;
            fwrite(pessoa, sizeof(pessoa), 1, agenda);
            fclose(agenda);
            return 0;
        }
    }
    fclose(agenda);
    return 1;
}

int main() {

    FILE *agenda;
    int exit = 0;
    tpessoa pessoa;

    do{
        limparTela();
        printf("MENU:\n");
        printf("(1) Cadastrar pessoa.\n");
        printf("(2) Excluir pessoa.\n");
        printf("(3) Listar pessoas que fazem aniversario na data selecionada.\n");
        printf("(4) Alterar dados de uma pessoa.\n");
        printf("(0) Sair.\n");
        printf("Digite o numero da opcao desejada:");
        scanf("%d", &exit);
    }while(exit != 0);

    return 0;
}
