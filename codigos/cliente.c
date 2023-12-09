//#define _GNU_SOURCE
#include <stdio.h>
#include "bignumber.h"
#include <string.h>
#include <stdlib.h>


int main(){

    int controle = 0;
    
    while(controle != 1 ){
    //BigNumber a = le_numerao(a);

    // imprime_numerao(a);

    BigNumber a = le_converte(a);

    //printf("%d", a.digitos[0]);

    if (a.digitos == NULL)
        break;

    
    //BigNumber a_conv = converte(a);

    //imprime_certo(a);

    //getchar();

    BigNumber b = le_converte(b);

    //imprime_certo(b);

    char operador = getchar();

    getchar(); // para tirar o \n após digitar o operador do buffer 

    //printf("%c \n", operador);

    // int comparacao = compara(&a, &b);

    // if(    ((comparacao == 1) && (a.sinal == '+' && b.sinal == '+' && operador =='-' )) // 1 1 -
    //     || ((comparacao == 1) && (a.sinal == '+' && b.sinal == '-' && operador =='+' )) // 1 -1 +
    //     || ((comparacao == 1) && (a.sinal == '-' && b.sinal == '+' && operador =='+' )) // -1 1 +
    //     || ((comparacao == 1) && (a.sinal == '-' && b.sinal == '-' && operador =='-' )) ){ // -1 -1 -
    //     printf("0\n");
    //     operador = '=';

     if (a.sinal == b.sinal && operador == '+'){
        operador = '+';
    
    }else if( (operador == '+') && ((a.sinal == '+' && b.sinal =='-') || (a.sinal == '-' && b.sinal == '+')) ){
        operador = '-';
        //printf("Esse entra \n");

    }else if ((operador == '-') && (a.sinal == '+' && b.sinal =='-')){ //|| (a.sinal == '-' && b.sinal == '+'))){
        operador = '+';
        //a.sinal = '+'; 
        b.sinal = '+';
        //printf("entrou \n");
    }else if((operador == '-') &&(a.sinal == '-' && b.sinal == '+')){
        operador = '+';
        b.sinal ='-';
    
    }else if ((operador == '-') && ((a.sinal == b.sinal))){
        //a.sinal = '-'; 

        //printf("entrou aqui? \n");
        if (b.sinal == '+')
            b.sinal = '-';
        else
            b.sinal = '+';

        //printf("%c \n", b.sinal);
    }


    switch (operador)
     {
     case '+' :
        //if (a.sinal == b.sinal){
            if( a.tamanho > b.tamanho )
                imprime_certo(somac(&a,&b));
            else
                imprime_certo(somac(&b,&a));
        // } else if( (a.sinal == '+' && b.sinal =='-') || (a.sinal == '-' && b.sinal == '+') )
        //         operador = '-';
        break;

    case '-':

    // printf("dig a : %d \n ", a.digitos[a.tamanho -1]);
    // printf("dig b : %d \n ", b.digitos[b.tamanho -1]);

    //printf("%d \n", a.digitos[a.tamanho-1]);
    //printf("%d \n", b.digitos[b.tamanho-1]);

    int ind_maior_a, ind_maior_b, t_a, t_b;

    if (a.digitos[a.tamanho - 1] == 0) {
        ind_maior_a = a.tamanho - 2;
        t_a = a.tamanho - 1;
    } else {
        ind_maior_a = a.tamanho - 1;
        t_a = a.tamanho;
    }

    if (b.digitos[b.tamanho - 1] == 0) {
        ind_maior_b = b.tamanho - 2;
        t_b = b.tamanho - 1;
    } else {
        ind_maior_b = b.tamanho - 1;
        t_b = b.tamanho;
    }

    // essas confições servem para desconsiderar que os dois numeros podem ficar iguais por causa de zero a esquerda ou o digito extra pro carry


    if(t_a > t_b || (t_a == t_b && (a.digitos[ind_maior_a] > b.digitos[ind_maior_b]))){ // verifica a > b
        imprime_certo(subtracao(&a,&b, a.sinal));
    } else {
        imprime_certo(subtracao(&b,&a, b.sinal));
    }
        break;


    case '*':
    
    //BigNumber resultado;

    // if (a.tamanho > b.tamanho)
    //     resultado.tamanho = 2*a.tamanho;
    // else 
    //     resultado.tamanho = 2*b.tamanho;

    //resultado.tamanho = a.tamanho + b.tamanho; 

    //resultado.digitos = (long long int*)calloc(resultado.tamanho, sizeof(long long int));

    // if (a.sinal == a.sinal)
    //     resultado.sinal = '+';
    // else
    //     resultado.sinal = '-';

    // if(a.tamanho > b.tamanho || (a.tamanho == b.tamanho && (a.digitos[a.tamanho -1] > b.digitos[b.tamanho -1])))
    //     (multiplicacao_karatsuba(&a,&b, &resultado));
    // else
    //(multiplicacao_karatsuba(&a,&b, &resultado));
    
    // resultado = multiplicacao_karatsuba(&a, &b);

    // if (a.sinal == b.sinal)
    //     resultado.sinal = '+';
    // else
    //     resultado.sinal = '-';
    
    //imprime_certo(resultado);


    //free(resultado.digitos);

    imprime_certo(muliplica_normal(&a, &b));
        break;
    
    default:
        break;
    }

    free(a.digitos);
    free(b.digitos);
    }
    return 0;
}