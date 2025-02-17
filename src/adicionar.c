#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/funcoes.h"


//Função adicionar para todas as entidades.

void addVeiculo(){
    FILE *f = fopen("dados/Veiculos.txt", "a+");
    int qnt = 0, ultimo_id = 0;
    if(f == NULL){
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }
    Veiculo v;
    while(fscanf(f, "%d,%s,%f,%d", &v.id, v.tipo_vec, &v.capacidade_carga, &v.status) != EOF){
        ultimo_id = v.id;
    }

    printf("ultimo id: %d\n", ultimo_id);

    printf("Quantos veiculos deseja adicionar?\n");
    scanf("%d", &qnt);
    
    
    for(int i = 0; i < qnt; i++){
        printf("\n*** Informacões do veiculo ***\n");
        v.id = ultimo_id + 1;
        printf("Digite o tipo do veiculo(sem espaços): ");
        scanf("%s", v.tipo_vec);
        printf("Digite a capacidade de carga: ");
        scanf("%f", &v.capacidade_carga);
        printf("Digite o status do veiculo (0 para livre, 1 para ocupado): ");
        scanf("%d", &v.status);
        
        fprintf(f, "%d,%s,%.2f,%d\n", v.id, v.tipo_vec, v.capacidade_carga, v.status);
        ultimo_id++;
    }
    fclose(f);
    printf("\nVeiculo(s) salvo(s) com sucesso.\n");
}

void addFuncionario(){
    FILE *f = fopen("dados/Funcionarios.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int qnt = 0, ultimo_id = 0;
    char linha[200];
    Funcionario func;

    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &qnt);
    getchar();
        
    
    while (fgets(linha, sizeof(linha), f) != NULL) {
        // processa linha e separa numero e nome
        if (sscanf(linha, "%d,%99[^\n]", &func.id, func.nome) == 2) {
            ultimo_id = func.id;
        }
    }

    for (int i = 0; i < qnt; i++) {
        func.id = ultimo_id + 1;
        printf("Digite o nome do Funcionario: ");
        fgets(func.nome, sizeof(func.nome), stdin);

        // Remover o '\n' do final da string, se presente
        size_t len = strlen(func.nome);
        if (len > 0 && func.nome[len - 1] == '\n') {
            func.nome[len - 1] = '\0';
        }
        // Remove espaco do final
        if (len > 1 && func.nome[len - 2] == ' ') {
            func.nome[len - 2] = '\0';
        }

        if (fprintf(f, "%d,%s\n", func.id, func.nome) < 0) {
            printf("Erro ao salvar os dados. Tente novamente.\n");
            i--;  // Repete a entrada
            continue;
        }

        ultimo_id = func.id;
    }

    fclose(f);
    printf("Funcionarios salvos com sucesso!\n");
}

void addCliente(){
    FILE *f = fopen("dados/Clientes.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int qnt = 0, ultimo_id = 0;
    char linha[200];
    char aux[200];
    Cliente cliente;

    printf("Quantos Clientes deseja cadastrar? ");
    scanf("%d", &qnt);
    getchar();
        
    
    while (fgets(linha, sizeof(linha), f) != NULL) {
        // processa linha e separa numero e nome
        if (sscanf(linha, "%d,%99[^\n]", &cliente.id, aux) == 2) {
            ultimo_id = cliente.id;
        }
    }

    for (int i = 0; i < qnt; i++) {
        cliente.id = ultimo_id + 1;
        printf("Digite o tipo de servico solicitado:\n1 - Economico\n2 - Padrao\n3 - Premium\n");
        scanf("%d", &cliente.tipo_servico);
        getchar();
        printf("Digite o nome completo do Cliente: ");
        fgets(cliente.nome, sizeof(cliente.nome), stdin);

        // Remover o '\n' do final da string, se presente
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

        // Remover o '\n' do final da string, se presente
        len = strlen(cliente.endereco);
        if (len > 0 && cliente.endereco[len - 1] == '\n') {
            cliente.endereco[len - 1] = '\0';
        }
        // Remove espaco do final
        if (len > 1 && cliente.endereco[len - 2] == ' ') {
            cliente.endereco[len - 2] = '\0';
        }

        fprintf(f, "%d,%d,%s,%s\n", cliente.id, cliente.tipo_servico, cliente.nome, cliente.endereco);

        ultimo_id = cliente.id;
    }

    fclose(f);
    printf("Clientes salvos com sucesso!\n");
}
 
void addEntrega(){
    FILE *f = fopen("dados/Entregas.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int qnt = 0, ultimo_id = 0;
    char linha[200];
    char aux[200];
    Entrega entrega;

    printf("Quantos Entregas deseja cadastrar? ");
    scanf("%d", &qnt);
    getchar();
        
    
    while (fgets(linha, sizeof(linha), f) != NULL) {
        char linha2[200], linha3[200];
        fgets(linha2, sizeof(linha2), f);
        fgets(linha3, sizeof(linha3), f);
        // processa linha e separa numero e nome
        if (sscanf(linha, "%d,%d,%d", &entrega.id, &entrega.tempo_estimado, &entrega.foi_concluida) == 3) {
            ultimo_id = entrega.id;
        }
    }

    for (int i = 0; i < qnt; i++) {
        entrega.id = ultimo_id + 1;
        printf("Digite o tempo estimado em horas para a entrega:\n");
        scanf("%d", &entrega.tempo_estimado);
        entrega.foi_concluida = 0;
        getchar();
        printf("Digite o endereco de Origem da entrega: ");
        fgets(entrega.origem, sizeof(entrega.origem), stdin);

        // Remover o '\n' do final da string, se presente
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

        // Remover o '\n' do final da string, se presente
        len = strlen(entrega.destino);
        if (len > 0 && entrega.destino[len - 1] == '\n') {
            entrega.destino[len - 1] = '\0';
        }
        // Remove espaco do final
        if (len > 1 && entrega.destino[len - 2] == ' ') {
            entrega.destino[len - 2] = '\0';
        }

        fprintf(f, "%d,%d,%d\n%s\n%s\n", entrega.id, entrega.tempo_estimado, entrega.foi_concluida, entrega.origem, entrega.destino);
        ultimo_id = entrega.id;
    }

    fclose(f);
    printf("Entregas salvas com sucesso!\n");
}
 