#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
// Declaração e inicialização da matriz do tabuleiro (10x10) com zeros (água)
int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

// Coordenadas iniciais e orientações definidas diretamente no código
// Navio 1 (Horizontal): Começa na linha 2, coluna 3
int linhaNavio1 = 2;
int colunaNavio1 = 3;
                        
// Navio 2 (Vertical): Começa na linha 5, coluna 7
int linhaNavio2 = 5;
int colunaNavio2 = 7;

// --- POSICIONAMENTO DO NAVIO 1 (HORIZONTAL) ---
// Validação básica: verifica se cabe no tabuleiro sem ultrapassar os limites
if (colunaNavio1 + TAM_NAVIO <= TAM_TABULEIRO) {
for (int i = 0; i < TAM_NAVIO; i++) {
tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
}
} else {
printf("Erro: O Navio 1 ultrapassa os limites do tabuleiro!\n");
}

// --- POSICIONAMENTO DO NAVIO 2 (VERTICAL) ---
// Validação básica: verifica se cabe no tabuleiro e se não sobrepõe o Navio 1
if (linhaNavio2 + TAM_NAVIO <= TAM_TABULEIRO) {
for (int i = 0; i < TAM_NAVIO; i++) {
// Verificação de segurança simplificada para evitar sobreposição
if (tabuleiro[linhaNavio2 + i][colunaNavio2] == 0) {
tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
} else {
printf("Erro: Sobreposição detectada na posição [%d][%d]!\n", linhaNavio2 + i, colunaNavio2);
}
}
} else {
printf("Erro: O Navio 2 ultrapassa os limites do tabuleiro!\n");
}

// --- EXIBIÇÃO DO TABULEIRO ---
printf("Tabuleiro de Batalha Naval:\n\n");
                                                                                                                                                                                                                                    
// Imprime o cabeçalho das colunas (0 a 9)
printf("  ");
for (int c = 0; c < TAM_TABULEIRO; c++) {
printf("%d ", c);
}
printf("\n");

// Loops aninhados para percorrer as linhas e colunas da matriz
for (int i = 0; i < TAM_TABULEIRO; i++) {
// Imprime o número da linha
printf("%d ", i);
                                                                                                                                                                                                                                                                                                
for (int j = 0; j < TAM_TABULEIRO; j++) {
// Exibe o valor na coordenada atual
printf("%d ", tabuleiro[i][j]);
}
// Pula para a próxima linha após imprimir todas as colunas
printf("\n");
}
    
return 0;
}
