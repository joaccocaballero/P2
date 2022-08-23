#include <stdio.h>
#include <string.h>
#include <ctype.h> //toupper function 

//precondicion 0<=inf<strlen(frase) && 0<=sup<strlen(frase) */
/*bool esPalindromeRec(char *frase, unsigned int ini, unsigned int fin){
bool res; 
if (ini >= fin){
    res = true;
}
else if (frase[ini] != frase[fin]){
    res = false;
}
else{
    res = esPalindromeRec(frase, ini +1, fin-1);
}

}*/

// otra forma
bool esPalindromeRec(char *frase, unsigned int ini, unsigned int fin){
    return ini>=fin || (frase[ini] == frase[fin]) && esPalindromeRec(frase, ini+1,fin-1);
};

bool esPalindrome(char *frase, unsigned int largo){
    return esPalindromeRec(frase,0,largo-1);
};

int main(){
    bool res;
    char *frase = new char[100];
    printf("Ingrese una frase:\n");
    scanf("%[^\n]s",frase);
    for(int i=0; i<strlen(frase);i++){
        frase[i] = toupper(frase[i]);
    }
    res = esPalindrome(frase, strlen(frase));
    
    if (res) {
        printf("La frase %s",frase);
        printf(" es palíndrome.");
    }
    else{
        printf("La frase %s",frase);
        printf(" no es palindrome.");
    }
    return 0;
}