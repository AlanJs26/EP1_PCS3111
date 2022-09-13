#include "UnidadeDeControle.h"
#include <iostream>
using namespace std;

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores,
    MemoriaDeInstrucoes* instrucoes, MemoriaDeDados* dados){
    this->registradores = registradores;
    this->instrucoes = instrucoes;
    this->dados = dados;
}

UnidadeDeControle::~UnidadeDeControle(){
    delete this->registradores;
    delete this->instrucoes;
    delete this->dados;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores(){
    return this->registradores;
}
MemoriaDeDados* UnidadeDeControle::getMemoriaDeDados(){
    return this->dados;
}
MemoriaDeInstrucoes* UnidadeDeControle::getMemoriaDeInstrucoes(){
    return this->instrucoes;
}

int UnidadeDeControle::getPC(){
    return this->pc;
}

void UnidadeDeControle::setPC(int pc){
    this->pc = pc;
}

void UnidadeDeControle::executarInstrucao(){
    Instrucao* instrucaoAtual = instrucoes->ler(pc);
    if(instrucaoAtual == NULL){
        pc++;
        return;
    }

    if(instrucaoAtual->getOpcode() == TIPO_R){
        switch (instrucaoAtual->getFuncao())
        {
        case FUNCAO_ADD:
            registradores->setValor(
                instrucaoAtual->getDestino(),
                registradores->getValor(instrucaoAtual->getOrigem1()) + registradores->getValor(instrucaoAtual->getOrigem2())
            );
            break;
        case FUNCAO_SUB:
            registradores->setValor(
                instrucaoAtual->getDestino(),
                registradores->getValor(instrucaoAtual->getOrigem1()) - registradores->getValor(instrucaoAtual->getOrigem2())
            );
            break;
        case FUNCAO_MULT:
            registradores->setValor(
                24,
                registradores->getValor(instrucaoAtual->getOrigem1()) * registradores->getValor(instrucaoAtual->getOrigem2())
            );
            break;
        case FUNCAO_DIV:
            registradores->setValor(
                24,
                registradores->getValor(instrucaoAtual->getOrigem1()) / registradores->getValor(instrucaoAtual->getOrigem2())
            );
            registradores->setValor(
                25,
                registradores->getValor(instrucaoAtual->getOrigem1()) % registradores->getValor(instrucaoAtual->getOrigem2())
            );
            break;
        }
        pc++;
    }else{
        bool atualizarPC = true;
        Dado* d;

        switch (instrucaoAtual->getOpcode())
        {
        case J:
            pc = instrucaoAtual->getImediato();
            atualizarPC = false;
            break;
        case BNE:
            if(registradores->getValor(instrucaoAtual->getOrigem1()) != registradores->getValor(instrucaoAtual->getOrigem2())){
                pc = instrucaoAtual->getImediato();
                atualizarPC = false;
            }
            break;
        case BEQ:
            if(registradores->getValor(instrucaoAtual->getOrigem1()) == registradores->getValor(instrucaoAtual->getOrigem2())){
                pc = instrucaoAtual->getImediato();
                atualizarPC = false;
            }
            break;
        case LW:
            d = dados->ler(instrucaoAtual->getImediato());
            registradores->setValor(
                instrucaoAtual->getDestino(),
                d == NULL ? 0 : d->getValor()
            );
            break;
        case SW:
            d = new Dado(registradores->getValor(instrucaoAtual->getDestino()));
            dados->escrever(
                instrucaoAtual->getImediato(),
                d
            );
            break;
        }

        if(atualizarPC){
            pc++;
        }
    }
    
}