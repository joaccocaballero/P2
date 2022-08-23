struct rep_deque {

};

typedef rep_deque * Deque;

/* CONSTRUCTORAS */
/* Crea la Deque vacía. */
Deque crearDeque ();
/* Inserta el entero x al principio de d. */
void insFrente (int x, Deque &d);
/* Inserta el entero x al final de d. */
void insFinal (int x, Deque &d);
/* PREDICADO */
/* Verifica si d está vacía. */
bool esVaciaDeque ( Deque d);
/* SELECTORAS */
/* Devuelve el primer elemento de d.
Pre : ! esVaciaDeque (d) */
int frenteDeque ( Deque d);
/* Devuelve el último elemento de d.
Pre : ! esVaciaDeque (d) */
int finalDeque ( Deque d);
/* Remueve el primer elemento de d.
Pre : ! esVaciaDeque (d) */  // alternativa: en caso de ser vacia la operacion no tiene efecto
void removerFrente ( Deque &d);
/* Remueve el último elemento de d.  
Pre : ! esVaciaDeque (d) */ // alternativa: en caso de ser vacia la operacion no tiene efecto
void removerFinal ( Deque &d);