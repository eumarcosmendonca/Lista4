/*
Há muito tempo atrás, existia uma muralha infinita que separava dois reinos em guerra. Os guardas da muralha não deveriam deixar ninguém passar de uma lado para outro, entretanto, como eram tempos de crise, eles sempre aceitavam moedas de prata para deixar que uma pessoa atravessasse a muralha.
Um viajante, chamado Vaqueiro, precisava seguir um plano de viagem entregue a ele por seu mestre, mas como vaqueiro nunca foi muito bom de matemática, ele precisa de sua ajuda para determinar o número mínimo de moedas de prata que ele precisa levar em sua jornada.
Na antiguidade, como sabemos, todos imaginavam que a terra era plana, por isso, podemos visualizar a terra como um grande plano cartesiano infinito, onde a muralha em questão é representada pela reta y - x = 0, e um dos reinos está na parte de baixo da reta, região em que y < x, e outro na parte superior dela, região em que y > x. Sabe-se também que os guardas cobram 1 moeda de prata para cada viajante que deseja atravessar a muralha.
Vaqueiro irá começar sua jornada na posição (0, 0) e a cada movimento ele pode ir para direita, 'D', e sair da posição (x, y) para posição (x+1, y), ou para cima, 'C', e sair da posição (x, y) para posição (x, y+1). Você recebera o plano de viagem que Vaqueiro deve seguir, que consiste em um inteiro N, indicando o numero de dias da viagem, seguido por N linhas, cada uma contendo um caractere 'D', ou 'C', indicando que naquele dia Vaqueiro realizará um movimento para direita ou para cima.
Sua tarefa é dizer a Vaqueiro quantas moedas de prata são necessárias para realizar todo o percurso, ou seja, quantas vezes Vaqueiro vai atravessar a reta y - x = 0 durante sua viagem. Note que, caso Vaqueiro apenas chegue na muralha, mas retorne em seguida para o mesmo reino em que já se encontrava, ele não deverá pagar nenhuma moeda para os guardas.
Considere que no início vaqueiro já está do lado correto da muralha, ou seja, ele não precisará pagar nenhuma moeda de prata no seu primeiro dia de viagem.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int turnos(int rodadas, int x, int y, char posicao, int contador, int moedas, char charMaior) {
    if (contador >= rodadas) {
        return moedas;
    }
    else {
        scanf(" %c", &posicao);
        if (contador == 0) {
            if (posicao == 'D') {
                x = x + 1;
            }
            if (posicao == 'C') {
                y = y + 1;
            }
            if (x > y) {
                charMaior = 'X';
            }
            if (y > x) {
                charMaior = 'Y';
            }
        }
        else {
            if (posicao == 'D') {
                x = x + 1;
            }
            if (posicao == 'C') {
                y = y + 1;
            }
            if (x > y && charMaior == 'Y') {
                moedas = moedas + 1;
                charMaior = 'X';
            }
            if (y > x && charMaior == 'X') {
                moedas = moedas + 1;
                charMaior = 'Y';
            }
        }
        return turnos(rodadas, x, y, posicao, contador + 1, moedas, charMaior);
    }
}

int main() {

    int rodadas;

    scanf("%d", &rodadas);

    int resultado = turnos(rodadas, 0, 0, 'A', 0, 0, 'A');

    printf("%d", resultado);

    return 0;

}