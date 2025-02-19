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

        // remove \n do final da string
        size_t len = strlen(origem);
        if (len > 0 && origem[len - 1] == '\n') {
            origem[len - 1] = '\0';
        }
        len = strlen(destino);
        if (len > 0 && destino[len - 1] == '\n') {
            destino[len - 1] = '\0';
        }

        fscanf(fent, "%d,%d,%d,%d", &idfunc, &idcliente, &idveiculo, &tempototal);

        printf("Id da entrega: %d\n", identrega);
        printf("Id do funcionario: %d\n", idfunc);
        printf("Id do cliente: %d\n", idcliente);
        printf("Id do veiculo: %d\n", idveiculo);
        printf("Origem: %s\n", origem);
        printf("Destino: %s\n", destino);
        printf("Tempo gasto para a entrega: %d\n", tempototal);
        printf("--------------------END--------------------\n");
    }
    fclose(fent);

}

