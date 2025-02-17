#ifndef STRUCTS_H
#define STRUCTS_H

//Estruturas utilizadas no programa.

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
    int tempo_estimado; // em horas.
    int foi_concluida;
    char origem[200]; 
    char destino[200];
} Entrega;
typedef struct {
     
} EntregasConcluidas;
typedef struct 
{
    int id;
    char nome[100];
} Funcionario;

typedef struct 
{
    int id;
    char nome[100];
    char endereco[100];
    int tipo_servico; // economico, padrao, premium
} Cliente;

#endif