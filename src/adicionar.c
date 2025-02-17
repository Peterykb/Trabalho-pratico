#include <stdio.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/funcoes.h"


//Função adicionar para todas as entidades.

void AddVeiculo(){
    FILE *f = fopen("../dados/Veiculos.txt", "a+");
    int qnt = 0, ultimoid = 0;
    if(f == NULL){
        printf("Erro ao abrir o arquivo.");
        system("pause");
        exit(1);
    }
    Veiculo v;
    while(fscanf(f,  "%d %s %f %d", &v.id, v.tipo_vec, &v.capacidade_carga, &v.status) == 4){
        ultimoid = v.id;
    }

    printf("Quantos veículos deseja adicionar?\n");
    scanf("%d", &qnt);
    
    
    for(int i = 0; i < qnt; i++){
        printf("\n*** Informacões do veículo ***\n");
        v.id = ultimoid + 1;
        printf("Digite o tipo do veículo: ");
        scanf("%s", v.tipo_vec);
        printf("Digite a capacidade de carga: ");
        scanf("%f", &v.capacidade_carga);
        printf("Digite o status do veículo (0 para livre, 1 para ocupado): ");
        scanf("%d", &v.status);
        
        fprintf(f, "%d %s %f %d \n", v.id, v.tipo_vec, v.capacidade_carga, v.status);
        while(fprintf(f, "%d %s %f %d \n", v.id, v.tipo_vec, v.capacidade_carga, v.status) < 0){
            printf("Erro ao salvar o arquivo. Digite novamente.");
            printf("Digite o tipo do veículo: ");
            scanf("%s", v.tipo_vec);
            printf("Digite a capacidade de carga: ");
            scanf("%f", &v.capacidade_carga);
            printf("Digite o status do veículo (0 para livre, 1 para ocupado): ");
            scanf("%d", &v.status);
            
            fprintf(f, "%d %s %f %d \n", v.id, v.tipo_vec, v.capacidade_carga, v.status);
        }
        ultimoid++;
    }
    fclose(f);
    printf("\nVeículo(s) salvo(s) com sucesso.\n");
}

void AddFuncionario(){
    FILE *f = fopen("../dados/Funcionarios.txt", "a+");
    int qnt = 0, ultimoid = 0;
    Funcionario func;

    printf("Quantos funcionários deseja cadastrar?");
    scanf("%d", &qnt);

    while(fscanf(f, "%d %s", &func.id, func.nome) == 2){
        ultimoid = func.id;
    }
    
    for(int i = 0; i < qnt; i++){
        func.id = ultimoid + 1;
        printf("Digite o nome do Funcionário: ");
        scanf("%s", func.nome);

        while(fprintf(f, "%d %s", func.id, func.nome) < 0){
            printf("Erro ao salvar os dados. Tente novamente.");
            printf("Digite o nome do Funcionário: ");
            scanf("%s", func.nome);
    
            fprintf(f, "%d %s", func.id, func.nome);
        }
        ultimoid = func.id;
    }
    
    fclose(f);
    printf("Funcionários salvos com sucesso!");
}
