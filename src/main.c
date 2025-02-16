#include <stdio.h>
#include "../include/structs.h"

//Funções
void AddVeiculo(){
    FILE *f = fopen("../dados/Veiculos.txt", "a+");
    int qnt = 0, ultimoid = 0;
    Veiculo v;
    while(fscanf(f,  "%d %s %f %d", &v.id, v.tipo_vec, &v.capacidade_carga, &v.status) == 4){
        ultimoid = v.id;
    }

    printf("Quantos veículos deseja adicionar?\n");
    scanf("%d", &qnt);
    
    printf("\n*** Informacões do veículo ***\n");
    
    for(int i = 0; i < qnt; i++){
        v.id = ultimoid + 1;
        printf("Digite o tipo do veículo: ");
        scanf("%s", v.tipo_vec);
        printf("Digite a capacidade de carga: ");
        scanf("%f", &v.capacidade_carga);
        printf("Digite o status do veículo (0 para livre, 1 para ocupado): ");
        scanf("%d", &v.status);
        
        fprintf(f, "%d %s %f %d \n", v.id, v.tipo_vec, v.capacidade_carga, v.status);
        ultimoid++;
    }
    fclose(f);
    printf("\nVeículo(s) salvo(s) com sucesso.\n");
}

// Main

int main(){


AddVeiculo();
    return 0;
}
