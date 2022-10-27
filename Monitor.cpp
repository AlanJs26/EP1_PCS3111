#include "Monitor.h"

Dado* Monitor::ler(){
    throw new logic_error("Monitor não é um dispositivo de entrada");
}

void Monitor::escrever(Dado* d){
    cout << d->getValor() << endl;
}