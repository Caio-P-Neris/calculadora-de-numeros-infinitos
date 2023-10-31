#include <stdio.h>
#include <math.h>
#include "bignumber.h"
#include <stdlib.h>
#include <string.h>

BigNumber le_numerao( BigNumber x){

    char *numerao = NULL;
    size_t tamanho = 0;

    printf("Digite o numero grande \n");

    getline(&numerao, &tamanho, stdin);

    tamanho = strlen(numerao);

    x.tamanho = tamanho;

    x.digitos = (int*)malloc(tamanho * sizeof(int));


    for(int i = x.tamanho -2 ; i >= 0; i--){ // -2 garante pegar so os numeros, sem '\0' ou '\n'
        x.digitos[i] = (numerao[i] - 48) ; //na tab ascii, a diferença é de 48 do cod de char numeral para o int
    //     printf("%d", x.digitos[i]);
        
    // printf("\n");
    }

    free(numerao);

    return x;

}

void imprime_numerao(BigNumber num){

    for(int i = 0 ; i < num.tamanho - 1 ; i++){
        printf("%d", num.digitos[i]);
    }
    printf("\n");
}