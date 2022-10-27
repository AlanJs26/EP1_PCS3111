#include "MemoriaRAM.h"

MemoriaRAM::MemoriaRAM(int tamanho){
    dados = new Dado*[tamanho];

    for (int i = 0; i < tamanho; i++) {
        dados[i] = NULL;
    }
    this->tamanho = tamanho;
};

MemoriaRAM::~MemoriaRAM(){
    for (int i = 0; i < tamanho; i++) {
        if (dados[i] != NULL) {
            delete dados[i];
        }
    }
    delete[] dados;
}

void MemoriaRAM::escrever(list <Dado*>* dadosExternos){
    if(dadosExternos->size() > tamanho){
        // TODO - Arrumar Logic_error
        throw new logic_error("Tamanho Excedido");
    }

    auto it = dadosExternos->begin();
    for(int i = 0; i < dadosExternos->size(); i++){
        advance(it, 1);

        dados[i] = *it;
    }

}

void MemoriaRAM::imprimir(){
    for (int i = 0; i < tamanho; i++)
    {
        if(dados[i] == NULL){
            cout << i << ": " << "-" << endl;
        }else{
            cout << i << ": " << dados[i]->getValor() << endl;
        }
    }
}

void MemoriaRAM::escrever(int posicao, Dado* d){
    if (posicao < 0 || posicao >= tamanho) {
        throw new logic_error("Posicao invalida de memoria");
    }

    if (dados[posicao] != NULL){
        delete dados[posicao];
    }

    dados[posicao] = d;
}


Dado* MemoriaRAM::ler(int posicao){
    if (posicao < 0 || posicao >= tamanho) {
        throw new logic_error("Posicao invalida");
    }
    
    return dados[posicao];
}