#ifndef MEMORIADEINSTRUCOES_h
#define MEMORIADEINSTRUCOES_h

#include "Instrucao.h"

class MemoriaDeInstrucoes {
private:
    int tamanho;
    Instrucao** instrucoes;
public:

    MemoriaDeInstrucoes(int tamanho);
    virtual ~MemoriaDeInstrucoes();
    int getTamanho();
    Instrucao* ler(int posicao);
    bool escrever(int posicao, Instrucao* d);

};

#endif