#include <iostream>
#include <stdio.h>

using namespace std;

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define ACERTO 1
#define ERRO 2

int main() {

    int tabuleiro[TAM][TAM];

    // Inicializa tabuleiro
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navios fixos
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    tabuleiro[2][6] = NAVIO;

    tabuleiro[5][1] = NAVIO;
    tabuleiro[6][1] = NAVIO;
    tabuleiro[7][1] = NAVIO;

    tabuleiro[0][0] = NAVIO;
    tabuleiro[1][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;

    tabuleiro[0][9] = NAVIO;
    tabuleiro[1][8] = NAVIO;
    tabuleiro[2][7] = NAVIO;

    int linha, coluna;
    int naviosRestantes = 12;

    while (naviosRestantes > 0) {

        // Mostrar tabuleiro
        printf("\nTABULEIRO\n\n");

        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {

                if (tabuleiro[i][j] == AGUA || tabuleiro[i][j] == NAVIO)
                    printf("~ ");

                else if (tabuleiro[i][j] == ACERTO)
                    printf("X ");

                else if (tabuleiro[i][j] == ERRO)
                    printf("O ");
            }
            printf("\n");
        }

        printf("\nNavios restantes: %d\n", naviosRestantes);

        // Jogada
        printf("\nDigite a linha (0-9): ");
        cin >> linha;

        printf("Digite a coluna (0-9): ");
        cin >> coluna;

        // Verifica limites
        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("Posicao invalida!\n");
            continue;
        }

        // Verifica acerto
        if (tabuleiro[linha][coluna] == NAVIO) {

            printf("?? ACERTOU UM NAVIO!\n");

            tabuleiro[linha][coluna] = ACERTO;
            naviosRestantes--;

        } else if (tabuleiro[linha][coluna] == AGUA) {

            printf("?? AGUA!\n");

            tabuleiro[linha][coluna] = ERRO;

        } else {

            printf("Voce ja atirou aqui!\n");

        }
    }

    printf("\n?? PARABENS! Voce destruiu todos os navios!\n");

    return 0;
}
