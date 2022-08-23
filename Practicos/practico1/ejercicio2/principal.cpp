#include "info.h"
#include <stdio.h>

int main(){
    TInfo info[3];
    info[0] = crearInfo(3, 67.1);
    info[1] = crearInfo(5, 98.3);
    info[2] = crearInfo(7, 103.5);

    // otra opción 
   /* TInfo info1 = crearInfo(3, 67.1);
    TInfo info2 = crearInfo(5, 98.3);
    TInfo info3 = crearInfo(7, 103.5);

    printf("La edad del paciente 1 es: %d \n", natInfo(paciente1));
    printf("La edad del paciente 1 es: %.1f \n", realInfo(paciente1));
    
    */

    for (int i = 0; i < 3; i++) {
        printf("La edad del paciente %d es %d \n", i+1, natInfo(info[i]));
        printf("La edad del paciente %d es %.1f \n", i+1,realInfo(info[i]));
    }
    return 0;
    }