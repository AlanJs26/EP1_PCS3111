#include "MemoriaDeDados.h"
#include "Dado.h"
#include <iostream>
using namespace std;

template <class T>
void inicializar(T** dados){
    dados = (T**)malloc(tamanho * sizeof(T*));
    for (int i = 0; i < tamanho; i++)
    {
        dados[i] = NULL;
    }
    
    this->tamanho = tamanho;
}

MemoriaDeDados::MemoriaDeDados(int tamanho){
    inicializar<Dado>(dados);
}

MemoriaDeDados::~MemoriaDeDados(){
    for (int i = 0; i < tamanho; i++){
        if(dados[i] != NULL){
            delete dados[i];
        }
    }
    free(dados);
}

int MemoriaDeDados::getTamanho(){
    return this->tamanho;
}

Dado* MemoriaDeDados::ler(int posicao){
    if(posicao >= tamanho || posicao < 0){
        return NULL;
    }

    return dados[posicao];
}

bool MemoriaDeDados::escrever(int posicao, Dado* d){
    if(posicao >= tamanho || posicao < 0){
        return false;
    }
    if(dados[posicao] != NULL){
        delete dados[posicao];
    }

    dados[posicao] = d;

    return true;

}

void MemoriaDeDados::imprimir(){
    for (int i = 0; i < tamanho; i++)
    {
        if(dados[i] == NULL){
            cout << i << ": " << "-" << endl;
        }else{
            cout << i << ": " << dados[i]->getValor() << endl;
        }
    }
}
