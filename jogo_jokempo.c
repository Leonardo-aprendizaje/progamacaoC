#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    char jogador [20];
    int escolhaJogador, escolhaComputador;
    srand(time(0));

    printf("*** jogo de jokempô ***\n");
    printf("Digite seu nome: ");
    scanf("%s", jogador);
    printf("Escolha uma opção: \n");
    printf("1. Pedra  \n");// Ganha da tesoura
    printf("2. Papel  \n");// Ganha da Pedra
    printf("3. Tesoura\n");// Ganha do Papel
    printf("\nEscolha: ");
    scanf("%d", &escolhaJogador);

    escolhaComputador = rand() % 3 + 1;//Resto da divisão 

    switch (escolhaJogador) {
        case 1:
            printf("%s: Pedra\n", jogador);
            break;
        case 2:
            printf("%s: Papel\n", jogador);
            break;
        case 3:
            printf("%s: Tesoura\n", jogador);
            break;
    
        default:
            printf("Opção inválida\n");
            break;
    }
    switch (escolhaComputador) {
        case 1:
            printf("Computador: Pedra\n");
            break;
        case 2:
            printf("Computador: Papel\n");
            break;
        case 3:
            printf("Computador: Tesoura\n");
            break;
    }

    if (escolhaComputador == escolhaJogador) {
            printf("\n### Jogo empatou! ###\n\n");
    } 
    else if ((escolhaJogador == 1) && (escolhaComputador == 3) || 
               (escolhaJogador == 2) && (escolhaComputador == 1) || 
               (escolhaJogador == 3) && (escolhaComputador == 2)) {
            printf("\n### Parabéns %s, você ganhou! ### \n", jogador);
    } 
    else {
            printf("\n### %s perdeu! ###\n", jogador);
    }
    
    
return 0;

}