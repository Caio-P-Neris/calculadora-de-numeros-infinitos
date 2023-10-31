#include <stdio.h>

int main(){

    char a = '0', b = '\n';

    for(int i = 0; i < 10; i++){
       printf("%c em ascii e %d\n", a, a);
       a+=1; 
    }

    printf("%c em ascii e %d\n", b, b);

    return 0;
}