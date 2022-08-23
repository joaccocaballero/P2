
// solucion iterativa.

void insertarOrdenado(float *A, unsigned int n, float e){
    while ((n>0) && (A[n]>e)){
        A[n+1] = A[n];
        n--;
    }
    A[n+1] = e;
}