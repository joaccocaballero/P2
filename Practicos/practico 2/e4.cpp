int mcm(int m,int n){
    if (n==0) {
        return m;
    }
    else{
        return mcm(n, m % n);
    }
}