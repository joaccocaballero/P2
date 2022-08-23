//#include <stdio.h>
int min(int c1, int c2, int c3, int c4, int c5)
{
    int min;
    min = c1;
    if (c2 < min)
    {
        min = c2;
    }
    else if (c3 < min)
    {
        min = c3;
    }
    else if (c4 < min)
    {
        min = c4;
    }
    else if (c5 < min)
    {
        min = c5;
    }
    return min; 

}
float PromClase(int c1, int c2, int c3, int c4, int c5)
    {
        int suma = c1 + c2 + c3 + c4 + c5 - min(c1,c2,c3,c4,c5);
        return suma/4.0;   
    }
/*int main()
{
    int c1,c2,c3,c4,c5; 
    float promedio;
    printf("Ingrese 5 calificaciones:\n");
    scanf("%i %i %i %i %i",&c1,&c2,&c3,&c4,&c5);
    promedio = PromClase(c1,c2,c3,c4,c5);
    printf("El promedio es:%.2f\n", promedio);
    return 0;
}*/