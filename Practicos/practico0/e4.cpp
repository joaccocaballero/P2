#include <string.h>
bool esPalindrome(char *frase)
{
    int largo = strlen(frase);
    int i = 0;
    while (frase[i] == frase[largo-i-1], i<largo/2)
        i++;
    return (i == largo/2);
}