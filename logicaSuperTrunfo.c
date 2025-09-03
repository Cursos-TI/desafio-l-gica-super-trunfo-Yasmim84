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
    int escolhadoAtributo;

    float area1, area2;
    float pib1, pib2, pib_per_capita1, pib_per_capita2;
    float densidade1, densidade2;
    


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

    // Menu interátivo
   printf("### Escolha o Atributo de Comparação ###\n");
   printf("1. População\n");
   printf("2. Área\n");
   printf("3. PIB\n");
   printf("4. Número de pontos túristicos\n");
   printf("5. Densidade demográfica (menor vence)\n");
   scanf("%d", &escolhadoAtributo);

   switch (escolhadoAtributo)
   {
    case 1: // População
        if (populacao1 > populacao2)
            printf("%s venceu com %lu habitantes contra %lu!\n", cidade1, populacao1, populacao2);
        else if (populacao1 < populacao2)
            printf("%s venceu com %lu habitantes contra %lu!\n", cidade2, populacao2, populacao1);
        else
            printf("Empate! Ambas têm %lu habitantes.\n", populacao1);
        break;

    case 2: // Área
        if (area1 > area2)
            printf("%s venceu com %.2f km² contra %.2f km²!\n", cidade1, area1, area2);
        else if (area1 < area2)
            printf("%s venceu com %.2f km² contra %.2f km²!\n", cidade2, area2, area1);
        else
            printf("Empate! Ambas têm %.2f km² de área.\n", area1);
        break;

    case 3: // PIB
        if (pib1 > pib2)
            printf("%s venceu com PIB de %.2f bilhões contra %.2f bilhões!\n", cidade1, pib1, pib2);
        else if (pib1 < pib2)
            printf("%s venceu com PIB de %.2f bilhões contra %.2f bilhões!\n", cidade2, pib2, pib1);
        else
            printf("Empate! Ambas têm PIB de %.2f bilhões.\n", pib1);
        break;

    case 4: // Pontos turísticos
        if (p_turistico1 > p_turistico2)
            printf("%s venceu com %d pontos turísticos contra %d!\n", cidade1, p_turistico1, p_turistico2);
        else if (p_turistico1 < p_turistico2)
            printf("%s venceu com %d pontos turísticos contra %d!\n", cidade2, p_turistico2, p_turistico1);
        else
            printf("Empate! Ambas têm %d pontos turísticos.\n", p_turistico1);
        break;

    case 5: // Densidade demográfica (menor vence)
        if (densidade1 < densidade2)
            printf("%s venceu com densidade de %.2f hab/km² contra %.2f hab/km²!\n", cidade1, densidade1, densidade2);
        else if (densidade1 > densidade2)
            printf("%s venceu com densidade de %.2f hab/km² contra %.2f hab/km²!\n", cidade2, densidade2, densidade1);
        else
            printf("Empate! Ambas têm densidade de %.2f hab/km².\n", densidade1);
        break;

    default:
        printf("Opção inválida. Escolha um número entre 1 e 5.\n");
        break;
   }
    return 0;
}
