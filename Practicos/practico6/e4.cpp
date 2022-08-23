#include "pila.h"
#include "cola.h"
bool mismosElementos(Pila &p, Cola &c){
    Pila cinvertida = crearPila();

    while(!esVaciaCola(c)){
        apilar(frente(c)),cinvertida);
        desencolar(c);
    }

    while (!esVaciaPila(p) && !esVaciaPila(cinvertida) && cima(p)==cima(cinvertida)){
        desapilar(p);
        desapilar(cinvertida);
    }

    bool res = esVaciaPila(p) && esVaciaPila(cinvertida);
    
    while (!esVaciaPila(p)){
        desapilar(p);
    }
    destruirPila(cinvertida);
    return res;
}