#include <stdio.h>
int main()
{
        /*  col.. 0 1 2
          fila 0  5 3 1
          fila 1  6 4 2  */
    int multi[2][3] = {{5,3,1},{6,4,2}};
    printf("%i\n",multi[0][2]);
    return 0;
}