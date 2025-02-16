#ifndef STRUCTS_H
#define STRUCTS_H


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
    int realizada; 
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

#endif