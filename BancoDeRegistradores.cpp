#include "BancoDeRegistradores.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void BancoDeRegistradores::resetaRegistradores(){
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++)
    {
        registradores[i] = 0;
    }
};
BancoDeRegistradores::~BancoDeRegistradores(){
    resetaRegistradores();
}

BancoDeRegistradores::BancoDeRegistradores(){
    resetaRegistradores();
}

int BancoDeRegistradores::getValor(int registrador){
    if(registrador >= QUANTIDADE_REGISTRADORES || registrador <= 0){
        // mudar a mensagem de erro
        throw new logic_error("Mensagem de erro");
    }

    return registradores[registrador];
}

void BancoDeRegistradores::setValor(int registrador, int valor){
    if(registrador >= QUANTIDADE_REGISTRADORES || registrador <= 0){
        // mudar a mensagem de erro
        throw new logic_error("Mensagem de erro");
    }

    registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir(){
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++)
    {
        cout << i << ": " << registradores[i] << endl;
    }
}