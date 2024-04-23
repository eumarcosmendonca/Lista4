/*
Faça um programa que mostre os n primeiros termos e calcule o resultado da seguinte série:
1!/1 + 2!/2 + 3!/3 + 4!/5 + 5!/5 + 6!/7 + 7!/7 + 8!/11 + 9!/11 ...
A cada termo são apresentados no dividendo o fatorial dos números naturais não nulos. No divisor, a partir do segundo termo, temos o menor número primo que seja maior ou igual ao dividendo.
Nesse programa você deve fazer pelo menos 3 funções:
eh_primo(x): Retorna True ou False se um número é primo ou não
proximo_primo(y): Retorna o próximo número primo a partir de um número y dado
fatorial(z): Retorna o fatorial de um número
O retorno deve ser os termos da série e o resultado da soma.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int eh_primo(int numero, int contador, int resultado) {
    if (contador > numero) {
        return resultado;
    }
    else {
        if (numero % contador == 0) {
            resultado = resultado + 1;
        }
        return eh_primo(numero, contador + 1, resultado);
    }
}

int proximo_primo(int numero, int resultado) {
    if (resultado == 2) {
        return numero - 1;
    }
    else {
        resultado = eh_primo(numero, 1, 0);
        proximo_primo(numero + 1, resultado);
    }
}

int fatorial(int numero) {
    if (numero == 1) {
        return 1;
    }
    else {
        return numero * fatorial(numero - 1);
    }
}

double programa(int numero, int contador, double valorTotal) {
    if (contador > numero) {
        return valorTotal;
    }
    else {
        printf("%d!/", contador);
        int proximoPrimo;
        if (contador == 1) {
            proximoPrimo = 1;
        }
        else if (contador == 2) {
            proximoPrimo = 2;
        }
        else if (contador == 3) {
            proximoPrimo = 3;
        }
        else {
            proximoPrimo = proximo_primo(contador, 0);
        }
        if (contador == numero) {
            printf("%d", proximoPrimo);
        }
        else if (contador < numero) {
            printf("%d + ", proximoPrimo);
        }
        valorTotal = (valorTotal + ((double)fatorial(contador) / (double)proximoPrimo));
        programa(numero, contador + 1, valorTotal);
    }
}

int main() {
    
    int numero;

    scanf("%d", &numero);

    double resultado = programa(numero, 1, 0);

    printf("\n");
    printf("%.2lf", resultado);

	return 0;

}