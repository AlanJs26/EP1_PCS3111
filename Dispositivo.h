#ifndef DISPOSITIVO_h
#define DISPOSITIVO_h

#include "Dado.h"
#include <iostream>

using namespace std;

class Dispositivo {
public:
    Dispositivo();
    virtual ~Dispositivo();
    virtual Dado* ler() = 0;
    virtual void escrever(Dado* d) = 0;
};

#endif