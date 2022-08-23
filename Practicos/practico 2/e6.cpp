#include <stdio.h>
typedef unsigned int uint;

uint factAcum(uint n, int acum){
    if (n > 1){
        acum = factAcum(n-1,acum)*n;
    }
    return acum;
}

int main (){
    int res,valor;
    printf("ingrese valor: ");
    scanf("%i", &valor);
    res = factAcum(valor, res);
    printf("El factorial de valor es: %i", res);
    return 0;
}