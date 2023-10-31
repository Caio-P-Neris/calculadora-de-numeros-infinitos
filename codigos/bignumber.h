#ifndef BIGNUMBER_H
#define BIGNUMBER_H

struct bignumber{
    int digitos[200];
};

typedef struct bignumber BigNumber;

BigNumber le_numerao(char numerao[200], int tamanho);

void imprime_numerao(BigNumber num, int tamanho);

#endif