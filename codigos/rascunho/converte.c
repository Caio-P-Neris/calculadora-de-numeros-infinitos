#include <stdio.h>
#include <stdlib.h>

// Função para converter um número para qualquer base
char* convertToBase(unsigned int numero, int base) {
    // Verifica se a base é válida
    if (base < 2 || base > 256) {
        printf("Base inválida. A base deve estar entre 2 e 256.\n");
        return NULL;
    }

    // Tamanho máximo da string resultante
    int tamanhoMaximo = 32;  // Ajuste conforme necessário

    // Aloca espaço para a string resultante
    char* resultado = (char*)malloc(tamanhoMaximo * sizeof(char));

    // Índice para a string resultante
    int indice = 0;

    // Verifica se a alocação de memória foi bem-sucedida
    if (resultado == NULL) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    // Lida com o caso especial do número 0
    if (numero == 0) {
        resultado[indice++] = '0';
        resultado[indice] = '\0';  // Adiciona o terminador de string
        return resultado;
    }

    // Converte o número para a base especificada
    while (numero > 0) {
        int resto = numero % base;
        if (resto < 10) {
            resultado[indice++] = resto + '0';
        } else {
            resultado[indice++] = resto - 10 + 'A';
        }
        numero = numero / base;
    }

    // Adiciona o terminador de string
    resultado[indice] = '\0';

    // Inverte a string resultante, pois os dígitos foram adicionados do último para o primeiro
    int i, j;
    char temp;
    for (i = 0, j = indice - 1; i < j; i++, j--) {
        temp = resultado[i];
        resultado[i] = resultado[j];
        resultado[j] = temp;
    }

    return resultado;
}

int main() {
    // Exemplo de uso
    unsigned int numero = 12345;
    int base = 2;

    char* resultado = convertToBase(numero, base);

    if (resultado != NULL) {
        printf("O numero %u na base %d e %s\n", numero, base, resultado);

        // Libera a memória alocada para a string resultante
        free(resultado);
    }

    return 0;
}