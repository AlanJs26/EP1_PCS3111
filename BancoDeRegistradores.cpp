#include "BancoDeRegistradores.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void BancoDeRegistradores::resetaRegistradores(){
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++){
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
    if(registrador >= QUANTIDADE_REGISTRADORES || registrador < 0){
        throw new logic_error("BancoDeRegistradores::getValor  :  Registrador não encontrado");
    }

    return registradores[registrador];
}

void BancoDeRegistradores::setValor(int registrador, int valor){
    if(registrador >= QUANTIDADE_REGISTRADORES || registrador < 0){
        throw new logic_error("BancoDeRegistradores::setValor  :  Registrador não encontrado");
    }

    registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir(){
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++)
    {
        cout << i << ": " << registradores[i] << endl;
    }
}