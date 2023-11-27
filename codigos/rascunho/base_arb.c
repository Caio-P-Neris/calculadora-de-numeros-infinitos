#include <stdio.h>
#include <stdlib.h>

void convertToBase(int original[], int originalSize, int result[], int base) {
    int carry = 0;

    for (int i = 0; i < originalSize; ++i) {
        int currentValue = original[i] + carry * 10; // Multiplica pelo valor da base atual

        result[i] = currentValue % base; // Armazena o valor atual na nova base

        carry = currentValue / base; // Calcula o carry para a próxima posição
    }

    // Armazena o valor excedente na próxima posição, se houver
    while (carry > 0) {
        result[originalSize] = carry % base;
        carry /= base;
        ++originalSize;
    }
}

int main() {
    // Exemplo de uso
    int original[] = {1, 2, 3, 4, 5}; // Seu número original armazenado em um vetor
    int originalSize = sizeof(original) / sizeof(original[0]);

    int base = 1000000000; // Base dinâmica (pode ser até 10^9)
    int *result = (int *)malloc((originalSize + 1) * sizeof(int));

    convertToBase(original, originalSize, result, base);

    // Imprime o resultado
    printf("Resultado na base %d: ", base);
    for (int i = originalSize; i >= 0; --i) {
        printf("%d ", result[i]);
    }

    free(result); // Liberar memória alocada dinamicamente

    return 0;
}