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
        }
        else {
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
    }
    else {
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
        printf("Erro ao criar arquivo temporário.\n");
        fclose(f);
        system("pause");
        exit(1);
    }

    printf("Insira o id do funcionário a ser excluído: ");
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
        printf("Funcionário excluído!\n");
    } else {
        remove("dados/Temp.txt");
        printf("Funcionário não encontrado.\n");
    }
}

// TODO
void excluirCliente() {
    FILE *f = fopen("dados/Clientes.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    printf("Insira o id do cliente a ser excluido: ");
    int id;
    scanf("%d", &id);
    
}

void excluirEntrega() {
    FILE *f = fopen("dados/Entregas.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    printf("Insira o id da entrega a ser excluida: ");
    int id;
    scanf("%d", &id);
    
}