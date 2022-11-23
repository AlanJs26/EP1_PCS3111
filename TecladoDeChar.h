#ifndef TECLADODECHAR_h
#define TECLADODECHAR_h

#include "Teclado.h"


class TecladoDeChar : public Teclado {

public:
    TecladoDeChar();
    virtual ~TecladoDeChar();
    virtual Dado* ler();
};

#endif