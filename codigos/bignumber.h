#ifndef BIGNUMBER_H
#define BIGNUMBER_H

struct bignumber{
    int *digitos;
    long long int tamanho;
    char sinal;
};

typedef struct bignumber BigNumber;

BigNumber le_numerao( BigNumber x);

void imprime_numerao(BigNumber num);

//BigNumber converte(BigNumber x);

BigNumber le_converte(BigNumber x);

BigNumber soma(BigNumber a, BigNumber b);

BigNumber somac(BigNumber *maior, BigNumber *menor);

BigNumber subtracao(BigNumber *maior, BigNumber *menor, int sinal);

void imprime_certo(BigNumber num);

#endif