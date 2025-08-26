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

// Declara as variáveis das cartas no escopo global para que possam ser acessadas em qualquer parte do código.
struct Carta carta1, carta2;

// Função para cadastrar os dados de uma carta.
void cadastrarCarta(struct Carta *carta, int numeroDaCarta) {
    printf("\n--- Cadastro da Carta %d ---\n", numeroDaCarta);

    printf("Qual o Estado (Ex: BA)?\n");
    scanf("%s", carta->estado);

    printf("Qual o Codigo da Carta (Ex: A01)?\n");
    scanf("%s", carta->codigoDaCarta);
    
    printf("Qual o Codigo da Cidade?\n");
    scanf("%s", carta->codigoDaCidade);
    
    printf("Qual a Populacao?\n");
    scanf("%d", &carta->populacao);
    
    printf("Qual o PIB (R$)?\n");
    scanf("%f", &carta->pib);
    
    printf("Qual a Area (km²)?\n");
    scanf("%f", &carta->area);
    
    printf("Qual o Numero de pontos turisticos?\n");
    scanf("%d", &carta->numeroDePontosTuristicos);
}

// Função para exibir os dados de uma carta.
void exibirCarta(struct Carta carta, int numeroDaCarta) {
    printf("\n--- Dados da Carta %d ---\n", numeroDaCarta);
    printf("Estado: %s\n", carta.estado);
    printf("Codigo da Carta: %s\n", carta.codigoDaCarta);
    printf("Codigo da Cidade: %s\n", carta.codigoDaCidade);
    printf("Populacao: %d\n", carta.populacao);
    printf("PIB: %.2f\n", carta.pib);
    printf("Area: %.2f\n", carta.area);
    printf("Numero de pontos turisticos: %d\n", carta.numeroDePontosTuristicos);
    printf("------------------------\n");
}

int main() {
    int opcao;

    printf("Bem-vindo ao Super Trunfo!\n");

    // Loop principal do jogo.
    while (1) {
        // Chama as funções para cadastrar as cartas.
        cadastrarCarta(&carta1, 1);
        cadastrarCarta(&carta2, 2);

        // Exibe as cartas cadastradas.
        exibirCarta(carta1, 1);
        exibirCarta(carta2, 2);

        printf("Cadastro realizado com sucesso!\n");

        printf("\nO que você gostaria de fazer agora?\n");
        printf("1 - Ver o resultado do jogo (quem venceu)\n");
        printf("2 - Jogar novamente\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Aqui você pode adicionar a lógica para comparar as cartas e mostrar o resultado.
            // Por exemplo, você pode perguntar ao usuário qual característica ele quer comparar.
            printf("\n--- Comparando as cartas ---\n");
            printf("A lógica de comparação será implementada aqui no futuro.\n");
            // Adicione a lógica de comparação aqui.
        } else if (opcao == 2) {
            // O loop continua, permitindo um novo jogo.
            printf("\nIniciando um novo jogo...\n");
            continue;
        } else if (opcao == 3) {
            // O loop é interrompido e o programa termina.
            break;
        } else {
            printf("\nOpção inválida. Por favor, escolha 1, 2 ou 3.\n");
        }
    }

    printf("\nObrigado por jogar Super Trunfo!\n");
    printf("Até a próxima!\n");

    return 0;
}