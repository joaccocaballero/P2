#include <stdio.h>
/*void saludo ()
{
    printf("Bienvenido\n");
    return;
}*/
int suma();
int main()
{
    printf("%i\n",suma());
    return 0;
}

int suma()
{
    int num1 = 12;
    int num2 = 4;
    int suma = num1 + num2;
    return suma;
}