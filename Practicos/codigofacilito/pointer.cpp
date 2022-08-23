#include <stdio.h>
int main ()
{
    int a = 2;
    int *apt = &a;
    //scanf("%i",&a);
    printf("%p\n",apt); //%p despliega direccion de memoria como entero HEXADECIMAL
    return 0;
}