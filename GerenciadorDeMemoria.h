#ifndef GERENCIADORDEMEMORIA_h
#define GERENCIADORDEMEMORIA_h

#include "MemoriaRAM.h"
#include <fstream>
#include <string>

class GerenciadorDeMemoria {


public:
    GerenciadorDeMemoria(){};
    // virtual ~GerenciadorDeMemoria();
    virtual void load(string arquivo, MemoriaRAM* m);
    virtual void dump(string arquivo, MemoriaRAM* m); 
};

#endif