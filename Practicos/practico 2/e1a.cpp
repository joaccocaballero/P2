// Ordena A[1..n] de manera creciente.
void ordenar(float * A, unsigned int n){
    if (n > 1){
        ordenar(A,n-1);
        insertarOrdenado(A,n-1,A[n]);
    }
}

//caso base
//cuando el arreglo tiene 0 o 1 elementos el resultado es conocido.