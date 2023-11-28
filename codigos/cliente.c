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
    if((a.tamanho > b.tamanho || (a.tamanho == b.tamanho && a.digitos[a.tamanho -1] > b.digitos[b.tamanho -1]))){ // verifica a > b
        imprime_certo(subtracao(&a,&b, 0));
    } else {
        imprime_certo(subtracao(&b,&a, 1));
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