#include <stdio.h>
int main()
{
    int casos;
    printf("ingresa nro\n");
    scanf("%i",&casos);
    switch(casos)
    {
        case 1:
        printf("primer caso\n");
        break;
        case 2:
        printf("segundo caso\n");
        break;
        case 3:
        printf("tercer caso\n");
        break;
        case 4:
        printf("cuarto caso\n");
        break;
        default:
        printf("caso sin identificar\n");
        break;
    }
    return 0;
}