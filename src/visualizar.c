#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/funcoes.h"

void visualizarVeiculo() {
    FILE *f = fopen("dados/Veiculos.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    Veiculo v;
    while(fscanf(f, "%d,%19[^,],%f,%d", &v.id, v.tipo_vec, &v.capacidade_carga, &v.status) != EOF) {
        if (v.status == 0) {
            printf("\nid: %d | Tipo: %s | Capacidade de carga: %.2f | status: livre", v.id, v.tipo_vec, v.capacidade_carga);
        } else {
            printf("\nid: %d | Tipo: %s | Capacidade de carga: %.2f | status: ocupado", v.id, v.tipo_vec, v.capacidade_carga);
        }
    }

    fclose(f);
}

void visualizarFuncionario() {
    FILE *f = fopen("dados/Funcionarios.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    Funcionario func;
    while (fscanf(f, "%d,%99[^,\n]\n", &func.id, func.nome) != EOF) {
        printf("\nid: %d | Nome: %s", func.id, func.nome);
    }

    fclose(f);
}

void visualizarCliente() {
    FILE *f = fopen("dados/Clientes.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    Cliente cliente;
    char linha[350];

    while (fgets(linha, sizeof(linha), f) != NULL) {
        // Tenta extrair os dados da linha lida
        if (sscanf(linha, "%d,%d,%99[^,],%199[^\n]", &cliente.id, &cliente.tipo_servico, cliente.nome, cliente.endereco) == 4) {
            char servico[20];

            switch (cliente.tipo_servico) {
                case 1: strcpy(servico, "Economico"); break;
                case 2: strcpy(servico, "Padrao"); break;
                case 3: strcpy(servico, "Premium"); break;
                default: strcpy(servico, "Desconhecido"); break;
            }

            printf("\nid: %d | Tipo de servico: %s | Nome: %s | Endereco: %s", cliente.id, servico, cliente.nome, cliente.endereco);
        } else {
            printf("\nErro ao ler linha: %s", linha);
        }
    }

    fclose(f);
}

void visualizarEntrega() {
    FILE *f = fopen("dados/Entregas.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    Entrega entrega;
    while (fscanf(f, "%d,%d,%d\n", &entrega.id, &entrega.tempo_estimado, &entrega.foi_concluida) != EOF) {
        fgets(entrega.origem, sizeof(entrega.origem), f);
        fgets(entrega.destino, sizeof(entrega.destino), f);

        if (entrega.foi_concluida == 1) {
            printf("\nid: %d | Tempo estimado (horas): %d | Foi concluida? Sim | Origem: %s | Destino: %s", entrega.id, entrega.tempo_estimado, entrega.origem, entrega.destino);
        } else {
            printf("\nid: %d | Tempo estimado (horas): %d | Foi concluida? Nao | Origem: %s | Destino: %s", entrega.id, entrega.tempo_estimado, entrega.origem, entrega.destino);
        }
    }

    fclose(f);

}