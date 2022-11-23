#include "GerenciadorDeMemoria.h"
#include <fstream>
#include "Instrucao.h"
#include <string>
using namespace std;

GerenciadorDeMemoria::GerenciadorDeMemoria(){}
GerenciadorDeMemoria::~GerenciadorDeMemoria(){}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM* m){
    string linha;

    ifstream file;
    file.open(arquivo.c_str());
    
    if (file.fail()) {
        file.close();
        throw new runtime_error("Arquivo nao encontrado ou erro de leitura");
    }

    file >> linha;

    int tamanhoExterno = stoi(linha);
    if (m->getTamanho() < tamanhoExterno) {
        throw new runtime_error("Nao cabe na memoria");
    }
    
    string tipo;
    int destino;
    int imediato;
    int origem1;
    int origem2;

    int memoriaAtual = 0;

    while (file && memoriaAtual < tamanhoExterno){

        file >> tipo;

        if(tipo == "D"){
            file >> imediato;
            m->escrever(memoriaAtual, new Dado(imediato));

        }else if(tipo == "ADD"){
            file >> destino;
            file >> origem1;
            file >> origem2;
            m->escrever(memoriaAtual, Instrucao::criarADD(destino,origem1,origem2));

        }else if(tipo == "SUB"){
            file >> destino;
            file >> origem1;
            file >> origem2;
            m->escrever(memoriaAtual, Instrucao::criarSUB(destino,origem1,origem2));
            
        }else if(tipo == "MULT"){
            file >> origem1;
            file >> origem2;
            m->escrever(memoriaAtual, Instrucao::criarMULT(origem1,origem2));

        }else if(tipo == "DIV"){
            file >> origem1;
            file >> origem2;
            m->escrever(memoriaAtual, Instrucao::criarDIV(origem1,origem2));

        }else if(tipo == "LW"){
            file >> destino;
            file >> imediato;
            m->escrever(memoriaAtual, Instrucao::criarLW(destino,imediato));

        }else if(tipo == "SW"){
            file >> destino;
            file >> imediato;
            m->escrever(memoriaAtual, Instrucao::criarSW(destino, imediato));

        }else if(tipo == "J"){
            file >> imediato;
            m->escrever(memoriaAtual, Instrucao::criarJ(imediato));
        
        }else if(tipo == "BNE"){
            file >> origem1;
            file >> origem2;
            file >> imediato;

            m->escrever(memoriaAtual, Instrucao::criarBNE(origem1,origem2, imediato));
        }else if(tipo == "BEQ"){
            file >> origem1;
            file >> origem2;
            file >> imediato;
            m->escrever(memoriaAtual, Instrucao::criarBEQ(origem1,origem2,imediato));
        }
        
        memoriaAtual++;
    }

    if (memoriaAtual == 0) {
        cout << "Arquivo Vazio" << endl;
        file.close();
        return;
    }

    file.close();
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM* m){
    ofstream file;
    file.open(arquivo.c_str(), ios_base::app | ios_base::out);

    if(file.fail()){
        throw new runtime_error("Erro ao escrever");
    }


    int tamanho = m->getTamanho();

    for (int i = 0; i < tamanho; i++){
        Dado* dado = m->ler(i);
        Instrucao* instrucao = dynamic_cast<Instrucao*>(dado);
        if(instrucao != NULL){
            
            if(instrucao->getOpcode() == Instrucao::TIPO_R){

                switch (instrucao->getOpcode()){
                    case Instrucao::FUNCAO_ADD :
                        file << "ADD " << instrucao->getDestino() << " " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                        break;
                    case Instrucao::FUNCAO_SUB :
                        file << "SUB " << instrucao->getDestino() << " " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                        break;
                    case Instrucao::FUNCAO_DIV :
                        file << "DIV " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                        break;
                    case Instrucao::FUNCAO_MULT :
                        file << "MULT " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                        break;
                    default:
                        throw new runtime_error("Instrucao desconhecida");
                }
            }else{
                switch (instrucao->getOpcode()) {
                    case Instrucao::J :
                        file << "J " << instrucao->getImediato() << endl;
                        break;
                    case Instrucao::BNE :
                        file << "BNE " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << " " << instrucao->getImediato()  << endl;
                        break;
                    case Instrucao::BEQ :
                        file << "BEQ " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << " " << instrucao->getImediato() << endl;
                        break;
                    case Instrucao::SW :
                        file << "SW " << instrucao->getDestino() << " " << instrucao->getImediato() << endl;
                        break;
                    case Instrucao::LW :
                        file << "LW " << instrucao->getDestino() << " " << instrucao->getImediato() << endl;
                        break;
                    default:
                        throw new runtime_error("Instrucao desconhecida");
                }
            }

        }else if(dado != NULL){
            file << "D " << dado->getValor() << endl;
        }else{
            file << "-" << endl;
        }
    }
    
    
    file.close();
} 