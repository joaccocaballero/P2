#include <stdio.h>
struct rep_fecha {
    unsigned int f ; //AAAAMMDD
}; 

int main()
{
    unsigned int n = 3;
    rep_fecha fechas[n];
    fechas[0].f = 20221010;
    fechas[1].f = 20220515;
    fechas[2].f = 19921120;

    int i, j, min_idx;
    for (i=0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if ((fechas[j].f/10000 < fechas[min_idx].f/10000) || (fechas[j].f/10000 == fechas[min_idx].f/10000 && fechas[j].f%10000/100 < fechas[min_idx].f%10000/100)||
            (fechas[j].f/10000 == fechas[min_idx].f/10000  && fechas[j].f%10000/100 == fechas[min_idx].f%10000/100 && fechas[j].f%10000%100 < fechas[j].f%10000%100))
                {
                    min_idx = j;
                }
        
        };

        rep_fecha aux = fechas[min_idx];
        fechas[min_idx] = fechas[i];
        fechas[i] = aux;
    }
    for (unsigned int i=0; i<n;i++)
    {
        printf("%d/ %d/ %d \n", fechas[i].f%10000%100, fechas[i].f%10000/100, fechas[i].f/10000);
    }
    return 0;
}