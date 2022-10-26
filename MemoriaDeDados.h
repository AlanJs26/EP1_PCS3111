#ifndef MEMORIADEDADOS_h
#define MEMORIADEDADOS_h

#include "Dado.h"
#include "Memoria.h"

class MemoriaDeDados : public Memoria<Dado> {
public:
    MemoriaDeDados(int tamanho) : Memoria<Dado>(tamanho){};

    void imprimir();
};

#endif