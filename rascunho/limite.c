#include <stdio.h>
#include <limits.h>

int main() {
    printf("O maior inteiro representável em int: %d\n", INT_MAX);
    printf("O menor inteiro representável em int: %d\n", INT_MIN);

    printf("O maior inteiro representável em unsigned int: %u\n", UINT_MAX);

    printf("O maior inteiro representável em long long int: %lld\n", LLONG_MAX);
    printf("O menor inteiro representável em long long int: %lld\n", LLONG_MIN);

    return 0;
}