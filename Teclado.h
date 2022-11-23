#ifndef TECLADO_h
#define TECLADO_h

#include "Dispositivo.h"


class Teclado : public Dispositivo {

public:
    Teclado();
    virtual ~Teclado();
    virtual Dado* ler();
    virtual void escrever(Dado* d);
};

#endif