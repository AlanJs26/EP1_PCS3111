#ifndef UNIDADEDECONTROLE_h
#define UNIDADEDECONTROLE_h

#include "BancoDeRegistradores.h"
#include "MemoriaDeDados.h"
#include "MemoriaDeInstrucoes.h"

class UnidadeDeControle {
private:
    BancoDeRegistradores* registradores;
    MemoriaDeInstrucoes* instrucoes;
    MemoriaDeDados* dados;
    int pc = 0;

public:
    UnidadeDeControle(BancoDeRegistradores* registradores,
    MemoriaDeInstrucoes* instrucoes, MemoriaDeDados* dados);
    virtual ~UnidadeDeControle();
    BancoDeRegistradores* getBancoDeRegistradores();
    MemoriaDeDados* getMemoriaDeDados();
    MemoriaDeInstrucoes* getMemoriaDeInstrucoes();
    int getPC();
    void setPC(int pc);
    void executarInstrucao();
};

#endif