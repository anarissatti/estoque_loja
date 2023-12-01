#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_CLIENTES 100

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

struct Cliente {
    int codigo;
    char nome[50];
    char sobrenome[50];
    char email[50];
};

struct Produto produtos[MAX_PRODUTOS];
struct Cliente clientes[MAX_CLIENTES];

int numProdutos = 0;
int numClientes = 0;

// Função para adicionar um novo produto
void adicionarProduto() {
    struct Produto novoProduto;

    printf("Digite o nome do produto: ");
    scanf("%s", novoProduto.nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novoProduto.quantidade);

    novoProduto.codigo = numProdutos + 1;
    produtos[numProdutos++] = novoProduto;

    printf("Produto adicionado com sucesso!\n");
}

// Função para listar todos os produtos
void listarProdutos() {
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Codigo: %d, Nome: %s, Preco: %.2f, Quantidade: %d\n",
               produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
}

// Função para adicionar um novo cliente
void adicionarCliente() {
    struct Cliente novoCliente;

    printf("Digite o nome do cliente: ");
    scanf("%s", novoCliente.nome);
    printf("Digite o sobrenome do cliente: ");
    scanf("%s", novoCliente.sobrenome);
    printf("Digite o email do cliente: ");
    scanf("%s", novoCliente.email);

    novoCliente.codigo = numClientes + 1;
    clientes[numClientes++] = novoCliente;

    printf("Cliente adicionado com sucesso\n");
}

// Função para listar todos os clientes
void listarClientes() {
    printf("\nLista de Clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("Codigo: %d, Nome: %s %s, Email: %s\n",
               clientes[i].codigo, clientes[i].nome, clientes[i].sobrenome, clientes[i].email);
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Adicionar Cliente\n");
        printf("4. Listar Clientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                adicionarCliente();
                break;
            case 4:
                listarClientes();
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}