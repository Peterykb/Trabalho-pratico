#include <stdio.h>

//structs
typedef struct 
{
    int id;
    char tipo_vec[20]; 
    float capacidade_carga;
    int status; // 0 para livre, 1 para ocupado
} Veiculo;
typedef struct 
{
    int id;
    char origem[200]; 
    char destino[200];
    int t_estimado; // em horas.
} Entrega;
typedef struct 
{
    int id;
    char nome[100];
} Funcionario;
typedef struct 
{
    int id;
    char nome[100];
    char tipo_servico[20]; // economico, padrao, premium
} Cliente;

//Funções
void AddVeiculo(){
    FILE *f = fopen("Veiculos.txt", "a");
    int qnt;

    printf("*** Informacões do veículo ***\n");
    
    printf("Quantos veículos deseja adicionar?\n");
    scanf("%d", &qnt);
    
    for(int i = 0; i < qnt; i++){
        Veiculo v;
        
        printf("Digite o tipo do veículo: ");
        scanf("%s", &v.tipo_vec);
        printf("Digite a capacidade de carga: ");
        scanf("%f", &v.capacidade_carga);
        printf("Digite o status do veículo (0 para livre, 1 para ocupado): ");
        scanf("%d", &v.status);
        printf("Id: ");
        scanf("%d", &v.id);
        fprintf(f, "%d %s %f %d \n", v.id, v.tipo_vec, v.capacidade_carga, v.status);
    }
    fclose(f);
    printf("\nVeículo(s) salvo(s) com sucesso.\n");
}

// Main

int main(){


AddVeiculo();
    return 0;
}
