#include <stdio.h>

typedef unsigned int uint;
struct EstInfo
{
    uint nota; // dato
    int ci;    // clave
};

struct nodoABB
{
    EstInfo info;
    nodoABB *izq;
    nodoABB *der;
};
typedef nodoABB *ABB;

ABB filtro(ABB a, uint cota){
    ABB fizq, fder, res;
    EstInfo raiz, mayor;
    if (a == NULL){
        res = NULL;
    }
    else{
        fizq = filtro(a->izq, cota);
        fder = filtro(a->der, cota);
        raiz = a->elem;
        if (cota < raiz.nota){
            res = new nodoABB;
            res->info = raiz;   
            res->izq = fizq;
            res->der = fder;
        }
        else if(fizq == NULL){
            res = fder;
        }
        else if(fder == NULL){
            res = fizq;
        }
        else{
            mayor = maxABB(fizq->info);
            removerMaxABB(fizq);
            res = new nodoABB;
            res->info = mayor;
            res->izq = fizq;
            res->der = fder;
        }
    }
    return res;
}