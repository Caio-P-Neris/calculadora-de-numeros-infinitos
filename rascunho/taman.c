#include <stdio.h>

int main(){

    int num1[] = {5, 7, 8, 9};

    int n_dig = sizeof(num1)/ sizeof(int);

    printf("%d", n_dig); 

    return 0;
}