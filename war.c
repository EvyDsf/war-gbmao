//        
// ============================================================================
//
#include <stdio.h>
#include <string.h>
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
@@ -21,9 +23,15 @@

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct territory {
    char name[50];
    char color[50];
    int troops;
} territory; 

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
territory addTerritory();
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
@@ -37,6 +45,21 @@ int main() {
// - Inicializa a semente para geração de números aleatórios com base no tempo atual.
// - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
// - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    territory map[5];

    for (int i = 0; i < 5; i++)
    {
        printf("\n\n--- Cadastrando Territorio %d ---", i + 1);
        map[i] = addTerritory();
    }


    for (int i = 0; i < 5; i++)
    {
        printf("\nTERRITORIO %d:\n- Nome: %s\n- Controlado por: %s\n- Tropas: %d",i +1, map[i].name, map[i].color, map[i].troops);
    }
    

// - Define a cor do jogador e sorteia sua missão secreta.

// 2. Laço Principal do Jogo (Game Loop):
@@ -63,6 +86,22 @@ int main() {
// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).
territory addTerritory() {
    territory t;

    printf("\n\nDigite o nome do território: ");
    scanf("%s", t.name);

    printf("Digite a cor do território: ");
    scanf("%s", t.color);

    printf("Digite o número de tropas: ");
    scanf("%d", &t.troops);

    printf("\nVocê adicionou:");
    printf("\nTerritório: %s, Controlado por: %s, Total de tropas: %d", t.name, t.color, t.troops);
    return t;
}

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.