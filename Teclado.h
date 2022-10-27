#ifndef TECLADO_h
#define TECLADO_h

#include "Dispositivo.h"


class Teclado : public Dispositivo {

public:
    Teclado();
    virtual ~Teclado();
    virtual Dado* ler() = 0;
    virtual void escrever(Dado* d) = 0;
};

#endif