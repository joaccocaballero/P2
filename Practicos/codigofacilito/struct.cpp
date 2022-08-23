#include <stdio.h>
struct perro
{
    char nombre[30]; //duda 
    int edadMeses;
    float peso;
};

int main()
{
    perro f;
    f.edadMeses = 10;
    f.peso = 10.6;
    printf("la edad en meses: %i\n", f.edadMeses);
    return 0;
}
