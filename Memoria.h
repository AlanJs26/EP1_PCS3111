#ifndef MEMORIA_h
#define MEMORIA_h
#include <iostream>

template <class T>
class Memoria {
protected:
    int tamanho;
    T** dados;
public:
    Memoria(int tamanho){
        dados = (T**)malloc(tamanho * sizeof(T*));
        for (int i = 0; i < tamanho; i++)
        {
            dados[i] = NULL;
        }
        
        this->tamanho = tamanho;
    };
    ~Memoria(){
        for (int i = 0; i < tamanho; i++){
            if(dados[i] != NULL){
                delete dados[i];
            }
        }
        free(dados);
    };
    int getTamanho(){
        return this->tamanho;
    };
    T* ler(int posicao){
        if(posicao >= tamanho || posicao < 0){
            return NULL;
        }

        return dados[posicao];
    };
    bool escrever(int posicao, T* d){
        if(posicao >= tamanho || posicao < 0){
            return false;
        }
        if(dados[posicao] != NULL){
            delete dados[posicao];
        }

        dados[posicao] = d;

        return true;

    };
};

#endif