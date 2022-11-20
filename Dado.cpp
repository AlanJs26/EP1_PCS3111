#include "Dado.h"
#include <iostream>

Dado::Dado(int valor){
    this->valor = valor;
}

Dado::~Dado(){}

int Dado::getValor(){
    return this->valor;
}

void Dado::imprimir(){
    std::cout << this->valor;
}
