#include "ESMapeadaNaMemoria.h"

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m){
    memoriaRam = m;
    
}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria(){
    delete memoriaRam;
    for (int i = 0; i < dispositivos->size(); i++)
    {
        delete (*dispositivos)[i];
    }
    dispositivos->clear();
    
    delete dispositivos;
}

MemoriaRAM* ESMapeadaNaMemoria::getMemoriaSubjacente(){
    return memoriaRam;
}


vector<Dispositivo*>* ESMapeadaNaMemoria::getDispositivos(){
    return dispositivos;
}

void ESMapeadaNaMemoria::adicionar(Dispositivo* d){
    dispositivos->push_back(d);
}

int ESMapeadaNaMemoria::getTamanho(){
    return memoriaRam->getTamanho() + dispositivos->size();
}

Dado* ESMapeadaNaMemoria::ler(int posicao){
    if (posicao >= memoriaRam->getTamanho())
    {
        return memoriaRam->ler(posicao);
    }else if(posicao < dispositivos->size()){
        return dispositivos->at(posicao)->ler();
    }
    throw new logic_error("posicao fora de ESMapeadaNaMemoria");
}


void ESMapeadaNaMemoria::escrever(int posicao, Dado* d){
    if (posicao >= memoriaRam->getTamanho())
    {
        memoriaRam->escrever(posicao, d);
    }else if(posicao < dispositivos->size()){
        return dispositivos->at(posicao)->escrever(d);
    }

    throw new logic_error("posicao fora de ESMapeadaNaMemoria");
}

void ESMapeadaNaMemoria::imprimir(){
    memoriaRam->imprimir();
}
