#include <stdio.h>

// Tamanhos fixos
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Valores de exibição
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Definir alguns navios como exemplo
    tabuleiro[2][3] = NAVIO;
    tabuleiro[4][4] = NAVIO;
    tabuleiro[7][6] = NAVIO;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf("~ ");  // Água
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N ");  // Navio
            } else if (tabuleiro[i][j] == HABILIDADE) {
                printf("* ");  // Área da habilidade
            } else {
                printf("? ");  // Outro (fallback)
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Função para criar matriz Cone (forma de triângulo apontando para baixo)
void criarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Condição: quanto mais embaixo, mais largo
            if (j >= (TAM_HABILIDADE / 2) - i && j <= (TAM_HABILIDADE / 2) + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz Cruz
void criarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz Octaedro (losango)
void criarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para aplicar uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                        int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                        int origemLinha, int origemColuna) {
    int centro = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha + (i - centro);
                int coluna = origemColuna + (j - centro);

                // Verificar limites do tabuleiro
                if (linha >= 0 && linha < TAM_TABULEIRO &&
                    coluna >= 0 && coluna < TAM_TABULEIRO) {
                    if (tabuleiro[linha][coluna] == AGUA) {
                        tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// ========================= Programa Principal =============================
int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializar tabuleiro com água e navios
    inicializarTabuleiro(tabuleiro);

    // Criar matrizes de habilidade
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // ========================= Tabuleiro Inicial =========================
    printf("\n=== Tabuleiro Inicial ===\n");
    exibirTabuleiro(tabuleiro);

    // ========================= Cone =========================
    aplicarHabilidade(tabuleiro, cone, 2, 2); // Ponto de origem linha 2, coluna 2
    printf("=== Após aplicar Cone ===\n");
    exibirTabuleiro(tabuleiro);

    // ========================= Cruz =========================
    aplicarHabilidade(tabuleiro, cruz, 5, 5); // Ponto de origem linha 5, coluna 5
    printf("=== Após aplicar Cruz ===\n");
    exibirTabuleiro(tabuleiro);

    // ========================= Octaedro =========================
    aplicarHabilidade(tabuleiro, octaedro, 7, 7); // Ponto de origem linha 7, coluna 7
    printf("=== Após aplicar Octaedro ===\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
