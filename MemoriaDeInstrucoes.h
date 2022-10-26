#ifndef MEMORIADEINSTRUCOES_h
#define MEMORIADEINSTRUCOES_h

#include "Instrucao.h"
#include "Memoria.h"

class MemoriaDeInstrucoes : public Memoria<Instrucao> {
public:
    MemoriaDeInstrucoes(int tamanho) : Memoria<Instrucao>(tamanho){};
};

#endif