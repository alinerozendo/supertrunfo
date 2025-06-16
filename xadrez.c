#include <stdio.h>

// =================== Torre (Recursiva) ===================
void moverTorreCima(int casas) {
    if (casas == 0) return;
    printf("Cima\n");
    moverTorreCima(casas - 1);
}

void moverTorreDireita(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorreDireita(casas - 1);
}

// =================== Bispo (Recursiva + Loops Aninhados) ===================
void moverBispo(int vertical, int horizontal) {
    if (vertical == 0 || horizontal == 0) return;
    printf("Diagonal: Cima Direita\n");
    moverBispo(vertical - 1, horizontal - 1);
}

void moverBispoLoops(int maxVertical, int maxHorizontal) {
    for (int i = 1; i <= maxVertical; i++) {
        for (int j = 1; j <= maxHorizontal; j++) {
            if (i == j) {
                printf("Diagonal: Cima Direita (%d, %d)\n", i, j);
            }
        }
    }
}

// =================== Rainha (Recursiva) ===================
void moverRainhaCima(int casas) {
    if (casas == 0) return;
    printf("Cima\n");
    moverRainhaCima(casas - 1);
}

void moverRainhaDireita(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverRainhaDireita(casas - 1);
}

void moverRainhaDiagonal(int casas) {
    if (casas == 0) return;
    printf("Diagonal: Cima Direita\n");
    moverRainhaDiagonal(casas - 1);
}

// =================== Cavalo (Loops Aninhados) ===================
void moverCavalo() {
    printf("Movimento do Cavalo:\n");
    for (int vertical = 2; vertical <= 2; vertical++) {   // Sempre sobe 2
        for (int horizontal = 1; horizontal <= 1; horizontal++) {  // Sempre anda 1 para direita
            if (vertical == 2 && horizontal == 1) {
                printf("Cima Cima Direita\n");
                continue;
            }
        }
    }
    printf("Movimento concluido.\n");
}

// =================== Função principal ===================
int main() {
    // Quantidade de casas para cada movimento
    int casasTorre = 3;
    int casasRainha = 2;
    int casasBispo = 2;
    
    // ================= Torre =================
    printf("\n=== Movimento da Torre ===\n");
    moverTorreCima(casasTorre);
    moverTorreDireita(casasTorre);

    // ================= Bispo =================
    printf("\n=== Movimento do Bispo (Recursivo) ===\n");
    moverBispo(casasBispo, casasBispo);

    printf("\n=== Movimento do Bispo (Loops Aninhados) ===\n");
    moverBispoLoops(casasBispo, casasBispo);

    // ================= Rainha =================
    printf("\n=== Movimento da Rainha ===\n");
    moverRainhaCima(casasRainha);
    moverRainhaDireita(casasRainha);
    moverRainhaDiagonal(casasRainha);

    // ================= Cavalo =================
    printf("\n=== Movimento do Cavalo ===\n");
    moverCavalo();

    printf("\n=== Fim dos movimentos ===\n");
    return 0;
}
