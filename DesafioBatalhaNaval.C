#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>  

// --- Protótipos das Funções ---
// A função exibirTabuleiro agora aceita um ponteiro para int,
// tornando-a compatível com matrizes de qualquer tamanho.
void exibirTabuleiro(int *tabuleiro, int tamanho, const char* titulo);
void batalhanavalNovato();
void batalhanavalAventureiro();
void batalhanavalMestre();
void aplicarHabilidadeCone(int tabuleiro[10][10], int linha, int coluna);
void aplicarHabilidadeOctaedro(int tabuleiro[10][10], int linha, int coluna);
void aplicarHabilidadeCruz(int tabuleiro[10][10], int linha, int coluna);

int main() {
    char continuarJogo;
    do {
        // A função main continua a mesma
        // pois a chamada para playGame() não precisa de alterações
        playGame();
        printf("\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &continuarJogo);
    } while (tolower(continuarJogo) == 's');

    printf("\nJogo finalizado, Obrigado por Jogar.\n");
    return 0;
}

// --- Funções Principais de Jogo ---

void playGame() {
    printf("---Desafio Batalha Naval ---\n");
    printf("Escolha o nivel de dificuldade:\n");
    printf("1 - Novato (Tabuleiro 5x5, Posicionamento)\n");
    printf("2 - Aventureiro (Tabuleiro 10x10, Navios Diagonais)\n");
    printf("3 - Mestre (Tabuleiro 10x10, Habilidades Especiais)\n");

    int nivel;
    do {
        printf("Escolha o nivel (1, 2 ou 3): ");
        scanf("%d", &nivel);
        if (nivel < 1 || nivel > 3) {
            printf("Escolha invalida. Por favor, digite 1, 2 ou 3.\n");
        }
    } while (nivel < 1 || nivel > 3);

    switch (nivel) {
        case 1:
            batalhanavalNovato();
            break;
        case 2:
            batalhanavalAventureiro();
            break;
        case 3:
            batalhanavalMestre();
            break;
    }
}

// --- Implementações dos Níveis ---

void batalhanavalNovato() {
    printf("\n--- Nivel Novato ---\n");
    int tabuleiro[5][5] = {0}; 

    int linha_navio_h = 2;
    int col_navio_h = 1;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_navio_h][col_navio_h + i] = 3;
        printf("Navio Horizontal posicionado em: (%d, %d)\n", linha_navio_h, col_navio_h + i);
    }

    int linha_navio_v = 0;
    int col_navio_v = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_navio_v + i][col_navio_v] = 3;
        printf("Navio Vertical posicionado em: (%d, %d)\n", linha_navio_v + i, col_navio_v);
    }

    printf("\n--- Resultados do Jogo ---\n");
    // A chamada agora passa o endereço da matriz, que é compatível com o ponteiro
    exibirTabuleiro((int *)tabuleiro, 5, "Tabuleiro com Navios");
}

void batalhanavalAventureiro() {
    printf("\n--- Nivel Aventureiro ---\n");
    int tabuleiro[10][10] = {0}; 

    for (int i = 0; i < 4; i++) {
        tabuleiro[3][1 + i] = 3;
    }

    for (int i = 0; i < 4; i++) {
        tabuleiro[1 + i][8] = 3;
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[1 + i][1 + i] = 3; 
        tabuleiro[7 - i][2 + i] = 3; 
    }

    printf("\n--- Resultados do Jogo ---\n");
    exibirTabuleiro((int *)tabuleiro, 10, "Tabuleiro com 4 Navios");
}

void batalhanavalMestre() {
    printf("\n--- Nivel Mestre ---\n");
    int tabuleiro[10][10] = {0}; 

    int linha, coluna;
    printf("Digite as coordenadas (linha e coluna) para as habilidades (0-9).\n");

    printf("Habilidade CONE: Digite a linha e a coluna do centro: ");
    scanf("%d %d", &linha, &coluna);
    aplicarHabilidadeCone(tabuleiro, linha, coluna);
    exibirTabuleiro((int *)tabuleiro, 10, "Habilidade CONE ativada (1 = area atingida)");

    for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) tabuleiro[i][j] = 0;

    printf("\nHabilidade OCTAEDRO: Digite a linha e a coluna do centro: ");
    scanf("%d %d", &linha, &coluna);
    aplicarHabilidadeOctaedro(tabuleiro, linha, coluna);
    exibirTabuleiro((int *)tabuleiro, 10, "Habilidade OCTAEDRO ativada (1 = area atingida)");

    for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) tabuleiro[i][j] = 0;

    printf("\nHabilidade CRUZ: Digite a linha e a coluna do centro: ");
    scanf("%d %d", &linha, &coluna);
    aplicarHabilidadeCruz(tabuleiro, linha, coluna);
    exibirTabuleiro((int *)tabuleiro, 10, "Habilidade CRUZ ativada (1 = area atingida)");
}

// --- Funções de Habilidades Especiais (Nível Mestre) ---

void aplicarHabilidadeCone(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i >= linha && (abs(j - coluna) <= (i - linha))) {
                tabuleiro[i][j] = 1;
            }
        }
    }
}

void aplicarHabilidadeOctaedro(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (abs(i - linha) + abs(j - coluna) <= 2) {
                tabuleiro[i][j] = 1;
            }
        }
    }
}

void aplicarHabilidadeCruz(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < 10; i++) {
        tabuleiro[linha][i] = 1;
        tabuleiro[i][coluna] = 1;
    }
}

// --- Função Auxiliar para Exibir o Tabuleiro (CORRIGIDA) ---

void exibirTabuleiro(int *tabuleiro, int tamanho, const char* titulo) {
    printf("\n%s\n", titulo);
    printf("  ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", i); 
        for (int j = 0; j < tamanho; j++) {
            // Acesso ao elemento da matriz via aritmética de ponteiros
            printf("%d ", *(tabuleiro + i * tamanho + j));
        }
        printf("\n");
    }
}