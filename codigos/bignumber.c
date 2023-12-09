//#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include "bignumber.h"
#include <stdlib.h>
#include <string.h>
#define BASE 1000000000

// BigNumber le_numerao( BigNumber x){

//     char *numerao = NULL;
//     size_t tamanho = 0;

//     printf("Digite o numero grande \n");

//     getline(&numerao, &tamanho, stdin);

//     tamanho = strlen(numerao);

//     //printf("%d", tamanho);

//     x.tamanho = tamanho -2 ;// -2 garante pegar so os numeros, sem '\0' ou '\n'

//     x.digitos = (int*)malloc(x.tamanho * sizeof(int));


//     for(int i = x.tamanho  ; i >= 0; i--){ 
//         int j = (x.tamanho ) -i;
//     //for(int i = 0; i < x.tamanho ; i++){
//         if (numerao[i] == 45 ){
//             x.digitos[j] = (numerao[i]); //cod asci p - é 45
//         } else
//         x.digitos[j] = (numerao[i] - 48) ; //na tab ascii, a diferença é de 48 do cod de char numeral para o int
//         //printf("%d", x.digitos[j]);
        
//     //printf("\n");
//     }

//     free(numerao);

//     return x;

// }

// int controla(int controle){
//     if (controle == 0)
//         return 0;
//     else
//         return 1;
// }

BigNumber le_converte(BigNumber x){

    char *numerao = NULL;
    size_t tamanho = 0;

    //printf("Digite o numero grande \n");

    int controle;

    controle = getline(&numerao, &tamanho, stdin);

    if (controle <= 1){
        x.digitos = NULL;
        free(numerao);
        //printf("entrou ! \n");
        return x;
    }


    tamanho = strlen(numerao);

    //printf(" tamanho %d \n", tamanho);

    x.tamanho = ceil((tamanho-1)/9) +1 ; //-2 para tirar \n e \0

    //printf("n digitos alocado %d \n ", x.tamanho);

    // arrumar tamanho em relação a sinal

    x.digitos = (long long int*)calloc(x.tamanho, sizeof(long long int));

    if (numerao[0] == '-')
        x.sinal = '-';
    else
        x.sinal = '+';


    int j = 0; // controla índice dos dígitos

    for (int i = tamanho - 2; i >= 0 && numerao[i] != '-'; i--) {


        x.digitos[j] +=  (numerao[i] - 48)  * (ceil(pow(10, (tamanho - 2 - i) % 9)));

        //printf("%c\n", numerao[i]);


        // Se alcançou 9 dígitos ou chegou ao final da string
        if ((tamanho - 2 - i) % 9 == 8 || i == 0) {
            //printf("%lld\n", x.digitos[j]);
            j++;
        }

    }

    // while ( x.digitos[x.tamanho -1] == 0){ //serve para retirar digitos que só tem zeros
    //     x.tamanho--;
    // }
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


    //printf("impressao:\n");

    if(num.sinal == '-' && num.digitos[0] == 0){
        //printf("%d \n", num.digitos[0]);
        num.sinal = '+';
    }

    

    if (num.sinal == '-') {
        printf("-");
    }

    printf("%lld", num.digitos[num.tamanho-1]);  

    for (int i = num.tamanho - 2; i >= 0; i--) {
        if (num.digitos[i] != 0)
            printf("%09lld", num.digitos[i]); // Imprime cada bloco de 9 dígitos com zeros à esquerda
        else
            printf("%d\n", 0);
    }

    printf("\n");
}

// void imprime_numerao(BigNumber num){

//     printf("impressao: \n");

//     //for(int i = 0 ; i < num.tamanho - 1 ; i++){
//     for(int i = num.tamanho ; i >= 0; i--){   // problema aqui com lixo de memoria
//         if (num.digitos[i] == 45){ //pra mostrar o sinal
//             printf("%c", num.digitos[i]);
//         } else
//             printf("%d", num.digitos[i]);
//     }
//     printf("\n");
// }

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

    for( i =0; i < menor->tamanho ; i++){

        if(maior->digitos[i] >= menor->digitos[i]){
            maior->digitos[i] -= menor->digitos[i] + carry;
            carry = 0;
        }else{
            //int numero = maior->digitos[i];

            int dig_vetor = sizeof(maior->digitos[i] / sizeof(int));

            //printf(" %d numero de digitos no vetor %d\n ", dig_vetor, i);
            
            maior->digitos[i] = maior->digitos[i] *(int)ceil(pow(10, dig_vetor)) - menor->digitos[i];
             
            carry = -1;
        } 

    // while ( maior->digitos[maior->tamanho -1] == 0){ //serve para retirar digitos que só tem zeros
    //     maior->tamanho--;
    // }

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

// void multiplicacao_karatsuba(const BigNumber* a, const BigNumber* b, BigNumber* resultado) {
//     if (a->tamanho == 1 && b->tamanho == 1) {
//         // Caso base: multiplicação de dígitos únicos
//         int produto = a->digitos[0] * b->digitos[0];

//         resultado->digitos[0] = produto % BASE;
//         if( produto % BASE != 0)
//             resultado->digitos[1] = produto / BASE;

//         return;
//     }

//     // Divisão dos números em duas partes
//     int meio = (a->tamanho > b->tamanho) ? floor(b->tamanho / 2) : floor(a->tamanho / 2) ;

//     BigNumber a1, a2, b1, b2;
//     a1.tamanho = meio;
//     a1.digitos = a->digitos;
//     a1.sinal = a->sinal;

//     a2.tamanho = a->tamanho - meio;
//     a2.digitos = a->digitos + meio;
//     a2.sinal = a->sinal;

//     b1.tamanho = meio;
//     b1.digitos = b->digitos;
//     b1.sinal = b->sinal;

//     b2.tamanho = b->tamanho - meio;
//     b2.digitos = b->digitos + meio;
//     b2.sinal = b->sinal;

//     // Recursivamente calcula três produtos
//     BigNumber z0, z1, z2;
//     z0.tamanho = a->tamanho + b->tamanho - 1;
//     z0.digitos = (long long int*)calloc(z0.tamanho, sizeof(long long int));
//     z1.tamanho = a->tamanho + b->tamanho - 1;
//     z1.digitos = (long long int*)calloc(z1.tamanho, sizeof(long long int));
//     z2.tamanho = a->tamanho + b->tamanho - 1;
//     z2.digitos = (long long int*)calloc(z2.tamanho, sizeof(long long int));

//     multiplicacao_karatsuba(&a1, &b1, &z0);
//     BigNumber a_plus_a2, b_plus_b2;
//     somac(&a1, &a2, &a_plus_a2);
//     somac(&b1, &b2, &b_plus_b2);
//     multiplicacao_karatsuba(&a_plus_a2, &b_plus_b2, &z1);
//     multiplicacao_karatsuba(&a2, &b2, &z2);

//     // Combina os produtos para obter o resultado final
//     for (int i = 0; i < z0.tamanho; i++) {
//         resultado->digitos[i] += z0.digitos[i];
//     }

//     for (int i = 0; i < z1.tamanho; i++) {
//         resultado->digitos[i + meio] += z1.digitos[i];
//     }

//     for (int i = 0; i < z2.tamanho; i++) {
//         resultado->digitos[i + 2 * meio] += z2.digitos[i];
//     }

//     // Trata os casos de carry
//     int j = 0;
//     while (j < resultado->tamanho - 1 && resultado->digitos[j] >= BASE) {
//         resultado->digitos[j + 1] += resultado->digitos[j] / BASE;
//         resultado->digitos[j] %= BASE;
//         j++;
//     }

//     resultado->sinal = (a->sinal == b->sinal) ? '+' : '-';

//     // Libera memória utilizada pelos produtos intermediários
//     free(z0.digitos);
//     free(z1.digitos);
//     free(z2.digitos);
// }




// BigNumber soma(BigNumber a, BigNumber b){
//     BigNumber maior, menor;
    
//     if( a.tamanho < b.tamanho){
//         menor = a;
//         maior = b;
//     }else{
//         menor = b;
//         maior = a;
//     }

//     for(int i = 0; i < menor.tamanho +1 ; i++){
//     //for(int i = menor.tamanho -2; i >= 0; i--){
//         int soma = maior.digitos[i] + menor.digitos[i];
        
//         printf("iteracao %d soma -> %d \n", i, soma);

//         if (soma > 9 && (menor.tamanho) != i) {
//             maior.digitos[i+1] += 1;
//             maior.digitos[i] = soma % 10;
//         //}else if (soma > 9 && (menor.tamanho +1) == i){
            

//         }else
//             maior.digitos[i] += menor.digitos[i];
//     }


//     return maior;
// }