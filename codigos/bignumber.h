#ifndef BIGNUMBER_H
#define BIGNUMBER_H

struct bignumber{
    int *digitos;
    int tamanho;
};

typedef struct bignumber BigNumber;

BigNumber le_numerao( BigNumber x);

void imprime_numerao(BigNumber num);

#endif