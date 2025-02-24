#include <stdio.h>
#include <string.h>

// Declaração de variáveis em uma struct representando uma das cartas
int maiorPopulacao;
int maiorArea;
int maiorPib;
int maiorPibPerCapita;
int maisPontosTuristicos;
int menorDensidadePopulacional;
int maiorPoder;
int atributosEscolhidos[2];
typedef struct Carta {
    char estado;
    char codCarta[4];
    char cidade[20];
    unsigned long populacao;
    float area;
    double pib;
    float pibPerCapita;
    unsigned short int pontosTuristicos;
    double densidadePopulacional;
    double poderTotal;
} Cartas;

Cartas cartas[2];

// Função auxiliar declarada aqui, mas sendo elaborada no final, para manter a organização do código
void compare(double propriedade1, double propriedade2, int *vencedor);

int main() {

    // Pedido de input do usuário, atribuindo os valores às variáveis de cada carta
    for (int indiceCarta = 0; indiceCarta < 2; indiceCarta++)
    {
        printf("\nCADASTRAR CARTA %i\n\n", indiceCarta + 1);
        printf("Insira o nome da Cidade: ");
        scanf(" %20[^\n]", cartas[indiceCarta].cidade);
        do 
        {
            printf("Insira a letra maiúscula que representará o Estado, de 'A' até 'H': ");
            scanf(" %c", &cartas[indiceCarta].estado);
            cartas[indiceCarta].codCarta[0] = cartas[indiceCarta].estado;
            cartas[indiceCarta].codCarta[1] = '0';
        } 
        while (cartas[indiceCarta].estado < 'A' || cartas[indiceCarta].estado > 'H');
        if (indiceCarta > 0) {
            do
            {
                printf("Insira o número da cidade, de '1' a '4': ");
                scanf(" %c", &cartas[indiceCarta].codCarta[2]);
            }
            while (cartas[indiceCarta].codCarta[2] > '4' 
                || cartas[indiceCarta].codCarta[2] < '1'
                ||  strcmp(cartas[0].codCarta, cartas[1].codCarta) == 0);
        } else {
            do
            {
                printf("Insira o número da cidade, de '1' a '4': ");
                scanf(" %c", &cartas[indiceCarta].codCarta[2]);
            }
            while (cartas[indiceCarta].codCarta[2] > '4' 
                || cartas[indiceCarta].codCarta[2] < '1');
        }
        printf("Insira a população da cidade: ");
        scanf(" %lu", &cartas[indiceCarta].populacao);
        printf("Insira a área em km², separando as casas decimais com '.' em vez de vírgula: ");
        scanf(" %f", &cartas[indiceCarta].area);
        printf("Insira o PIB, separando os centavos com '.' em vez de vírgula: ");
        scanf(" %lf", &cartas[indiceCarta].pib);
        printf("Insira o número de pontos turísticos da cidade: ");
        scanf(" %i", &cartas[indiceCarta].pontosTuristicos);
        cartas[indiceCarta].pibPerCapita = cartas[indiceCarta].pib / cartas[indiceCarta].populacao;
        cartas[indiceCarta].densidadePopulacional = cartas[indiceCarta].populacao / cartas[indiceCarta].area;
        cartas[indiceCarta].poderTotal = 0;
    
        // Exibição dos dados da carta de forma estruturada
        printf("\nINFORMAÇÕES DA CARTA %i\n\n", indiceCarta + 1);
        printf("Nome da Cidade: %s\n", cartas[indiceCarta].cidade);
        printf("Estado: %c\n", cartas[indiceCarta].estado);
        printf("Código da Carta: %s\n", cartas[indiceCarta].codCarta);
        printf("População: %i habitantes\n", cartas[indiceCarta].populacao);
        printf("Área: %.2f km²\n", cartas[indiceCarta].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[indiceCarta].pib / 1000000000);
        printf("PIB per capita: %.2f reais\n", cartas[indiceCarta].pibPerCapita);
        printf("Densidade populacional: %.2f hab/m²\n", cartas[indiceCarta].densidadePopulacional);
        printf("Número de pontos turísticos: %i\n", cartas[indiceCarta].pontosTuristicos);
    }

    // Comparação entre as cartas e apresentação da carta vencedora em cada categoria
    compare(cartas[0].populacao, cartas[1].populacao, &maiorPopulacao);
    compare(cartas[0].area, cartas[1].area, &maiorArea);
    compare(cartas[0].pib, cartas[1].pib, &maiorPib);
    compare(cartas[0].pibPerCapita, cartas[1].pibPerCapita, &maiorPibPerCapita);
    compare(cartas[1].densidadePopulacional, cartas[0].densidadePopulacional, &menorDensidadePopulacional);
    compare(cartas[0].pontosTuristicos, cartas[1].pontosTuristicos, &maisPontosTuristicos);
    
    puts("\nCOMPARAÇÕES\n");

    for (int indiceAtributo = 0; indiceAtributo < 2; indiceAtributo++)
    {
        if (indiceAtributo == 0)
        {
            puts("Digite 1 para comparar os valores de População");
            puts("Digite 2 para comparar os valores de Área");
            puts("Digite 3 para comparar os valores de PIB");
            puts("Digite 4 para comparar os valores de PIB per Capita");
            puts("Digite 5 para comparar os valores de Densidade Populacional");
            puts("Digite 6 para comparar os valores de Pontos Turísticos");
            printf("Sua escolha: ");
            scanf("%i", &atributosEscolhidos[0]);
        }
        else
        {
            switch(atributosEscolhidos[0])
            {
                case 1:
                    puts("\nDigite 0 para comparar apenas os valores apenas do atributo inserido anteriormente");
                    puts("Digite 2 para comparar os valores de Área");
                    puts("Digite 3 para comparar os valores de PIB");
                    puts("Digite 4 para comparar os valores de PIB per Capita");
                    puts("Digite 5 para comparar os valores de Densidade Populacional");
                    puts("Digite 6 para comparar os valores de Pontos Turísticos");
                    printf("Sua escolha: ");
                    scanf("%i", &atributosEscolhidos[1]);
                    printf("\n");
                    break;
                case 2:
                    puts("\nDigite 0 para comparar apenas os valores apenas do atributo inserido anteriormente");
                    puts("Digite 1 para comparar os valores de População");
                    puts("Digite 3 para comparar os valores de PIB");
                    puts("Digite 4 para comparar os valores de PIB per Capita");
                    puts("Digite 5 para comparar os valores de Densidade Populacional");
                    puts("Digite 6 para comparar os valores de Pontos Turísticos");
                    printf("Sua escolha: ");
                    scanf("%i", &atributosEscolhidos[1]);
                    printf("\n");
                    break;
                case 3:
                    puts("\nDigite 0 para comparar apenas os valores apenas do atributo inserido anteriormente");
                    puts("Digite 1 para comparar os valores de População");
                    puts("Digite 2 para comparar os valores de Área");
                    puts("Digite 4 para comparar os valores de PIB per Capita");
                    puts("Digite 5 para comparar os valores de Densidade Populacional");
                    puts("Digite 6 para comparar os valores de Pontos Turísticos");
                    printf("Sua escolha: ");
                    scanf("%i", &atributosEscolhidos[1]);
                    printf("\n");
                    break;
                case 4:
                    puts("\nDigite 0 para comparar apenas os valores apenas do atributo inserido anteriormente");
                    puts("Digite 1 para comparar os valores de População");
                    puts("Digite 2 para comparar os valores de Área");
                    puts("Digite 3 para comparar os valores de PIB");
                    puts("Digite 5 para comparar os valores de Densidade Populacional");
                    puts("Digite 6 para comparar os valores de Pontos Turísticos");
                    printf("Sua escolha: ");
                    scanf("%i", &atributosEscolhidos[1]);
                    printf("\n");
                    break;
                case 5:
                    puts("\nDigite 0 para comparar apenas os valores apenas do atributo inserido anteriormente");
                    puts("Digite 1 para comparar os valores de População");
                    puts("Digite 2 para comparar os valores de Área");
                    puts("Digite 3 para comparar os valores de PIB");
                    puts("Digite 4 para comparar os valores de PIB per Capita");
                    puts("Digite 6 para comparar os valores de Pontos Turísticos");
                    printf("Sua escolha: ");
                    scanf("%i", &atributosEscolhidos[1]);
                    printf("\n");
                    break;
                case 6:
                    puts("\nDigite 0 para comparar apenas os valores apenas do atributo inserido anteriormente");
                    puts("Digite 1 para comparar os valores de População");
                    puts("Digite 2 para comparar os valores de Área");
                    puts("Digite 3 para comparar os valores de PIB");
                    puts("Digite 4 para comparar os valores de PIB per Capita");
                    puts("Digite 5 para comparar os valores de Densidade Populacional");
                    printf("Sua escolha: ");
                    scanf("%i", &atributosEscolhidos[1]);
                    printf("\n");
                    break;
                default:
                    break;
            }
        }
    }


    for (int indiceComparado = 0; indiceComparado < 2; indiceComparado++)
    {
        switch(atributosEscolhidos[indiceComparado])
        {
            case 0:
                switch (atributosEscolhidos[0])
                {
                    case 1:
                        if (maiorPopulacao == 0)
                        {
                            puts("Resultado: Empate!");
                            return 0;
                        }
                        printf("Resultado: Carta %i (%s) venceu!", maiorPopulacao, cartas[maiorPopulacao - 1].cidade);
                        return 0;
                    case 2:
                        if (maiorArea == 0)
                        {
                            puts("Resultado: Empate!");
                            return 0;
                        }
                        printf("Resultado: Carta %i (%s) venceu!", maiorArea, cartas[maiorArea - 1].cidade);
                        return 0;
                    case 3:
                        if (maiorPib == 0)
                        {
                            puts("Resultado: Empate!");
                            return 0;
                        }
                        printf("Resultado: Carta %i (%s) venceu!", maiorPib, cartas[maiorPib - 1].cidade);
                        return 0;
                    case 4:
                        if (maiorPibPerCapita == 0)
                        {
                            puts("Resultado: Empate!");
                            return 0;
                        }
                        printf("Resultado: Carta %i (%s) venceu!", maiorPibPerCapita, cartas[maiorPibPerCapita - 1].cidade);
                        return 0;
                    case 5:
                        if (maisPontosTuristicos == 0)
                        {
                            puts("Resultado: Empate!");
                            return 0;
                        }
                        printf("Resultado: Carta %i (%s) venceu!", maisPontosTuristicos, cartas[maisPontosTuristicos - 1].cidade);
                        return 0;
                    case 6:
                        if (menorDensidadePopulacional == 0)
                        {
                            puts("Resultado: Empate!");
                            return 0;
                        }
                        printf("Resultado: Carta %i (%s) venceu!", menorDensidadePopulacional, cartas[menorDensidadePopulacional - 1].cidade);
                        return 0;
                    default:
                    return 0;
                }
            case 1:
                printf("Carta 1 - %s - População: %i habitantes\n", cartas[0].cidade, cartas[0].populacao);
                printf("Carta 2 - %s - População: %i habitantes\n\n", cartas[1].cidade, cartas[1].populacao);
                cartas[0].poderTotal = cartas[0].poderTotal + cartas[0].populacao;
                cartas[1].poderTotal = cartas[1].poderTotal + cartas[1].populacao;
                break;
            case 2:
                printf("Carta 1 - %s - Área: %.2f km²\n", cartas[0].cidade, cartas[0].area);
                printf("Carta 2 - %s - Área: %.2f km²\n\n", cartas[1].cidade, cartas[1].area);
                cartas[0].poderTotal = cartas[0].poderTotal + cartas[0].area;
                cartas[1].poderTotal = cartas[1].poderTotal + cartas[1].area;
                break;
            case 3:
                printf("Carta 1 - %s - PIB: %.2f bilhões de reais\n", cartas[0].cidade, cartas[0].pib / 1000000000);
                printf("Carta 2 - %s - PIB: %.2f bilhões de reais\n\n", cartas[1].cidade, cartas[1].pib / 1000000000);
                cartas[0].poderTotal = cartas[0].poderTotal + cartas[0].pib;
                cartas[1].poderTotal = cartas[1].poderTotal + cartas[1].pib;
                break;
            case 4:
                printf("Carta 1 - %s - PIB per Capita: %.2f reais\n", cartas[0].cidade, cartas[0].pibPerCapita);
                printf("Carta 2 - %s - PIB per Capita: %.2f reais\n\n", cartas[1].cidade, cartas[1].pibPerCapita);
                cartas[0].poderTotal = cartas[0].poderTotal + cartas[0].pibPerCapita;
                cartas[1].poderTotal = cartas[1].poderTotal + cartas[1].pibPerCapita;
                break;
            case 5:
                printf("Carta 1 - %s - Pontos Turísticos: %i\n", cartas[0].cidade, cartas[0].pontosTuristicos);
                printf("Carta 2 - %s - Pontos Turísticos: %i\n\n", cartas[1].cidade, cartas[1].pontosTuristicos);
                cartas[0].poderTotal = cartas[0].poderTotal + cartas[0].pontosTuristicos;
                cartas[1].poderTotal = cartas[1].poderTotal + cartas[1].pontosTuristicos;
                break;
            case 6:
                printf("Carta 1 - %s - Densidade populacional: %.2f habitantes/m²\n", cartas[0].cidade, cartas[0].densidadePopulacional);
                printf("Carta 2 - %s - Densidade Populacional: %.2f habitantes/m²\n\n", cartas[1].cidade, cartas[1].densidadePopulacional);
                cartas[0].poderTotal = cartas[0].poderTotal + cartas[0].densidadePopulacional;
                cartas[1].poderTotal = cartas[1].poderTotal + cartas[1].densidadePopulacional;
                break;
            default:
                break;
        }
    }

    printf("Carta 1 - %s - Poder total: %.2f\n", cartas[0].cidade, cartas[0].poderTotal);
    printf("Carta 2 - %s - Poder total: %.2f\n\n", cartas[1].cidade, cartas[1].poderTotal);

    compare(cartas[0].poderTotal, cartas[1].poderTotal, &maiorPoder);
    if (maiorPoder == 0)
    {
        puts("Resultado: Empate!");
        return 0;
    }
    printf("Resultado: Carta %i (%s) venceu!", maiorPoder, cartas[maiorPoder - 1].cidade);

    return 0;
}

void compare(double propriedade1, double propriedade2, int *vencedor)
{
    *vencedor = (propriedade1 > propriedade2) 
    ? 1
    : (propriedade1 < propriedade2) 
        ? 2
        : 0;
}