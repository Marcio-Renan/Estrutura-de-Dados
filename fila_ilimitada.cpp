#include <iostream>

using namespace std;

template<typename T>
class Fila{
    T *vet;
    int size;
    int last;
    int qtt;
    
    public:
        Fila(){
            size = 1;
            last = -1;
            qtt = 0;
            vet = new T[size];
        }
        
        T primeiro(){
            return vet[last - (qtt - 1)];
        }
        
        void inserir(T element){
            if(qtt == size){
                T *aux = new T[size * 2];
                int first = last - (qtt - 1);
                for(int i = first; i < size; i++){
                    aux[i] = vet[i];
                }
                delete vet;
                *vet = *aux;
            }
            
            vet[++last] = element;
            qtt++;
        }
        
        void remover(){
            if(qtt == size/2){
                T *aux = new T[size / 2];
                int first = last - (qtt - 1);
                for(int i = first; i < size; i++){
                    aux[i] = vet[i];
                }
                delete vet;
                *vet = *aux;
            }
            
            qtt--;
        }
};

int main()
{
    Fila<int> fila;
    fila.inserir(50);
    fila.inserir(20);
    fila.inserir(30);
    fila.inserir(40);
    for(int i = 0; i < 3; i++){
        fila.remover();
    }
    cout << fila.primeiro();

    return 0;
}
