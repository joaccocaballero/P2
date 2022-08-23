#include <stdio.h>
typedef unsigned int uint;
struct nodoAB
{
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

struct nodoLista{
    uint elem;
    nodoLista *sig;
};
typedef nodoLista *Lista;

TCadena concatenar(TCadena l1, TCadena l2, TCadena l3){
    if (l1 == NULL){
        return l2;
    }
    else if (l1->sig == NULL){
        l1->sig = l2;
        return l1;
    }
    else{
        l1->sig = concatenar (l1->sig, l2);
        return l1;
    }
}
Lista EnOrden(AB b){
    if (b==NULL){
        return NULL;
    }
    else{
        Lista lizq = EnOrden(b->izq);
        Lista lraiz = new nodoLista;
        lraiz->elem = b->elem;
        lraiz->sig = EnOrden(b->der);
        return concatenar(lizq, lraiz);
    }
}

TCadena linealizacion(TAbb abb){
    TCadena cad = NULL;
    if (a != NULL){
        TCadena left = linealizacion 
    }
}

void enOrden(AB b){
    if (b != NULL){
        enOrden(b->izq);
        printf("%d", b->elem);
        enOrden(b->der);
    }
}

void preOrden(AB b){
    if (b != NULL){
        printf("%d", b->elem);
        enOrden(b->izq);
        enOrden(b->der);
    }
}

void postOrden(AB b){
    if (b != NULL){
        enOrden(b->izq);
        enOrden(b->der);
        printf("%d", b->elem);
    }
}

bool esCamino(AB b, Lista l){
    if (b == NULL & l == NULL){
        return true;
    }
    else{
        return esCaminoAux(b,l);
    }
}
bool esHoja (AB b){
    return (b->izq == NULL && b->der == NULL);
}
bool esCaminoAux(AB b, Lista l){
    if (b == NULL || l == NULL){
        return false;
    }
    else if (b->elem != l->elem){
        return false;
    }
    else if (l->sig == NULL && esHoja(b)){
        return true;
    }
    else{
        return esCaminoAux (b->izq, l->sig) || esCaminoAux(b->der,l->sig);
    }
}

void caminoMasLargoRec(AB b, Lista &l, int &largo){
    if (b == NULL){
        l = NULL;
        largo = 0;
    }
    else{
        Lista l1,l2;
        int largo1, largo2;
        caminoMasLargoRec(b->izq,l1,largo1);
        caminoMasLargoRec(b->der,l2,largo2);
        Lista nuevo = new nodoLista;
        nuevo->elem = b->elem;
        if (largo1 > largo2){
            nuevo->sig = l1;
            liberarLista(l2);
            largo = largo1+1;
        }
        else{
            nuevo->sig = l2;
            liberarLista(l1);
            largo = largo2+1;
        }
        l=nuevo;
    }
}
Lista caminoMasLargo(AB b){
    Lista l;
    int largo;
    caminoMasLargoRec(b,l,largo);
    return l;
}
