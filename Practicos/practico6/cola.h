typedef int * T;

struct RepresentacionCola; typedef RepresentacionCola* Cola;

/* Devuelve en c la cola vacia. */
Cola crearCola ();

/* Agrega el elemento t al final de c. */
void encolar (T t, Cola &c);

/* Devuelve 'true' si c es vacia, 'false' en otro caso. */
bool esVaciaCola (Cola c);

/* Devuelve el primer elemento de c.
Precondicion: ! esVaciaCola(c). */
T frente (Cola c);

/* Remueve el primer elemento de c.
Precondicion: ! esVaciaCola(c). */
void desencolar (Cola &c);

/* Libera toda la memoria ocupada por c. */
void destruirCola (Cola &c);
