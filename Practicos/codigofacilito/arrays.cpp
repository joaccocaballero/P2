#include <stdio.h>
int main()
{
    /* int array[5] = {6,3,4,1,5};
    printf("%i\n",array[2]);
    return 0;*/
    int sizeA;
    printf("tamaño del arreglo\n");
    scanf("%i",&sizeA);
    int age[sizeA];
    for(int i = 0; i < sizeA; i++)
    {
        printf("ingresa el valor%i\n",i+1);
        scanf("%i",&age[i]);
    }
        printf("los valores del arreglo son:\n");
        for(int i = 0; i < sizeA;i++)
    {
        printf("%i-", age[i]);
    }
    printf("\n");
    return 0; 
}  

// los arreglos son una entdad estática, no cambian su tamaño en ejecución del programa.