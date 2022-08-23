#include  <stdio.h>

typedef unsigned int uint;
struct EstInfo{
    uint nota; //dato
    int ci; //clave
};

struct nodoABB{
    EstInfo info;
    nodoABB *izq;
    nodoABB *der;
};
typedef nodoABB *ABB;

ABB filtrado(ABB b, uint cota){
    if (b == NULL){
        return NULL;
    }
    else{
        ABB fizq = filtrado(b->izq, cota);
        ABB fder = filtrado(b->der, cota);
        EstInfo estudiante = b->info;
        if ((estudiante.nota) > cota){
            ABB nuevo = new nodoABB;
            nuevo->izq = fizq;
            nuevo->der = fder;
            nuevo->info = estudiante;
            return nuevo;
        }
        else if (fizq != NULL){
            return fder;
        }
        else if (fder != NULL){
            return fizq;
        }
        else { // (b != NULL) && (fizq != NULL) && (fder != NULL) && (estudiante.cota <= cota)
            EstInfo est = maxABB(fizq);
            removerMaxABB(fizq);
            ABB nuevo = new nodoABB;
            nuevo->izq = fizq;
            nuevo->der = fder; 
            nuevo->info = est;
            return nuevo;
        }
    }
    
}


