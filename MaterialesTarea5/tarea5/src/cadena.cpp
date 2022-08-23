/*5282672*/ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"

struct _rep_cadena{
    TInfo elem;
    _rep_cadena *sig;
    _rep_cadena *ant;
};

TCadena crearCadena(){
    TCadena nueva = NULL;
    return nueva;
}

void liberarCadena(TCadena cad){
    if (cad == NULL){
        cad = NULL;
    }
    else{
        cad->ant->sig = NULL;
        TCadena cursor = cad;
        while (cad != NULL){
            cad = cad->sig;
            liberarInfo(cursor->elem);
            delete cursor;
            cursor = cad;
        }
    }
}

nat cantidadEnCadena(TCadena cad){
    nat cantidad = 0;
    TCadena cursor = cad;
    if (cad == NULL){
        return cantidad;
    }
    else{
        while (cursor->sig != cad){
            cursor = cursor->sig;
            cantidad++;
        }
        cantidad++;
        return cantidad;
    }
}

bool estaEnCadena(nat natural, TCadena cad){
    bool esta = false;
    if (cad == NULL){
        return esta;
    }
    else{
        TCadena primero = cad;
        TCadena cursor = cad->sig;
        if (cad->sig == cad){
            if (natInfo(cad->elem) != natural){
                esta = false;
            }
            else{
                esta = true;
            }
        }
        else{
            if (natInfo(primero->elem) == natural){
                esta = true;
            }
            else{
                while (cursor != cad && natInfo(cursor->elem) != natural){
                    cursor = cursor->sig;
                }
                if (natInfo(cursor->elem) == natural){
                    esta = true;
                }
                else{
                    esta = false;
                }
            }
        }
    }
    return esta;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad){
    TCadena nuevo = new _rep_cadena;
    nuevo->elem = crearInfo(natural, real);
    if (cad != NULL){
        nuevo->sig = cad;
        nuevo->ant = cad->ant;
        cad->ant->sig = nuevo;
        cad->ant = nuevo;
        cad = nuevo;
    }
    else{
        cad = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    }
    return cad;
}

TInfo infoCadena(nat natural, TCadena cad){
    TInfo val;
    TCadena aux = cad;
    while (natInfo(aux->elem) != natural){
        aux = aux->sig;
    }
    val = aux->elem;
    return val;
}

TInfo primeroEnCadena(TCadena cad){
    TInfo primero;
    primero = cad->elem;
    return primero;
}

TCadena cadenaSiguiente(TCadena cad){
    if ((cad == NULL) || (cad->sig == cad)){
        return cad;
    }
    else{
        cad = cad->sig;
    }
    return cad;
}

TCadena removerDeCadena(nat natural, TCadena cad){
    TCadena aborrar;
    if (cantidadEnCadena(cad) == 1){
        aborrar = cad;
        cad = NULL;
        liberarInfo(aborrar->elem);
        delete aborrar;
    }
    else if (natInfo(cad->elem) == natural){
        TCadena last = cad->ant;
        aborrar = cad;
        cad = cad->sig;
        last->sig = cad;
        cad->ant = last;
        liberarInfo(aborrar->elem);
        delete aborrar;
    }
    else{
        TCadena aux = cad;
        while (natural != natInfo(aux->sig->elem)){
            aux = aux->sig;
        }
        aborrar = aux->sig;
        aux->sig = aborrar->sig;
        aborrar->sig->ant = aux;
        liberarInfo(aborrar->elem);
        delete aborrar;
    }
    return cad;
}

void imprimirCadena(TCadena cad){
    if (cantidadEnCadena(cad) == 0){
        printf("\n");
    }
    else{
        if (cantidadEnCadena(cad) == 1){
            TCadena aux = cad;
            imprimirInfo(aux->elem);
        }
        else{
            TCadena aux = cad;
            imprimirInfo(aux->elem);
            aux = aux->sig;
            while (aux != cad){
                imprimirInfo(aux->elem);
                ;
                aux = aux->sig;
            }
        }
        printf("\n");
    }
}

TCadena insertarAlFinal(nat natural, double real, TCadena cad){
    TCadena nuevo = new _rep_cadena;
    nuevo->elem = crearInfo(natural, real);
    if (cad != NULL){
        nuevo->ant = cad->ant;
        cad->ant->sig = nuevo;
        cad->ant = nuevo;
        nuevo->sig = cad;
    }
    else{
        cad = nuevo;
        nuevo->ant = nuevo;
        nuevo->sig = nuevo;
    }
    return cad;
}

TCadena removerPrimero(TCadena cad){
    if (cad->sig == cad){
        TCadena aborrar = cad;
        liberarInfo(aborrar->elem);
        delete aborrar;
        cad = NULL;
    }
    else{
        TCadena aBorrar = cad;
        cad = cad->sig;
        aBorrar->ant->sig = cad;
        cad->ant = aBorrar->ant;
        liberarInfo(aBorrar->elem);
        delete aBorrar;
    }
    return cad;
}

TCadena copiaCadena(TCadena cad){
    TCadena nuevacad = NULL;
    TCadena aux = cad;
    TCadena cursor = cad;
    if (cantidadEnCadena(cad) == 0){
        return nuevacad;
    }
    else if (cantidadEnCadena(cad) == 1){
        nuevacad = insertarAlInicio(natInfo(primeroEnCadena(aux)), realInfo(primeroEnCadena(aux)), nuevacad);
    }
    else{
        while (cadenaSiguiente(cursor) != cad){
            nuevacad = insertarAlFinal(natInfo(primeroEnCadena(cursor)), realInfo(primeroEnCadena(cursor)), nuevacad);
            cursor = cadenaSiguiente(cursor);
        }
        nuevacad = insertarAlFinal(natInfo(primeroEnCadena(cursor)), realInfo(primeroEnCadena(cursor)), nuevacad);
    }
    return nuevacad;
}
