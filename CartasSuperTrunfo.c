#include <stdio.h>
#include <string.h>

// Declaração de variáveis em uma struct representando uma das cartas
char maiorPopulacao;
char maiorArea;
char maiorPib;
char maiorPibPerCapita;
char maisPontosTuristicos;
char menorDensidadePopulacional;
char maiorPoder;
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
    double superPoder;
} Cartas;

Cartas cartas[2];

// Função auxiliar declarada aqui, mas sendo elaborada no final, para manter a organização do código
void compare(double propriedade1, double propriedade2, char *vencedor);

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
        cartas[indiceCarta].superPoder = 
            cartas[indiceCarta].populacao
            + cartas[indiceCarta].pib
            + cartas[indiceCarta].area
            + cartas[indiceCarta].pontosTuristicos;
    
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
        printf("Super Poder: %.2f\n", cartas[indiceCarta].superPoder);
    }

    // Comparação entre as cartas e apresentação da carta vencedora em cada categoria
    compare(cartas[0].populacao, cartas[1].populacao, &maiorPopulacao);
    compare(cartas[0].area, cartas[1].area, &maiorArea);
    compare(cartas[0].pib, cartas[1].pib, &maiorPib);
    compare(cartas[0].pibPerCapita, cartas[1].pibPerCapita, &maiorPibPerCapita);
    compare(cartas[1].densidadePopulacional, cartas[0].densidadePopulacional, &menorDensidadePopulacional);
    compare(cartas[0].pontosTuristicos, cartas[1].pontosTuristicos, &maisPontosTuristicos);
    compare(cartas[0].superPoder, cartas[1].superPoder, &maiorPoder);

    printf("\nVENCEDORES\n\n");
    printf("Carta com maior população: %c\n", maiorPopulacao);
    printf("Carta com maior área: %c\n", maiorArea);
    printf("Carta com maior PIB: %c\n", maiorPib);
    printf("Carta com maior PIB per capita: %c\n", maiorPibPerCapita);
    printf("Carta com menor densidade populacional: %c\n", menorDensidadePopulacional);
    printf("Carta com maior número de pontos turísticos: %c\n", maisPontosTuristicos);
    printf("Carta com maior Super Poder: %c\n", maiorPoder);

    return 0;
}

void compare(double propriedade1, double propriedade2, char *vencedor) 
{
    *vencedor = (propriedade1 > propriedade2) 
    ? '1' 
    : (propriedade1 < propriedade2) 
        ? '2'
        : '-';
}