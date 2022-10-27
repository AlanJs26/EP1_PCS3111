#ifndef MEMORIA_h
#define MEMORIA_h

#include "Dado.h"
#include <iostream>
#include <stdexcept>
using namespace std;

class Memoria {
protected:
    int tamanho;
    Dado** dados;
public:
    Memoria();
    virtual ~Memoria();

    virtual int getTamanho();
    virtual Dado* ler(int posicao) = 0;
    virtual void escrever(int posicao, Dado* d) = 0;
    virtual void imprimir() = 0;
};

#endif