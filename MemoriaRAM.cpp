#include "MemoriaRAM.h"
#include "Instrucao.h"
#include <stdexcept>

MemoriaRAM::MemoriaRAM(int tamanho){
    dados = new Dado*[tamanho];

    for (int i = 0; i < tamanho; i++){
        dados[i] = NULL;
    }
    this->tamanho = tamanho;
}

MemoriaRAM::~MemoriaRAM(){
    for (int i = 0; i < tamanho; i++){
        if (dados[i] != NULL) {
            delete dados[i];
        }
    }
    delete[] dados;
}

void MemoriaRAM::escrever(list <Dado*>* dadosExternos){
    if((int)(dadosExternos->size()) > tamanho){
        throw new logic_error("Tamanho Excedido");
    }

    auto it = dadosExternos->begin();
    for(int i = 0; i < (int)(dadosExternos->size()); i++){
        advance(it, 1);

        dados[i] = *it;
    }
}

void MemoriaRAM::imprimir(){
    for (int i = 0; i < tamanho; i++){
        Instrucao* instrucao = dynamic_cast<Instrucao*>(dados[i]);

        if(instrucao != NULL){
            cout << i << ": " << "Instrucao " << instrucao->getOpcode() << endl;
        }else if(dados[i] != NULL){
            cout << i << ": " << dados[i]->getValor() << endl;
        }else{
            cout << i << ": " << "-" << endl;
        }
    }
}

int MemoriaRAM::getTamanho(){
    return tamanho;
}

void MemoriaRAM::escrever(int posicao, Dado* d){
    if (posicao < 0 || posicao >= tamanho){
        throw new logic_error("Posicao invalida de memoria");
    }

    if (dados[posicao] != NULL){
        delete dados[posicao];
    }
    
    dados[posicao] = d;
}


Dado* MemoriaRAM::ler(int posicao){
    if (posicao < 0 || posicao >= tamanho){
        throw new logic_error("Posicao invalida");
    }
    
    return dados[posicao];
}