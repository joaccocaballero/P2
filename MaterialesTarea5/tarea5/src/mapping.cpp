/*5282672*/ // sustituiir con los 7 dígitos de la cédula

#include "../include/mapping.h"
#include "../include/colCadenas.h"

struct _rep_mapping{
    TColCadenas elems;
    nat tam;
    nat cant;
};

TMapping crearMap(nat M){
    TMapping nuevo = new _rep_mapping;
    nuevo->elems = crearColCadenas(M);
    nuevo->tam = M;
    nuevo->cant = 0;
    return nuevo; 
}

void liberarMap(TMapping map){
    liberarColCadenas(map->elems);
    delete map;    
}

TMapping asociarEnMap(nat clave, double valor, TMapping map){ 
        int ind = (clave % (map->tam));
        insertarEnColCadenas(clave, valor,ind,map->elems);
        map->cant++;
        return map;
}

TMapping desasociarEnMap(nat clave, TMapping map) {
    int ind = (clave % (map->tam));
    removerDeColCadenas(clave,ind,map->elems);
    map->cant--;
    return map;
}

bool esClaveEnMap(nat clave, TMapping map){ 
    int ind = (clave % (map->tam));
    return estaEnColCadenas(clave, ind, map->elems);
}

double valorEnMap(nat clave, TMapping map){ 
    int ind = (clave % (map->tam));
    return realInfo(infoEnColCadenas(clave,ind,map->elems)); 
}

bool estaLlenoMap(TMapping map){ 
    return (map->cant == map->tam); 
}