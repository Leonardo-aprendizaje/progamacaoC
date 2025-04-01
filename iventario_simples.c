#include <stdio.h>

int main(){

    char produtoA[30] = "Produto A";
    char produtoB[30] = "Produto B";
    char produtoC[30] = "Produto C";
    char produtoD[30] = "Produto D";

    unsigned int estoqueA = 1000;
    unsigned int estoqueB = 2000;
    unsigned int estoqueC = 3000;
    unsigned int estoqueD = 4000;


    float valorA = 10.00;
    float valorB = 5.80;
    float valorC = 50.00;
    float valorD = 20.20;

    unsigned int estoqueMinimoA = 1010;
    unsigned int estoqueMinimoB = 200;
    unsigned int estoqueMinimoC = 300;
    unsigned int estoqueMinimoD = 100;

    double valorTotalA = estoqueA * valorA;
    double valorTotalB = estoqueB * valorB;
    double valorTotalC = estoqueC * valorC;
    double valorTotalD = estoqueD * valorD;

    int resultadoA;
    int resultadoB;
    int resultadoC;
    int resultadoD;

    //EXIBIR AS INFORMAÇÕES DOS PRODUTOS
    printf("%s tem estoque %u unidades e o valor unitario R$ %.2f\n", produtoA, estoqueA, valorA);
    printf("%s tem estoque %u unidades e o valor unitario R$ %.2f\n", produtoB, estoqueB, valorB);
    printf("%s tem estoque %u unidades e o valor unitario R$ %.2f\n", produtoC, estoqueC, valorC);
    printf("%s tem estoque %u unidades e o valor unitario R$ %.2f\n", produtoD, estoqueD, valorD);


    //COMPARAÇÕES COM O VALOR MÍNIMO DO ESTOQUE
    resultadoA = estoqueA > estoqueMinimoA; // 1 para verdadeiro e 0 para Falso
    resultadoB = estoqueB > estoqueMinimoB;
    resultadoC = estoqueC > estoqueMinimoC;
    resultadoD = estoqueD > estoqueMinimoD;

    printf("O %s têm estoque mínimo %d\n", produtoA, resultadoA);
    printf("O %s têm estoque mínimo %d\n", produtoB, resultadoB);
    printf("O %s têm estoque mínimo %d\n", produtoC, resultadoC);
    printf("O %s têm estoque mínimo %d\n", produtoD, resultadoD);

    //SOMA DOS VALORES TOTAIS EM CADA ESTOQUE POR PRODUTO
    printf("O valor total do estoque A é: R$ %.2f\n", valorTotalA);
    printf("O valor total do estoque B é: R$ %.2f\n", valorTotalB);
    printf("O valor total do estoque C é: R$ %.2f\n", valorTotalC);
    printf("O valor total do estoque D é: R$ %.2f\n", valorTotalD);

    //COMPARAÇÕES ENTRE OS VALORES TOTAIS DOS PRODUTOS
    printf("\nO valor total de A (R$ %.2f) é maior que o valor total de B (R$ %.2f) ?? : %d\n",valorTotalA ,valorTotalB, (valorTotalA > valorTotalB));

    printf("O valor total de C (R$ %.2f) é maior que o valor total de D (R$ %.2f) ?? : %d\n",valorTotalC ,valorTotalD, (valorTotalC > valorTotalD));                         
                           
           
    // 1 = Verdadeiro
    // 0 = Falso


    
    return 0;

}