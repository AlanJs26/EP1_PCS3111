#include "ESMapeadaNaMemoria.h"
#include "Teclado.h"
#include "TecladoDeChar.h"
#include "Monitor.h"
#include "MonitorDeChar.h"

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m){
    memoriaRam = m;

    this->dispositivos = new vector<Dispositivo*>();
}

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos){
    memoriaRam = m;

    this->dispositivos = dispositivos;
}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria(){
    delete memoriaRam;
    for (int i = 0; i < (int)(dispositivos->size()); i++){
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
    return memoriaRam->getTamanho() + (int)(dispositivos->size());
}

Dado* ESMapeadaNaMemoria::ler(int posicao){
    if (posicao < memoriaRam->getTamanho()){
        return memoriaRam->ler(posicao);
    }else if((size_t)(posicao-memoriaRam->getTamanho()) < dispositivos->size()){
        return dispositivos->at(posicao-memoriaRam->getTamanho())->ler();
    }
    throw new logic_error("posicao fora de ESMapeadaNaMemoria");
}


void ESMapeadaNaMemoria::escrever(int posicao, Dado* d){
    if (posicao < memoriaRam->getTamanho()){
        memoriaRam->escrever(posicao, d);
    }else if((size_t)(posicao-memoriaRam->getTamanho()) < dispositivos->size()){
        dispositivos->at(posicao-memoriaRam->getTamanho())->escrever(d);
    }else{
        throw new logic_error("posicao fora de ESMapeadaNaMemoria");
    }
}

void ESMapeadaNaMemoria::imprimir(){
    memoriaRam->imprimir();
}
