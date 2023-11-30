#include <stdio.h>
#include <math.h>

int countDigits(long long int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        ++count;
    }
    return count;
}

void karatsuba(long long int x, long long int y, long long int *result) {
    if (x < 10 || y < 10) {
        *result = x * y;
    } else {
        // Calcula o número total de dígitos em x e y
        int n = fmax(countDigits(x), countDigits(y));
        int half = n / 2;

        // Calcula as potências de 10 para dividir os números
        long long int i1 = pow(10, half);
        long long int i2 = pow(10, 2 * half);

        // Divide os números em partes menores
        long long int a = x / i1;
        long long int b = x % i1;
        long long int c = y / i1;
        long long int d = y % i1;

        // Chama a função recursivamente
        long long int ac, bd, ad_plus_bc;
        karatsuba(a, c, &ac);
        karatsuba(b, d, &bd);
        karatsuba(a + b, c + d, &ad_plus_bc);

        // Calcula o resultado final
        ad_plus_bc = ad_plus_bc - ac - bd;
        *result = ac * i2 + ad_plus_bc * i1 + bd;
    }
}

int main() {
    long long int x = 1234;
    long long int y = 999999999;
    long long int result;

    karatsuba(x, y, &result);

    printf("O produto de %lld e %lld é %lld\n", x, y, result);

    return 0;
}
