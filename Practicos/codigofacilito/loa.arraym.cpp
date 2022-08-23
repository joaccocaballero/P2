#include <stdio.h>
int main()
{
    int filaA;
    printf("Ingrese cantidad de filas\n");
    scanf("%i", &filaA);
    int columnaA;
    printf("Ingrese cantidad de columnas\n");
    scanf("%i", &columnaA);
    int mul[filaA][columnaA];
    int i,j;
        for (int i = 0; i < filaA; i++)
        {
            for (int j = 0; j < columnaA; j++)
            {
                printf("ingrese componente: ");
                scanf("%i", &mul[i][j]);
            }
        }
    printf("su matriz...\n");
    {
        for (int i = 0; i < filaA; i++)
        {
            for (int j = 0; j < columnaA; j++)
            {
                printf("%i",mul[i][j]);
            }
            printf("\n");
        }
    }
        return 0;
}