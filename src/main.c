#include <stdio.h>
#include <../include/funcoes.h>

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
                } else if(entidade == 3){
                    addEntrega();
                } else if(entidade == 4) {
                    addCliente();
                } else {
                    printf("Opção inválida!\n");
                }
                break;

            case 2:
                printf("\nEscolha a entidade para visualizar:\n");
                printf("1 - Veículo\n2 - Funcionário\n3 - Entrega\n4 - Cliente\n");
                scanf("%d", &entidade);
                if (entidade == 1) {
                    visualizarVeiculo();
                } else if (entidade == 2) {
                    visualizarFuncionario();
                } else if(entidade == 3){
                    visualizarEntrega();
                } else if(entidade == 4) {
                    visualizarCliente();
                } else {
                    printf("Opção inválida!\n");
                }
                break;
                break;
            case 3:
                printf("\nEscolha a entidade para editar:\n");
                printf("1 - Veículo\n2 - Funcionário\n3 - Entrega\n4 - Cliente\n");
                scanf("%d", &entidade);
                if (entidade == 1) {
                    editarVeiculo();
                } else if (entidade == 2) {
                    editarFuncionario();
                } else if(entidade == 3){
                    editarEntrega();
                } else if(entidade == 4) {
                    editarCliente();
                } else {
                    printf("Opção inválida!\n");
                }
                break;
            case 4:
                printf("\nEscolha a entidade para excluir:\n");
                printf("1 - Veículo\n2 - Funcionário\n3 - Entrega\n4 - Cliente\n");
                scanf("%d", &entidade);
                if (entidade == 1) {
                    excluirVeiculo();
                } else if (entidade == 2) {
                    excluirFuncionario();
                } else if(entidade == 3){
                    excluirEntrega();
                } else if(entidade == 4) {
                    excluirCliente();
                } else {
                    printf("Opção inválida!\n");
                }
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
    return 0;
}
