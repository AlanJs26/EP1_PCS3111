#ifndef MEMORIA_ESMAPEADANAMEMORIA_h
#define MEMORIA_ESMAPEADANAMEMORIA_h

#include "MemoriaRAM.h"
#include "Dispositivo.h"
#include <vector>

using namespace std;

class ESMapeadaNaMemoria : public Memoria {

private:
    MemoriaRAM* memoriaRam;
    vector<Dispositivo*>* dispositivos;
public:
    ESMapeadaNaMemoria(MemoriaRAM* m);
    ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos);
    virtual ~ESMapeadaNaMemoria();
    virtual MemoriaRAM* getMemoriaSubjacente();
    virtual void adicionar(Dispositivo* d);
    virtual vector<Dispositivo*>* getDispositivos();

    virtual int getTamanho();
    virtual Dado* ler(int posicao);
    virtual void escrever(int posicao, Dado* d);
    virtual void imprimir();
};

#endif