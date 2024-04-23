/*
Rick e Morty resolveram realizar outra aventura no mundo dos sonhos, no entanto, dessa vez eles vão utilizar um dispositivo diferente que necessita de uma calibração manual,da quantidade de energia que deve ser utilizada por esse dispositivo, essa calibração deverá ser feita de acordo com a seguinte série:
Uma série numérica, seguindo o padrão: fica alternando entre adicionar 3 e adicionar o resto da divisão por 5 do numero anterior começando com um valor N dado.Onde N é o tempo em que a primeira pessoa está dormindo. E a cada pessoa que entramos dentro do sono passamos pro elemento seguinte da série.
Faça um algoritmo, recursivo, que calcula qual será o número que será colocado no dispositivo em função do tempo inicial do sonho e a camada dos sonhos que eles estão.
Exemplo:
Caso N seja 0, a série terá o formato:
0 3 6 9 13 16 17 20 20 23 26 29 33 36 37 40 40 43 46...
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void lista(int comeco, int posicao, int contador) {
    if (contador > posicao) {
        printf("%d", comeco);
        return;
    }
    else {
        if (contador % 2 != 0) {
            comeco = comeco + 3;
            lista(comeco, posicao, contador + 1);
        }
        else {
            int valor = comeco % 5;
            comeco = comeco + valor;
            lista(comeco, posicao, contador + 1);
        }
    }
}

int main() {
    
    int comeco, posicao;

    scanf("%d %d", &comeco, &posicao);

    lista(comeco, posicao, 1);

	return 0;

}