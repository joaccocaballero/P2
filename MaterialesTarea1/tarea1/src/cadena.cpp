/* 5282672 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"
#include "../include/info.h"


// los elementos se mantienen entre 0 y cantidad - 1, incluidos
struct _rep_cadena {
  TInfo info[L];
  nat   tope;
};

TCadena crearCadena() {
  TCadena nueva = new _rep_cadena;
    nueva->tope = 0;
  return nueva;
}
/* en siguientes tareas
void liberarCadena(TCadena cad) {
}
*/
nat cantidadEnCadena(TCadena cad) {
  nat cant;
  TCadena aux = cad;
  cant = aux->tope;
  return cant;
}

bool estaEnCadena(nat natural, TCadena cad) {
  nat i = 0;
  if ((cad->info[i] == NULL) || (cantidadEnCadena(cad) == 0)){
    return false;
  }
  else
  {
    while ((i<cantidadEnCadena(cad)) && (natInfo(cad->info[i]) != natural)){
    i++;
  }
    return (i<=cad->tope-1);
  }
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad) {
  if (cantidadEnCadena(cad)==0)
  {
    cad->info[0] = crearInfo(natural, real);
    cad->tope = cad->tope + 1;
  }
  else
    {
      for (nat i = cantidadEnCadena(cad); i >= 1; i--){
          cad->info[i] =  cad->info[i-1];
      }
      cad->info[0] = crearInfo(natural, real);
      cad->tope = cad->tope + 1;
  }
  return cad;
}

TInfo infoCadena(nat natural, TCadena cad) {
  nat i = 0;
  TInfo elem;
  while ((i<cantidadEnCadena(cad)) && (natInfo(cad->info[i])!= natural)){
    i++;
  }
  elem = cad->info[i];
  return elem;
}

TCadena removerDeCadena(nat natural, TCadena cad) {
  nat i=0;
  while ((i<cantidadEnCadena(cad)) && (natInfo(cad->info[i])!= natural)){
    i++;
  }
  if (natInfo(cad->info[i]) == natural){
    liberarInfo(cad->info[i]);
    cad->tope =  cantidadEnCadena(cad)-1;
  }
  for (nat j = i; j<=cantidadEnCadena(cad);j++){
    cad->info[j] =  cad->info[j+1];
  }
  return cad;
}

void imprimirCadena(TCadena cad) {
  nat i = 0;
  while (i<cantidadEnCadena(cad)){
        imprimirInfo(cad->info[i]);
        i++;
      }
    if (i>=cantidadEnCadena(cad))
        {
          printf("\n");
        };
}
