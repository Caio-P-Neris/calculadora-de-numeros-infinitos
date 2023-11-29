#include <stdio.h>
#include "bignumber.h"
#include <string.h>
#include <stdlib.h>


int main(){

    //BigNumber a = le_numerao(a);

    // imprime_numerao(a);

    BigNumber a = le_converte(a);
    
    //BigNumber a_conv = converte(a);

    imprime_certo(a);

    //getchar();

    BigNumber b = le_converte(b);

    imprime_certo(b);

    char operador = getchar();

    //printf("%c \n", operador);

    if (a.sinal == b.sinal && operador == '+'){
        operador = '+';
    
    }else if( (operador == '+') && ((a.sinal == '+' && b.sinal =='-') || (a.sinal == '-' && b.sinal == '+')) ){
        operador = '-';
        //printf("Esse entra \n");

    // CUIDADO COM SINAL NA MULTIPLICAÇÃO!!


    }else if ((operador == '-') && ((a.sinal == '+' && b.sinal =='-') || (a.sinal == '-' && b.sinal == '+'))){
        operador = '+';
        a.sinal = '-'; 
        b.sinal = '-';
        //printf("entrou \n");
    }else if ((operador == '-') && ((a.sinal == b.sinal))){
        //a.sinal = '-'; 

        printf("entrou aqui? \n");
        if (b.sinal == '+')
            b.sinal = '-';
        else
            b.sinal = '+';

        printf("%c \n", b.sinal);
    }


    switch (operador)
     {
     case '+' :
        //if (a.sinal == b.sinal){
            if( a.digitos > b.digitos)
                imprime_certo(somac(&a,&b));
            else
                imprime_certo(somac(&b,&a));
        // } else if( (a.sinal == '+' && b.sinal =='-') || (a.sinal == '-' && b.sinal == '+') )
        //         operador = '-';
        break;

    case '-':

    printf("dig a : %d \n ", a.digitos[a.tamanho -1]);
    printf("dig b : %d \n ", b.digitos[b.tamanho -1]);

    if(a.tamanho > b.tamanho || (a.tamanho == b.tamanho && (a.digitos[a.tamanho -1] > b.digitos[b.tamanho -1]))){ // verifica a > b
        imprime_certo(subtracao(&a,&b, a.sinal));
    } else {
        imprime_certo(subtracao(&b,&a, b.sinal));
    }
        break;

    // case '*':
    //     multiplica(a,b);
    //     break;
    
    default:
        break;
    }

    free(a.digitos);
    free(b.digitos);

    return 0;
}