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
    int primeiroAtributo, segundoAtributo;

    double area1, area2;
    double pib1, pib2, pib_per_capita1, pib_per_capita2;
    double densidade1, densidade2;

    // Soma dos atributos
    double soma1 = 0, soma2 = 0;

    // Coleta de dados da carta 1
    printf("### Bem-Vindo ao Super Trunfo ###\n");
    printf("Carta 01\n");

    printf("Informe o código da carta: ");
    scanf("%3s", codigo1);

    printf("Informe o estado: ");
    scanf("%2s", estado1);

    getchar(); // Limpa o buffer antes do fgets
    printf("Informe o nome da cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0';

    printf("Informe a população: ");
    scanf("%lu", &populacao1);

    printf("Informe a área em Km²: ");
    scanf("%lf", &area1);

    printf("Informe o PIB (em bilhões de reais): ");
    scanf("%lf", &pib1);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &p_turistico1);

    // Coleta de dados da carta 2
    printf("\nCarta 02\n");

    printf("Informe o código da carta: ");
    scanf("%3s", codigo2);

    printf("Informe o estado: ");
    scanf("%2s", estado2);

    getchar();
    printf("Informe o nome da cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';

    printf("Informe a população: ");
    scanf("%lu", &populacao2);

    printf("Informe a área em Km²: ");
    scanf("%lf", &area2);

    printf("Informe o PIB (em bilhões de reais): ");
    scanf("%lf", &pib2);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &p_turistico2);

    // Cálculo da densidade e PIB per capita
    densidade1 = (double)populacao1 / area1;
    pib_per_capita1 = (pib1 * UM_BILHAO) / (double)populacao1;

    densidade2 = (double)populacao2 / area2;
    pib_per_capita2 = (pib2 * UM_BILHAO) / (double)populacao2;

    // Exibição
    printf("\nDados da Carta 1:\n");
    printf("Cidade: %s | População: %lu | Área: %.2lf | PIB: %.2lf bi | PIB per capita: %.2lf | Pontos: %d | Densidade: %.2lf\n",
       cidade1, populacao1, area1, pib1, pib_per_capita1, p_turistico1, densidade1);

    printf("\nDados da Carta 2:\n");
    printf("Cidade: %s | População: %lu | Área: %.2lf | PIB: %.2lf bi | PIB per capita: %.2lf | Pontos: %d | Densidade: %.2lf\n",
       cidade2, populacao2, area2, pib2, pib_per_capita2 , p_turistico2, densidade2);

    // Escolha dos atributos
    printf("\n### Escolha o Segundo Atributo de Comparação ###\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade (menor vence)\n");
    scanf("%d", &primeiroAtributo);

   // Primeiro atributo comparando 
    switch (primeiroAtributo) {
    case 1: {
        printf("Comparando População...\n");
        if (populacao1 > populacao2) {
            printf("Carta 1 venceu!\n");
        } else if (populacao2 > populacao1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        soma1 += populacao1; soma2 += populacao2;
    break;
    }

    case 2: {
        printf("Comparando Área...\n");
        if (area1 > area2) {
            printf("Carta 1 venceu!\n");
        } else if (area2 > area1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        soma1 += area1; soma2 += area2;
     break;
    }

    case 3: {
        printf("Comparando PIB...\n");
        if (pib1 > pib2) {
            printf("Carta 1 venceu!\n");
        } else if (pib2 > pib1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        soma1 += pib1; soma2 += pib2;
     break;
    }

    case 4: {
        printf("Comparando Pontos Turísticos...\n");
        if (p_turistico1 > p_turistico2) {
            printf("Carta 1 venceu!\n");
        } else if (p_turistico2 > p_turistico1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        soma1 += p_turistico1; soma2 += p_turistico2;
     break;
    }

    case 5: {
        printf("Comparando Densidade...\n");
        if (densidade1 < densidade2) {
            printf("Carta 1 venceu!\n");
        } else if (densidade2 < densidade1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        {
         double maxD = (densidade1 > densidade2 ? densidade1 : densidade2);
         soma1 += (maxD - densidade1);
         soma2 += (maxD - densidade2);
        }
    break;
    }

    default: {
        printf("Opção inválida!\n");
     break;
    }
}

    printf("\n### Escolha o Segundo Atributo de Comparação ###\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade (menor vence)\n");
    scanf("%d", &segundoAtributo);

    // Segundo atributo
    switch (segundoAtributo) {
    case 1: {
        printf("Comparando População...\n");
        if (populacao1 > populacao2) {
            printf("Carta 1 venceu!\n");
        } else if (populacao2 > populacao1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        soma1 += populacao1; soma2 += populacao2;
        break;
    }

    case 2: {
        printf("Comparando Área...\n");
        if (area1 > area2) {
            printf("Carta 1 venceu!\n");
        } else if (area2 > area1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        soma1 += area1; soma2 += area2;
        break;
    }

    case 3: {
        printf("Comparando PIB...\n");
        if (pib1 > pib2) {
            printf("Carta 1 venceu!\n");
        } else if (pib2 > pib1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        soma1 += pib1; soma2 += pib2;
        break;
    }

    case 4: {
        printf("Comparando Pontos Turísticos...\n");
        if (p_turistico1 > p_turistico2) {
            printf("Carta 1 venceu!\n");
        } else if (p_turistico2 > p_turistico1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        soma1 += p_turistico1; soma2 += p_turistico2;
        break;
    }

    case 5: {
        printf("Comparando Densidade...\n");
        if (densidade1 < densidade2) {
            printf("Carta 1 venceu!\n");
        } else if (densidade2 < densidade1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        {
            double maxD = (densidade1 > densidade2 ? densidade1 : densidade2);
            soma1 += (maxD - densidade1);
            soma2 += (maxD - densidade2);
        }
        break;
    }

    default: {
        printf("Opção inválida!\n");
        break;
    }
}

 
    // Resultado final
    printf("\n--- Resultado Final ---\n");
    printf("Soma dos atributos Carta 1: %.2lf\n", soma1);
    printf("Soma dos atributos Carta 2: %.2lf\n", soma2);

    if (soma1 > soma2) {
        printf("Carta 1 venceu a rodada!\n");
    } else if (soma2 > soma1) {
        printf("Carta 2 venceu a rodada!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}