/* 5282672 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"
#include "../include/cadena.h"
#include "../include/iterador.h"
#include "../include/info.h"

TCadena insertarAlFinal(nat natural, double real, TCadena cad){
    if (cantidadEnCadena(cad)==0){
      return insertarAlInicio(natural,real,cad);
    }
    else{
      TCadena aux = insertarAlInicio(natural, real, cad);
      return cadenaSiguiente(aux);
    }
}

TCadena removerPrimero(TCadena cad){
  nat aborrar = natInfo(primeroEnCadena(cad)); 
  TCadena aux;
  aux = removerDeCadena(aborrar,cad);
  return aux;
}

TCadena copiaCadena(TCadena cad){
  TCadena nuevacad = NULL;
  TCadena aux = cad;
  TCadena cursor = cad;
  if (cantidadEnCadena(cad) == 0){
    return nuevacad;
  }
  else if (cantidadEnCadena(cad)==1){
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
void reverRec(TIterador iter, TIterador &res){
  if (estaDefinidaActual(iter)){
    nat aux = actualEnIterador(iter);
    avanzarIterador(iter);
    reverRec(iter,res);
    agregarAIterador(aux, res);
    avanzarIterador(res);
  }
}

TIterador reversoDeIterador(TIterador iter){
  TIterador res = crearIterador();
  reiniciarIterador(iter);
  reverRec(iter, res);
  return res;
  }

