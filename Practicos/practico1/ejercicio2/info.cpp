#include "info.h"

struct _rep_info {
    unsigned int n;
    double r;
}; // ; luego de implementar un struct para compilación

TInfo crearInfo(unsigned int natural, double real) {
    TInfo nuevo = new _rep_info;
    (*nuevo).n = natural;
    (*nuevo).r = real;
    return nuevo;
}

unsigned int natInfo(TInfo info){
    return (*info).n;
}

double realInfo(TInfo info){
    return info->r;
}