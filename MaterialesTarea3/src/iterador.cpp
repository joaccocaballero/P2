/* 5282672 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/iterador.h"

struct nodo{
    nat n;
    nodo *sig;
};
struct _rep_iterador {
    nodo *primero;
    nodo *actual;
    nodo *ultimo;
};

TIterador crearIterador(){
    TIterador nuevo = new _rep_iterador;
    nuevo->primero = NULL;
    nuevo->actual = NULL;
    nuevo->ultimo = NULL;
    return nuevo;
}

void liberarIterador(TIterador iter){
    while (iter->primero != NULL){
        iter->actual = iter->primero;
        iter->primero = iter->primero->sig;
        delete iter->actual;
    }
    delete iter;
}

bool estaDefinidaActual(TIterador iter){
    if (iter->actual != NULL){
        return true;
    }
    else{
        return false;
    }
}

void agregarAIterador(nat elem, TIterador const iter){
    nodo *nuevo = new nodo;
    nuevo->n = elem;
    nuevo->sig = NULL;
    if (iter->primero == NULL){
        iter->primero = nuevo;
        iter->ultimo = nuevo;
    }
    else{
        iter->ultimo = iter->primero;
        while (iter->ultimo->sig != NULL){
            iter->ultimo = iter->ultimo->sig;
        }
        iter->ultimo->sig = nuevo;
        iter->ultimo = nuevo;
    }
}

void reiniciarIterador(TIterador const iter){
    if (iter != NULL){
        iter->actual = iter->primero;
    }
}

void avanzarIterador(TIterador const iter){
    if (estaDefinidaActual(iter)){
        iter->actual = iter->actual->sig;
    }
    else if (estaDefinidaActual(iter) && (iter->actual == iter->ultimo)){
        iter->actual = NULL;
    }
}

nat actualEnIterador(TIterador iter){
    return iter->actual->n;
}
