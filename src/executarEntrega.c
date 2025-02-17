#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void executarEntrega() {
    FILE *fEntregas = fopen("dados/Entregas.txt", "r");
    FILE *fTemp = fopen("dados/temp.txt", "w");
    FILE *fConcluidas = fopen("dados/EntregasConcluidas.txt", "a");
    FILE *fVeiculos = fopen("dados/Veiculos.txt", "r");
    FILE *fTempVeiculos = fopen("dados/temp_veiculos.txt", "w");

    if (!fEntregas || !fTemp || !fConcluidas || !fVeiculos || !fTempVeiculos) {
        printf("Erro ao abrir um dos arquivos.\n");
        exit(1);
    }

    Entrega e;
    Veiculo v;
    int idEscolhido, idFuncionario, idVeiculo, idCliente, encontrou = 0;
    int tempoTotal;

    printf("Entregas pendentes:\n");
    while (fscanf(fEntregas, "%d,%d,%d\n", &e.id, &e.tempo_estimado, &e.foi_concluida) != EOF) {
        fgets(e.origem, sizeof(e.origem), fEntregas);
        fgets(e.destino, sizeof(e.destino), fEntregas);
        e.origem[strcspn(e.origem, "\n")] = 0;
        e.destino[strcspn(e.destino, "\n")] = 0;
        
        if (e.foi_concluida == 0) {
            printf("ID: %d | Origem: %s | Destino: %s\n", e.id, e.origem, e.destino);
        }
    }
    rewind(fEntregas);
    
    printf("Digite o ID da entrega a concluir: ");
    scanf("%d", &idEscolhido);
    printf("Digite o ID do funcionário responsável: ");
    scanf("%d", &idFuncionario);
    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);
    printf("Digite o tempo total da entrega (em horas): ");
    scanf("%d", &tempoTotal);

    printf("Veículos disponíveis:\n");
    while (fscanf(fVeiculos, "%d,%[^,],%f,%d", &v.id, v.tipo_vec, &v.capacidade_carga, &v.status) != EOF) {
        if (v.status == 0) {
            printf("ID: %d | Tipo: %s | Capacidade: %.2f\n", v.id, v.tipo_vec, v.capacidade_carga);
        }
    }
    rewind(fVeiculos);
    
    printf("Digite o ID do veículo utilizado: ");
    scanf("%d", &idVeiculo);

    while (fscanf(fEntregas, "%d,%d,%d\n", &e.id, &e.tempo_estimado, &e.foi_concluida) != EOF) {
        fgets(e.origem, sizeof(e.origem), fEntregas);
        fgets(e.destino, sizeof(e.destino), fEntregas);
        e.origem[strcspn(e.origem, "\n")] = 0;
        e.destino[strcspn(e.destino, "\n")] = 0;
        
        if (e.id == idEscolhido && e.foi_concluida == 0) {
            e.foi_concluida = 1;
            fprintf(fConcluidas, "%d,%d,%d\n%s\n%s\n%d,%d,%d,%d\n", e.id, e.tempo_estimado, e.foi_concluida, e.origem, e.destino, idFuncionario, idCliente, idVeiculo, tempoTotal);
            encontrou = 1;
        } else {
            fprintf(fTemp, "%d,%d,%d\n%s\n%s\n", e.id, e.tempo_estimado, e.foi_concluida, e.origem, e.destino);
        }
    }

    fclose(fEntregas);
    fclose(fConcluidas);
    fclose(fTemp);
    remove("dados/Entregas.txt");
    rename("dados/temp.txt", "dados/Entregas.txt");

    if (!encontrou) {
        printf("Entrega não encontrada ou já concluída.\n");
        fclose(fVeiculos);
        fclose(fTempVeiculos);
        return;
    }

    while (fscanf(fVeiculos, "%d,%[^,],%f,%d", &v.id, v.tipo_vec, &v.capacidade_carga, &v.status) != EOF) {
        if (v.id == idVeiculo) {
            v.status = 0;
        }
        fprintf(fTempVeiculos, "%d %s %.2f %d\n", v.id, v.tipo_vec, v.capacidade_carga, v.status);
    }

    fclose(fVeiculos);
    fclose(fTempVeiculos);
    remove("dados/Veiculos.txt");
    rename("dados/temp_veiculos.txt", "dados/Veiculos.txt");

    printf("Entrega %d concluída com sucesso!\n", idEscolhido);
}
