#include <stdio.h>

int main(){

    char a = '0', b = '-';

    for(int i = 0; i < 10; i++){
       printf("%c em ascii e %d\n", a, a);
       a+=1; 
    }

    printf("%c em ascii e %d\n", b, b);

    char d = b - 48;

    printf("%c em ascii e %d\n", d, d);

    char f ='-';
    printf("- em acii %d\n", f);
    return 0;

}