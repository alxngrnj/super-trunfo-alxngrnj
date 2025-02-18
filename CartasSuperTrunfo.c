#include <stdio.h>

int main() {
    // declaração de variáveis
    char estado;
    char codCarta[4];
    char cidade[20];
    unsigned long populacao;
    float area;
    double pib;
    unsigned short int pontosTuristicos;
    double densidadePopulacional;
    
    // Pedido de input do usuário, atribuindo os valores às variáveis
    printf("\nNOVA CARTA\n\n");
    printf("Insira o nome da Cidade: ");
    scanf("%20[^\n]", cidade);
    do 
    {
        printf("Insira a letra maiúscula que representará o Estado, de 'A' até 'H': ");
        scanf(" %c", &estado);
        codCarta[0] = estado;
    } 
    while (estado < 'A' || estado > 'H');
    do
    {
        printf("Insira o número da cidade, de '01' a '04': ");
        scanf(" %s", &codCarta[1]);
    }
    while (codCarta[2] > '4' || codCarta[2] < '1');
    printf("Insira a população da cidade: ");
    scanf(" %lu", &populacao);
    printf("Insira a área em km², separando as casas decimais com '.' em vez de vírgula: ");
    scanf(" %f", &area);
    printf("Insira o PIB, separando os centavos com '.' em vez de vírgula: ");
    scanf(" %lf", &pib);
    printf("Insira o número de pontos turísticos da cidade: ");
    scanf(" %i", &pontosTuristicos);

    // Exibição dos dados da carta de forma estruturada
    printf("\nNome da Cidade: %s\n", cidade);
    printf("Estado: %c\n", estado);
    printf("Código da Carta: %s\n", codCarta);
    printf("População: %i habitantes\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib / 1000000000);
    printf("PIB per capita: %.2f reais\n", pib / populacao);
    printf("Densidade populacional: %.2f hab/m²\n", populacao / area);
    printf("Número de pontos turísticos: %i", pontosTuristicos);
    
    // TODO
    // Comparação das cartas e Super Poder

    return 0;
}