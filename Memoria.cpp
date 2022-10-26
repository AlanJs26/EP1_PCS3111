#include "Memoria.h"

int Memoria::getTamanho(){
    return tamanho;
}

Dado* Memoria::ler(int posicao){
    if (posicao < 0 || posicao >= tamanho) {
        throw new logic_error("Posicao invalida");
    }
    
    return dados[posicao];
}

void Memoria::escrever(int posicao, Dado* d){
    if (posicao < 0 || posicao >= tamanho) {
        throw new logic_error("Posicao invalida de memoria");
    }

    if (dados[posicao] != NULL){
        delete dados[posicao];
    }

    dados[posicao] = d;
}

void Memoria::imprimir(){
    for (int i = 0; i < tamanho; i++)
    {
        if(dados[i] == NULL){
            cout << i << ": " << "-" << endl;
        }else{
            cout << i << ": " << dados[i]->getValor() << endl;
        }
    }
}