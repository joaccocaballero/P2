typedef struct  nodo{
    int elem;
    nodo *sig;
};

struct cabezal{
    nodo *ini, *fin;
}

typedef cabezal *lEnt;

void insertar(int x, LEnt &l){
    lEnt nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig=l;
    l=nuevo;
}

bool esVacia(lEnt l){
    return l == NULL;
}

int primero(lEnt l){
    return l->elem;
}

void resto(lEnt &l){
    lEnt aBorrar = l;
    l = l->sig;
    delete aBorrar;  
}

void insFinal(int x, lEnt &l){
    nodo *nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = NULL;
    if (l->fin != NULL) //caso borde 
        l->fin->sig = nuevo;
    else // l->ini == NULL
        l->ini = nuevo;
    l->fin = nuevo;
}

lEnt null(){
    lEnt l = new cabezal;
    l->ini = NULL;
    l->fin = NULL;
    return l;
}

void insertar(int x, lEnt &l){
    nodo *nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = l->ini;
    l->ini = nuevo;

    if (l->fin == NULL)
        l->fin = l->nuevo;
}

/* Insertar el entero x en la lista l, ordenada*/
void insertar (int x, lEnt &l)