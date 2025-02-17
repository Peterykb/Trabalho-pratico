#include <stdio.h>
#include <../include/funcoes.h>

//terminal -> chcp 65001, compilar -> gcc main.c -o ..\bin\main.exe, executar -> ..\bin\main.exe

//Menu principal

int main(){
    
int instrucao, entidade;

printf("***Bem vindo ao Sistema de Entregas dos Correios***\n");
 do {
        printf("\n* O que deseja fazer? *\n");
        printf("0 - Finalizar programa\n");
        printf("1 - Adicionar\n");
        printf("2 - Visualizar\n");
        printf("3 - Editar\n");
        printf("4 - Excluir\n");
        printf("5 - Executar entrega\n");
        printf("6 - Gerar Relatório\n");
        printf("Escolha uma opção: ");
        scanf("%d", &instrucao);
        
        switch (instrucao) {
            case 0:
                printf("Finalizando o programa...\n");
                break;
            case 1:
                printf("\nEscolha a entidade para adicionar:\n");
                printf("1 - Veículo\n2 - Funcionário\n3 - Entrega\n4 - Cliente\n");
                scanf("%d", &entidade);
                if (entidade == 1) {
                    addVeiculo();
                } else if (entidade == 2) {
                    addFuncionario();
                }
                else if(entidade == 3){
                    //AddEntrega
                } else if(entidade == 4) {
                    addCliente();
                }
                else {
                    printf("Opção inválida!\n");
                }
                break;
            case 2:
                // visualizar();
                break;
            case 3:
                // editar();
                break;
            case 4:
                // excluir();
                break;
            case 5:
               executarEntrega();
                break;
            case 6:
                gerarRelatorio();
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (instrucao != 0);
//AddVeiculo();
//AddFuncionario();
    return 0;
}
