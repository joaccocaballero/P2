/* 1234567 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/colCadenas.h"

struct _rep_colCadenas {
  TCadena arr[CANT_CADS];
};

TColCadenas crearColCadenas() {
  TColCadenas nuev = new _rep_colCadenas;
  for (int i = 0; i < CANT_CADS; i++)
  {
    nuev->arr[i] = crearCadena();
  }
  return nuev;
}

void liberarColCadenas(TColCadenas col){
  for (int i = 0; i < CANT_CADS; i++)
  {
   liberarCadena(col->arr[i]);
  }
  delete col;
};

TCadena cadenaDeColCadenas(nat pos, TColCadenas col) {
  TCadena nueva = col->arr[pos];
  return nueva;
}

nat cantidadColCadenas(nat pos, TColCadenas col) {
  TColCadenas temp;
  temp = col;
  return cantidadEnCadena((*temp).arr[pos]);
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col) {
  bool esta;
  TColCadenas temp;
  temp = col;
  if (estaEnCadena(natural, (*temp).arr[pos]))
  {
    esta = true;
  }
  else
  {
    esta = false;
  }
  return esta;
}

TColCadenas insertarEnColCadenas(nat natural, double real, nat pos,
                                 TColCadenas col) {
  TColCadenas temp;
  temp = col;
  col->arr[pos] = insertarAlInicio(natural, real, temp->arr[pos]);
  return col;
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col) {
  TInfo elem;
  elem = infoCadena(natural, col->arr[pos]);
  return elem;
}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col) {
  col->arr[pos] = removerDeCadena(natural, col->arr[pos]);
  return col;
}
