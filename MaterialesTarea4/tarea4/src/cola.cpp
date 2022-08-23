/* 5282672 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cola.h"
struct nodo{
    TInfo elem;
    nodo *sig;
    nodo *ant;
};
struct _rep_cola{
    nodo *frente;
    nodo *fin;
    nat cant;
};

TCola crearCola(){ 
    TCola nuevo = new _rep_cola;
    nuevo->frente= NULL;
    nuevo->fin = NULL;
    nuevo->cant = 0;
    return nuevo;
}

void liberarCola(TCola c){
    nodo *aborar;
    while (c->frente != NULL){
        aborar = c->frente;
        c->frente = c->frente->sig;
        liberarInfo(aborar->elem);
        delete aborar;
    }
    delete c;
}

nat cantidadEnCola(TCola c){ 
    return c->cant; 
}

TCola encolar(TInfo info, TCola c){ 
    TCola cnueva = c;
    nodo *nuevo = new nodo;
    nuevo->elem = copiaInfo(info);
    nuevo->sig = NULL;
    if (cnueva->frente == NULL){
        cnueva->frente = nuevo;
    }
    else{
        cnueva->fin->sig = nuevo;
    }
    cnueva->fin = nuevo;
    cnueva->cant++;
    return cnueva;
}

TInfo frente(TCola c){ 
    return c->frente->elem; 
}

TCola desencolar(TCola c){ 
    TCola cnueva = c;
    nodo *aquitar = c->frente;
    c->frente = c->frente->sig;
    if(c->frente == NULL){
        c->fin = NULL;
    }
    liberarInfo(aquitar->elem);
    delete aquitar;
    cnueva->cant--;
    return cnueva;
}
