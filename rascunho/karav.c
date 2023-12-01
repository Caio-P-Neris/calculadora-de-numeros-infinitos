#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int* add(int num1[], int len1, int num2[], int len2, int *len_result) {
    int max_len = max(len1, len2);
    int* result = (int*)malloc(sizeof(int) * (max_len + 1));
    int carry = 0;

    for (int i = 0; i < max_len; i++) {
        int sum = carry;
        if (i < len1) sum += num1[i];
        if (i < len2) sum += num2[i];

        result[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result[max_len] = carry;
        *len_result = max_len + 1;
    } else {
        *len_result = max_len;
    }

    return result;
}


int* multiply_vectors_karatsuba(int num1[], int len1, int num2[], int len2, int *len_result) {
    if (len1 == 1 || len2 == 1) {
        // Caso base: multiplicação direta para números pequenos
        int* result = (int*)malloc(sizeof(int) * (len1 + len2));
        *len_result = len1 + len2;
        for (int i = 0; i < *len_result; i++) {
            result[i] = 0;
        }

        for (int i = 0; i < len1; i++) {
            int carry = 0;
            for (int j = 0; j < len2; j++) {
                int temp = num1[i] * num2[j] + result[i + j] + carry;
                carry = temp / 10;
                result[i + j] = temp % 10;
            }

            result[i + len2] += carry;
        }

        return result;
    }

    // Caso recursivo de Karatsuba
    int n = max(len1, len2);
    int mid = n / 2;

    // Dividir os números em partes menores
    int* a = num1;
    int* b = num1 + mid;
    int* c = num2;
    int* d = num2 + mid;

    int len_a = mid;
    int len_b = len1 - mid;
    int len_c = mid;
    int len_d = len2 - mid;

    // Calcular os termos do produto recursivamente
    int* ac = multiply_vectors_karatsuba(a, len_a, c, len_c, len_result);
    int* bd = multiply_vectors_karatsuba(b, len_b, d, len_d, len_result);

    int* abcd = multiply_vectors_karatsuba(add(a, len_a, b, len_b, len_result),
                                          *len_result,
                                          add(c, len_c, d, len_d, len_result),
                                          *len_result,
                                          len_result);

    int* adbc = add(abcd, *len_result, ac, *len_result, len_result);
    adbc = add(adbc, *len_result, bd, *len_result, len_result);

    // Calcular 10^(2*mid) * ac + 10^mid * (ad + bc) + bd
    int* result = (int*)malloc(sizeof(int) * (2 * mid + *len_result));
    for (int i = 0; i < 2 * mid + *len_result; i++) {
        result[i] = 0;
    }

    for (int i = 0; i < *len_result; i++) {
        int sum = adbc[i] + result[mid + i];
        result[mid + i] = sum % 10;
        result[mid + i + 1] += sum / 10;
    }

    for (int i = 0; i < *len_result; i++) {
        int sum = ac[i] + result[2 * mid + i];
        result[2 * mid + i] = sum % 10;
        result[2 * mid + i + 1] += sum / 10;
    }

    for (int i = 0; i < *len_result; i++) {
        int sum = bd[i] + result[i];
        result[i] = sum % 10;
        result[i + 1] += sum / 10;
    }

    *len_result = 2 * mid + *len_result;

    free(ac);
    free(bd);
    free(abcd);
    free(adbc);

    return result;
}

int main() {
    int num1[] = {9, 3, 4};  // Representa o número 439
    int len1 = 3;

    int num2[] = {5, 6, 7};  // Representa o número 765
    int len2 = 3;

    int len_result;
    int* result = multiply_vectors_karatsuba(num1, len1, num2, len2, &len_result);

    // Remover zeros à esquerda do resultado
    int index = len_result - 1;
    while (index > 0 && result[index] == 0) {
        index--;
    }

    // Imprimir resultado
    printf("O resultado da multiplicação é: ");
    for (; index >= 0; index--) {
        printf("%d", result[index]);
    }
    printf("\n");

    free(result);  // Liberar memória alocada dinamicamente

    return 0;
}
