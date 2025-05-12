#include <stdio.h>

int main(){
    int tabuleiro[10][10] = {0};
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linha = 4, coluna = 5, tamanho = 3;

    // Posiciona um navio na diagonal principal 
    for (int i = 0; i < 10; i++) {
        tabuleiro[i][i] = 3;
    }
    // Posiciona um navio na diagonal secundaria 
    for (int i = 0; i < 10; i++) {
        tabuleiro[i][9 - i] = 3;
    }
    

      // 🔹 Navio horizontal 
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[0][4 + i] == 0) {
            tabuleiro[0][4 + i] = 3;
        }
    }

    // 🔸 Navio vertical
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[2 + i][9] == 0) {
            tabuleiro[2 + i][9] = 3;
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
