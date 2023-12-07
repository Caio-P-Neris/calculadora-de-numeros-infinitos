#include <stdio.h>
#include <string.h>

int main(){
    //int n;

    char* linha = NULL;
    size_t tama = 0;

    int controle = 0;
    //controle = getline(&linha, &tama, stdin);

    while (controle != 1){
        controle = getline(&linha, &tama, stdin);
        printf("Controle %d \n", controle);
    }

    return 0;
}