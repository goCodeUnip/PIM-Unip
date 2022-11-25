#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#define MAX_SENHA 8
#define MAX_LOGIN 50

typedef struct Clientes {
int codigo;
char nome[50];
char telefone[17];
char email[30];
char deletado;
};
typedef struct Produto {
int codigo;
char descricao[50];
float valor;
char deletado;
};
typedef struct Fornecedores {
int codigo;
char nome[50];
char telefone[17];
char email[30];
char deletado;
};
typedef struct Usuarios {
int codigo;
char nome[100];
char senha[100];
char deletado;
};

FILE *arq;
void montarMenu(const char* funcionalidade);
void gerenciarMenu(int opcao, const char* funcionalidade);
void gerenciarMenuPrincipal(int opcao);
void cadastrar();
void alterar();
void consultar();
void excluir();
void criptografia();

void banner(void)
	{
        printf("\t+----------------------------------------+\n");
        printf("\t|              CompanyDrinks             |\n");
        printf("\t+----------------------------------------+\n");
	}
void menuAdministrador()
{
    int continuar = 0;
    printf("\n\tMenu de Administrador\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Gerenciar Cliente\n");
    printf("2. Gerenciar Produtos\n");
    printf("3. Gerenciar Fornecedores\n");
    printf("4. Criptografia\n");
    printf("5. Gerenciar Usuários\n");
    scanf("%i", &continuar);
    system("cls || clear");
    switch(continuar)
    {
        case 1:
            montarMenu("Clientes");
            break;
        case 2:
            montarMenu("Produtos");
            break;
        case 3:
            montarMenu("Fornecedores");
            break;
        case 4:
            criptografia();
        break;
        case 5:
            montarMenu("Usuarios");
            break;
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}
void montarMenu(const char* funcionalidade)
{
   int opcao = 0;
    banner();
    printf("\n\tMenu de Administrador - %s\n\n", funcionalidade);
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar %s\n", funcionalidade);
    printf("2. Alterar %s\n", funcionalidade);
    printf("3. Consultar %s\n", funcionalidade);
    printf("4. Excluir %s\n", funcionalidade);
    printf("5. Voltar ao Menu Principal\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenu(opcao, funcionalidade);
}
void gerenciarMenu(int opcao, const char* funcionalidade)
{
    switch(opcao)
    {
        case 1:
            cadastrar(funcionalidade);
            break;
        case 2:
            alterar(funcionalidade);
            break;
        case 3:
            consultar(funcionalidade);
            break;
        case 4:
            excluir(funcionalidade);
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}
void cadastrar(const char* funcionalidade)
{
    if (strcmp (funcionalidade, "Clientes") == 0){
    struct Clientes clientes;
    int retorno;
    arq = fopen("Clientes.txt", "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo");
        return;
    }
    printf("Digite o Codigo do Cliente: \n");
    scanf("%d", &clientes.codigo);
    printf("Digite o Nome do Cliente: \n");
    scanf("%s", &clientes.nome);
    printf("Digite o Telefone do Cliente: \n");
    fflush(stdin);
    gets(clientes.telefone);
    printf("Digite o E-mail do Cliente: \n");
    scanf("%s", &clientes.email);
    retorno = fwrite (&clientes, sizeof(clientes), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        printf("\n Dados do Cliente incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }
    else
    {
        fclose (arq);
        printf("\n Falha ao gravar dados do Cliente.");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }else{
    if (strcmp (funcionalidade, "Produtos") == 0){
    struct Produto produtos;
    int retorno;
    arq = fopen("Produtos.txt", "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo");
        return;
    }
    printf("Digite o codigo do Produto: \n");
    scanf("%d", &produtos.codigo);
    printf("Digite a descricao do Produto: \n");
    fflush(stdin);
    gets(produtos.descricao);
    printf("Digite o valor do Produto: \n");
    scanf("%f", &produtos.valor);
    retorno = fwrite (&produtos, sizeof(produtos), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        printf("\n Dados do produto incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }else{
        fclose (arq);
        printf("\n Falha ao gravar dados do Produto.");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    }else{
     if (strcmp (funcionalidade, "Fornecedores") == 0){
    struct Fornecedores fornecedores;
    int retorno;
    arq = fopen("Fornecedores.txt", "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo");
        return;
    }
    printf("Digite o Codigo do Fornecedor: \n");
    scanf("%d", &fornecedores.codigo);
    printf("Digite o Nome do Fornecedor: \n");
    scanf("%s", &fornecedores.nome);
    printf("Digite o Telefone do Fornecedor: \n");
    fflush(stdin);
    gets(fornecedores.telefone);
    printf("Digite o E-mail do Fornecedor: \n");
    scanf("%s", &fornecedores.email);
    retorno = fwrite (&fornecedores, sizeof(fornecedores), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        printf("\n Dados do Fornecedor incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Fornecedores");
    }
    else
    {
        fclose (arq);
        printf("\n Falha ao gravar dados do Fornecedor.");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");

    }else{
     if (strcmp (funcionalidade, "Usuarios") == 0){
    struct Usuarios usuarios;
    int retorno;
    arq = fopen("Usuarios.txt", "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo");
        return;
    }
    printf("Digite o codigo do Usuário: \n");
    scanf("%d", &usuarios.codigo);
    printf("Digite o Nome do Usuário: \n");
    scanf("%s", &usuarios.nome);
    printf("Digite a Senha do Usuário: \n");
    scanf("%s", &usuarios.senha);
    retorno = fwrite (&usuarios, sizeof(usuarios), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        printf("\n Dados do Usuários incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Usuários");
    }
    else
    {
        fclose (arq);
        printf("\n Falha ao gravar dados do Usuários.");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }}}}
}
void alterar(const char* funcionalidade)
{
  if (strcmp (funcionalidade, "Clientes") == 0){
    arq = fopen("Clientes.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }
    struct Clientes clientes;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo do cliente que deseja alterar: \n");
    scanf ("%d", &cod);
    while (fread (&clientes, sizeof(clientes), 1, arq))
    {
        if (cod == clientes.codigo)
        {
            printf("Cod %d --- Nome: %s --- Telefone: %s --- E-mail: %s \n\n",clientes.codigo, clientes.nome, clientes.telefone, clientes.email);
            encontrado = 1;
            fseek(arq,sizeof(struct Clientes)*-1, SEEK_CUR);
            printf("\nDigite o novo Nome: \n");
            fflush(stdin);
            gets(clientes.nome);
            printf("\nDigite o novo Telefone....: \n");
            scanf("%f", &clientes.telefone);
            printf("\nDigite o novo E-mail....: \n");
            scanf("%f", &clientes.email);
            fwrite(&clientes, sizeof(clientes), 1, arq);
            fseek(arq, sizeof(clientes)* 0, SEEK_END);
            printf("\n Dados do Cliente alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
            montarMenu("Clientes");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }
    fclose(arq);
    }else{
    if (strcmp (funcionalidade, "Produtos") == 0){
    arq = fopen("Produtos.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    struct Produto produtos;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo que deseja alterar: \n");
    scanf ("%d", &cod);
    while (fread (&produtos, sizeof(produtos), 1, arq))
    {
        if (cod == produtos.codigo)
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n",produtos.codigo, produtos.descricao, produtos.valor);
            encontrado = 1;
            fseek(arq,sizeof(struct Produto)*-1, SEEK_CUR);
            printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            gets(produtos.descricao);
            printf("\nDigite o novo preco....: \n");
            scanf("%f", &produtos.valor);
            fwrite(&produtos, sizeof(produtos), 1, arq);
            fseek(arq, sizeof(produtos)* 0, SEEK_END);
            printf("\n Dados do produto alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
            montarMenu("Produtos");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    fclose(arq);
    }else{
     if (strcmp (funcionalidade, "Fornecedores") == 0){
    arq = fopen("Fornecedores.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Fornecedores");
    }
    struct Fornecedores fornecedores;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo do Fornecedor que deseja alterar: \n");
    scanf ("%d", &cod);
    while (fread (&fornecedores, sizeof(fornecedores), 1, arq))
    {
        if (cod == fornecedores.codigo)
        {
            printf("Cod %d --- Nome: %s --- Telefone: %s --- E-mail: %s \n\n",fornecedores.codigo, fornecedores.nome, fornecedores.telefone, fornecedores.email);
            encontrado = 1;
            fseek(arq,sizeof(struct Fornecedores)*-1, SEEK_CUR);
            printf("\nDigite o novo Nome: \n");
            fflush(stdin);
            gets(fornecedores.nome);
            printf("\nDigite o novo Telefone....: \n");
            scanf("%f", &fornecedores.telefone);
            printf("\nDigite o novo E-mail....: \n");
            scanf("%f", &fornecedores.email);
            fwrite(&fornecedores, sizeof(fornecedores), 1, arq);
            fseek(arq, sizeof(fornecedores)* 0, SEEK_END);
            printf("\n Dados do Fornecedores alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
            montarMenu("Fornecedores");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Fornecedores");
    }
    fclose(arq);
    }else{
     if (strcmp (funcionalidade, "Usuarios") == 0){
    arq = fopen("Usuarios.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Usuarios");
    }
    struct Usuarios usuarios;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo do Usuario que deseja alterar: \n");
    scanf ("%d", &cod);
    while (fread (&usuarios, sizeof(usuarios), 1, arq))
    {
        if (cod == usuarios.codigo)
        {
            printf("Cod %d --- Nome: %s --- Senha: %s \n\n",usuarios.codigo, usuarios.nome, usuarios.senha);
            encontrado = 1;
            fseek(arq,sizeof(struct Usuarios)*-1, SEEK_CUR);
            printf("\nDigite o novo Nome: \n");
            fflush(stdin);
            gets(usuarios.nome);
            printf("\nDigite a nova Senha....: \n");
            scanf("%f", &usuarios.senha);
            fwrite(&usuarios, sizeof(usuarios), 1, arq);
            fseek(arq, sizeof(usuarios)* 0, SEEK_END);
            printf("\n Dados do Usuarios alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
            montarMenu("Usuarios");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Usuarios");
    }
    fclose(arq);
    }}}}
}
void consultar(const char* funcionalidade)
{
    if (strcmp (funcionalidade, "Clientes") == 0){
    arq = fopen("Clientes.txt", "rb");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }
    struct Clientes clientes;
    while (fread (&clientes, sizeof(clientes), 1, arq))
    {
        if ((clientes.deletado != '*'))
        {
 printf("Cod %d --- Nome: %s --- Telefone: %s --- E-mail: %s \n\n",clientes.codigo, clientes.nome, clientes.telefone, clientes.email);
        }
    }
    fclose(arq);
    printf("Fim da lista. Pressione qualquer tecla para continuar.\n");
    system("pause>nul");
    system("cls || clear");
    montarMenu("Clientes");
    }else{
    if (strcmp (funcionalidade, "Produtos") == 0){
    arq = fopen("produtos.txt", "rb");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    struct Produto produtos;
    while (fread (&produtos, sizeof(produtos), 1, arq))
    {
        if ((produtos.deletado != '*'))
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n",produtos.codigo, produtos.descricao, produtos.valor);
        }
    }
    fclose(arq);
    printf("Fim da lista. Pressione qualquer tecla para continuar.\n");
    system("pause>nul");
    system("cls || clear");
    montarMenu("Produtos");
    }else{
    if (strcmp (funcionalidade, "Fornecedores") == 0){
    arq = fopen("Fornecedores.txt", "rb");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Fornecedores");
    }
    struct Fornecedores fornecedores;
    while (fread (&fornecedores, sizeof(fornecedores), 1, arq))
    {
        if ((fornecedores.deletado != '*'))
        {
            printf("Cod %d --- Nome: %s --- Telefone: %s --- E-mail: %s \n\n",fornecedores.codigo, fornecedores.nome, fornecedores.telefone, fornecedores.email);
        }
    }
    fclose(arq);
    printf("Fim da lista. Pressione qualquer tecla para continuar.\n");
    system("pause>nul");
    system("cls || clear");
    montarMenu("Fornecedores");
    }else{
     if (strcmp (funcionalidade, "Usuarios") == 0){
        arq = fopen("Usuarios.txt", "rb");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Usuarios");
    }
    struct Usuarios usuarios;
    while (fread (&usuarios, sizeof(usuarios), 1, arq))
    {
        if ((usuarios.deletado != '*'))
        {
            printf("Cod %d --- Nome: %s --- Senha: %s \n\n",usuarios.codigo, usuarios.nome, usuarios.senha);
        }
    }
    fclose(arq);
    printf("Fim da lista. Pressione qualquer tecla para continuar.\n");
    system("pause>nul");
    system("cls || clear");
    montarMenu("Usuarios");
    }}}}
}
void excluir(funcionalidade)
{
if (strcmp (funcionalidade, "Clientes") == 0){
    arq = fopen("Clientes.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }
    struct Clientes clientes;
    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf ("%d", &cod);
    while (fread (&clientes, sizeof(clientes), 1, arq))
    {
        if (cod == clientes.codigo)
        {
            printf("Cod %d --- Nome: %s --- Telefone: %s --- E-mail: %s \n\n",clientes.codigo, clientes.nome, clientes.telefone, clientes.email);
            encontrado = 1;
            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                clientes.deletado = '*';
                fseek(arq,sizeof(struct Clientes)*-1, SEEK_CUR);
                fwrite(&clientes, sizeof(clientes), 1, arq);
                fseek(arq, sizeof(clientes)* 0, SEEK_END);
                printf("\nProduto excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
                montarMenu("Clientes");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                montarMenu("Clientes");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Clientes");
    }
    fclose(arq);
    }else{
    if (strcmp (funcionalidade, "Produtos") == 0){
    arq = fopen("produtos.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    struct Produto produtos;
    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf ("%d", &cod);
    while (fread (&produtos, sizeof(produtos), 1, arq))
    {
        if (cod == produtos.codigo)
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n",produtos.codigo, produtos.descricao, produtos.valor);
            encontrado = 1;
            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                produtos.deletado = '*';
                fseek(arq,sizeof(struct Produto)*-1, SEEK_CUR);
                fwrite(&produtos, sizeof(produtos), 1, arq);
                fseek(arq, sizeof(produtos)* 0, SEEK_END);
                printf("\nProduto excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
                montarMenu("Produtos");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                montarMenu("Produtos");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    fclose(arq);
    }else{
     if (strcmp (funcionalidade, "Fornecedores") == 0){
    arq = fopen("Fornecedores.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Fornecedores");
    }
    struct Fornecedores fornecedores;
    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf ("%d", &cod);
    while (fread (&fornecedores, sizeof(fornecedores), 1, arq))
    {
        if (cod == fornecedores.codigo)
        {
            printf("Cod %d --- Nome: %s --- Telefone: %s --- E-mail: %s \n\n",fornecedores.codigo, fornecedores.nome, fornecedores.telefone, fornecedores.email);
            encontrado = 1;
            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                fornecedores.deletado = '*';
                fseek(arq,sizeof(struct Fornecedores)*-1, SEEK_CUR);
                fwrite(&fornecedores, sizeof(fornecedores), 1, arq);
                fseek(arq, sizeof(fornecedores)* 0, SEEK_END);
                printf("\nProduto excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
                montarMenu("Fornecedores");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                montarMenu("Fornecedores");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Fornecedores");
    }
    fclose(arq);
    }else{
     if (strcmp (funcionalidade, "Usuarios") == 0){
    arq = fopen("Usuarios.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Usuarios");
    }
    struct Usuarios usuarios;
    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf ("%d", &cod);
    while (fread (&usuarios, sizeof(usuarios), 1, arq))
    {
        if (cod == usuarios.codigo)
        {
            printf("Cod %d --- Nome: %s --- Senha: %s \n\n",usuarios.codigo, usuarios.nome, usuarios.senha);
            encontrado = 1;
            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                usuarios.deletado = '*';
                fseek(arq,sizeof(struct Usuarios)*-1, SEEK_CUR);
                fwrite(&usuarios, sizeof(usuarios), 1, arq);
                fseek(arq, sizeof(usuarios)* 0, SEEK_END);
                printf("\nProduto excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
                montarMenu("Usuarios");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                montarMenu("Usuarios");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Usuarios");
    }
    fclose(arq);
    }}}}
}
void criptografia()
{
    FILE *origem, *destino; // Declarando ponteiros para abertura de arquivos
    int opcao; // Inteiro que designa a opcao de criptografar ou descriptografar
    puts("Programa de criptografia");
    puts("Digite 1 ou 2 conforme abaixo:");
    puts("  1 - Criptografar");
    puts("  2 - Descriptografar");
    scanf("%d", &opcao);
    if (opcao == 1) // Se for para criptografia
    {
        origem = fopen("origem.txt", "r"); // Tenta abrir origem.txt para leitura
        destino = fopen("destino.txt", "w"); // Tenta abrir o arquivo destino.txt para escrita, e o cria se ele nao existir
        if(origem != NULL && destino != NULL) // Se o arquivo de origem existe e se o de destino existe ou conseguiu ser criado
        {
            char c; // Define a variavel c, para ler caractere por caractere do arquivo
            int contador = 0; // Define contador que indicara a posicao do arquivo
            int i = 0; // Variavel inteira que utilizaremos para mostrar a representacao ASCII do caractere
            // Faz enquanto o fgetc nao retornar o fim do arquivo
            while(( c = fgetc(origem)) != EOF)
            {
                contador++; // Mesma coisa que contador = contador + 1;
                //printf("%c", c); // Mostra o caractere na tela
                i = c; // i sera o codigo numerico do caractere c em ASCII;
                i = i * contador; // Multiplicando i pela posicao do caractere no arquivo;
                fprintf(destino,"%i ", i); // Escreve a representacao numerica de i e um espaco a frente no arquivo de destino
                printf("%i", i); // Mostra o caractere na tela
            }
            fclose(origem); // Fecha o arquivo de origem
            fclose(destino); // Fecha o arquivo de destino
        }
        else
        {
            puts("Erro de leitura/escrita nos arquivos...");
        }
    }
    else if(opcao == 2) // Se for descriptografia
    {
        origem = fopen("destino.txt", "r"); // Tenta abrir destino.txt para leitura
        destino = fopen("descriptografado.txt", "w"); // Tenta abrir o arquivo descriptografado.txt para escrita, e o cria se ele nao existir
        if(origem != NULL && destino != NULL) // Se o arquivo de origem existe e se o de destino existe ou conseguiu ser criado
        {
            int contador = 0; // Define contador que indicara a posicao do arquivo
            char c[100]; // Utilizaremos para armazenar cada codigo que leremos
            int i = 0; // Variavel inteira que utilizaremos para representacao numerica lida do codigo lido no arquivo
            while(fscanf(origem, "%s", c) != EOF)  // Faz enquanto o fscanf nao retornar o fim do arquivo
            {
                contador++; // Mesma coisa que contador = contador + 1;
                i = atoi(c); // Converte um char* para inteiro e atribui a i
                i /= contador; // Mesma coisa que i = i / contador;
                printf("%c", i); // Mostra o caractere na tela
                fprintf(destino,"%c", i); // Escreve a representacao numerica de i no arquivo de destino
            }
            fclose(origem); // Fecha o arquivo de origem
            fclose(destino); // Fecha o arquivo de destino
        }
    }
    else // Se a opcao for invalida
    {
        puts("Opcao invalida...");
    }
    puts("\n"); // Pula duas linhas
    system("pause"); // Pausa o sistema em ambiente windows
}
void login()
{
arq = fopen("Usuarios.txt", "rb");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Usuarios");
    }
    struct Usuarios usuarios;
    int encontrado = 0;
    char user[100];
    char pass[100];
    printf ("\nDigite o Usuario: \n");
    scanf ("%s", &user);
    printf ("\nDigite a Senha: \n");
    scanf ("%s", &pass);
    system("pause>nul");
    while (fread (&usuarios, sizeof(usuarios), 1, arq))
    {
        if (!strcmp(user, usuarios.nome)&&!strcmp(pass, usuarios.senha))
        {
            printf("Login efetuado com sucesso!");
            encontrado = 1;
            fclose(arq);
            system("pause>nul");
            system("cls || clear");
            menuAdministrador();
        }
        else
        {
        printf("\nUsuario nao cadastrado ou senha incorreta!!\n");
        fclose(arq);
        system("pause>nul");
        system("cls || clear");
        banner();
        return login();
        }
    }
 }
int main()
{
    int var,tentativas = 0;
	char *user  = (char*)malloc(sizeof *user * MAX_LOGIN);
	char *senha;
	FILE* fpIN;
    setlocale(LC_ALL,"Portuguese");
    banner();
    system("title PIM - Projeto Integrado Multidisciplinar");
    system("color 5F");
    printf("\tVeja todas as funções disponiveis no menu.\n");
    printf("\tUse os numeros para selecionar a opção desejada.\n");
    printf("\tPressione qualquer tecla para continuar ou\n\tEspaço para sair do programa agora.\n\t");
    var=getch();
    if(var == 32){ exit(0);}// 32 corresponde a espaço no teclado conforme Tabela ASCII
    login();
}
