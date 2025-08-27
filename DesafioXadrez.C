#include <stdio.h>
#include <ctype.h>

#define TAMANHO_TABULEIRO 8

// --- Protótipos das Funções de Movimentação ---
void moverBispo(int linha, int coluna);
void moverCavalo(int linha, int coluna);
void moverRainha(int linha, int coluna);
void moverBispoRecursivo(int linha, int coluna, int dir_linha, int dir_coluna);

// --- Função Principal do Jogo ---
void playGame();

int main() {
    char continueGame;

    do {
        playGame();
        printf("\n\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &continueGame);
    } while (tolower(continueGame) == 's');

    printf("\nObrigado por jogar! O jogo foi finalizado.\n");
    return 0;
}

// --- Funções de Jogo ---

void playGame() {
    printf("--- MateCheck - Desafio de Xadrez ---\n");
    printf("Bem-vindo! Escolha o nivel de dificuldade:\n");
    printf("1 - Novato (Movimentacao do Bispo)\n");
    printf("2 - Aventureiro (Movimentacao do Cavalo)\n");
    printf("3 - Mestre (Movimentacao da Rainha)\n");

    int nivel;
    int linha, coluna;

    // Loop para garantir uma escolha de nível válida
    do {
        printf("Escolha o nivel (1, 2 ou 3): ");
        scanf("%d", &nivel);
        if (nivel < 1 || nivel > 3) {
            printf("Escolha invalida. Por favor, digite 1, 2 ou 3.\n");
        }
    } while (nivel < 1 || nivel > 3);

    // Pede a posição inicial da peça para todos os níveis
    printf("\nDigite a linha inicial da peca (0 a 7): ");
    scanf("%d", &linha);
    printf("Digite a coluna inicial da peca (0 a 7): ");
    scanf("%d", &coluna);
    
    printf("\n");

    // Usa um switch para chamar a funcao de acordo com o nivel escolhido
    switch (nivel) {
        case 1:
            printf("--- Nivel Novato: Movimentacao do Bispo ---\n");
            moverBispo(linha, coluna);
            break;
        case 2:
            printf("--- Nivel Aventureiro: Movimentacao do Cavalo ---\n");
            moverCavalo(linha, coluna);
            break;
        case 3:
            printf("--- Nivel Mestre: Movimentacao da Rainha ---\n");
            moverRainha(linha, coluna);
            break;
    }
}

// --- Implementacoes das Funcoes de Movimentacao ---

// Nível Novato
void moverBispo(int linha, int coluna) {
    printf("Movimentacao do Bispo a partir de (%d, %d):\n", linha, coluna);
    for (int i = 1; i < TAMANHO_TABULEIRO; i++) {
        if (linha + i < TAMANHO_TABULEIRO && coluna + i < TAMANHO_TABULEIRO) {
            printf("  -> (%d, %d) [superior-direita]\n", linha + i, coluna + i);
        }
        if (linha + i < TAMANHO_TABULEIRO && coluna - i >= 0) {
            printf("  -> (%d, %d) [superior-esquerda]\n", linha + i, coluna - i);
        }
        if (linha - i >= 0 && coluna + i < TAMANHO_TABULEIRO) {
            printf("  -> (%d, %d) [inferior-direita]\n", linha - i, coluna + i);
        }
        if (linha - i >= 0 && coluna - i >= 0) {
            printf("  -> (%d, %d) [inferior-esquerda]\n", linha - i, coluna - i);
        }
    }
}

// Nível Aventureiro
void moverCavalo(int linha, int coluna) {
    printf("Movimentacao do Cavalo a partir de (%d, %d):\n", linha, coluna);
    int movimentos_x[] = {1, 1, 2, 2, -1, -1, -2, -2};
    int movimentos_y[] = {2, -2, 1, -1, 2, -2, 1, -1};

    for (int i = 0; i < 8; i++) {
        int nova_linha = linha + movimentos_x[i];
        int nova_coluna = coluna + movimentos_y[i];

        if (nova_linha >= 0 && nova_linha < TAMANHO_TABULEIRO &&
            nova_coluna >= 0 && nova_coluna < TAMANHO_TABULEIRO) {
            printf("  -> (%d, %d)\n", nova_linha, nova_coluna);
        }
    }
}

// Nível Mestre
void moverRainha(int linha, int coluna) {
    printf("Movimentacao da Rainha a partir de (%d, %d):\n", linha, coluna);

    printf("\n  - Diagonais (usando recursao):\n");
    moverBispoRecursivo(linha + 1, coluna + 1, 1, 1);
    moverBispoRecursivo(linha - 1, coluna - 1, -1, -1);
    moverBispoRecursivo(linha + 1, coluna - 1, 1, -1);
    moverBispoRecursivo(linha - 1, coluna + 1, -1, 1);

    printf("\n  - Retos (usando loops):\n");
    // Movimento para a direita
    for (int i = coluna + 1; i < TAMANHO_TABULEIRO; i++) {
        printf("  -> (%d, %d)\n", linha, i);
    }
    // Movimento para a esquerda
    for (int i = coluna - 1; i >= 0; i--) {
        printf("  -> (%d, %d)\n", linha, i);
    }
    // Movimento para cima
    for (int i = linha - 1; i >= 0; i--) {
        printf("  -> (%d, %d)\n", i, coluna);
    }
    // Movimento para baixo
    for (int i = linha + 1; i < TAMANHO_TABULEIRO; i++) {
        printf("  -> (%d, %d)\n", i, coluna);
    }
}

void moverBispoRecursivo(int linha, int coluna, int dir_linha, int dir_coluna) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO ||
        coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return;
    }
    printf("  -> (%d, %d)\n", linha, coluna);
    moverBispoRecursivo(linha + dir_linha, coluna + dir_coluna, dir_linha, dir_coluna);
}