#ifndef UNIDADEDECONTROLE_h
#define UNIDADEDECONTROLE_h

#include "BancoDeRegistradores.h"
#include "Memoria.h"
#include "Instrucao.h"

class UnidadeDeControle {
private:
    BancoDeRegistradores* registradores;
    Memoria* memoria;
    int pc;
public:
    UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria);
    virtual ~UnidadeDeControle();
    virtual BancoDeRegistradores* getBancoDeRegistradores();
    virtual Memoria* getMemoria();
    virtual int getPC();
    virtual void setPC(int pc);
    virtual void executarInstrucao(); 
};

#endif