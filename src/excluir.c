#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/funcoes.h"

void excluirVeiculo() {
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

    printf("Insira o id do veiculo a ser excluido: ");
    int id;
    scanf("%d", &id);
    Veiculo v;
    int encontrou = 0;
    while(fscanf(f, "%d,%19[^,],%f,%d", &v.id, v.tipo_vec, &v.capacidade_carga, &v.status) != EOF){
        if (id == v.id) {
            encontrou = 1;
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
        printf("Veiculo excluido!");
    } else {
        remove("dados/Tmp.txt");
        printf("Veiculo nao encontrado.\n");
    }
}
 
void excluirFuncionario() {
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

    printf("Insira o id do funcionario a ser excluido: ");
    int id;
    scanf("%d", &id);
    Funcionario func;
    int encontrou = 0;
    while (fscanf(f, "%d,%99[^,\n]\n", &func.id, func.nome) != EOF) {
        if (id == func.id) {
            encontrou = 1;
        } else {
            fprintf(tmp, "%d,%s\n", func.id, func.nome);
        }
    }

    fclose(f);
    fclose(tmp);

    if (encontrou) {
        remove("dados/Funcionarios.txt");
        rename("dados/Temp.txt", "dados/Funcionarios.txt");
        printf("Funcionario excluido!\n");
    } else {
        remove("dados/Temp.txt");
        printf("Funcionario não encontrado.\n");
    }
}

void excluirCliente() {
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

    printf("Insira o id do cliente a ser excluido: ");
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
        } else {
            fprintf(tmp, "%d,%d,%s,%s\n", cliente.id, tipo_servico, nome, endereco);
        }
    }

    fclose(f);
    fclose(tmp);

    if (encontrou) {
        remove("dados/Clientes.txt");
        rename("dados/Temp.txt", "dados/Clientes.txt");
        printf("Cliente excluido!\n");
    } else {
        remove("dados/Temp.txt");
        printf("Cliente não encontrado.\n");
    }
}

void excluirEntrega() {
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

    printf("Insira o id da entrega a ser excluida: ");
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
        } else {
            fprintf(tmp, "%d,%d,%d\n%s%s", entrega.id, entrega.tempo_estimado, entrega.foi_concluida, origem, destino);
        }
    }

    fclose(f);
    fclose(tmp);

    if (encontrou) {
        remove("dados/Entregas.txt");
        rename("dados/Temp.txt", "dados/Entregas.txt");
        printf("Entrega excluida!\n");
    } else {
        remove("dados/Temp.txt");
        printf("Entrega não encontrada.\n");
    }
}