#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista {
    int numero_conta;
    char nome_cliente[40];
    float saldo;
    struct lista* prox;
} Lista;

Lista* inserir_cadastros(Lista* primeiro);
void listar_cadastros(Lista* primeiro);
Lista* excluir_cadastros(Lista* primeiro);
void alterar_cadastros(Lista* primeiro);
void limpa_linha(void);

int main() {


    Lista *primeiro= NULL;
    char opcao;

    while(opcao!='s')
    {

//Menu
        printf("\t\t\tMENU DOUGLAS <3        \n");
        printf("      ####  <A>  Novo Cadastro      ####      \n");
        printf("      ####  <B>  Listar Registros   ####      \n");
        printf("      ####  <C>  Excluir Cadastro   ####      \n");
        printf("      ####  <D>  Alterar Cadastro   ####      \n");
        printf("      ####  <S>  Sair                         \n");
        printf("\n\n\n\n");
//Lendo menu
        opcao = getch();

//Menu de opções
        switch(opcao)
        {
        case 'A':
        case 'a':
//Inserindo a Conta.
            fflush(stdin);
            system("cls");
            printf("\t\t\t          NOVO CADASTRO     \n");
            primeiro= inserir_cadastros(primeiro);
            getch();
            system("cls");
            break;
        case 'B':
        case 'b':
//Listando os Cadastros.
            system ("cls");
            printf("\t\t\t     LISTA DE REGISTROS CADASTRADOS     \n");
            listar_cadastros(primeiro);
            getch();
            system("cls");
            break;
        case 'C':
        case 'c':

            system ("cls");
            printf("\t\t\t       EXCLUIR CADASTROS    \n");
            primeiro= excluir_cadastros(primeiro);
            getch();
            system("cls");
            break;
        case 'D':
        case 'd':

            system ("cls");
            printf("\t\t\t       ALTERAR CADASTRADOS   \n");
            printf("\t\t\t      |\n");

            alterar_cadastros(primeiro);
            getch();
            system("cls");
            break;
        case 'S':
        case 's':

            opcao='s';
            break;
        default:

            system("cls");
            break;
        }
    }
}

void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}

Lista* inserir_cadastros(Lista* primeiro) {

    Lista cliente;
    Lista *atual = primeiro;
    char identificador = 'F';

    printf("  Numero da Conta: ");
    scanf("%d", &cliente.numero_conta);
    limpa_linha();
    printf ("\n");
    printf("  Nome: ");
    fgets(cliente.nome_cliente, 40, stdin);
    printf ("\n");
    printf("  Saldo: ");
    scanf("%f", &cliente.saldo);
    limpa_linha();

    printf ("\n");

    for (atual = primeiro; atual != NULL; atual = atual->prox) {
        if (atual->numero_conta == cliente.numero_conta) {
            identificador = 'V';
            break;
        }
    }

    if ( identificador != 'V' && (strlen(cliente.nome_cliente) != 1)) {


        Lista* NovoCliente = malloc (sizeof(Lista));
        strcpy(NovoCliente->nome_cliente, cliente.nome_cliente);
        NovoCliente->saldo = cliente.saldo;
        NovoCliente->numero_conta = cliente.numero_conta;
        NovoCliente->prox = primeiro;
        printf("  Cadastro feito com sucesso <3 <3.");
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return NovoCliente;
    } else {
        printf("  Cadastro invalido!");
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
    }
}


void listar_cadastros(Lista* primeiro) {

    Lista* atual;


    for (atual = primeiro ; atual != NULL; atual = atual->prox) {
        printf("\n  Conta: ");
        printf("%d", atual->numero_conta);
        printf("\n  Nome: ");
        printf("%s", atual->nome_cliente);
        printf("  Saldo: ");
        printf("%.2f", atual->saldo);
        printf("\n\n");
    }
    if ( primeiro == NULL)
        printf("  Nenhum Cliente Cadastrado.");
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Lista* excluir_cadastros(Lista* primeiro) {

    Lista *anterior = NULL;
    Lista *atual = primeiro;
    int numero_conta = 0;


    printf("  Digite o codigo do cliente para exclusao: ");
    scanf("%d",&numero_conta);
    limpa_linha();


    while( atual != NULL && atual->numero_conta != numero_conta) {
        anterior = atual;
        atual = atual->prox;
    }


    if (atual == NULL) {
        printf("\n  Cliente nao encontrado.");
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
    }


    if (anterior == NULL) {
        printf("\n  Conteudo excluido com sucesso.");
        primeiro= atual->prox;

    } else {
        printf("\n  Conteudo excluido com sucesso.");
        anterior->prox= atual->prox;
    }


    free(atual);
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return primeiro;
}


void alterar_cadastros(Lista *primeiro) {

    int numero_contasub;
    char nome_substituto[40];
    float saldo_sub;
    Lista *atual = primeiro;
    int encontrado;


    printf("  Digite o codigo do cliente para a alteracao: ");
    scanf("%d", &numero_contasub);
    limpa_linha();

    encontrado = 0;

    for (atual = primeiro; atual != NULL; atual = atual->prox) {
        if (atual->numero_conta == numero_contasub) {
            encontrado = 1;
            printf("\n  Novo nome: ");
            fgets(nome_substituto, 40, stdin);
            strcpy(atual->nome_cliente, nome_substituto);
            printf("\n  Novo Saldo: ");
            scanf("%f", &saldo_sub);
            limpa_linha();
            printf ("\n");
            atual->saldo = saldo_sub;
            printf("Dados alterados com sucesso!");
        }
    }
    if (!encontrado) {
        printf("\nCliente nao encontrado!");
    }

    printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
