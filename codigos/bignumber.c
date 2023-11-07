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

    x.tamanho = tamanho -2 ;

    x.digitos = (int*)malloc(tamanho * sizeof(int));


    for(int i = x.tamanho  ; i >= 0; i--){ // -2 garante pegar so os numeros, sem '\0' ou '\n'
        int j = (x.tamanho ) -i;
    //for(int i = 0; i < x.tamanho ; i++){
        if (numerao[i] == 45){
            x.digitos[j] = (numerao[i]); //cod asci p - é 45
        } else
        x.digitos[j] = (numerao[i] - 48) ; //na tab ascii, a diferença é de 48 do cod de char numeral para o int
        printf("%d", x.digitos[j]);
        
    printf("\n");
    }

    free(numerao);

    return x;

}

void imprime_numerao(BigNumber num){

    printf("impressao: \n");

    //for(int i = 0 ; i < num.tamanho - 1 ; i++){
    for(int i = num.tamanho ; i >= 0; i--){   // problema aqui com lixo de memoria
        if (num.digitos[i] == 45){
            printf("%c", num.digitos[i]);
        } else
            printf("%d", num.digitos[i]);
    }
    printf("\n");
}

BigNumber soma(BigNumber a, BigNumber b){
    BigNumber maior, menor;
    
    if( a.tamanho < b.tamanho){
        menor = a;
        maior = b;
    }else{
        menor = b;
        maior = a;
    }

    for(int i = 0; i < menor.tamanho +1 ; i++){
    //for(int i = menor.tamanho -2; i >= 0; i--){
        int soma = maior.digitos[i] + menor.digitos[i];
        
        printf("iteracao %d soma -> %d \n", i, soma);

        if (soma > 9 && (menor.tamanho) != i) {
            maior.digitos[i+1] += 1;
            maior.digitos[i] = soma % 10;
        //}else if (soma > 9 && (menor.tamanho +1) == i){
            

        }else
            maior.digitos[i] += menor.digitos[i];
    }


    return maior;
}