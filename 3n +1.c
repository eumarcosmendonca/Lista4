/*
Considere o seguinte algoritmo para gerar uma sequência de números. Comece com um inteiro n. Se n for par, divida por 2. Se n for ímpar, multiplique por 3 e some 1. Repita esse processo com o novo valor de n, terminando quando n = 1. Por exemplo, a seguinte sequência de números será gerada quando n é 22:
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Embora ainda não exista uma prova, os matemáticos acreditam que esse algoritmo sempre termina com n=1, para qualquer inteiro n. Bem, para este problema aqui no Huxley, essa propriedade se mantém para qualquer inteiro menor que 1.000.000.
Para uma entrada n, o "tamanho do ciclo" de n é a quantidade de números gerados até o 1 (incluindo o próprio 1). No exemplo acima, o "tamanho do ciclo" de 22 é 16.
Dado dois números i e j, determine o máximo "tamanho do ciclo" dentre todos os números entre i e j, incluindo tanto i quanto j.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int programa2(int numero, int contador) {
    if (numero == 1) {
        return contador;
    }
    else {
        if (numero % 2 == 0) {
            numero = numero / 2;
            programa2(numero, contador + 1);
        }
        else {
            numero = (numero * 3) + 1;
            programa2(numero, contador + 1);
        }
    }
}

int programa1(int comecoIntervalo, int finalIntervalo, int resultadoMaiorCiclo) {
    if (comecoIntervalo > finalIntervalo) {
        return resultadoMaiorCiclo;
    }
    else {
        int resultado = programa2(comecoIntervalo, 1);
        if (resultado >= resultadoMaiorCiclo) {
            resultadoMaiorCiclo = resultado;
        }
        programa1(comecoIntervalo + 1, finalIntervalo, resultadoMaiorCiclo);
    }
}

void principal(int comecoIntervalo, int finalIntervalo) {
    if (scanf("%d %d", &comecoIntervalo, &finalIntervalo) == EOF) {
        return;
    }
    else {
        int a, b;
        if (comecoIntervalo < finalIntervalo) {
            a = comecoIntervalo;
            b = finalIntervalo;
        }
        else if (comecoIntervalo == finalIntervalo) {
            a = comecoIntervalo;
            b = finalIntervalo;
        }
        else {
            a = finalIntervalo;
            b = comecoIntervalo;
        }
        int resultadoFinal = programa1(a, b, 0);
        printf("%d ", comecoIntervalo);
        printf("%d ", finalIntervalo);
        printf("%d", resultadoFinal);
        printf("\n");
        principal(comecoIntervalo, finalIntervalo);
    }
}

int main() {
    
    int comecoIntervalo, finalIntervalo;

    principal(comecoIntervalo, finalIntervalo);

	return 0;

}