//Variables
#include <stdio.h>
int main()
{
    char C = 'y'; //tamaño de 1 byte 0...255
    int a = 20; // 2 bytes -32768..32767
    short e = -1; // -128..127
    unsigned int u = 25; // 2 bytes 0..65535... no contiene valores negativos 
    long l = 5932; // 4 bytes -2147483648..2147483647
    float f = 72.534; // 4 bytes 
    double d = 12323.8777658; // 8 bytes
    printf("%c\n",C);
    printf("%i\n",a);
    printf("%i\n",e);
    printf("%li\n",l);
    printf("%.2f\n",f);
    printf("%.2lf\n",d); 
    return 0; 
}