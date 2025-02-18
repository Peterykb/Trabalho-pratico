#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/funcoes.h"

void gerarRelatorio() {
    FILE *fent = fopen("dados/EntregasConcluidas.txt", "r");
    int identrega, idfunc, idcliente, idveiculo, tempoestimado, tempototal, concluida;
    char origem[100], destino[100];

    if(fent == NULL){
        printf("Erro ao abrir os arquivos.");
        system("pause");
        exit(1);
    }

    printf("*** RELATORIO DAS ENTREGAS CONCLUIDAS ***\n");

    while(fscanf(fent, "%d,%d,%d\n", &identrega, &tempoestimado, &concluida) != EOF){
        fgets(origem, sizeof(origem), fent);
        fgets(destino, sizeof(destino), fent);

        origem[strcspn(origem, "\n")] = 0;
        destino[strcspn(destino, "\n")] = 0;

        fscanf(fent, "%d,%d,%d,%d", &idfunc, &idcliente, &idveiculo, &tempototal);

        printf("Id da entrega: %d\n", identrega);
        printf("Id do funcionario: %d\n", idfunc);
        printf("Id do cliente: %d\n", idcliente);
        printf("Id do veiculo: %d\n", idveiculo);
        printf("Origem: %s", origem);
        printf("Destino: %s", destino);
        printf("Tempo gasto para a entrega: %d\n", tempototal);
        printf("--------------------END--------------------\n");
    }
    fclose(fent);

}

