#include <stdio.h>
#include <string.h>

#define UM_BILHAO 1000000000.0f

int main() {

    // Declaração das variáveis
    char cidade1[50], cidade2[50];
    char estado1[3], estado2[3];
    char codigo1[4], codigo2[4];

    unsigned long int populacao1, populacao2;
    int p_turistico1, p_turistico2;

    float area1, area2;
    float pib1, pib2, pib_per_capita1, pib_per_capita2;
    float densidade1, densidade2;
    float superPoder1, superPoder2;



    // Coleta de dados da carta 1
    printf("Carta 01\n");

    printf("Informe o código da carta: ");
    scanf("%3s", codigo1);

    printf("Informe o estado: ");
    scanf("%2s", estado1);

    getchar(); // Limpa o buffer antes do fgets
    printf("Informe o nome da cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0'; // Remove o '\n'

    printf("Informe a população: ");
    scanf("%lu", &populacao1);

    printf("Informe a área em Km²: ");
    scanf("%f", &area1);

    printf("Informe o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &p_turistico1);

    // Coleta de dados da carta 2
    printf("\nCarta 02\n");

    printf("Informe o código da carta: ");
    scanf("%3s", codigo2);

    printf("Informe o estado: ");
    scanf("%2s", estado2);

    getchar(); // Limpa o buffer antes do fgets
    printf("Informe o nome da cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0'; // Remove o '\n'

    printf("Informe a população: ");
    scanf("%lu", &populacao2);

    printf("Informe a área em Km²: ");
    scanf("%f", &area2);

    printf("Informe o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &p_turistico2);

    // Cálculo da densidade populacional e PIB per capita
    densidade1 = (float)populacao1 / area1;
    pib_per_capita1 = (pib1 * UM_BILHAO) / (float)populacao1;

    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * UM_BILHAO) / (float)populacao2;

    // Exibição dos dados
    printf("\nDados da Carta 1:\n");
    printf("Código: %s\n", codigo1);
    printf("Estado: %s\n", estado1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f Km²\n", area1);
    printf("PIB: R$ %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", p_turistico1);
    printf("Densidade Populacional: %.2f hab/Km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita1);

    printf("\nDados da Carta 2:\n");
    printf("Código: %s\n", codigo2);
    printf("Estado: %s\n", estado2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f Km²\n", area2);
    printf("PIB: R$ %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", p_turistico2);
    printf("Densidade Populacional: %.2f hab/Km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita2);

    // Comparação do atributo escolhido
    printf("\nComparação de cartas (Atributo: Área):\n");
    if (area1 > area2){
        printf("Área: Carta 1 venceu!\n");
    }else {
        printf("Área: Carta 2 venceu!\n");
    }
    return 0;
}
