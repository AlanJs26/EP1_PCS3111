#include "Instrucao.h"
#include <iostream>
using namespace std;


Instrucao::~Instrucao(){
}

Instrucao::Instrucao(int opcode, int origem1, int origem2, int destino, int imediato, int funcao) : Dado(opcode){
    this->origem1 = origem1;
    this->origem2 = origem2;
    this->destino = destino;
    this->imediato = imediato;
    this->funcao = funcao;
}

int Instrucao::getOpcode(){
    return this->getValor();
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

Instrucao* Instrucao::criarLW(int destino, int imediato){
    return new Instrucao(Instrucao::LW, 0, 0, destino, imediato, 0);
}

Instrucao* Instrucao::criarSW(int destino, int imediato){
    return new Instrucao(Instrucao::SW, 0, 0, destino, imediato, 0);
}

Instrucao* Instrucao::criarJ(int imediato){
    return new Instrucao(Instrucao::J, 0, 0, 0, imediato, 0);
}

Instrucao* Instrucao::criarBNE(int origem1, int origem2, int imediato){
    return new Instrucao(Instrucao::BNE, origem1, origem2, 0, imediato, 0);
}

Instrucao* Instrucao::criarBEQ(int origem1, int origem2, int imediato){
    return new Instrucao(Instrucao::BEQ, origem1, origem2, 0, imediato, 0);
}

Instrucao* Instrucao::criarADD(int destino, int origem1, int origem2){
    return new Instrucao(Instrucao::TIPO_R, origem1, origem2, destino, 0, Instrucao::FUNCAO_ADD);
}

Instrucao* Instrucao::criarSUB(int destino, int origem1, int origem2){
    return new Instrucao(Instrucao::TIPO_R, origem1, origem2, destino, 0, Instrucao::FUNCAO_SUB);
}

Instrucao* Instrucao::criarMULT(int origem1, int origem2){
    return new Instrucao(Instrucao::TIPO_R, origem1, origem2, 0, 0, Instrucao::FUNCAO_MULT);
}

Instrucao* Instrucao::criarDIV(int origem1, int origem2){
    return new Instrucao(Instrucao::TIPO_R, origem1, origem2, 0, 0, Instrucao::FUNCAO_DIV);
}

void Instrucao::imprimir(){
    cout << "Instrucao " << getOpcode();
}
