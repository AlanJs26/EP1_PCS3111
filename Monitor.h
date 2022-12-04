#ifndef MONITOR_h
#define MONITOR_h

#include "Dispositivo.h"
#include <stdexcept>

using namespace std;

class Monitor : public Dispositivo {
public:
    Monitor();
    virtual ~Monitor();
    virtual Dado* ler();
    virtual void escrever(Dado* d);
};

#endif