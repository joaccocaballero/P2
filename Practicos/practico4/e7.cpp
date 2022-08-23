#include <stdio.h>

typedef unsigned int uint;
struct nodoLista
{
    uint elem;
    nodoLista *sig;
};
typedef nodoLista *Lista;

struct nodoAG
{
    int dato;
    nodoAG *pH;
    nodoAG *sH;
};

typedef nodoAG *AG;
bool esPrefijo(Lista l, AG g){
    if (l == NULL){
        return true;
    }
    else if (g == NULL){
        return false;
    }
    else{
        return (g->dato == l->elem && esPrefijo(l->sig,g->pH) || esPrefijo(l,g->sH));
    }
}