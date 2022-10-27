#include "Instrucao.h"
#include <iostream>
using namespace std;

Instrucao::~Instrucao(){
    this->opcode = 0;
    this->origem1 = 0;
    this->origem2 = 0;
    this->destino = 0;
    this->imediato = 0;
    this->funcao = 0;
}

Instrucao::Instrucao(int opcode, int origem1, int origem2, int destino, int imediato,
    int funcao){

    this->opcode = opcode;
    this->origem1 = origem1;
    this->origem2 = origem2;
    this->destino = destino;
    this->imediato = imediato;
    this->funcao = funcao;
}

int Instrucao::getOpcode(){
    return this->opcode;
}
int Instrucao::getOrigem1(){
    return this->origem1;
}
int Instrucao::getOrigem2(){
    return this->origem2;
}
int Instrucao::getDestino(){
    return this->destino;
}
int Instrucao::getImediato(){
    return this->imediato;
}
int Instrucao::getFuncao(){
    return this->funcao;
}