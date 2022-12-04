#include "MonitorDeChar.h"

MonitorDeChar::MonitorDeChar(){
}

MonitorDeChar::~MonitorDeChar(){
}

void MonitorDeChar::escrever(Dado* d){
    cout << (char)(d->getValor());
}