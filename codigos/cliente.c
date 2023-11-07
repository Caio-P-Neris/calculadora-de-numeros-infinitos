#include <stdio.h>
#include "bignumber.h"
#include <string.h>
#include <stdlib.h>


int main(){

    BigNumber a = le_numerao(a);

    imprime_numerao(a);

    BigNumber b = le_numerao(b);

    imprime_numerao(b);

    char operador = getchar();

    switch (operador)
    {
    case '+' :
        imprime_numerao(soma(a,b));
        break;

    // case '-':
    //     subtracao(a,b);
    //     break;

    // case '*':
    //     multiplica(a,b);
    //     break;
    
    // default:
    //     break;
    }

    

    return 0;
}