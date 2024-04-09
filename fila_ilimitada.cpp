#include <iostream>

using namespace std;

template<typename TX>
struct Fila{
    int qtd_elem;
    int tam;
    int ultimo;
    TX *vet;
};

template<typename TX>
void inicializar(Fila<TX> &f){
    f.ultimo = -1;
    f.vet = new TX[1];
    f.tam = 1;
}

template<typename TX>
bool cheio(Fila<TX> &f){
    return !((f.qtd_elem + 1) % f.tam);
}

template<typename TX>
void inserir(Fila<TX> &f, TX elem){
    if(cheio(f)){
        TX *aux = new TX[2*f.tam];
        for(int i = (f.ultimo + f.tam - f.qtd_elem + 1); i < f.tam; i++){
            aux[i] = f.vet[i];
        }
        f.vet = aux;
        f.tam *= 2;
        delete f.vet;
    }
    
    f.vet[++f.ultimo] = elem;
}

template<typename TX>
void remover(Fila<TX> &f){
    f.qtd_elem--;
    if(f.tam/2 == f.qtd_elem){
        TX *aux = new TX[f.tam/2];
        for(int i = (f.ultimo + f.tam - f.qtd_elem + 1); i < f.tam; i++){
            aux[i] = f.vet[i];
        }
        f.vet = aux;
        f.tam /= 2;
        delete f.vet;
    }
}

template<typename TX>
TX primeiro(Fila<TX> &f){
    return (f.ultimo + f.tam - f.qtd_elem + 1);
}

int main(){
    Fila<int> f;
    inicializar(f);
    inserir(f, 5);
    cout << primeiro(f);
    
    return 0;
}
