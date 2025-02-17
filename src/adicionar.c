#include <stdio.h>
#include <stdlib.h>
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

    printf("Quantos veículos deseja adicionar?\n");
    scanf("%d", &qnt);
    
    
    for(int i = 0; i < qnt; i++){
        printf("\n*** Informacões do veículo ***\n");
        v.id = ultimo_id + 1;
        printf("Digite o tipo do veículo(sem espaços): ");
        scanf("%s", v.tipo_vec);
        printf("Digite a capacidade de carga: ");
        scanf("%f", &v.capacidade_carga);
        printf("Digite o status do veículo (0 para livre, 1 para ocupado): ");
        scanf("%d", &v.status);
        
        fprintf(f, "%d,%s,%.2f,%d\n", v.id, v.tipo_vec, v.capacidade_carga, v.status);
        ultimo_id++;
    }
    fclose(f);
    printf("\nVeículo(s) salvo(s) com sucesso.\n");
}

void addFuncionario(){
    FILE *f = fopen("dados/Funcionarios.txt", "a+");
    int qnt = 0, ultimo_id = 0;
    Funcionario func;

    printf("Quantos funcionários deseja cadastrar?");
    scanf("%d", &qnt);

    while(fscanf(f, "%d,%s", &func.id, func.nome) != EOF){
        ultimo_id = func.id;
    }
    
    for(int i = 0; i < qnt; i++){
        func.id = ultimo_id + 1;
        printf("Digite o nome do Funcionário: ");
        scanf("%s", func.nome);
        fprintf(f, "%d,%s", func.id, func.nome);
        ultimo_id = func.id;
    }
    
    fclose(f);
    printf("Funcionários salvos com sucesso!");
}
