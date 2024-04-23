/*
Marquinhos é um aluno do IC.
Ele adora programar, tanto que, num certo dia, muito inspirado pela sua aula de Programação 1, ele resolveu criar um robô!
Marquinhos resolveu chamá-lo de XQ472E-1712, e ele tem a incrível capacidade de imprimir traços e pontos, é incrível não é mesmo!?
Mas não se engane, Marquinhos percebeu algo estranho com o XQ472E-1712, e descobriu que, na verdade, ele possui sua própria linguagem.
Para se comunicar com seu amigo robô, Marquinhos decidiu criar um sistema de comunicação que funciona da seguinte forma:
Ele comunica ao robô um número inteiro, onde o XQ472E-1712 vai imprimir como resposta um '.'(ponto) para cada dígito par desse número e um '-'(traço) para cada dígito ímpar, começando pela unidade.
EXEMPLO:
Número escolhido por Marquinhos -> 4223
O que o robô imprime -> -...
Marquinhos precisa de alguém para ajudá-lo a criar um algoritmo que faça essa conversão para 10 números inteiros, informados por ele, e a resposta do XQ472E-1712 em traços e pontos. Como eu não queria ajudá-lo, eu te indiquei porque você é desenrolado(a)!
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void codigo(int numero, int resultadoQuantidade, int div, int mod) {

    if (resultadoQuantidade == 0) {
        return;
    }
    else {
        int numeroIsolado = (numero / div) % 10;
        if (numeroIsolado % 2 == 0) {
            printf(".");
            codigo(numero, resultadoQuantidade - 1, div * 10, mod);
        }
        else {
            printf("-");
            codigo(numero, resultadoQuantidade - 1, div * 10, mod);
        }
    }

}

int quantidade(int numero, int contador) {

    if (numero == 0) {
        return contador;
    }
    else {
        numero = numero / 10;
        contador = contador + 1;
        quantidade(numero, contador);
    }
    
}

void programa(int primeiroNumero, int quantidadeNumeros) {

    if (quantidadeNumeros < 0) {
        return;
    }
    else {
        int resultadoQuantidade = quantidade(primeiroNumero, 0);
        codigo(primeiroNumero, resultadoQuantidade, 1, 10);
        printf("\n");
        int proximoNumero;
        scanf("%d", &proximoNumero);
        programa(proximoNumero, quantidadeNumeros - 1);
    }

}

int main() {
    
    int numero;

    scanf("%d", &numero);

    programa(numero, 9);

	return 0;

}