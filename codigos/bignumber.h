#ifndef BIGNUMBER_H
#define BIGNUMBER_H

struct bignumber{
    int digitos[200];
    int tamanho;
};

typedef struct bignumber BigNumber;

BigNumber le_numerao(char numerao[200], BigNumber x);

void imprime_numerao(BigNumber num);

#endif