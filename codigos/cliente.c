#include <stdio.h>
#include "bignumber.h"
#include <string.h>
#include <stdlib.h>

int main(){

    char numerao[200];
    int tamanho;

    printf("DIgite o numerao: \n");
    // scanf("%c", &numerao);
    fgets(numerao, 200, stdin);

    tamanho = strlen(numerao);
    
    // printf("Seu numerao e %s", numerao);

    BigNumber x = le_numerao(numerao, tamanho);
    imprime_numerao(x, tamanho);

    return 0;
}