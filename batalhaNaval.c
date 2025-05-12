#include <stdio.h>

int main(){
    int tabuleiro[10][10] = {0};
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};


    // ==== Cruz (centro: linha 1, coluna 5) ====
    int cruz_linha = 1, cruz_coluna = 5;
    for (int i = -1; i <= 1; i++) {
        if (cruz_linha + i >= 0 && cruz_linha + i < 10)
            tabuleiro[cruz_linha + i][cruz_coluna] = 3;
        if (cruz_coluna + i >= 0 && cruz_coluna + i < 10)
            tabuleiro[cruz_linha][cruz_coluna + i] = 3;
    }

    // ==== Triângulo (topo: linha 4, coluna 2) ====
    int tri_linha = 4, tri_coluna = 2;
    for (int i = 0; i < 3; i++) { // linhas
        for (int j = 0; j < 5; j++) { // colunas
            if (j >= 2 - i && j <= 2 + i) { // formato de triângulo
                if (tri_linha + i < 10 && tri_coluna - 2 + j >= 0 && tri_coluna - 2 + j < 10)
                    tabuleiro[tri_linha + i][tri_coluna - 2 + j] = 3;
            }
        }
    }

    // ==== Losango (centro: linha 8, coluna 7) ====
    int los_linha = 8, los_coluna = 7;
    for (int i = -1; i <= 1; i++) { // linhas acima e abaixo
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 && (j == -1 || j == 0 || j == 1)) || (j == 0 && (i == -1 || i == 1))) {
                int l = los_linha + i;
                int c = los_coluna + j;
                if (l >= 0 && l < 10 && c >= 0 && c < 10)
                    tabuleiro[l][c] = 3;
            }
        }
    }


    // Imprime as letras das colunas
    printf("   "); // Espaço para alinhar com os números das linhas
    for (int i = 0; i < 10; i++) {
        printf(" %c", colunas[i]);
    }
    printf("\n");

    // Imprime o tabuleiro com números das linhas
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}