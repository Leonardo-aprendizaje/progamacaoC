#include <stdio.h>
#include <string.h>
#include <locale.h>

// Definição da estrutura da carta
struct cartaEstadoCidade {
    char estado[60];               
    char codigo_carta[5];          
    char nome_cidade[60];          
    unsigned long int populacao;       
    float area_km2;                 
    unsigned long long int pib;  // %llu                   
    int pontos_turisticos;
    float densidade; 
    float pib_per_capita;
    unsigned long long int super_poder; // Corrigido o tipo

};

// Função para coletar os dados da carta
void coletarDados(struct cartaEstadoCidade *carta, int numero) { 
    printf("\n=== Cadastro da Carta %d ===\n", numero);
    
    // Estado
    printf("Digite o Estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0;  

    // Código da carta
    printf("Digite o código da carta: ");
    scanf("%4s", carta->codigo_carta);
    getchar(); 

    // Nome da cidade
    printf("Digite o nome da cidade: "); 
    fgets(carta->nome_cidade, sizeof(carta->nome_cidade), stdin);
    carta->nome_cidade[strcspn(carta->nome_cidade, "\n")] = 0; 

    // População
    printf("Digite a quantidade da população: ");
    scanf("%lu", &carta->populacao);
    getchar();

    // Área em km²
    printf("Digite a área em km²: ");
    scanf("%f", &carta->area_km2);
    getchar();

    // PIB
    printf("Digite o PIB (em bilhões, sem pontos, colocar todos os numeros.): ");
    scanf("%llu", &carta->pib);
    getchar();

    // Pontos turísticos
    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    getchar();

    // Cálculo da densidade
    carta->densidade = carta->populacao / carta->area_km2;

    // Cálculo do PIB per capita
    carta->pib_per_capita = (float)carta->pib / carta->populacao;

    // Cálculo do Super Poder (SEMPRE CONVERTER OS TIPOS, PARA NÃO TER ERROS.)
    carta->super_poder = carta->populacao + (unsigned long long int)carta->area_km2 + carta->pib + 
                         carta->pontos_turisticos + (unsigned long long int)carta->pib_per_capita +
                         (unsigned long long int)(carta->area_km2 / carta->populacao);
}

// Função para exibir os dados da carta
void exibirDados(struct cartaEstadoCidade carta, int numero) {
    printf("\n=== Dados da Carta %d ===\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Código da carta: %s\n", carta.codigo_carta);
    printf("Cidade: %s\n", carta.nome_cidade);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area_km2);
    printf("PIB: R$ %llu bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
    printf("Super Poder: %llu\n", carta.super_poder);  // Correção na exibição
}

// Comparação das cartas
void compararCartas(struct cartaEstadoCidade carta1, struct cartaEstadoCidade carta2) {
    printf("\n=== Comparação das Cartas ===\n");


    int resultado;

    // População
    resultado = (carta1.populacao > carta2.populacao);
    printf("População: %d - %s\n", resultado, resultado ? "Carta 1 venceu" : (carta1.populacao < carta2.populacao ? "Carta 2 venceu" : "Empate"));

    // Área km²
    resultado = (carta1.area_km2 > carta2.area_km2);
    printf("Área km²: %d - %s\n", resultado, resultado ? "Carta 1 venceu" : (carta1.area_km2 < carta2.area_km2 ? "Carta 2 venceu" : "Empate"));

    // PIB
    resultado = (carta1.pib > carta2.pib);
    printf("PIB: %d - %s\n", resultado, resultado ? "Carta 1 venceu" : (carta1.pib < carta2.pib ? "Carta 2 venceu" : "Empate"));

    // Pontos Turísticos
    resultado = (carta1.pontos_turisticos > carta2.pontos_turisticos);
    printf("Pontos Turísticos: %d - %s\n", resultado, resultado ? "Carta 1 venceu" : (carta1.pontos_turisticos < carta2.pontos_turisticos ? "Carta 2 venceu" : "Empate"));

    // Densidade Populacional (menor vence)
    resultado = (carta1.densidade < carta2.densidade);
    printf("Densidade Populacional: %d - %s\n", resultado, resultado ? "Carta 1 venceu" : (carta1.densidade > carta2.densidade ? "Carta 2 venceu" : "Empate"));

    // PIB per Capita
    resultado = (carta1.pib_per_capita > carta2.pib_per_capita);
    printf("PIB per Capita: %d - %s\n", resultado, resultado ? "Carta 1 venceu" : (carta1.pib_per_capita < carta2.pib_per_capita ? "Carta 2 venceu" : "Empate"));

    //FEITA A COMPARAÇÃO DO SUPER PODER EM IF / ELSE IF / ELSE

    if (carta1.super_poder > carta2.super_poder) {
        printf("A carta 1 (%s - %s) é mais forte com super poder de %llu.\n", 
               carta1.estado, carta1.nome_cidade, carta1.super_poder); // Para mostrar na tela o nome do estado, cidade e os pontos totais do super poder.
    } else if (carta1.super_poder < carta2.super_poder) {
        printf("A carta 2 (%s - %s) é mais forte com super poder de %llu.\n", 
               carta2.estado, carta2.nome_cidade, carta2.super_poder);
    } else {
        printf("As duas cartas têm o mesmo super poder de %llu.\n\n", carta1.super_poder);
    }
}

int main() {
    setlocale(LC_CTYPE, "pt_BR.UTF-8");

    struct cartaEstadoCidade carta1, carta2;

    // Coletar dados das duas cartas
    coletarDados(&carta1, 1);
    coletarDados(&carta2, 2);

    // Exibir dados das duas cartas
    exibirDados(carta1, 1);
    exibirDados(carta2, 2);

    // Comparação entre cartas
    compararCartas(carta1, carta2);

    return 0;
}

