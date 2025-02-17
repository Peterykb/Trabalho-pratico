#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/funcoes.h"

void editarVeiculo() {
    FILE *f = fopen("dados/Veiculos.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    FILE *tmp = fopen("dados/Tmp.txt", "w");
    if (tmp == NULL) {
        printf("Erro ao criar arquivo temporario\n");
        system("pause");
        exit(1);
    }

    printf("Insira o id do veiculo a ser editado: ");
    int id;
    scanf("%d", &id);
    Veiculo v;


    int encontrou = 0;
    while(fscanf(f, "%d,%19[^,],%f,%d", &v.id, v.tipo_vec, &v.capacidade_carga, &v.status) != EOF){
        if (id == v.id) {
            encontrou = 1;

            printf("\n*** Informacões do veiculo ***\n");
            printf("Digite o tipo do veiculo(sem espaços): ");
            scanf("%s", v.tipo_vec);
            printf("Digite a capacidade de carga: ");
            scanf("%f", &v.capacidade_carga);
            printf("Digite o status do veiculo (0 para livre, 1 para ocupado): ");
            scanf("%d", &v.status);
            fprintf(tmp, "%d,%s,%.2f,%d\n", v.id, v.tipo_vec, v.capacidade_carga, v.status);
        } else {
            fprintf(tmp, "%d,%s,%.2f,%d\n", v.id, v.tipo_vec, v.capacidade_carga, v.status);
            printf("%d\n", v.status);
        }
    }

    fclose(f);
    fclose(tmp);

    if (encontrou) {
        remove("dados/Veiculos.txt");
        rename("dados/Tmp.txt", "dados/Veiculos.txt");
        printf("Veiculo editado!");
    } else {
        remove("dados/Tmp.txt");
        printf("Veiculo nao encontrado.\n");
    }
}

void editarFuncionario() {
    FILE *f = fopen("dados/Funcionarios.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    FILE *tmp = fopen("dados/Temp.txt", "w");
    if (tmp == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(f);
        system("pause");
        exit(1);
    }

    printf("Insira o id do funcionario a ser editado: ");
    int id;
    scanf("%d", &id);
    Funcionario func;
    int encontrou = 0;
    while (fscanf(f, "%d,%99[^,\n]\n", &func.id, func.nome) != EOF) {
        if (id == func.id) {
            encontrou = 1;

            printf("\n*** Informacões do funcionario ***\n");
            printf("Digite o nome do Funcionario: ");
            fgets(func.nome, sizeof(func.nome), stdin);
            // Remove o '\n' do final da string, se presente
            size_t len = strlen(func.nome);
            if (len > 0 && func.nome[len - 1] == '\n') {
                func.nome[len - 1] = '\0';
            }
            // Remove espaco do final
            if (len > 1 && func.nome[len - 2] == ' ') {
                func.nome[len - 2] = '\0';
            }

            fprintf(tmp, "%d,%s\n", func.id, func.nome);
        } else {
            fprintf(tmp, "%d,%s\n", func.id, func.nome);
        }
    }

    fclose(f);
    fclose(tmp);

    if (encontrou) {
        remove("dados/Funcionarios.txt");
        rename("dados/Temp.txt", "dados/Funcionarios.txt");
        printf("Funcionario editado!\n");
    } else {
        remove("dados/Temp.txt");
        printf("Funcionario nao encontrado.\n");
    }
}

void editarCliente() {
    FILE *f = fopen("dados/Clientes.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    FILE *tmp = fopen("dados/Temp.txt", "w");
    if (tmp == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(f);
        system("pause");
        exit(1);
    }

    printf("Insira o id do cliente a ser editado: ");
    int id;
    scanf("%d", &id);
    Cliente cliente;
    int encontrou = 0;
    char nome[100];
    char endereco[200];
    int tipo_servico;

    while (fscanf(f, "%d,%d,%99[^,],%199[^\n]\n", &cliente.id, &tipo_servico, nome, endereco) != EOF) {
        if (id == cliente.id) {
            encontrou = 1;
            printf("\n*** Informacões do cliente ***\n");
            printf("Digite o tipo de servico solicitado:\n1 - Economico\n2 - Padrao\n3 - Premium\n");
            scanf("%d", &cliente.tipo_servico);
            getchar();
            printf("Digite o nome completo do Cliente: ");
            fgets(cliente.nome, sizeof(cliente.nome), stdin);

            // Remove o '\n' do final da string, se presente
            size_t len = strlen(cliente.nome);
            if (len > 0 && cliente.nome[len - 1] == '\n') {
                cliente.nome[len - 1] = '\0';
            }
            // Remove espaco do final
            if (len > 1 && cliente.nome[len - 2] == ' ') {
                cliente.nome[len - 2] = '\0';
            }

            printf("Digite o endereco completo do Cliente: ");
            fgets(cliente.endereco, sizeof(cliente.endereco), stdin);

            // Remove o '\n' do final da string, se presente
            len = strlen(cliente.endereco);
            if (len > 0 && cliente.endereco[len - 1] == '\n') {
                cliente.endereco[len - 1] = '\0';
            }
            // Remove espaco do final
            if (len > 1 && cliente.endereco[len - 2] == ' ') {
                cliente.endereco[len - 2] = '\0';
            }

            fprintf(tmp, "%d,%d,%s,%s\n", cliente.id, cliente.tipo_servico, cliente.nome, cliente.endereco);

        
        } else {
            fprintf(tmp, "%d,%d,%s,%s\n", cliente.id, tipo_servico, nome, endereco);
        }
    }

    fclose(f);
    fclose(tmp);

    if (encontrou) {
        remove("dados/Clientes.txt");
        rename("dados/Temp.txt", "dados/Clientes.txt");
        printf("Cliente editado!\n");
    } else {
        remove("dados/Temp.txt");
        printf("Cliente nao encontrado.\n");
    }
}

void editarEntrega() {
    FILE *f = fopen("dados/Entregas.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    FILE *tmp = fopen("dados/Temp.txt", "w");
    if (tmp == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(f);
        system("pause");
        exit(1);
    }

    printf("Insira o id da entrega a ser editada: ");
    int id;
    scanf("%d", &id);
    Entrega entrega;
    int encontrou = 0;
    char origem[200];
    char destino[200];

    while (fscanf(f, "%d,%d,%d\n", &entrega.id, &entrega.tempo_estimado, &entrega.foi_concluida) != EOF) {
        fgets(origem, sizeof(origem), f);
        fgets(destino, sizeof(destino), f);

        if (id == entrega.id) {
            encontrou = 1;
            printf("\n*** Informacões da entrega ***\n");
            printf("Digite o tempo estimado em horas para a entrega:\n");
            scanf("%d", &entrega.tempo_estimado);
            printf("Entrega foi concluida? ");
            scanf("%d", &entrega.foi_concluida);
            getchar();
            printf("Digite o endereco de Origem da entrega: ");
            fgets(entrega.origem, sizeof(entrega.origem), stdin);

            // Remove o '\n' do final da string, se presente
            size_t len = strlen(entrega.origem);
            if (len > 0 && entrega.origem[len - 1] == '\n') {
                entrega.origem[len - 1] = '\0';
            }
            // Remove espaco do final
            if (len > 1 && entrega.origem[len - 2] == ' ') {
                entrega.origem[len - 2] = '\0';
            }

            printf("Digite o endereco de Destino da Entrega: ");
            fgets(entrega.destino, sizeof(entrega.destino), stdin);

            // Remove o '\n' do final da string, se presente
            len = strlen(entrega.destino);
            if (len > 0 && entrega.destino[len - 1] == '\n') {
                entrega.destino[len - 1] = '\0';
            }
            // Remove espaco do final
            if (len > 1 && entrega.destino[len - 2] == ' ') {
                entrega.destino[len - 2] = '\0';
            }

            fprintf(tmp, "%d,%d,%d\n%s\n%s\n", entrega.id, entrega.tempo_estimado, entrega.foi_concluida, entrega.origem, entrega.destino);
        } else {
            fprintf(tmp, "%d,%d,%d\n%s%s", entrega.id, entrega.tempo_estimado, entrega.foi_concluida, origem, destino);
        }
    }

    fclose(f);
    fclose(tmp);

    if (encontrou) {
        remove("dados/Entregas.txt");
        rename("dados/Temp.txt", "dados/Entregas.txt");
        printf("Entrega editada!\n");
    } else {
        remove("dados/Temp.txt");
        printf("Entrega nao encontrada.\n");
    }
}