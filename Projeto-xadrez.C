#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 8

// Estrutura para representar uma posição no tabuleiro
typedef struct {
    int x, y;
} Posicao;

// Função para exibir o tabuleiro com a peça na posição atual
void exibirTabuleiro(Posicao p) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == p.x && j == p.y)
                printf(" P "); // Peça
            else
                printf(" . "); // Espaço vazio
        }
        printf("\n");
    }
    printf("\n");
}

// Função para verificar se a posição está dentro do tabuleiro
int posicaoValida(int x, int y) {
    return (x >= 0 && x < TAM && y >= 0 && y < TAM);
}

// Função para mover a Torre
void moverTorre(Posicao *p, int dx, int dy) {
    if (dx == 0 || dy == 0) {
        if (posicaoValida(p->x + dx, p->y + dy)) {
            p->x += dx;
            p->y += dy;
        } else {
            printf("Movimento inválido!\n");
        }
    } else {
        printf("Movimento inválido para a Torre!\n");
    }
}

// Função para mover o Bispo
void moverBispo(Posicao *p, int dx, int dy) {
    if (abs(dx) == abs(dy)) {
        if (posicaoValida(p->x + dx, p->y + dy)) {
            p->x += dx;
            p->y += dy;
        } else {
            printf("Movimento inválido!\n");
        }
    } else {
        printf("Movimento inválido para o Bispo!\n");
    }
}

// Função para mover a Rainha
void moverRainha(Posicao *p, int dx, int dy) {
    if (dx == 0 || dy == 0 || abs(dx) == abs(dy)) {
        if (posicaoValida(p->x + dx, p->y + dy)) {
            p->x += dx;
            p->y += dy;
        } else {
            printf("Movimento inválido!\n");
        }
    } else {
        printf("Movimento inválido para a Rainha!\n");
    }
}

// Função para mover o Cavalo
void moverCavalo(Posicao *p, int dx, int dy) {
    if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) {
        if (posicaoValida(p->x + dx, p->y + dy)) {
            p->x += dx;
            p->y += dy;
        } else {
            printf("Movimento inválido!\n");
        }
    } else {
        printf("Movimento inválido para o Cavalo!\n");
    }
}

int main() {
    Posicao p = {0, 0}; // Peça começa no canto superior esquerdo
    char escolha;
    int dx, dy;

    printf("Bem-vindo ao Xadrez Programável!\n");
    while (1) {
        printf("\nTabuleiro virtual\n");
        exibirTabuleiro(p);
        printf("Escolha uma peça (T - Torre, B - Bispo, R - Rainha, C - Cavalo, D - Dica, S - Sair): ");
        scanf(" %c", &escolha);
        escolha = toupper(escolha);
        
        if (escolha == 'S') {
            printf("Jogo encerrado.\n");
            break;
        }

        if (escolha == 'D') {
            printf("\nA Torre se movimenta apenas verticalmente e longitunalmente e sem limite de casas.\n");
            printf("A Rainha se movimenta para todos os lados e sem limite de casas.\n");
            printf("O Bispo se movimenta apenas na diagonal e sem limite de casas.\n");
            printf("O Cavalo se movimenta apenas em L.\n");
            printf("O 'dx' representa a altura e o 'dy' representa a distancia lateral.\n");
            printf("Para se movimentar para trás basta colocar um número negativo (Exemplo: -2 -2).\n");
        }
        if (escolha != 'D'){
            printf("Digite o movimento (dx dy): \n");
            scanf("%d %d", &dx, &dy);
        }

        switch (escolha) {
            case 'T': moverTorre(&p, dx, dy); break;
            case 'B': moverBispo(&p, dx, dy); break;
            case 'R': moverRainha(&p, dx, dy); break;
            case 'C': moverCavalo(&p, dx, dy); break;
            default: printf("\nJogue novamente!\n\n"); break;
        }
    }
    return 0;
}