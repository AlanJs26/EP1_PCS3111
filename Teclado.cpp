#include "Teclado.h"

void Teclado::escrever(Dado* d){
    throw new logic_error("Teclado não é um dispositivo de saida");
}

Dado* Teclado::ler(){
    int valor;
    cout << "Digite um numero: ";
    cin >> valor;

    return new Dado(valor);
}