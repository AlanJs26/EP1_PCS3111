#include "TecladoDeChar.h"

Dado* TecladoDeChar::ler(){
    int valor;
    cout << "Digite um caracter: ";
    cin >> valor;

    return new Dado((int)(valor));
}