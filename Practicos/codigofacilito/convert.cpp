//Existen 32 palabras reservadas
#include <stdio.h>
int main ()
{
    int a = 80;
    float f = 45.3;
    float suma = (float)a + f;
    //(datatype.a.convertir)"variable"
    printf("entero%i\n flotante%.2f\n double%.3f\n caracter %c\n",a, (float)a,(double)a,(char)a); 
    printf("%.2f\n", suma);
    return 0; 
}