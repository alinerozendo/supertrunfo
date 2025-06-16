#include <stdio.h>

int main() {
    // ---------- CARTA 1 ----------
    // criando as variáveis para cada atributo da cidade
    char estado[50], codigo_da_cidade[50], nome_da_cidade[50];
    unsigned long int populacao;
    float area, pib;
    int pontos_turisticos;
    float densidade_populacional, pib_per_capita, super_poder;

    // pedindo ao usuário as informações de cada atributo da cidade
    printf("Carta 1: \n");
    printf("Estado: ");
    scanf("%s", estado);
    printf("Código: ");
    scanf("%s", codigo_da_cidade);
    printf("Nome da Cidade: ");
    scanf("%s", nome_da_cidade);
    printf("População: ");
    scanf("%lu", &populacao);
    printf("Área (km²): ");
    scanf("%f", &area);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos);

    densidade_populacional = populacao / area; // definindo a regra da densidade populacional
    pib_per_capita = pib / populacao; // definindo a regra do pib per capita
    super_poder = (float)populacao + area + pib + (float)pontos_turisticos + pib_per_capita + ((float)1 / densidade_populacional); // defindo a regra do super poder (soma de todos os atributos da cidade exceto estado, código e nome)

    // ---------- CARTA 2 ----------
    // criando as variáveis para cada atributo da cidade
    char estado2[50], codigo_da_cidade2[50], nome_da_cidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos_turisticos2;
    float densidade_populacional2, pib_per_capita2, super_poder2;

    // pedindo ao usuário as informações de cada atributo da cidade
    printf("\nCarta 2: \n");
    printf("Estado: ");
    scanf("%s", estado2);
    printf("Código: ");
    scanf("%s", codigo_da_cidade2);
    printf("Nome da Cidade: ");
    scanf("%s", nome_da_cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    densidade_populacional2 = populacao2 / area2; // definindo a regra da densidade populacional
    pib_per_capita2 = pib2 / populacao2; // definindo a regra do pib per capita
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos_turisticos2 + pib_per_capita2 + ((float)1 / densidade_populacional2); // defindo a regra do super poder (soma de todos os atributos da cidade exceto estado, código e nome)

    // exibindo as cartas
    printf("\n\n----------- DADOS DAS CARTAS -----------\n");

    printf("\nCARTA 1\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codigo_da_cidade);
    printf("Nome: %s\n", nome_da_cidade);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Pontos Turísticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita);
    printf("Super Poder: %.2f\n", super_poder);

    printf("\nCARTA 2\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo_da_cidade2);
    printf("Nome: %s\n", nome_da_cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    printf("\n\n----------- COMPARAÇÃO DAS CARTAS -----------\n");

    int venceu;  //declarando uma variável para armazenar o resultado da comparação dos atributos

    // comparando os atributos das cartas
    // (1 para verdadeiro – Carta 1 vence – e 0 para falso – Carta 2 vence)
    venceu = populacao > populacao2;
    printf("População: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = area > area2;
    printf("Área: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = pib > pib2;
    printf("PIB: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = pontos_turisticos > pontos_turisticos2;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = densidade_populacional < densidade_populacional2;
    printf("Densidade Populacional (menor vence): Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = pib_per_capita > pib_per_capita2;
    printf("PIB per Capita: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = super_poder > super_poder2;
    printf("Super Poder: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    return 0;
}