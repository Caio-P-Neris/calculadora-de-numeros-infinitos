//#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include "bignumber.h"
#include <stdlib.h>
#include <string.h>
#define BASE 1000000000 // alterar a base nao funciona, so esta aqui de referencia


BigNumber le_converte(BigNumber x){

    char *numerao = NULL;
    size_t tamanho = 0;

    //printf("Digite o numero grande \n");

    int controle;

    controle = getline(&numerao, &tamanho, stdin);

    if (controle <= 1){
        x.digitos = NULL;
        free(numerao);

        return x;
    }


    tamanho = strlen(numerao);

    //printf(" tamanho %d \n", tamanho);

    x.tamanho = ceil((tamanho-1)/9) +1 ; //-2 para tirar \n e \0

    //printf("n digitos alocado %d \n ", x.tamanho);

    x.digitos = (long long int*)calloc(x.tamanho, sizeof(long long int));

    if (numerao[0] == '-')
        x.sinal = '-';
    else
        x.sinal = '+';


    int j = 0; // controla índice dos dígitos

    for (int i = tamanho - 2; i >= 0 && numerao[i] != '-'; i--) {


        x.digitos[j] +=  (numerao[i] - 48)  * (ceil(pow(10, (tamanho - 2 - i) % 9)));

        //printf("%c\n", numerao[i]);


        // se alcançou 9 dígitos ou chegou ao final da string
        if ((tamanho - 2 - i) % 9 == 8 || i == 0) {
            //printf("%lld\n", x.digitos[j]);
            j++;
        }

    }

    free(numerao);

    return x;

}


void imprime_certo(BigNumber num) {
    //printf("impressao:\n");

    if(num.sinal == '-' && num.digitos[0] == 0){
        //printf("%d \n", num.digitos[0]);
        num.sinal = '+';
    }
    

    if (num.sinal == '-') {
        printf("-");
    }

    int contazero = 0;

    for (int i = num.tamanho - 1; i >= 0; i--) {
        if (num.digitos[i] == 0)
            contazero += 1;
    }

    if (contazero == num.tamanho) {
        printf("%d\n", 0);
        return;
    }



    printf("%lld", num.digitos[num.tamanho-1]);  

    for (int i = num.tamanho - 2; i >= 0; i--) {
        printf("%09lld", num.digitos[i]); // imprime cada bloco de 9 dígitos com zeros à esquerda

    }

    printf("\n");
}


BigNumber somac(BigNumber *maior, BigNumber *menor){
    int i;
    int carry = 0;
    

    for( i =0; i < menor->tamanho ; i++){
        
        maior->digitos[i] += (menor->digitos[i] + carry);
        carry = maior->digitos[i] / 1000000000;

        maior->digitos[i] = maior->digitos[i] % 1000000000;
    }

    if(carry == 1)
        maior->digitos[i] += 1;

    while ( maior->digitos[maior->tamanho -1] == 0){ //serve para retirar digitos que só tem zeros
        maior->tamanho--;
    }


    return *maior;
}

int compara(BigNumber *a, BigNumber *b){
    if(a->tamanho != b->tamanho){
        //printf("a tam %d b tam %d \n", a->tamanho, b->tamanho);
        return 0;
    }else{
        for(int i = 0; i < a->tamanho ; i++){
            //printf("digito a %d  digito b %d \n", a->digitos[i], b->digitos[i]);
            if(a->digitos[i] != b->digitos[i])
                return 0;
        //se ao entrou em nennhum return ate aqui, é igual
        }
        return 1;
    }

}

BigNumber subtracao(BigNumber *maior, BigNumber *menor, char sinal){
    int i; 
    int carry = 0;

    //printf("Sinal na sub %d", sinal);

        for (i = 0; i < menor->tamanho; i++) {
        int diferenca = maior->digitos[i] - menor->digitos[i] - carry;

        if (diferenca < 0) {
            diferenca += 1000000000; // 10^9, pois cada posição contém 9 dígitos

            carry = 1;
        } else {
            carry = 0;
        }

        maior->digitos[i] = diferenca;
    }

    // Tratar carry restante, se houver
    for (i = menor->tamanho; i < maior->tamanho && carry; i++) {
        if (maior->digitos[i] >= carry) {
            maior->digitos[i] -= carry;
            carry = 0;
        } else {
            maior->digitos[i] += 1000000000 - carry; // 10^9

            carry = 1;
        }
    }

    while ( maior->digitos[maior->tamanho -1] == 0){ //serve para retirar digitos que só tem zeros
        maior->tamanho--;
    }

    

    if(sinal == '-')
        maior->sinal = '-';
    else
        maior->sinal = '+';
    
    return *maior;
}

BigNumber muliplica_normal(BigNumber* a, BigNumber *b){
    BigNumber resultado;
    
    resultado.tamanho = a->tamanho + b->tamanho; 

    resultado.digitos = (long long int*)calloc(resultado.tamanho, sizeof(long long int));

    if (a->sinal == b->sinal)
        resultado.sinal = '+';
    else
        resultado.sinal = '-';


    for(int i = 0; i < a->tamanho; i++){
        int carry = 0;
        for (int j = 0; j < b->tamanho; j++){
            long long int temp = a->digitos[i] * b->digitos[j] + resultado.digitos[i + j] + carry;
            carry = temp / BASE;
            resultado.digitos[i + j] = temp % BASE;
        }
        resultado.digitos[i + b->tamanho] += carry;
    }

    while ( resultado.digitos[resultado.tamanho -1] == 0){ //serve para retirar digitos que só tem zeros
        resultado.tamanho--;
    }

        return resultado;
}

