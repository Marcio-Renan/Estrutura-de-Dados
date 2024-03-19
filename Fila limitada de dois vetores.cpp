#include <iostream>

using namespace std;

struct Fila{
    int vet1[5], vet2[5], p, u;
};

void inicializar(Fila &F){
    F.p = -1;
    F.u = -1;
}

bool vazio(Fila &F){
    return (F.p == -1);
}

bool cheio(Fila &F){
    return !((F.p + F.u + 1) % 10);
}

void inserir(Fila &F, int elemento){
    if(cheio(F))    return;
    
    if(vazio(F))    F.p = 0;
    
    F.u = ++F.u % 10;
    //cout << F.u << "\n";
    
    if(F.u > 5)     F.vet2[F.u-5] = elemento;
    
    else F.vet1[F.u] = elemento;
    
    
}

void remover(Fila &F){
    if(vazio(F)) return;
    if(F.p == F.u) F.p = F.u = -1;
    else F.p = (F.p+1 % 10);
    cout << F.p << "\n";
}

int primeiro(Fila &F){
    return F.p > 4 ? F.vet1[F.p] : F.vet2[F.p-5];
}

int main()
{
    Fila F;
    inicializar(F);
    inserir(F, 1);
    inserir(F, 2);
    inserir(F, 3);
    inserir(F, 4);
    inserir(F, 5);
    inserir(F, 6);
    inserir(F, 7);
    inserir(F, 8);
    inserir(F, 9);
    inserir(F, 10);
    remover(F);
    remover(F);
    remover(F);
    remover(F);
    remover(F);
    remover(F);
    remover(F);
    remover(F);
    remover(F);
    remover(F);
    inserir(F,11);

    cout << primeiro(F);
    
    return 0;
}
