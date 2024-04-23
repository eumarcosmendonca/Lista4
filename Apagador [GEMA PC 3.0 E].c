/*
A Entidade vai participar de uma competição matemática. Nessa competição, existirá vários números de três dígitos e o objetivo é apagar exatamente um dígito de forma que o número resultante seja o maior possível.
A Entidade quer treinar para a competição, mas precisa de um programa que sempre faça a melhor escolha para poder comparar seu desempenho. Faça um programa que receba um número n de três dígitos e informe o maior número x que pode ser formado apagando exatamente um único dígito.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int teste(int numero) {
    int a, b, c, soma1, soma2, soma3;
    int maiorSoma = 0;
    a = numero % 10;
    b = (numero / 10) % 10;
    c = numero / 100;

    soma1 = c * 10 + a;
    if (soma1 > maiorSoma) {
        maiorSoma = soma1;
    }

    soma2 = c * 10 + b;
    if (soma2 > maiorSoma) {
        maiorSoma = soma2;
    }

    soma3 = b * 10 + a;
    if (soma3 > maiorSoma) {
        maiorSoma = soma3;
    }

    printf("%d", maiorSoma);

    return 0;

}

void turnos(int quantidade) {

    if (quantidade == 0) {

        return;

    }
    else {

        int numero;
        scanf("%d", &numero);
        teste(numero);
        printf("\n");
        turnos(quantidade - 1);
        
    }

}

int main() {

    int quantidade;

    scanf("%d", &quantidade);

    turnos(quantidade);

	return 0;

}