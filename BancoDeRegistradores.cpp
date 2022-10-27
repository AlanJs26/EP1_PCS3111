#include "BancoDeRegistradores.h"
#include <iostream>
using namespace std;

void BancoDeRegistradores::resetaRegistradores(){
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++)
    {
        registradores[i] = 0;
    }
}
BancoDeRegistradores::~BancoDeRegistradores(){
    resetaRegistradores();
}

BancoDeRegistradores::BancoDeRegistradores(){
    resetaRegistradores();
}

int BancoDeRegistradores::getValor(int registrador){
    if(registrador >= QUANTIDADE_REGISTRADORES || registrador <= 0){
        return 0;
    }

    return registradores[registrador];
}

void BancoDeRegistradores::setValor(int registrador, int valor){
    if(registrador >= QUANTIDADE_REGISTRADORES || registrador <= 0){
        return;
    }

    registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir(){
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++)
    {
        cout << i << ": " << registradores[i] << endl;
    }
}