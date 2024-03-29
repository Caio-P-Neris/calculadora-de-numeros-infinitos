//#define _GNU_SOURCE
#include <stdio.h>
#include "bignumber.h"
#include <string.h>
#include <stdlib.h>


int main(){

    int controle = 0;
    
    while(controle != 1 ){

    BigNumber a = le_converte(a);

    //printf("%d", a.digitos[0]);

    if (a.digitos == NULL){
        free(a.digitos);
        break;
    }


    BigNumber b = le_converte(b);

    //imprime_certo(b);

    char operador = getchar();

    getchar(); // para tirar o \n após digitar o operador do buffer 

    //printf("%c \n", operador);


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

            if( a.tamanho > b.tamanho )
                imprime_certo(somac(&a,&b));
            else
                imprime_certo(somac(&b,&a));
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

        while( a.digitos[ind_maior_a ] == b.digitos[ind_maior_b ]){
            ind_maior_a--;
            ind_maior_b--;

        }

        if(t_a > t_b || (t_a == t_b && (a.digitos[ind_maior_a] > b.digitos[ind_maior_b]))){ // verifica a > b
            imprime_certo(subtracao(&a,&b, a.sinal));

        } else {
            imprime_certo(subtracao(&b,&a, b.sinal));
        }
        
            break;


    case '*':

        BigNumber resultado = muliplica_normal(&a, &b);

        imprime_certo(resultado);

        free(resultado.digitos);
        
            break;
    
    default:
        break;
    }

    free(a.digitos);
    free(b.digitos);
    }
    return 0;
}