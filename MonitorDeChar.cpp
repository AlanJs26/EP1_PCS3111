#include "MonitorDeChar.h"

void MonitorDeChar::escrever(Dado* d){
    cout << (char)(d->getValor());
}