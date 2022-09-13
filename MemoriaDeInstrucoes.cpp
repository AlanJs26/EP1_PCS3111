#include "MemoriaDeInstrucoes.h"
#include "Instrucao.h"
#include <iostream>
using namespace std;
#include <vector>

vector<int> g = {1,2,3};

MemoriaDeInstrucoes::MemoriaDeInstrucoes(int tamanho){
    instrucoes = (Instrucao**)malloc(tamanho * sizeof(Instrucao*));
    for (int i = 0; i < tamanho; i++)
    {
        instrucoes[i] = NULL;
    }
    
    this->tamanho = tamanho;
}

MemoriaDeInstrucoes::~MemoriaDeInstrucoes(){
    for (int i = 0; i < tamanho; i++){
        if(instrucoes[i] != NULL){
            delete instrucoes[i];
        }
    }
    free(instrucoes);
}

int MemoriaDeInstrucoes::getTamanho(){
    return this->tamanho;
}

Instrucao* MemoriaDeInstrucoes::ler(int posicao){
    if(posicao >= tamanho || posicao < 0){
        return NULL;
    }

    return instrucoes[posicao];
}

bool MemoriaDeInstrucoes::escrever(int posicao, Instrucao* d){
    if(posicao >= tamanho || posicao < 0){
        return false;
    }

    if(instrucoes[posicao] != NULL){
        delete instrucoes[posicao];
    }

    instrucoes[posicao] = d;

    return true;
}