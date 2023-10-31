#include <stdio.h>
#include <math.h>
#include "bignumber.h"
#include <stdlib.h>
#include <string.h>

BigNumber le_numerao(char numerao[200], int tamanho){

    BigNumber num; 

    for(int i = tamanho-1 ; i >= 0; i--){
        
        num.digitos[i] = numerao[i] - '\0';
    }

    return num;
}

void imprime_numerao(BigNumber num, int tamanho){

    for(int i = tamanho -1 ; i >= 0; i--){
        printf("%d", num.digitos[i]);
    }
    }