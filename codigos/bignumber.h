#ifndef BIGNUMBER_H
#define BIGNUMBER_H

struct bignumber{
    long long int *digitos;
    long long int tamanho;
    char sinal;
};

typedef struct bignumber BigNumber;

BigNumber le_converte(BigNumber x);

BigNumber somac(BigNumber *maior, BigNumber *menor);

BigNumber subtracao(BigNumber *maior, BigNumber *menor, char sinal  );

BigNumber muliplica_normal(BigNumber* a, BigNumber *b);

void imprime_certo(BigNumber num);

#endif