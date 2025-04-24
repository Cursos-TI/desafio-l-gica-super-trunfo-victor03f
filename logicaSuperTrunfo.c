#include <stdio.h>

int escolherAtributo(const char* ordem) {
    int opcao;
    printf("\n📊 Escolha o %s atributo para comparação:\n", ordem);
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per Capita\n");
    printf("Opção (1-6): ");
    scanf("%d", &opcao);
    return opcao;
}

int compararAtributo(int opcao, unsigned long int p1, unsigned long int p2, float a1, float a2,
                     float pib1, float pib2, int pt1, int pt2, float dens1, float dens2, float ppc1, float ppc2) {
    switch (opcao) {
        case 1: return (p1 > p2) ? 1 : (p2 > p1) ? 2 : 0;
        case 2: return (a1 > a2) ? 1 : (a2 > a1) ? 2 : 0;
        case 3: return (pib1 > pib2) ? 1 : (pib2 > pib1) ? 2 : 0;
        case 4: return (pt1 > pt2) ? 1 : (pt2 > pt1) ? 2 : 0;
        case 5: return (dens1 < dens2) ? 1 : (dens2 < dens1) ? 2 : 0;
        case 6: return (ppc1 > ppc2) ? 1 : (ppc2 > ppc1) ? 2 : 0;
        default: return -1;
    }
}

int main() {
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float PIB1, PIB2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    char estado1[3], estado2[3];
    char codigo1[20], codigo2[20];
    char nomeCidade1[50], nomeCidade2[50];

    printf("Cadastre a primeira carta:\n");
    printf("Estado (sigla): "); scanf("%s", estado1);
    printf("Código: "); scanf("%s", codigo1);
    printf("Nome da cidade: "); scanf(" %[^\n]", nomeCidade1);
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área (km²): "); scanf("%f", &area1);
    printf("PIB (bilhões): "); scanf("%f", &PIB1);
    printf("Pontos turísticos: "); scanf("%d", &pontosTuristicos1);

    printf("\nCadastre a segunda carta:\n");
    printf("Estado (sigla): "); scanf("%s", estado2);
    printf("Código: "); scanf("%s", codigo2);
    printf("Nome da cidade: "); scanf(" %[^\n]", nomeCidade2);
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área (km²): "); scanf("%f", &area2);
    printf("PIB (bilhões): "); scanf("%f", &PIB2);
    printf("Pontos turísticos: "); scanf("%d", &pontosTuristicos2);

    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = (PIB1 * 1000000000) / populacao1;
    pibPerCapita2 = (PIB2 * 1000000000) / populacao2;

    // Escolha dos atributos
    int attr1 = escolherAtributo("1º");
    int attr2 = escolherAtributo("2º");

    // Comparações
    int resultado1 = compararAtributo(attr1, populacao1, populacao2, area1, area2, PIB1, PIB2,
                                      pontosTuristicos1, pontosTuristicos2, densidade1, densidade2,
                                      pibPerCapita1, pibPerCapita2);

    int resultado2 = compararAtributo(attr2, populacao1, populacao2, area1, area2, PIB1, PIB2,
                                      pontosTuristicos1, pontosTuristicos2, densidade1, densidade2,
                                      pibPerCapita1, pibPerCapita2);

    int vitorias1 = (resultado1 == 1) + (resultado2 == 1);
    int vitorias2 = (resultado1 == 2) + (resultado2 == 2);

    printf("\n🏁 Resultado Final da Comparação:\n");
    if (vitorias1 > vitorias2) {
        printf("🏆 A cidade vencedora é: %s (%s)\n", nomeCidade1, estado1);
    } else if (vitorias2 > vitorias1) {
        printf("🏆 A cidade vencedora é: %s (%s)\n", nomeCidade2, estado2);
    } else {
        printf("🤝 Empate entre as cidades!\n");
    }

    return 0;
}
