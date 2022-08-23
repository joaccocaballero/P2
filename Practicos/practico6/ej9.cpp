#include "cola.h"
struct nodoAB{
    int x;
    nodoAB*izq;
    nodoAB*der;
}
// imprime elementos como lista de enteros
void imprimirNiveles(AB t){
    if (t!=NULL){
        colaAB c = new crearColaAB();
        encolar(t,c);
        while(!esVaciaColaAB(T)){
            desencolar(c);
            printf("%d", frente->dato);
            if (frente->izq != NULL){
                encolar(frente->izq, c);
            }
            if (frente->der != NULL){
                encolar(frente->der,c);
            }
        }
        liberarColaAB(c)
    }
}

// imprime niveles con salto de linea
void imprimirNiveles(AB t){
    if (t != NULL){
        colaAB c = new crearColaAB();
        encolar(t, c);
        encolar(NULL, c);
        int nivel = 1;
        printf("%d", nivel);
        while (!esVaciaColaAB(T)){
            desencolar(c);
            if (frente != NULL){
                printf("%d", frente->dato) 
                if (frente->izq != NULL){
                    encolar(frente->izq, c);
                }
                if (frente->der != NULL){
                    encolar(frente->der, c);
                }
            }
            else{ //frente == NULL;
                if (!esVaciaColaAB(c)){
                    nivel++;
                    printf("/n");
                    printf("%d", nivel);
                    encolar(NULL,c);
                }
            }
        }
        liberarColaAB(c)
    }
}

// imprime elementos como lista de enteros en orden inverso
void imprimirNiveles2(AB t){
    if (t != NULL){
        colaAB c = new crearColaAB();
        pilaAB p = new crearPilaAb();
        encolar(t, c);
        while (!esVaciaColaAB(T)){
            desencolar(c);
            apilar(frente->dato, p);
            if (frente->izq != NULL){
                encolar(frente->izq, c);
            }
            if (frente->der != NULL){
                encolar(frente->der, c);
            }
        }
        while (!esVaciaPila(p)){
            printf("%d ", cima);
            desapilar(p);
        }
        liberarColaAB(c)
        destruirPila(p);
    }
}