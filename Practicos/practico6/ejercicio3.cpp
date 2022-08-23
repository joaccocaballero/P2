struct nodo {
    int elem;
    nodo *sig;
    nodo *ant;

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
    nuevo->sig = d->frente;
    nuevo->ant = NULL;

    if(d->ini == NULL){
        d->fin = nuevo;
    }
    else{
        d->ini->ant = nuevo;
    }
    d->frente = nuevo;
}

/* Inserta el entero x al final de d. */
void insFinal (int x, Deque &d){

}


/* PREDICADO */
/* Verifica si d está vacía. */
bool esVaciaDeque ( Deque d);
    return (d->ini == NULL);

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
void removerFrente ( Deque &d){

}

/* Remueve el último elemento de d.  
Pre : ! esVaciaDeque (d) */ // alternativa: en caso de ser vacia la operacion no tiene efecto
void removerFinal ( Deque &d){
    nodo* borrar = d->fin;
    d->fin = d->fing>ant;
    if (d->fin != NULL){
        d->fin->sig = NULL;
    }
    else{
        d->frente = NULL;
    }
    delete borrar;

}
    