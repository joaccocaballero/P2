/* 5282672 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/pila.h"
struct nodo{
    TInfo elem;
    nodo *sig;
    nodo *ant;
};

struct _rep_pila{
    nodo* frente;
    nat cant;
};

TPila crearPila(){ 
    TPila p = new _rep_pila;
    p->frente = NULL;
    p->cant = 0;
    return p;
}

void liberarPila(TPila p){
   nodo *abr;
    while(p->frente != NULL){
        abr = p->frente;
        p->frente = p->frente->ant;
        liberarInfo(abr->elem);
        delete abr;
    }
    delete p;
}

nat cantidadEnPila(TPila p){ 
    return p->cant; 
}

TPila apilar(TInfo info, TPila p){ 
    TPila pnueva = p;
    nodo *nuevo = new nodo;
    nuevo->elem = copiaInfo(info);
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    if (pnueva->frente == NULL){
        pnueva->frente = nuevo;
    }
    else{
        nuevo->ant = pnueva->frente;
        pnueva->frente->sig = nuevo;
        pnueva->frente = nuevo;
    }
    pnueva->cant++;
    return pnueva;
}

TInfo cima(TPila p){ 
    return p->frente->elem;; 
}

TPila desapilar(TPila p){ 
    TPila pnueva = p;
    nodo *aquitar = pnueva->frente;
    if (pnueva->cant == 1){
        pnueva->frente = NULL;
    }
    else{
        pnueva->frente = pnueva->frente->ant;
        pnueva->frente->sig = NULL;
    }
    liberarInfo(aquitar->elem);
    delete aquitar;
    pnueva->cant--;
    return pnueva;
}
