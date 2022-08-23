#include <stdio.h>

typedef unsigned int uint;
struct nodoAG{
    int dato;
    nodoAG *pH;
    nodoAG *sH;
};

typedef nodoAG *AG;
AG copiaParcial(AG g, uint k){
    if (k == 0 || g == NULL)
    {
        return NULL;
    }
    else{
        AG nuevo = new nodoAG;
        nuevo->dato = g->dato;
        nuevo->pH = copiaParcial(g->pH, k - 1);
        nuevo->sH = copiaParcial(g->sH, k);
    }
}