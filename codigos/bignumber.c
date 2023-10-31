#include <stdio.h>
#include <math.h>
#include "bignumber.h"
#include <stdlib.h>
#include <string.h>

BigNumber le_numerao(char numerao[200], BigNumber x){

    //BigNumber num; 

    //for(int i = 0 ; numerao[i] != '\n'; i++){ // caso queira ficar invertido 
    for(int i = x.tamanho -2 ; i >= 0; i--){ 
        x.digitos[i] = (numerao[i] - 48) ; //na tab ascii, a diferença é de 48 do cod de char numeral para o int
    //     printf("%d", num.digitos[i]);
    //     }
    // printf("\n");
    }
    return x;

}

void imprime_numerao(BigNumber num){

    //for(int i = tamanho -2 ; i >= 0; i--){ // caso queira ficar invertido
    for(int i = 0 ; i < num.tamanho - 1 ; i++){
        printf("%d", num.digitos[i]);
    }
    printf("\n");
}