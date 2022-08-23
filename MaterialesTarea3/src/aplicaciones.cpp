/* 5282672 */ // sustituiir con los 7 dígitos de la cédula

#include <string.h>
#include <math.h>
#include "../include/aplicaciones.h"
#include "../include/info.h"

static TCadena insertarAlFinal(nat natural, double real, TCadena cad);
static void enOrdenaux(TAbb b, TCadena &cad);
static void printRec(int prf, TAbb abb);
static int cantNodos(TAbb abb);
static int max(int a, int b);
static int altura(TAbb abb);
static int poten(int b);
static void caminorec(nat clave, nat k, TAbb abb, TIterador &res, nat &cont);
static void palcortasAux(char arr[], nat k, nat l, TPalabras palabras);
static TPalabras buscarRec(ArregloChars prefijo, TPalabras palabras, int largo, int i);

TCadena insertarAlFinal(nat natural, double real, TCadena cad){
  if (cantidadEnCadena(cad) == 0){
    return insertarAlInicio(natural, real, cad);
  }
  else{
    TCadena aux = insertarAlInicio(natural, real, cad);
    return cadenaSiguiente(aux);
  }
}

void enOrdenaux(TAbb b, TCadena &cad){
  if (b != NULL){
    enOrdenaux(izquierdo(b), cad);
    cad = insertarAlFinal(natInfo(raiz(b)), realInfo(raiz(b)), cad);
    enOrdenaux(derecho(b), cad);
  }
}

TCadena linealizacion(TAbb abb){
  TCadena cad = crearCadena();
  enOrdenaux(abb, cad);
  return cad;
}

void printRec(int prf, TAbb abb){
  if (abb != NULL){
    printRec(prf+1,derecho(abb));
    for (int i = 0; i<prf;i++){
      printf("-");
    }
    imprimirInfo(raiz(abb));
    printf("\n");
    printRec(prf+1,izquierdo(abb));
  }
}

void imprimirAbb(TAbb abb) {
  int prf = 0;
  printRec(prf, abb);
}

int cantNodos(TAbb abb){
  if (abb == NULL){
    return 0;
  }
  else{
    return 1 + cantNodos(derecho(abb)) + cantNodos(izquierdo(abb));
  }
}

int max(int a, int b){
  if (a>b)
    return a;
  else 
    return b;
}

int altura(TAbb abb){
  if (abb == NULL){
    return 0;
  }
  else{
    return 1 + max(altura(izquierdo(abb)), altura(derecho(abb)));
  }
}

int poten(int b){
  int res = 1;
  while (b != 0){
    res = 2*res;
    b--;
  }
  return res;
}

bool esPerfecto(TAbb abb){
  if (abb == NULL){
    return true;
  }
  else{
    if (poten(altura(abb))-1 == cantNodos(abb)){
      return true;
    }
    else{
      return false;
    }
  }
}

TAbb menores(double limite, TAbb abb){
  TAbb nuevomenores, mizq, mder;
  TInfo mayor = NULL;
  TInfo elem = NULL;
  if (abb == NULL){
    nuevomenores = NULL;
  }
  else{
    mizq = menores(limite, izquierdo(abb));
    mder = menores(limite, derecho(abb));
    elem = raiz(abb);
    if (realInfo(raiz(abb)) < limite){
      nuevomenores = consAbb(copiaInfo(elem),mizq,mder);
    }
    else if(mizq == NULL){
        nuevomenores = mder;
    }
    else if(mder == NULL){
        nuevomenores = mizq;
    }
    else{
      mayor = copiaInfo(mayorEnAbb(mizq));
      mizq = removerDeAbb(natInfo(mayorEnAbb(mizq)), mizq);
      nuevomenores = consAbb(mayor,mizq,mder);
    }
  }
  return nuevomenores;
}


void caminorec(nat clave, nat k, TAbb abb, TIterador &res, nat &cont){
    if (k!=0){
        if (natInfo(raiz(abb)) == clave){
          if (cont < k){
            agregarAIterador(natInfo(raiz(abb)), res);
            cont++;
          }
        }
        else if (clave > natInfo(raiz(abb))){
          caminorec(clave, k, derecho(abb), res, cont);
          if (cont < k){
            agregarAIterador(natInfo(raiz(abb)), res);
          }
          cont++;
        }
        else if (clave < natInfo(raiz(abb))){
          caminorec(clave, k, izquierdo(abb), res, cont);
          if (cont < k){
            agregarAIterador(natInfo(raiz(abb)), res);
          }
          cont++;
        }
      }
}

TIterador caminoAscendente(nat clave, nat k, TAbb abb){ 
  TIterador res = crearIterador();
  nat cont;
  cont = 0;
  caminorec(clave,k,abb,res,cont);
  return res; 
}

void palcortasAux(char arr[],nat k,nat l,TPalabras palabras){
  if (letra(palabras) == '\0'){
    arr[l] = '\0';
    if (l<=k)
    printf("%s\n", arr);
  }
  else{
    arr[l] = letra(palabras);
    palcortasAux(arr,k,l+1, subarboles(palabras));
  }
  if (siguientes(palabras) != NULL)
    palcortasAux(arr,k,l, siguientes(palabras));
}

void imprimirPalabrasCortas(nat k, TPalabras palabras){
  char arr[k];
  nat l;
  l=0;
  palcortasAux(arr,k,l,subarboles(palabras));
}

TPalabras buscarRec(ArregloChars prefijo, TPalabras palabras, int largo, int i){
  if (palabras != NULL){
    if (letra(palabras) != prefijo[i]){
        return buscarRec(prefijo,siguientes(palabras),largo,i);
    }
    else{
        if (largo == i+1){
          return palabras;
        }
        else{
          return buscarRec(prefijo,subarboles(palabras),largo,i+1);
        }
    }
  }
  else{
    return NULL;
  }
}

TPalabras buscarFinPrefijo(ArregloChars prefijo, TPalabras palabras){
  TPalabras res;
  int i = 0;
  int largo = strlen(prefijo);
  res = buscarRec(prefijo, subarboles(palabras),largo,i);
  return res;
}