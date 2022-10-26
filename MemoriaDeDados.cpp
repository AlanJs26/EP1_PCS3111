#include "MemoriaDeDados.h"
#include <iostream>
using namespace std;

void MemoriaDeDados::imprimir(){
    for (int i = 0; i < tamanho; i++)
    {
        if(dados[i] == NULL){
            cout << i << ": " << "-" << endl;
        }else{
            cout << i << ": " << dados[i]->getValor() << endl;
        }
    }
}

