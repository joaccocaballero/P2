typedef unsigned int uint;
void vasos(bool*V,uint n){
    vasosRec(V,1,n);
}
void vasosRec(bool*V,uint inf, uint sup){
    if (sup == inf +3){
        V[inf+1]=false;
        V[sup+1]=true;
    }
    else{
        vasosRec(V,inf+2,inf-2);
    }
}