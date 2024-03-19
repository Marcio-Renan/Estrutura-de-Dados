#include <iostream>

using namespace std;

struct Conjunto{
    int vet[5], n;
};

void inicializar(Conjunto &C){
    C.n = 0;
}

bool vazio(Conjunto &C){
    return (!C.n);
}

bool cheio(Conjunto &C){
    return (C.n == 5);
}

bool pertence(Conjunto &C, int elemento, int inicio, int fim){
    if (inicio > fim) return false;
    int metade = inicio + ((fim-inicio)/2);
    if (C.vet[metade] == elemento) return true;
    else if(C.vet[metade] > elemento) return pertence(C, elemento, inicio, metade-1);
    else return pertence(C, elemento, metade+1, fim);
}

int procurarPertence(Conjunto &C, int elemento){
    int inicio = 0, fim = C.n-1;
    while(inicio <= fim){
        int metade = inicio + ((fim-inicio)/2);
        if(C.vet[metade] > elemento){
            fim = metade-1;
        } else{
            inicio = metade+1;
        }
    }
    return inicio;
}

void inserir(Conjunto &C, int elemento){
    if(vazio(C)) C.vet[C.n++] = elemento;
    if(!cheio(C) && !pertence(C, elemento, 0, C.n-1)){
        int posicao = procurarPertence(C, elemento);
        for(int i = C.n; i > posicao;i--){
            C.vet[i] = C.vet[i-1];
        }
        C.vet[posicao] = elemento;
        C.n++;
    }
}

void remover(Conjunto &C, int elemento){
    for(int i = 0; i < C.n; i++){
        if(C.vet[i] == elemento){
            C.n--;
            for(int j = i; j < C.n;j++){
                C.vet[j] = C.vet[j+1];
            }
            break;
        }
    }
}

int main()
{
    Conjunto C;
    inicializar(C);
    inserir(C, 0);
    inserir(C, 1);
    inserir(C, 2);
    inserir(C, 3);
    inserir(C, 4);
    remover(C, 3);
    inserir(C, -1);
    
    for(int i = 0; i < 5; i++){
        cout << C.vet[i] << "\n";
    }

    cout << pertence(C, 4, 0, 4);

    return 0;
}
