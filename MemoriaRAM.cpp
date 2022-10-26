#include "MemoriaRAM.h"

MemoriaRAM::MemoriaRAM(int tamanho){
    dados = new Dado*[tamanho];

    for (int i = 0; i < tamanho; i++) {
        dados[i] = NULL;
    }
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
    if(dadosExternos->size() > tamanho)
        // Arrumar Logic_error
        throw new logic_error("Tamanho Excedido");
    
    for(int i = 0; i < dadosExternos->size(); i++){
        dados[i] = dadosExternos->;

    }

}
