#include <stdio.h>
#include "bignumber.h"
#include <string.h>
#include <stdlib.h>
#define MAX 1000000

int main(){

    BigNumber a, b;
    char numerao_a[MAX], numerao_b[MAX];

    printf("DIgite o numerao a: \n");

    fgets(numerao_a, MAX, stdin);

    printf("DIgite o numerao b: \n");
    fgets(numerao_b, MAX, stdin);


    a.tamanho = strlen(numerao_a);
    b.tamanho = strlen(numerao_b);

    a = le_numerao(numerao_a, a);
    imprime_numerao(a);

    b = le_numerao(numerao_b, b);
    imprime_numerao(b);

    return 0;
}