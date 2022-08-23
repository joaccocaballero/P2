/*5282672*/ // sustituiir con los 7 dígitos de la cédula
#include <stdio.h>
#include "../include/colaDePrioridad.h"
#include "../include/info.h"

struct dato{
  nat elem;
  double prioridad;
};

struct _rep_colaDePrioridad{
  dato *heap;
  nat *posiciones;
  nat tope;
  nat max;
  bool ordenP;
};

void filtradoAsc(TColaDePrioridad &cp, nat pos){
  if (cp->ordenP){
    dato aux = cp->heap[pos];
    while ((pos != 1) && (cp->heap[pos / 2].prioridad > aux.prioridad)){
      cp->heap[pos] = cp->heap[pos / 2];
      cp->posiciones[cp->heap[pos / 2].elem] = pos;
      pos = pos / 2;
    }
    cp->heap[pos] = aux;
    cp->posiciones[aux.elem] = pos;
  }
  else{
    dato aux = cp->heap[pos];
    while ((pos != 1) && (cp->heap[pos / 2].prioridad < aux.prioridad)){
      cp->heap[pos] = cp->heap[pos / 2];
      cp->posiciones[cp->heap[pos / 2].elem] = pos;
      pos = pos / 2;
    }
    cp->heap[pos] = aux;
    cp->posiciones[aux.elem] = pos;
  }
  }

void filtradoDesc(TColaDePrioridad &cp, nat pos){
  dato aux = cp->heap[pos];
  if (2 * pos <= cp->tope){
    if (cp->ordenP){
      do{
        nat posHijo = 2 * pos;
        if ((2 * pos + 1 <= cp->tope) && (cp->heap[2*pos + 1].prioridad < cp->heap[2 * pos].prioridad)){
          posHijo = 2 * pos + 1;
        }
        if (aux.prioridad > cp->heap[posHijo].prioridad){
          cp->heap[pos] = cp->heap[posHijo];
          cp->posiciones[cp->heap[posHijo].elem] = pos;
          pos = posHijo;
        };
      } while ((2 * pos <= cp->tope) && (aux.prioridad > cp->heap[2 * pos].prioridad));
      cp->heap[pos] = aux;
      cp->posiciones[aux.elem] = pos;
    }
    else{
      do{
        nat posHijo = 2 * pos;
        if ((2*pos + 1 <= cp->tope) && (cp->heap[2*pos + 1].prioridad > cp->heap[2 * pos].prioridad)){
          posHijo = 2 * pos + 1;
        }
        if (aux.prioridad < cp->heap[posHijo].prioridad){
          cp->heap[pos] = cp->heap[posHijo];
          cp->posiciones[cp->heap[posHijo].elem] = pos;
          pos = posHijo;
        };
      } while ((2 * pos <= cp->tope) && (aux.prioridad < cp->heap[2 * pos].prioridad));
      cp->heap[pos] = aux;
      cp->posiciones[aux.elem] = pos;
    }
  }
}

TColaDePrioridad crearCP(nat N){ 
  TColaDePrioridad nuevo = new _rep_colaDePrioridad;
  nuevo->heap = new dato[N+1];
  nuevo->posiciones = new nat[N+1];
  for (nat i = 0; i <= N; i++){
    nuevo->posiciones[i] = 0;
  }
  nuevo->ordenP = true;
  nuevo->tope = 0;
  nuevo->max = N;
  return nuevo; 
}

TColaDePrioridad invertirPrioridad(TColaDePrioridad cp){ 
  cp->ordenP = !cp->ordenP;
  if(cp->tope > 1){
    for (nat i = cp->tope; i >= 1; i--){
      filtradoAsc(cp, i);
    }
  }
  return cp;
}
  
void liberarCP(TColaDePrioridad cp){
  delete [] cp->heap;
  delete [] cp->posiciones;
  delete cp;
}

TColaDePrioridad insertarEnCP(nat elem, double valor, TColaDePrioridad cp) {
  if (elem>=1 && elem<=cp->max){
    if (estaEnCP(elem, cp)){
      nat pos = cp->posiciones[elem];
      double prio_ant = cp->heap[pos].prioridad;
      cp->heap[pos].prioridad = valor;
      if (cp->heap[pos].prioridad >= prio_ant)
        filtradoDesc(cp,pos);
      else
        filtradoAsc(cp,pos);
    }
    else{
      cp->tope++;
      cp->heap[cp->tope] = dato{elem, valor};
      cp->posiciones[elem] = cp->tope;
      filtradoAsc(cp, cp->tope);
    }
  }
  return cp;
}

bool estaVaciaCP(TColaDePrioridad cp){ 
  return (cp->tope == 0); 
}

nat prioritario(TColaDePrioridad cp){
  return cp->heap[1].elem; 
}

TColaDePrioridad eliminarPrioritario(TColaDePrioridad cp){ 
  if (cp->tope > 0){
    cp->posiciones[cp->heap[1].elem] = 0;
    cp->heap[1] = cp->heap[cp->tope];
    cp->tope--;
    if (cp->tope > 1){
      filtradoDesc(cp, 1);
    }
  }
  return cp;   
}

bool estaEnCP(nat elem, TColaDePrioridad cp){ 
  if ((elem>=1 && elem<=cp->max)){
    return (cp->posiciones[elem] != 0);
  }
  return false;
}

double prioridad(nat elem, TColaDePrioridad cp){
    return (cp->heap[cp->posiciones[elem]].prioridad);
}
