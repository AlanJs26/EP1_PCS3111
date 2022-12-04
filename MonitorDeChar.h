#ifndef MONITORDECHAR_h
#define MONITORDECHAR_h

#include "Monitor.h"


class MonitorDeChar : public Monitor {
public:
    MonitorDeChar();
    virtual ~MonitorDeChar();
    virtual void escrever(Dado* d);
};

#endif