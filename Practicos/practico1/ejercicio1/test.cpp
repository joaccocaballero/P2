#include <stdio.h>

int main()
{
    int fecha = 19921120;
    int mes, dia, anio;
    anio = fecha / 10000; //
    mes = fecha  % 10000 / 100;
    dia = fecha  % 10000 % 100;
    printf("%i\n",anio);
    printf("%i\n", mes);
    printf("%i\n", dia);

    return 0;
}