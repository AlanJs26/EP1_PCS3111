#include "UnidadeDeControle.h"
#include <iostream>
using namespace std;

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria){
    this->registradores = registradores;
    this->memoria = memoria;
    this->pc = 0;
}

UnidadeDeControle::~UnidadeDeControle(){
    delete this->registradores;
    delete this->memoria;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores(){
    return this->registradores;
}
Memoria* UnidadeDeControle::getMemoria(){
    return this->memoria;
}

int UnidadeDeControle::getPC(){
    return this->pc;
}

void UnidadeDeControle::setPC(int pc){
    this->pc = pc;
}

void UnidadeDeControle::executarInstrucao(){
    Instrucao* instrucaoAtual = dynamic_cast<Instrucao*>(memoria->ler(pc));

    if (instrucaoAtual == NULL) {
        pc++;
        return;
    }

    if(instrucaoAtual->getOpcode() == Instrucao::TIPO_R){
        switch (instrucaoAtual->getFuncao())
        {
        case Instrucao::FUNCAO_ADD:
            registradores->setValor(
                instrucaoAtual->getDestino(),
                registradores->getValor(instrucaoAtual->getOrigem1()) + registradores->getValor(instrucaoAtual->getOrigem2())
            );
            break;
        case Instrucao::FUNCAO_SUB:
            registradores->setValor(
                instrucaoAtual->getDestino(),
                registradores->getValor(instrucaoAtual->getOrigem1()) - registradores->getValor(instrucaoAtual->getOrigem2())
            );
            break;
        case Instrucao::FUNCAO_MULT:
            registradores->setValor(
                24,
                registradores->getValor(instrucaoAtual->getOrigem1()) * registradores->getValor(instrucaoAtual->getOrigem2())
            );
            break;
        case Instrucao::FUNCAO_DIV:
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
        case Instrucao::J:
            pc = instrucaoAtual->getImediato();
            atualizarPC = false;
            break;
        case Instrucao::BNE:
            if(registradores->getValor(instrucaoAtual->getOrigem1()) != registradores->getValor(instrucaoAtual->getOrigem2())){
                pc = instrucaoAtual->getImediato();
                atualizarPC = false;
            }
            break;
        case Instrucao::BEQ:
            if(registradores->getValor(instrucaoAtual->getOrigem1()) == registradores->getValor(instrucaoAtual->getOrigem2())){
                pc = instrucaoAtual->getImediato();
                atualizarPC = false;
            }
            break;
        case Instrucao::LW:
            d = memoria->ler(instrucaoAtual->getImediato());
            
            registradores->setValor(
                instrucaoAtual->getDestino(),
                d == NULL ? 0 : d->getValor()
            );

            break;
        case Instrucao::SW:
            d = new Dado(registradores->getValor(instrucaoAtual->getDestino()));
            memoria->escrever(
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