#include <stdio.h>

// Tamanho do tabuleiro
#define TAM 5

int main() {
    char tabuleiro[TAM][TAM];
    int linha, coluna;
    int acertos = 0;
    int total_navios = 3;
    
    // Inicializa o tabuleiro com água (~)
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';
        }
    }
    
    // Posiciona os navios (fixos)
    tabuleiro[1][1] = 'N';  // Navio 1
    tabuleiro[3][2] = 'N';  // Navio 2
    tabuleiro[4][4] = 'N';  // Navio 3
    
    printf("Bem-vindo ao Batalha Naval Simplificado!\n");
    printf("Tabuleiro 5x5 - Encontre os %d navios\n\n", total_navios);
    
    while(acertos < total_navios) {
        // Mostra o tabuleiro
        for(int i = 0; i < TAM; i++) {
            for(int j = 0; j < TAM; j++) {
                if(tabuleiro[i][j] == 'N') {
                    printf("~ ");  // Esconde os navios
                } else {
                    printf("%c ", tabuleiro[i][j]);
                }
            }
            printf("\n");
        }
        
        // Pede o palpite
        printf("\nDigite linha e coluna (0-4): ");
        scanf("%d %d", &linha, &coluna);
        
        // Verifica se acertou
        if(linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
            if(tabuleiro[linha][coluna] == 'N') {
                printf("Acertou um navio!\n");
                tabuleiro[linha][coluna] = 'X';
                acertos++;
            } else if(tabuleiro[linha][coluna] == '~') {
                printf("Agua!\n");
                tabuleiro[linha][coluna] = '.';
            } else {
                printf("Voce ja tentou aqui!\n");
            }
        } else {
            printf("Coordenadas invalidas!\n");
        }
    }
    
    printf("\nParabens! Voce afundou todos os navios!\n");
    
    // Mostra o tabuleiro final
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
