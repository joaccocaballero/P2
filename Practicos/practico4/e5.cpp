#include <stdio.h>
typedef unsigned int uint;
struct nodoAG{
    int dato;
    nodoAG *pH;
    nodoAG *sH;
};
typedef nodoAG *AG;

AG arbolHoja(AG t, int x){
    t->dato = x;
    return t;
}

bool esArbolHoja(AG t){
    return t->pH == NULL && t->sH == NULL;
}

bool pertenece(uint x, AG t){
    return t!=NULL && (t->dato || pertenece(x,t->pH) || pertenece(x,t->sH));
}

void insertar(uint h, uint p, AG &g){
    if (!pertenece(h,g)){
        AG ptr = buscar(p,g);
        if(ptr != NULL){
            AG nuevo = new nodoAG;
            nuevo->dato = h;
            nuevo->sH = ptr->pH;
            nuevo->sH = NULL;
            ptr->pH = nuevo;
        }
    }
}

AG buscar(uint x, AG t){
    AG res = NULL;
    if(t != NULL){
        if (t->dato == x){
            res = t;
        }
        else{
            res = buscar(x, t->sH);
            if(res == NULL){
                res = buscar(x,t->pH);
            }
        }
    }
    return res;
}

