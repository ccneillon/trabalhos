#include <stdio.h>
#include <string.h>

// Define uma estrutura para organizar os dados de uma carta.
struct Carta {
    char estado[3];
    char codigoDaCarta[10];
    char codigoDaCidade[50];
    int populacao;
    float pib;
    float area;
    int numeroDePontosTuristicos;
};

int main() {
    struct Carta carta1, carta2;
    int escolha;
    char continuar_jogando = 's'; // Variável para controlar o loop, 's' para sim.

    printf("Bem-vindo ao Super Trunfo!\n");

    // Loop principal do jogo. Ele continuará enquanto o usuário digitar 's' ou 'S'.
    while (continuar_jogando == 's' || continuar_jogando == 'S') {

        // --- Cadastro da Carta 1 ---
        printf("\n--- Cadastro da Carta 1 ---\n");
        printf("Qual o Estado (Ex: BA)?\n");
        scanf("%s", carta1.estado);
        printf("Qual o Codigo da Carta (Ex: A01)?\n");
        scanf("%s", carta1.codigoDaCarta);
        printf("Qual o Codigo da Cidade?\n");
        scanf("%s", carta1.codigoDaCidade);
        printf("Qual a Populacao?\n");
        scanf("%d", &carta1.populacao);
        printf("Qual o PIB (R$)?\n");
        scanf("%f", &carta1.pib);
        printf("Qual a Area (km²)?\n");
        scanf("%f", &carta1.area);
        printf("Qual o Numero de pontos turisticos?\n");
        scanf("%d", &carta1.numeroDePontosTuristicos);

        // --- Cadastro da Carta 2 ---
        printf("\n--- Cadastro da Carta 2 ---\n");
        printf("Qual o Estado (Ex: SP)?\n");
        scanf("%s", carta2.estado);
        printf("Qual o Codigo da Carta (Ex: B02)?\n");
        scanf("%s", carta2.codigoDaCarta);
        printf("Qual o Codigo da Cidade?\n");
        scanf("%s", carta2.codigoDaCidade);
        printf("Qual a Populacao?\n");
        scanf("%d", &carta2.populacao);
        printf("Qual o PIB (R$)?\n");
        scanf("%f", &carta2.pib);
        printf("Qual a Area (km²)?\n");
        scanf("%f", &carta2.area);
        printf("Qual o Numero de pontos turisticos?\n");
        scanf("%d", &carta2.numeroDePontosTuristicos);

        // --- Exibição das Cartas e Lógica de Comparação ---
        printf("\n--- Dados da Carta 1 ---\n");
        printf("Estado: %s\n", carta1.estado);
        printf("Codigo da Carta: %s\n", carta1.codigoDaCarta);
        printf("Codigo da Cidade: %s\n", carta1.codigoDaCidade);
        printf("1. Populacao: %d\n", carta1.populacao);
        printf("2. PIB: %.2f\n", carta1.pib);
        printf("3. Area: %.2f\n", carta1.area);
        printf("4. Numero de pontos turisticos: %d\n", carta1.numeroDePontosTuristicos);
        printf("\n------------------------\n");

        printf("\n--- Dados da Carta 2 ---\n");
        printf("Estado: %s\n", carta2.estado);
        printf("Codigo da Carta: %s\n", carta2.codigoDaCarta);
        printf("Codigo da Cidade: %s\n", carta2.codigoDaCidade);
        printf("1. Populacao: %d\n", carta2.populacao);
        printf("2. PIB: %.2f\n", carta2.pib);
        printf("3. Area: %.2f\n", carta2.area);
        printf("4. Numero de pontos turisticos: %d\n", carta2.numeroDePontosTuristicos);
        printf("------------------------\n");

        printf("\nEscolha o atributo para a comparacao:\n");
        printf("1. Populacao\n");
        printf("2. PIB\n");
        printf("3. Area\n");
        printf("4. Numero de Pontos Turisticos\n");
        printf("Digite o numero do atributo: ");
        scanf("%d", &escolha);

        printf("\n--- Resultado da Comparacao ---\n");

        switch (escolha) {
            case 1:
                if (carta1.populacao > carta2.populacao) {
                    printf("Carta 1 (%s) venceu com o atributo Populacao!\n", carta1.codigoDaCarta);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("Carta 2 (%s) venceu com o atributo Populacao!\n", carta2.codigoDaCarta);
                } else {
                    printf("Empate no atributo Populacao!\n");
                }
                break;
            case 2:
                if (carta1.pib > carta2.pib) {
                    printf("Carta 1 (%s) venceu com o atributo PIB!\n", carta1.codigoDaCarta);
                } else if (carta2.pib > carta1.pib) {
                    printf("Carta 2 (%s) venceu com o atributo PIB!\n", carta2.codigoDaCarta);
                } else {
                    printf("Empate no atributo PIB!\n");
                }
                break;
            case 3:
                if (carta1.area > carta2.area) {
                    printf("Carta 1 (%s) venceu com o atributo Area!\n", carta1.codigoDaCarta);
                } else if (carta2.area > carta1.area) {
                    printf("Carta 2 (%s) venceu com o atributo Area!\n", carta2.codigoDaCarta);
                } else {
                    printf("Empate no atributo Area!\n");
                }
                break;
            case 4:
                if (carta1.numeroDePontosTuristicos > carta2.numeroDePontosTuristicos) {
                    printf("Carta 1 (%s) venceu com o atributo Pontos Turisticos!\n", carta1.codigoDaCarta);
                } else if (carta2.numeroDePontosTuristicos > carta1.numeroDePontosTuristicos) {
                    printf("Carta 2 (%s) venceu com o atributo Pontos Turisticos!\n", carta2.codigoDaCarta);
                } else {
                    printf("Empate no atributo Pontos Turisticos!\n");
                }
                break;
            default:
                printf("Opcao invalida. A comparacao nao pode ser realizada.\n");
                break;
        }

        // --- Pergunta ao usuário se ele quer continuar ---
        printf("\nObrigado por jogar Super Trunfo!\n");
        printf("Deseja jogar novamente? (S/N): ");
        scanf(" %c", &continuar_jogando);
    }

    printf("\nAté a próxima!\n");

    return 0;
}