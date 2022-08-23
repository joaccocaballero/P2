typedef int * T;

struct RepresentacionPila;
typedef RepresentacionPila * Pila;
// CONSTRUCTORAS
// Devuelve la pila vacía.
Pila crearPila ();

/* Inserta i en la cima de p. */
void apilar (T i, Pila &p);

// SELECTORAS
/* Devuelve la cima de p.
Precondicion: ! esVaciaPila(p). */
T cima (Pila p);

/* Remueve la cima de p.
Precondicion: ! esVaciaPila(p). */
void desapilar (Pila &p); 

// PREDICADOS

/* Devuelve true si y sólo si p es vacia. */
bool esVaciaPila (Pila p);

/* Devuelve 'true' si y sólo si p tiene cota elementos, donde cota
es el valor del parámetro pasado en crearPila. */
bool esLlenaPila (Pila p);

// DESTRUCTORA
/* Libera toda la memoria ocupada por p. */
void destruirPila (Pila &p);
