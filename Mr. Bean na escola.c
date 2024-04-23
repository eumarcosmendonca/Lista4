/*
O famoso personagem de televisão "Mr.Bean" está para fazer uma prova de matemática, nessa prova ele pode usar ajuda de um algoritmo para responder as questões. Porém nosso querido personagem não sabe programar, e ele tem um amigo que está estudando programação, e esse amigo é você.
Seu programa vai receber um número "N", que corresponde a quantidade de entradas, e abaixo dele N números aleatórios. 
Você deve imprimir:
O maior número par (se não receber números pares deve ser impressa a mensagem que será mostrada na saída)
O menor número ímpar (se não receber números ímpares deve ser impressa a mensagem que será mostrada na saída)
O primeiro primo que seja menor e mais próximo ao maior número par (Exemplo: Se você tem 8 como o maior número par, o primo mais próximo dele e que é menor que ele seria o 7).
O primeiro primo que seja menor e mais próximo ao menor número ímpar (Exemplo: Se você tem 7 como o menor número ímpar, o primo mais próximo dele e que é menor que ele seria o 5).
Mr. Bean Ficaria muito grato se você conseguir ajudá-lo.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int verificador(int n, int contador, int resultado) {
    if (contador > n) {
        return resultado;
    }
    else {
        if (n % contador == 0) {
            resultado = resultado + 1;
        }
        verificador(n, contador + 1, resultado);
    }
}

int primoMenor(int n, int resultado) {
    if (n == 0) {
        return resultado;
    }
    else {
        n = n - 1;
        int teste = verificador(n, 1, 0);
        if (teste == 2) {
            resultado = n;
            return resultado;
        }
        primoMenor(n, resultado);
    }
}

int parOuImpar(int n) {
    return n % 2;
}

void rodadas(int n, int numero, int maiorPar, int menorImpar, int resultadoPrimoMenorProximoPar, int resultadoPrimoMenorProximoImpar) {
    if (n == 0) {
        resultadoPrimoMenorProximoPar = primoMenor(maiorPar, 0);
        resultadoPrimoMenorProximoImpar = primoMenor(menorImpar, 0);
        if (maiorPar == 0 && menorImpar != 0) {
            printf("Sem numeros pares\n");
            printf("Menor impar: %d\n", menorImpar);
            printf("Primo anterior ao menor: %d\n", resultadoPrimoMenorProximoImpar);
            return;
        }
        else if (maiorPar != 0 && menorImpar == 0) {
            printf("Maior par: %d\n", maiorPar);
            printf("Primo anterior ao maior: %d\n", resultadoPrimoMenorProximoPar);
            printf("Sem numeros impares");
            return;
        }
        else if (maiorPar != 0 && menorImpar != 0) {
            printf("Maior par: %d\n", maiorPar);
            printf("Primo anterior ao maior: %d\n", resultadoPrimoMenorProximoPar);
            printf("Menor impar: %d\n", menorImpar);
            printf("Primo anterior ao menor: %d\n", resultadoPrimoMenorProximoImpar);
            return;
        }
    }
    else {
        scanf("%d", &numero);
        int resultadoParImpar = parOuImpar(numero);
        if (resultadoParImpar == 0) {
            if (numero > maiorPar) {
                maiorPar = numero;
            }
        }
        if (resultadoParImpar != 0) {
            if (menorImpar == 0) {
                menorImpar = numero;
            }
            else if (numero < menorImpar) {
                menorImpar = numero;
            }
        }
        rodadas(n - 1, numero, maiorPar, menorImpar, resultadoPrimoMenorProximoPar, resultadoPrimoMenorProximoImpar);
    }
}

int main() {
    
    int n;

    scanf("%d", &n);

    rodadas(n, 0, 0, 0, 0, 0);

    return 0;

}