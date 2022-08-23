/*directivas del preprocesador*/
#include <stdio.h>
#include <math.h>
#define CUBO(a) a*a*a //ejemplo de una macro 
int main()
{
    //int suma;
    // suma = PI + 3;
    int a = 3;
    printf("resultado es :%i\n",CUBO(a));
    return 0;
}
