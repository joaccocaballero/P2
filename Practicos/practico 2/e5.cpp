void hanoirec(unsigned int n, char origen, char aux, char dest){
    if (n>0){
        if (n ==1){
            printf("%d %c %c\n",1,origen, dest);
        }
    }
    else{
        hanoirec(n-1,origen,dest,aux);
        printf("%d %c %c\n",n,origen,dest);
        hanoirec(n-1,aux,origen,dest);
    }
}

void hanoi (unsigned int n){
    hanoirec(n,"A","B","C");
}