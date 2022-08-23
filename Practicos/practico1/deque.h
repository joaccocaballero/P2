struct nodo {
    int elem;
    rep_deque *sig;

};
struct _rep_deque{
    nodo* ini;
    nodo* fin;
}
typedef _rep_deque *Deque;


/* CONSTRUCTORAS */
/* Crea la Deque vacía. */
Deque crearDeque (){
    Deque nuevo = new rep_deque;
    nuevo->ini = NULL;
    nuevo->ini = NULL;
    return nuevo;
}

/* Inserta el entero x al principio de d. */
void insFrente (int x, Deque &d){
    rep_deque *nuevo = new _rep_deque;
    nuevo->elem = x;
    if(esVaciaDeque(d)){
        d->ini = nuevo;
        d->fin = nuevo;
        nuevo->sig = NULL;
    }
    else{
        nuevo->sig = d->ini;
        d->ini = nuevo;
    }
}

/* Inserta el entero x al final de d. */
void insFinal (int x, Deque &d);
    rep_deque *nuevo = new _rep_deque;
    nuevo->elem = x;
    if(esVaciaDeque(d)){
        d->ini = nuevo;
        d->fin = nuevo;
        nuevo->sig = NULL;
    }
    else{
        d->fin->sig = nuevo;
        nuevo->sig = NULL;
        d->fin = nuevo; 
    }

/* PREDICADO */
/* Verifica si d está vacía. */
bool esVaciaDeque ( Deque d);
    if (d->ini == null){
        return true;
    }
    else{
        return false;
    }

/* SELECTORAS */
/* Devuelve el primer elemento de d.
Pre : ! esVaciaDeque (d) */
int frenteDeque ( Deque d);
    return d->ini->elem;

/* Devuelve el último elemento de d.
Pre : ! esVaciaDeque (d) */
int finalDeque ( Deque d);
    return d->fin->elem;

/* Remueve el primer elemento de d.
Pre : ! esVaciaDeque (d) */  // alternativa: en caso de ser vacia la operacion no tiene efecto
void removerFrente ( Deque &d);
    _rep_deque aborrar = d->ini;
    if (d->ini == d->final){
     d->final = NULL   
    }
    d->ini = d->ini->sig;
    delete aborrar;

/* Remueve el último elemento de d.  
Pre : ! esVaciaDeque (d) */ // alternativa: en caso de ser vacia la operacion no tiene efecto
void removerFinal ( Deque &d);
    _rep_deque aborrar = d->fin;
    if (d->ini == d->