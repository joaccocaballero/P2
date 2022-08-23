/* Inserta e en A[1..n+1] de manera ordenada.
    Precondicion: n>=0. Si n>=1 --> A[1..n] está ordenado de manera creciente.
    A[n+1] es indeterminado.
    Postcondicion: A[1..n+1] queda ordenado de manera creciente. */

void insertarOrdenado(float *A, unsigned int n, float e){
    if (n == 0 && e >= A[n])
        A[n+1] = e;
    else{
        A[n+1] = A[n];
        insertarOrdenado(A, n-1,e);
    }
}

/* caso base: 
    n=0, e se inserta a A, ṕues A está vacío.
    A[n+1]= e, e es mayor a los elementos del arreglo ya ordenado.

    paso recursivo: e se inserta en el resto del arreglo -> insertarOrdenado[A,n-1,e]
*/

