
typedef unsigned int uint;
struct rep_heap{
    T *arreglo;
    uint tope;
    uint max_elems;
};
typedef rep_heap *heap_t;

//Filtrado Ascendente version recursiva:
void filtradoAscRec(T* arreglo, uint pos){
    if (pos > 1 && arreglo[pos/2] > arreglo[pos]){
        swap(arreglo[pos/2], arreglo[pos]);
        filtradoAscRec(arreglo, pos/2);
    }
}

//Filtrado Ascendente version iterativa:
void filtradoAscIterativo(T* arreglo, uint pos){
    while(pos > 1 && arreglo[pos/2] > arreglo[pos]){
        swap(arreglo[pos/2], arreglo[pos]);
        pos/=2; //divide y asigna
    }
}

//Filtrado Descendente version recursiva:
void filtradoDescRec(T* arreglo, uint tope, uint pos){
    if (2*pos <= tope){
        uint pos_hijo = 2*pos;
        if (2*pos <= tope && arreglo[pos_hijo] > arreglo[pos_hijo+1])
            pos_hijo++;
        if (arreglo[pos] > arreglo[pos_hijo]){
            swap(arreglo[pos], arreglo[pos_hijo]);
            filtradoDesRec(arreglo,tope,pos_hijo);
        }
    }
}

// Filtrado Descendente version iterativa:
void filtradoDesIter(T* arreglo, uint tope, uint pos){
    T swap = arreglo[pos];
    bool flag = true;
    while(2*pos <= tope && flag){
        uint pos_hijo = 2*pos;
        if ( 2*pos+1 <= tope && arreglo[pos_hijo] > arreglo[pos_hijo+1])
            pos_hijo++;
        if (arreglo[pos] > arreglo[pos_hijo]){
            arreglo[pos] = arreglo[pos_hijo];
            pos = pos_hijo;
        }
        else{
            flag = false;
        }
    }
    arreglo[pos] = swap;
}

// PRE: !estaLleno(h);
void insertar(heap_t &t, T dato){
    h->tope++;
    h->arreglo[h->tope] = dato;
    filtrarAsc(arreglo, h->tope);
}


void eliminar_min(heap_t &h, T dato){ 
    if (h->tope > 0){
        // liberar(h->arreglo[i]);
        h->arreglo[i] = h->arreglo[h->tope];
        h->tope--;
        filtradoDesc(arreglo, h->tope, 1);
    }
}
