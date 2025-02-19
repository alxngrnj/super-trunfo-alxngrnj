#include <stdio.h>
#include <string.h>

int main() {
    // Declaração de variáveis em ma struct representando uma das cartas
    typedef struct Carta {
        char estado;
        char codCarta[4];
        char cidade[20];
        unsigned long populacao;
        float area;
        double pib;
        unsigned short int pontosTuristicos;
        double densidadePopulacional;
    } Cartas;

    Cartas cartas[2];

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
        } 
        while (cartas[indiceCarta].estado < 'A' || cartas[indiceCarta].estado > 'H');
        if (indiceCarta > 0) {
            do
            {
                printf("Insira o número da cidade, de '01' a '04': ");
                scanf(" %s", &cartas[indiceCarta].codCarta[1]);
            }
            while (cartas[indiceCarta].codCarta[2] > '4' 
                || cartas[indiceCarta].codCarta[2] < '1'
                ||  strcmp(cartas[0].codCarta, cartas[1].codCarta) == 0);
        } else {
            do
            {
                printf("Insira o número da cidade, de '01' a '04': ");
                scanf(" %s", &cartas[indiceCarta].codCarta[1]);
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
    
        // Exibição dos dados da carta de forma estruturada
        printf("\nINFORMAÇÕES DA CARTA %i\n\n", indiceCarta + 1);
        printf("Nome da Cidade: %s\n", cartas[indiceCarta].cidade);
        printf("Estado: %c\n", cartas[indiceCarta].estado);
        printf("Código da Carta: %s\n", cartas[indiceCarta].codCarta);
        printf("População: %i habitantes\n", cartas[indiceCarta].populacao);
        printf("Área: %.2f km²\n", cartas[indiceCarta].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[indiceCarta].pib / 1000000000);
        printf("PIB per capita: %.2f reais\n", cartas[indiceCarta].pib / cartas[indiceCarta].populacao);
        printf("Densidade populacional: %.2f hab/m²\n", cartas[indiceCarta].populacao / cartas[indiceCarta].area);
        printf("Número de pontos turísticos: %i\n", cartas[indiceCarta].pontosTuristicos);
    }
    
    // TODO
    // Comparação das cartas e Super Poder

    return 0;
}