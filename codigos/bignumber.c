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

    //printf("%d", tamanho);

    x.tamanho = tamanho -2 ;// -2 garante pegar so os numeros, sem '\0' ou '\n'

    x.digitos = (int*)malloc(x.tamanho * sizeof(int));


    for(int i = x.tamanho  ; i >= 0; i--){ 
        int j = (x.tamanho ) -i;
    //for(int i = 0; i < x.tamanho ; i++){
        if (numerao[i] == 45 ){
            x.digitos[j] = (numerao[i]); //cod asci p - é 45
        } else
        x.digitos[j] = (numerao[i] - 48) ; //na tab ascii, a diferença é de 48 do cod de char numeral para o int
        //printf("%d", x.digitos[j]);
        
    //printf("\n");
    }

    free(numerao);

    return x;

}

BigNumber le_converte(BigNumber x){
    #define BASE 1000000000

    char *numerao = NULL;
    size_t tamanho = 0;

    printf("Digite o numero grande \n");

    getline(&numerao, &tamanho, stdin);

    tamanho = strlen(numerao);

   printf(" tamanho %d \n", tamanho);

    x.tamanho = ceil((tamanho-1)/9) +1 ; //-2 para tirar \n e \0

    printf("n digitos alocado %d \n ", x.tamanho);

    // arrumar tamanho em relação a sinal

    x.digitos = (int*)calloc(x.tamanho, sizeof(int));

    if (numerao[0] == '-')
        x.sinal = '-';
    else
        x.sinal = '+';


    int j = 0; // controla índice dos dígitos

    for (int i = tamanho - 2; i >= 0 || numerao[i] == '-'; i--) {


        x.digitos[j] +=  (numerao[i] - 48)  * (ceil(pow(10, (tamanho - 2 - i) % 9)));

        //printf("%c\n", numerao[i]);


        // Se alcançou 9 dígitos ou chegou ao final da string
        if ((tamanho - 2 - i) % 9 == 8 || i == 0) {
            printf("%d\n", x.digitos[j]);
            j++;
        }

    }
    // int w = 0; // controla indice dos digitos

    // for(int i = tamanho -2  ; i >= 0 || numerao[i] == '-'; i = i - 9){ 
    // //for(int i = 0; i < x.tamanho ; i++){
    //     // if (numerao[i] == 45){
    //     //     x.digitos[j] = (numerao[i]); //cod asci p - é 45 tem que encerrar
    //     // } else
    //     for(int j = i -8 ; j <= i; j++){
    //         if (numerao[j] < 0)
    //             break;
    //             // i = -1
    //         else{

    //         x.digitos[w] += (numerao[j] - 48) * pow(10, i - j)  ; //na tab ascii, a diferença é de 48 do cod de char numeral para o int
    //         printf("%c \n", numerao[j]);
    //         }
    //     }

    //     x.digitos[w] += 1;

    //     printf("%d \n", x.digitos[w]);
    //     w += 1;
    //printf("\n");
    //}

    free(numerao);

    return x;

}


void imprime_certo(BigNumber num) {
    printf("impressao:\n");

    // Imprime o caractere de sinal, se existir
    if (num.sinal == '-') {
        printf("-");
    }

    for (int i = num.tamanho - 1; i >= 0; i--) {
        printf("%d", num.digitos[i]); // Imprime cada bloco de 9 dígitos com zeros à esquerda
    }

    printf("\n");
}

void imprime_numerao(BigNumber num){

    printf("impressao: \n");

    //for(int i = 0 ; i < num.tamanho - 1 ; i++){
    for(int i = num.tamanho ; i >= 0; i--){   // problema aqui com lixo de memoria
        if (num.digitos[i] == 45){ //pra mostrar o sinal
            printf("%c", num.digitos[i]);
        } else
            printf("%d", num.digitos[i]);
    }
    printf("\n");
}

// BigNumber converte(BigNumber x){
//     #define BASE 2;

//     BigNumber y;
//     y.tamanho = log(x.); //para ter mais um digito se preciso
//     int taman = y.tamanho;

//     y.digitos = (int*) malloc(taman *sizeof(int));

//     int carrega = 0; 

//     for(int i = 0; i < x.tamanho; i++){
//         int atual = x.digitos[i] + carrega *10;

//         y.digitos[i] = atual % BASE; 
//         carrega = atual / BASE;

//     }

//     while (carry > 0) {
//         result[originalSize] = carry % base;
//         carry /= base;
//         ++originalSize;
//     }
// }

//     return y;
// }



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