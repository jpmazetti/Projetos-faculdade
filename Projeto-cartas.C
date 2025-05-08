#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 32  // 8 estados * 4 cidades cada

// Estrutura para armazenar as informações de uma cidade
typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular os valores derivados da carta
void calcularPropriedades(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos;
}

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("\nCadastro de nova carta:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    printf("Código da Carta (Ex: A01): ");
    scanf(" %s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nome);
    printf("População: ");
    scanf(" %d", &carta->populacao);
    printf("Área (km²): ");
    scanf(" %f", &carta->area);
    printf("PIB (bilhões R$): ");
    scanf(" %f", &carta->pib);
    printf("Número de Pontos Turísticos: ");
    scanf(" %d", &carta->pontos_turisticos);
    
    calcularPropriedades(carta);
}

// Função para exibir uma carta
void exibirCarta(Carta carta) {
    printf("\n------------------------------\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões R$\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per Capita: %.2f R$\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

// Função para comparar duas cartas
void compararCartas(Carta c1, Carta c2) {
    printf("\nComparação entre %s e %s:\n", c1.nome, c2.nome);
    
    printf("População: %s\n", (c1.populacao > c2.populacao) ? c1.nome : c2.nome);
    printf("Área: %s\n", (c1.area > c2.area) ? c1.nome : c2.nome);
    printf("PIB: %s\n", (c1.pib > c2.pib) ? c1.nome : c2.nome);
    printf("Pontos Turísticos: %s\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.nome : c2.nome);
    printf("Densidade Populacional: %s (Menor vence)\n", (c1.densidade_populacional < c2.densidade_populacional) ? c1.nome : c2.nome);
    printf("PIB per Capita: %s\n", (c1.pib_per_capita > c2.pib_per_capita) ? c1.nome : c2.nome);
    printf("Super Poder: %s (Maior vence)\n", (c1.super_poder > c2.super_poder) ? c1.nome : c2.nome);
}

int main() {
    Carta cartas[MAX_CARTAS];
    int num_cartas = 0;
    int opcao;
    
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar carta\n");
        printf("2. Exibir cartas cadastradas\n");
        printf("3. Comparar duas cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %d", &opcao);
        
        switch (opcao) {
            case 1:
                if (num_cartas < MAX_CARTAS) {
                    cadastrarCarta(&cartas[num_cartas]);
                    num_cartas++;
                } else {
                    printf("Limite máximo de cartas atingido!\n");
                }
                break;
            case 2:
                for (int i = 0; i < num_cartas; i++) {
                    exibirCarta(cartas[i]);
                }
                break;
            case 3:
                if (num_cartas < 2) {
                    printf("É necessário pelo menos duas cartas para comparar!\n");
                } else {
                    int i, j;
                    printf("Digite os índices das duas cartas para comparar (0-%d): ", num_cartas - 1);
                    scanf(" %d %d", &i, &j);
                    if (i >= 0 && i < num_cartas && j >= 0 && j < num_cartas && i != j) {
                        compararCartas(cartas[i], cartas[j]);
                    } else {
                        printf("Índices inválidos!\n");
                    }
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}