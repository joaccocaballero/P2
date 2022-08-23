#include <stdio.h>
typedef unsigned int uint;
struct nodoABB{
    uint elem;
    nodoABB *izq, *der;
};
typedef nodoABB *ABB;

// ARBOLES BINARIOS DE BÚSQUEDA
void insertarABB(uint x, ABB &b){
    if (b == NULL){
        ABB nuevo = new nodoABB;
        nuevo->elem = x;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        b = nuevo;
    }
    else if (x < b->elem)
    {
        insertarABB(x, b->izq);
    }
    else if (x > b->elem)
    {
        insertarABB(x, b->der);
    }
}

bool perteneceABB(uint x, ABB b){
    if (b == NULL){
        return false;
    }
    else if (x == b->elem)
    {
        return true;
    }
    else if (x < b->elem)
    {
        return perteneceABB(x, b->izq);
    }
    else
    {
        return perteneceABB(x, b->der);
    }
}

int maxABB(ABB b){
    if (b->der == NULL)
    {
        return b->elem;
    }
    else
    {
        maxABB(b->der);
    }
}

void removerMaxABB(ABB &b){
    if (b->der != NULL){
        removerMaxABB(b->der);
    }
    else{
        ABB borrar = b;
        b = b->izq;
        delete borrar;
    }
}

void removerABB(uint x, ABB &b){
    if (b != NULL){
        if (x == b->elem){
                if (b->izq == NULL){
                    ABB borrar = b;
                    b = b->der;
                    delete borrar;
                }
                else if (b->der == NULL){
                    ABB borrar = b;
                    b = b->izq;
                    delete borrar;
                }
                else{
                    b->elem = maxABB(b->izq);
                    removerMaxABB(b->izq);
                }
        }
        else{ // x != b->elem
                if (x < b->elem){
                    removerABB(x, b->izq);
                }
                else{
                    removerABB(x, b->der);
                }
        }
    }
}

void removerABB(uint x, ABB &a){
    ABB aux;
    if (a != NULL){
        if (a-> elem == x){
            if (a-> izq == NULL){
                aux = a;
                a = a-> der;
                delete aux;
            }
            else if (a-> der == NULL){
                aux = a;
                a = a-> izq;
                delete aux;
            }
            else{
                a-> elem = maxABB(a-> izq);
                removerABB(a-> elem, a-> izq);
            }
        }
        else if (x<a -> elem)
            removerABB(x, a-> izq);
        else
            removerABB(x, a-> der);
    }
}
void késimoaux(uint x, ABB b, ABB&t){
    t = NULL;
    if (x>0 && t!= NULL){
        uint faltan = x;
        késimoaux(faltan, b->izq,t);
        if (faltan  > 0){
            faltan--; //contamos raiz;
            if(faltan == 0){
                t = b; //raiz es kesimo
            }
            else{
                késimoaux(faltan,b->der,t);
            }
            x = faltan;
        } //2do if;
    }
}
