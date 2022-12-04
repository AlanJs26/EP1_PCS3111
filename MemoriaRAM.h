#ifndef MEMORIA_RAM_h
#define MEMORIA_RAM_h

#include "Memoria.h"
#include <iostream>
#include <list>
using namespace std;

class MemoriaRAM : public Memoria {
public:
    MemoriaRAM(int tamanho);
    virtual ~MemoriaRAM();
    virtual void escrever(list<Dado*>* dados); 

    int getTamanho();
    void escrever(int posicao, Dado* d);
    Dado* ler(int posicao);
    void imprimir();
};

#endif