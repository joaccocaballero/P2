#include <stdio.h>
bool CalcPrimos(int x)
{
    int i = 2;
    bool b = true;
    while ((i<x) && (x % i != 0)) 
    {
        i++;
    }
    if (i > x)
    {
        b = false;
    };
    return b;
};

void EsPrimo(int A, int B)
{
    for(int i = A+1; i<B ;i++)
    {
        if (CalcPrimos(i))
        {
            printf("%d\n",i);
        }
    }
};

int main()
{
    int A,B;
    printf("Ingrese un nro A tq A<B: ");
    scanf("%i",&A);
    printf("Ingrese un nro B tq B>A: ");
    scanf("%i",&B);
    EsPrimo(A,B);
}
