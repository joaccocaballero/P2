#include <stdio.h>
struct rep_fecha {
    unsigned int d ;
    unsigned int m ;
    unsigned int a ;
}; 
int main()
{
    unsigned int n = 3;
    rep_fecha fechas[n];
    fechas[0].d = 10; fechas[0].m = 10; fechas[0].a = 2022;
    fechas[1].d = 15; fechas[1].m = 5; fechas[1].a = 2022;
    fechas[2].d = 20; fechas[2].m = 11; fechas[2].a = 1992;

    int i, j, min_idx; 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if ((fechas[j].a < fechas[min_idx].a) || (fechas[j].a == fechas[min_idx].a && fechas[j].m < fechas[min_idx].m) || 
            (fechas[j].a == fechas[min_idx].a && fechas[j].m == fechas[min_idx].m && fechas[j].d < fechas[min_idx].d))
            {
                min_idx = j;
            }
        };
    rep_fecha aux = fechas[min_idx];
    fechas[min_idx] = fechas[i];
    fechas[i]=aux;
    }
    for (unsigned int i=0; i<n;i++)
    {
        printf("%d/ %d/ %d \n", fechas[i].d, fechas[i].m, fechas[i].a);
    }
    return 0;
}