/*5282672*/ // sustituiir con los 7 dígitos de la cédula

#include "../include/abb.h"

struct _rep_abb{
    TInfo elem;
    _rep_abb *izq;
    _rep_abb *der;
};

static void insABB(TInfo dato, TAbb &abb);
static TInfo maxABB(TAbb b);
static void removerMaxABB(TAbb &b);
static void removerABB(nat x, TAbb &b);
static void rotacionDer(TAbb &abb);
static void rotacionIzq(TAbb &abb);

void rotacionDer(TAbb &abb){
         TAbb n = abb->izq;
         TAbb m = n->der;
         n->der = abb;
         abb->izq = m;
         abb = n;

}

void rotacionIzq(TAbb &abb){
        TAbb n = abb->der;
        TAbb m = n->izq;
        n->izq = abb;
        abb->der = m;
        abb = n;
}

TAbb rotar(nat clave, char tipo[2], TAbb abb){
    if (abb != NULL){
        if (clave < natInfo(abb->elem)){
            abb->izq = rotar(clave, tipo, abb->izq);
        }

        else if (clave > natInfo(abb->elem)){
            abb->der = rotar(clave,tipo,abb->der);
        }

        else if (natInfo(abb->elem) == clave){
            if (tipo[0] == 'L' && tipo[1] == 'L'){
                if(abb->izq!= NULL){
                    rotacionDer(abb);
                }
            }
            if (tipo[0] == 'L' && tipo[1] == 'R'){
                if (abb->izq != NULL){
                    if(abb->izq->der != NULL){
                        rotacionIzq(abb->izq);
                        rotacionDer(abb);
                    }
                }
            }
            if (tipo[0] == 'R' && tipo[1] == 'R'){
                if (abb->der != NULL){
                    rotacionIzq(abb);
                }
            }
            if (tipo[0] == 'R' && tipo[1] == 'L'){
                if (abb->der!=NULL){
                    if (abb->der->izq != NULL){
                        rotacionDer(abb->der);
                        rotacionIzq(abb);
                    }
                }
            }
        }
    }
    return abb;
}

TAbb crearAbb(){
    TAbb nuevo = NULL;
    return nuevo;
}

void liberarAbb(TAbb abb){
    if (abb != NULL){
        liberarAbb(abb->der);
        liberarAbb(abb->izq);
        liberarInfo(abb->elem);
        delete abb;
        abb = NULL;
    }
}

bool esVacioAbb(TAbb abb){
    if (abb != NULL){
        return false;
    }
    else{
        return true;
    }
}

TAbb buscarSubarbol(nat clave, TAbb abb){
    while ((abb != NULL) && (natInfo(abb->elem) != clave)){
        if (natInfo(abb->elem) > clave){
            abb = abb->izq;
        }
        else{
            abb = abb->der;
        }
    }
    return abb;
}

TInfo raiz(TAbb abb){
    return abb->elem;
}

TAbb izquierdo(TAbb abb){
    return abb->izq;
}

TAbb derecho(TAbb abb){
    return abb->der;
}

TInfo menorEnAbb(TAbb abb){
    if (esVacioAbb(abb->izq)){
        return raiz(abb);
    }
    else{
        return menorEnAbb(abb->izq);
    }
}

TInfo mayorEnAbb(TAbb abb){
    if (esVacioAbb(abb->der)){
        return raiz(abb);
    }
    else{
        return mayorEnAbb(abb->der);
    }
}

TAbb consAbb(TInfo dato, TAbb izq, TAbb der){
    TAbb res = new _rep_abb;
    res->elem = dato;
    res->der = der;
    res->izq = izq;
    return res;
}

void insABB(TInfo dato, TAbb &abb){
    if (abb == NULL){
        TAbb nuevo = new _rep_abb;
        nuevo->elem = dato;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        abb = nuevo;
    }
    else if (natInfo(dato) > natInfo(abb->elem)){
        insABB(dato, abb->der);
    }
    else if (natInfo(dato) < natInfo(abb->elem)){
        insABB(dato, abb->izq);
    }
}

TAbb insertarEnAbb(TInfo dato, TAbb abb){
    insABB(dato, abb);
    return abb;
}

TInfo maxABB(TAbb b){
    while (b->der != NULL){
        b = b->der;
    }
    return b->elem;
}

void removerMaxABB(TAbb &b){
    if (b->der != NULL){
        removerMaxABB(b->der);
    }
    else{
        TAbb borrar = b;
        b = b->izq;
        delete borrar;
    }
}

void removerABB(nat x, TAbb &b){
    if (b != NULL){
        if (x == natInfo(b->elem)){
            if (b->izq == NULL){
                TAbb borrar = b;
                b = b->der;
                liberarInfo(borrar->elem);
                delete borrar;
            }
            else if (b->der == NULL){
                TAbb borrar = b;
                b = b->izq;
                liberarInfo(borrar->elem);
                delete borrar;
            }
            else{
                liberarInfo(b->elem);
                b->elem = maxABB(b->izq);
                removerMaxABB(b->izq);
            }
        }
        else{ // x != natInfo(b->elem)
            if (x < natInfo(b->elem)){
                removerABB(x, b->izq);
            }
            else{
                removerABB(x, b->der);
            }
        }
    }
}

TAbb removerDeAbb(nat clave, TAbb abb){
    removerABB(clave, abb);
    return abb;
}

TAbb copiaAbb(TAbb abb){
    if (abb == NULL){
        return NULL;
    }
    else{
        TAbb nuevo = new _rep_abb;
        nuevo->elem = copiaInfo(abb->elem);
        nuevo->izq = copiaAbb(abb->izq);
        nuevo->der = copiaAbb(abb->der);
        return nuevo;
    } 
}
