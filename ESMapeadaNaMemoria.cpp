#include "ESMapeadaNaMemoria.h"
#include "Teclado.h"
#include "TecladoDeChar.h"
#include "Monitor.h"
#include "MonitorDeChar.h"

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m){
    memoriaRam = m;
}

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos){
    memoriaRam = m;

    this->dispositivos = dispositivos;
}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria(){
    delete memoriaRam;
    for (int i = 0; i < (int)(dispositivos->size()); i++)
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
    if (posicao < memoriaRam->getTamanho())
    {
        return memoriaRam->ler(posicao);
    }else if((size_t)(posicao-memoriaRam->getTamanho()) < dispositivos->size()){
        return dispositivos->at(posicao-memoriaRam->getTamanho())->ler();
    }

    throw new logic_error("posicao fora de ESMapeadaNaMemoria");
}


void ESMapeadaNaMemoria::escrever(int posicao, Dado* d){
    if (posicao < memoriaRam->getTamanho())
    {
        memoriaRam->escrever(posicao, d);
    }else if((size_t)(posicao-memoriaRam->getTamanho()) < dispositivos->size()){
        dispositivos->at(posicao-memoriaRam->getTamanho())->escrever(d);
    }else{
        throw new logic_error("posicao fora de ESMapeadaNaMemoria");
    }
}

void ESMapeadaNaMemoria::imprimir(){
    memoriaRam->imprimir();

    // for(Dispositivo* d : *dispositivos){
    //     Monitor* monitor = dynamic_cast<Monitor*>(d);
    //     MonitorDeChar* monitordechar = dynamic_cast<MonitorDeChar*>(d);
    //     Teclado* teclado = dynamic_cast<Teclado*>(d);
    //     TecladoDeChar* tecladodechar = dynamic_cast<TecladoDeChar*>(d);

    //     if(monitor != NULL){
    //         cout << "Dispositivo " << "Monitor" << endl;
    //     }else if(monitordechar != NULL){
    //         cout << "Dispositivo " << "MonitorDeChar" << endl;
    //     }else if(teclado != NULL){
    //         cout << "Dispositivo " << "Teclado" << endl;
    //     }else if(tecladodechar != NULL){
    //         cout << "Dispositivo " << "TecladodeChar" << endl;
    //     }else{
    //         cout << "Dispositivo Desconhecido" << endl;
    //     }
    // }
}
