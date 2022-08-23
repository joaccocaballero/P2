/*5282672*/ // sustituiir con los 7 dígitos de la cédula
#include <string.h>
#include <math.h>
#include "../include/aplicaciones.h"
#include "../include/colCadenas.h"
#include "../include/mapping.h"

static void enOrdenaux(TAbb b, TCadena &cad);
static void printRec(int prf, TAbb abb);
static int cantNodos(TAbb abb);
static int max(int a, int b);
static int altura(TAbb abb);
static void reverRec(TIterador iter, TIterador &res);
static void caminorec(nat clave, nat k, TAbb abb, TIterador &res, nat &cont);
static void palcortasAux(char arr[], nat k, nat l, TPalabras palabras);
static TPalabras buscarRec(ArregloChars prefijo, TPalabras palabras, int largo, int i);
static TAbb baux(TInfo *arreglo, int ini, int fin);
static TInfo *cadtoArr(TCadena cad, nat n);
static int valabs(int alt);
static nat minNodos(nat h);
static double sumadou(nat n, TMapping Map);

int valabs(int alt){
  if (alt<0){
    return alt * -1;
  }
  return alt;
}

bool esAvl(TAbb abb){
  if (esVacioAbb(abb) || (esVacioAbb(izquierdo(abb)) && esVacioAbb(derecho(abb)))){
    return true;
  }
  else if (esVacioAbb(derecho(abb)) && !esVacioAbb(izquierdo(abb))){
    return (altura(izquierdo(abb)) == 1);
  }
  else if (!esVacioAbb(derecho(abb)) && esVacioAbb(izquierdo(abb))){
    return (altura(derecho(abb)) == 1);  
  }
  else{
    if (valabs(altura(izquierdo(abb))-altura(derecho(abb)))>1){
      return false;
    }
    else{
      return (esAvl(derecho(abb)) && esAvl(izquierdo(abb)));
    }
  }
}

nat minNodos(nat h){
  if (h==0 || h==1){
    return h;
  }
  else{
    return minNodos(h-1) + minNodos(h-2) + 1;
  }
}

TAbb minaux(nat h, nat cant){
 if (h==0){
  return NULL;
 }
 if (h == 1){
  TInfo raiz = crearInfo(cant,0.0);
  TAbb abb = consAbb(raiz,NULL,NULL);
  return abb;
 }
 TInfo raiz = crearInfo(cant, 0.0);
 TAbb izquierdo = minaux(h - 1, cant-minNodos(h-1)+minNodos(h-2));
 TAbb derecho = minaux(h - 2,cant+minNodos(h-1)-minNodos(h-2));
 TAbb res = consAbb(raiz, izquierdo, derecho);
 return res;
 }

TAbb avlMin(nat h){ 
  nat cant = minNodos(h-1)+1;
  TAbb res = minaux(h,cant);
  return res;
}

double sumadou(nat n, TMapping Map){
  double real = 0;
  while (esClaveEnMap(n, Map)){
    real = real + valorEnMap(n, Map);
    desasociarEnMap(n, Map);
  }
  return real;
}

TCadena filtradaOrdenada(TCadena cad, TIterador it){ 
  TCadena res = crearCadena();
  reiniciarIterador(it);
  if (cad!=NULL && estaDefinidaActual(it)){
    nat n = cantidadEnCadena(cad);
    TMapping map = crearMap(n);
    for (nat i = 0; i < n; i++){
        asociarEnMap(natInfo(primeroEnCadena(cad)), realInfo(primeroEnCadena(cad)), map);
        cad = cadenaSiguiente(cad);
    }
      while (estaDefinidaActual(it)){
        bool clave = esClaveEnMap(actualEnIterador(it), map);
        if (clave){
          double R = sumadou(actualEnIterador(it), map);
          res = insertarAlFinal(actualEnIterador(it), R, res);
        }
        avanzarIterador(it);
      }
      liberarMap(map);
  }
  return res;
}

bool estaOrdenada(TCadena cad){
  bool res = false;
  TCadena cursor = cad;
  if (cadenaSiguiente(cad) == cad || cad == NULL){
    res = true;
  }
  else{
    while (cadenaSiguiente(cursor) != cad && natInfo(primeroEnCadena(cursor)) < natInfo(primeroEnCadena(cadenaSiguiente(cursor)))){
      cursor = cadenaSiguiente(cursor);
    }
    if (cadenaSiguiente(cursor) == cad){
      res = true;
    }
    else{
      res = false;
    }
  }
  return res;
}

TCadena mezclaCadenas(TCadena cad1, TCadena cad2){
  TCadena resultado = NULL;
  nat cont1 = cantidadEnCadena(cad1);
  nat cont2 = cantidadEnCadena(cad2);
  if (cad1 == NULL){
    return copiaCadena(cad2);
  }
  if (cad2 == NULL){
    return copiaCadena(cad1);
  }
  if (cadenaSiguiente(cad1) == cad1 && cadenaSiguiente(cad2) == cad2){
    if (natInfo(primeroEnCadena(cad1)) < natInfo(primeroEnCadena(cad2))){
      resultado = insertarAlFinal(natInfo(primeroEnCadena(cad1)), realInfo(primeroEnCadena(cad1)), resultado);
      resultado = insertarAlFinal(natInfo(primeroEnCadena(cad2)), realInfo(primeroEnCadena(cad2)), resultado);
    }
    else if (natInfo(primeroEnCadena(cad1)) == natInfo(primeroEnCadena(cad2))){
      resultado = insertarAlFinal(natInfo(primeroEnCadena(cad1)), realInfo(primeroEnCadena(cad1)), resultado);
    }
    else{
      resultado = insertarAlFinal(natInfo(primeroEnCadena(cad2)), realInfo(primeroEnCadena(cad2)), resultado);
      resultado = insertarAlFinal(natInfo(primeroEnCadena(cad1)), realInfo(primeroEnCadena(cad1)), resultado);
    }
  }
  if (cadenaSiguiente(cad1) != cad1 || cadenaSiguiente(cad2) != cad2){
    while (cont1 != 0 && cont2 != 0){
      if (natInfo(primeroEnCadena(cad1)) < natInfo(primeroEnCadena(cad2))){
        resultado = insertarAlFinal(natInfo(primeroEnCadena(cad1)), realInfo(primeroEnCadena(cad1)), resultado);
        cad1 = cadenaSiguiente(cad1);
        cont1--;
      }
      else if (natInfo(primeroEnCadena(cad1)) == natInfo(primeroEnCadena(cad2))){
        resultado = insertarAlFinal(natInfo(primeroEnCadena(cad1)), realInfo(primeroEnCadena(cad1)), resultado);
        cad1 = cadenaSiguiente(cad1);
        cad2 = cadenaSiguiente(cad2);
        cont1--;
        cont2--;
      }
      else{
        resultado = insertarAlFinal(natInfo(primeroEnCadena(cad2)), realInfo(primeroEnCadena(cad2)), resultado);
        cad2 = cadenaSiguiente(cad2);
        cont2--;
      }
    }
    while (cont1 != 0){
      resultado = insertarAlFinal(natInfo(primeroEnCadena(cad1)), realInfo(primeroEnCadena(cad1)), resultado);
      cad1 = cadenaSiguiente(cad1);
      cont1--;
    }
    while (cont2 != 0){
      resultado = insertarAlFinal(natInfo(primeroEnCadena(cad2)), realInfo(primeroEnCadena(cad2)), resultado);
      cad2 = cadenaSiguiente(cad2);
      cont2--;
    }
  }
  return resultado;
}

TAbb baux(TInfo *arreglo, int ini, int fin){
  if (ini > fin){
    return NULL;
  }
  int medio = (ini+fin) / 2;
  TInfo raiz = copiaInfo(arreglo[medio]);
  TAbb izq = baux(arreglo, ini, medio-1);
  TAbb der = baux(arreglo, medio+1, fin);
  TAbb abb = consAbb(raiz, izq, der);
  return abb;
}

TAbb crearBalanceado(TInfo *arreglo, nat n){
  return baux(arreglo, 0, n - 1);
}

TInfo *cadtoArr(TCadena cad, nat n){
  TInfo *arr = new TInfo[n];
  for (nat i = 0; i < n; i++){
    arr[i] = primeroEnCadena(cad);
    cad = cadenaSiguiente(cad);
  }
  return arr;
}

TAbb unionAbbs(TAbb abb1, TAbb abb2){
  TCadena a = linealizacion(abb1);
  TCadena b = linealizacion(abb2);
  TCadena merged = mezclaCadenas(a, b);
  nat n = cantidadEnCadena(merged);
  TInfo *arreglo = cadtoArr(merged, n);
  TAbb resultado = crearBalanceado(arreglo, n);
  liberarCadena(a);
  liberarCadena(b);
  liberarCadena(merged);
  delete[] arreglo;
  return resultado;
}

TCola ordenadaPorModulo(nat p, TCadena cad){
  TCola res = crearCola();
  if (cad != NULL){
    TColCadenas nueva = crearColCadenas(p);
    TCadena t1 = cad;
    while (cadenaSiguiente(cad) != t1){
      nueva = insertarEnColCadenas(natInfo(primeroEnCadena(cad)), realInfo(primeroEnCadena(cad)), (natInfo(primeroEnCadena(cad)) % p), nueva);
      cad = cadenaSiguiente(cad);
    }
    nueva = insertarEnColCadenas(natInfo(primeroEnCadena(cad)), realInfo(primeroEnCadena(cad)), (natInfo(primeroEnCadena(cad)) % p), nueva);

    for (nat i = 0; i < p; i++){
      if (cantidadColCadenas(i, nueva) > 0){
        TCadena ca = cadenaDeColCadenas(i, nueva);
        nat size = cantidadColCadenas(i, nueva);
        int t = size;
        TInfo *arr = cadtoArr(ca, size);
        for (int j = (t - 1); j >= 0; j--){
          encolar(arr[j], res);
        }
        delete[] arr;
      }
    }
    liberarColCadenas(nueva);
  }
  return res;
}

TPila menoresQueElResto(TCadena cad, nat cantidad){
  TPila res = crearPila();
  if (cantidad == 0){
    return res;
  }
  else if (cantidad == 1){
    apilar(primeroEnCadena(cad), res);
    return res;
  }
  else if (cantidad == 2){
    if (natInfo(primeroEnCadena(cad)) < natInfo(primeroEnCadena(cadenaSiguiente(cad))))
      apilar(primeroEnCadena(cad), res);
    else
      apilar(primeroEnCadena(cadenaSiguiente(cad)), res);
  }
  else{
    nat cont2 = cantidad;
    TCadena ultimo = cad;
    while (cont2 != 1){
      ultimo = cadenaSiguiente(ultimo);
      cont2--;
    }
    TCadena c1 = cad;
    TCadena cursor = cadenaSiguiente(c1);
    while (c1 != ultimo){
      if (natInfo(primeroEnCadena(c1)) < natInfo(primeroEnCadena(ultimo))){
        while (natInfo(primeroEnCadena(c1)) < natInfo(primeroEnCadena(cursor)) && cursor != ultimo){
          cursor = cadenaSiguiente(cursor);
        }
        if (cursor == ultimo){
          apilar(primeroEnCadena(c1), res);
          c1 = cadenaSiguiente(c1);
          cursor = cadenaSiguiente(c1);
        }
        else{
          c1 = cadenaSiguiente(c1);
          cursor = cadenaSiguiente(c1);
        }
      }
      else{
        c1 = cadenaSiguiente(c1);
        cursor = cadenaSiguiente(c1);
      }
    }
    apilar(primeroEnCadena(ultimo), res);
  }
  return res;
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
    printRec(prf + 1, derecho(abb));
    for (int i = 0; i < prf; i++){
      printf("-");
    }
    imprimirInfo(raiz(abb));
    printf("\n");
    printRec(prf + 1, izquierdo(abb));
  }
}

void imprimirAbb(TAbb abb){
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
  if (a > b)
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

bool esPerfecto(TAbb abb){
  if (abb == NULL){
    return true;
  }
  else{
    if (pow(2,altura(abb)) - 1 == cantNodos(abb)){
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
      nuevomenores = consAbb(copiaInfo(elem), mizq, mder);
    }
    else if (mizq == NULL){
      nuevomenores = mder;
    }
    else if (mder == NULL){
      nuevomenores = mizq;
    }
    else{
      mayor = copiaInfo(mayorEnAbb(mizq));
      mizq = removerDeAbb(natInfo(mayorEnAbb(mizq)), mizq);
      nuevomenores = consAbb(mayor, mizq, mder);
    }
  }
  return nuevomenores;
}

void caminorec(nat clave, nat k, TAbb abb, TIterador &res, nat &cont){
  if (k != 0){
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
  caminorec(clave, k, abb, res, cont);
  return res;
}

void palcortasAux(char arr[], nat k, nat l, TPalabras palabras){
  if (letra(palabras) == '\0'){
    arr[l] = '\0';
    if (l <= k)
      printf("%s\n", arr);
  }
  else{
    arr[l] = letra(palabras);
    palcortasAux(arr, k, l + 1, subarboles(palabras));
  }
  if (siguientes(palabras) != NULL)
    palcortasAux(arr, k, l, siguientes(palabras));
}

void imprimirPalabrasCortas(nat k, TPalabras palabras){
  char arr[k];
  nat l;
  l = 0;
  palcortasAux(arr, k, l, subarboles(palabras));
}

TPalabras buscarRec(ArregloChars prefijo, TPalabras palabras, int largo, int i){
  if (palabras != NULL){
    if (letra(palabras) != prefijo[i]){
      return buscarRec(prefijo, siguientes(palabras), largo, i);
    }
    else{
      if (largo == i + 1){
        return palabras;
      }
      else{
        return buscarRec(prefijo, subarboles(palabras), largo, i + 1);
      }
    }
  }
  else{
    return NULL;
  }
}

TPalabras buscarFinPrefijo(ArregloChars prefijo, TPalabras palabras) {
  TPalabras res;
  int i = 0;
  int largo = strlen(prefijo);
  res = buscarRec(prefijo, subarboles(palabras), largo, i);
  return res;
}

void reverRec(TIterador iter, TIterador &res){
  if (estaDefinidaActual(iter)){
    nat aux = actualEnIterador(iter);
    avanzarIterador(iter);
    reverRec(iter, res);
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
