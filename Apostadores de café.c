/*
kcaj e Ordep são viciados em apostas, em um belo dia, Sophia apresentou a eles um jogo inovador baseado em batalhas, onde os únicos atributos eram ataque e vida, além disso, as habilidades especiais dos personagens e as regras do jogo eram definidas pelos próprios usuários. Após kcaj e Ordep estudarem bem o jogo, eles decidiram as habilidades e regras do jogo.
REGRAS GERAIS:
Caso a rodada esteja em um número primo, kcaj não atacará e como consequência, não conseguirá usar sua habilidade naquele momento.
Caso a rodada esteja em um número resultante da potência de 2, Ordep não atacará e como consequência, não conseguirá usar sua habilidade naquele momento.
OBS.1: Pode ocorrer das duas regras serem ativadas.
Habilidades de Ordep: Na vez de Ordep, caso a vida de seu boneco seja maior que o ataque, os atributos serão trocados antes de atacar
Habilidade de kcaj: Na vez de kcaj, caso a vida de seu boneco seja ímpar, ele aumenta seu ataque em 5 antes de atacar.
OBS.2: As habilidades podem ativar mais de uma vez na mesma batalha.
Vão ocorrer X batalhas, onde serão dados o ataque e a vida do personagem de Ordep e o ataque e a vida do personagem de kcaj, em cada batalha. Ambos entraram em consenso e determinaram que Ordep sempre vai ser o primeiro a atacar em cada batalha. Uma rodada é composta pelo ataque(ou tentativa, caso a regra seja ativada) de Ordep e Kcaj. Perde aquele na qual o personagem tiver vida menor ou igual a 0 primeiro.
OBS.3: Batalha não é a mesma coisa que rodada, em 1 batalha podemos ter várias rodadas.
OBS.4: Considere que a rodada sempre inicia em 1.
Foi determinado que o perdedor pagaria a quantidade de Batalhas perdidas em café. Caso não tenha um perdedor, ou seja, a batalha resultou em um empate, imprima a mensagem “F coffees”.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int eh_impar(int vida) {
    return vida % 2;
}

int potenciacao(int n, int expoente) {
    double resultado = pow(2, expoente);
    if (resultado == n) {
        return 1;
    }
    else if (resultado > n) {
        return 0;
    }
    else {
        return potenciacao(n, expoente + 1);  
    }
}

int eh_primo(int n, int contador, int x) {
    if (contador > n) {
        return x;
    }
    else {
        if (n % contador == 0) {
            x = x + 1;
        }
        return eh_primo(n, contador + 1, x);
    }
}

int rodada(int ataqueOrdep, int vidaOrdep, int ataqueKcaj, int vidaKcaj, int turno) {
    int resultadoCondicaoOrdep = potenciacao(turno, 0);
    if (resultadoCondicaoOrdep != 1) {
        if (vidaOrdep > ataqueOrdep) {
        int variavelOdep = ataqueOrdep;
        ataqueOrdep = vidaOrdep;
        vidaOrdep = variavelOdep;
        }
        vidaKcaj = vidaKcaj - ataqueOrdep;
        if (vidaKcaj <= 0) {
            return 1;
        }
    }

    int resultadoCondicaoKcaj = eh_primo(turno, 1, 0);
    if (resultadoCondicaoKcaj != 2) {
        int verificacaoVidaKcaj = eh_impar(vidaKcaj);
        if (verificacaoVidaKcaj != 0) {
            ataqueKcaj = ataqueKcaj + 5;
        }
        vidaOrdep = vidaOrdep - ataqueKcaj;
        if (vidaOrdep <= 0) {
            return 2;
        }
    }
    return rodada(ataqueOrdep, vidaOrdep, ataqueKcaj, vidaKcaj, turno + 1);
}

void batalha(int n, int vitoriaOrdep, int vitoriaKcaj) {
    if (n == 0) {
        if (vitoriaOrdep > vitoriaKcaj) {
            printf("ordep ganhou %d coffees", vitoriaOrdep);
            return;
        }
        else if (vitoriaKcaj > vitoriaOrdep) {
            printf("kcaj ganhou %d coffees", vitoriaKcaj);
            return;
        }
        else if (vitoriaOrdep == vitoriaKcaj) {
            printf("F coffees");
            return;
        }
    }
    else {
        int ataqueOrdep, vidaOrdep, ataqueKcaj, vidaKcaj;
        scanf("%d %d %d %d", &ataqueOrdep, &vidaOrdep, &ataqueKcaj, &vidaKcaj);

        int resultadoRodada = rodada(ataqueOrdep, vidaOrdep, ataqueKcaj, vidaKcaj, 1);

        if (resultadoRodada == 1) {
            vitoriaOrdep = vitoriaOrdep + 1;
        }
        else if (resultadoRodada == 2) {
            vitoriaKcaj = vitoriaKcaj + 1;
        }

        batalha(n - 1, vitoriaOrdep, vitoriaKcaj);
    }
}

int main() {

    int n;

    scanf("%d", &n);

    batalha(n, 0, 0);

    return 0;

}