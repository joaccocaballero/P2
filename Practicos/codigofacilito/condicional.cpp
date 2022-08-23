#include <stdio.h>
int main ()
{
    int edad;
    printf("ingresa edad\n");
    scanf("%d",&edad);
    if (edad>=18)
    {
        printf("eres mayor de edad\n");
    }else if (edad==17)
    {
        printf("eres casi mayor de edad\n");
    }else
    {
        printf("eres mayor de edad\n");
    }
    return 0;
}