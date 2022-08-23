#include <stdio.h>

typedef unsigned int uint;
struct nodoAB
{
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

int contarElems (AB t){
    if (t==NULL){
        return 0;
    }
    else{
        return 1 + contarElems(t->izq) + contarElems(t->der);
    }
}

int contarHojas(AB t){
    if (t == NULL){
        return 0;
    }
    else if (t->izq == NULL && t->der==NULL){
        return 1;
    }
    else{
        return contarHojas(t->izq) + contarHojas(t->der);
    }
}
int altura(AB t){
    if (t==NULL){
        return 0;
    }
    else{
        return 1 + max(altura(t->izq), altura(t->der));
    }
}

AB copiar(AB b){
    if (b == NULL){
        return NULL;
    }
    else{
        AB nuevo = new nodoAB;
        nuevo->elem = b->elem;
        nuevo->izq = copiar(b->izq);
        nuevo->der = copiar(b->der);
        return nuevo;
    }
}

