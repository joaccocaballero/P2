/* 5282672 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"

struct _rep_cadena{
  TInfo elem;
  _rep_cadena *sig;
};
typedef _rep_cadena *TCadena;
static TCadena ultimo(TCadena cad);

TCadena crearCadena(){
  TCadena nueva;
  nueva = NULL;
  return nueva;
}

void liberarCadena(TCadena cad){
  if(cad == NULL){
      cad = NULL;
  }
  else{
    TCadena t = cad->sig;
    while (t->sig != cad)
    {
      t = t->sig;
    }
    t->sig = NULL;
    TCadena cursor = cad;
    while (cad != NULL)
    {
      cad = cad->sig;
      liberarInfo(cursor->elem);
      delete cursor;
      cursor = cad;
    }
  }
}

static TCadena ultimo(TCadena cad){
  if (cad->sig == cad){
    return cad;
  }
  else {
    TCadena ult = cad->sig;
    while(ult->sig != cad){
      ult= ult->sig;
    }
    return ult;
  }
}

nat cantidadEnCadena(TCadena cad){
  nat cantidad = 0;
  TCadena cursor = cad;
  if (cad == NULL){
    return cantidad;
  }
  while (cursor->sig != cad){
    cursor = cursor->sig;
    cantidad++;
  }
  cantidad++;
  return cantidad;
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
  if (cad == NULL){
    cad = nuevo;
    cad->sig = cad;
  }
  else{
    TCadena f = cad;
    while (f->sig != cad){
      f = f->sig;
    }
    TCadena aux = cad;
   
    cad = nuevo;
    nuevo->sig = aux;
    f->sig = nuevo;
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
  if ((cantidadEnCadena(cad) == 0) || (cantidadEnCadena(cad) == 1)){
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
    TCadena last = ultimo(cad);
    aborrar = cad;
    cad = cad->sig;
    last->sig = cad;
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
        imprimirInfo(aux->elem);;
        aux = aux->sig;
      }
    }
    printf("\n");
  }
}
