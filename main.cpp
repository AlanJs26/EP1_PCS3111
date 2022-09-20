#include "UnidadeDeControle.h"

#include <iostream>
using namespace std;
int telaRegistradores(){
    int escolha = 0;
    cout << "Registradores" << endl;
    cout << "1) Alterar Valor" << endl;
    cout << "2) Imprimir" << endl;
    cout << "0) Voltar" << endl;
    cout << "Escolha uma opcao: ";

    cin >> escolha;
    
    cout << endl;

    return escolha;
}

int telaMemoriaDeDados(){
    int escolha = 0;
    cout << "Memoria de Dados" << endl;
    cout << "1) Alterar valor" << endl;
    cout << "2) Imprimir" << endl;
    cout << "0) Voltar" << endl;
    cout << "Escolha uma opcao: ";

    cin >> escolha;
    
    cout << endl;

    return escolha;
}

int telaEmuladorMips(){
    int escolha = 0;
    cout << "Emulador de MIPS" << endl;
    cout << "1) Memoria de Dados" << endl;
    cout << "2) Registradores" << endl;
    cout << "3) Executar proxima instrucao" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opcao: ";

    cin >> escolha;

    cout << endl;

    return escolha;
}

void alterarMemoria(MemoriaDeDados* dados){
    int posicao, novoValor;
    cout << "Posicao a ser alterada: ";
    cin >> posicao;
    cout << "Novo valor: ";
    cin >> novoValor;
    cout << endl;

    Dado* novoDado = new Dado(novoValor);
    dados->escrever(posicao, novoDado);
}

void alterarRegistrador(BancoDeRegistradores* registradores){
    int antigoRegistrador, novoValor;

    cout << "Registrador a ser alterado: ";
    cin >> antigoRegistrador;
    cout << endl << "Novo valor: ";
    cin >> novoValor;
    cout << endl;
    
    registradores->setValor(antigoRegistrador, novoValor);
}



int main()
{
// 1 opcode
// 2 origem1
// 3 origem2
// 4 destino
// 5 imediato
// 6 funcao
int codigo[][6] = {
    {LW,0,0,8,0,0}, // LW 8, 0
    {LW,0,0,9,1,0}, // LW 9, 1
    {LW,0,0,10,2,0}, // LW 10, 2
    {BNE,9,10,0,7,0}, // BNE 9, 10, 7
    {TIPO_R,8,10,0,0,FUNCAO_MULT}, // MULT 8, 10
    {SW,0,0,24,3,0}, // SW 24, 3
    {J,0,0,0,0,0}, // J 0
    {TIPO_R,10,8,9,0,FUNCAO_ADD}, // ADD 9, 10, 8
    {SW,0,0,9,3,0}, // SW 9, 3
    {J,0,0,0,10,0} // J 10
};
    BancoDeRegistradores* registradores = new BancoDeRegistradores;
    MemoriaDeDados* dados = new MemoriaDeDados(16);
    MemoriaDeInstrucoes* instrucoes = new MemoriaDeInstrucoes(16);

    Instrucao* itt;
    for(int i = 0; i < 10; i++){
        itt = new Instrucao(
                    codigo[i][0],
                    codigo[i][1],
                    codigo[i][2],
                    codigo[i][3],
                    codigo[i][4],
                    codigo[i][5]
                );
        instrucoes->escrever(i, itt);
    }

    UnidadeDeControle* unidadeControle = new UnidadeDeControle(registradores, instrucoes, dados);

    int telaAtual = 0;
    int escolha;
    while(true){
        if(telaAtual == 0){
            escolha = telaEmuladorMips();

            if(escolha == 0){
                break;
            }
            if(escolha == 3){
                cout << "PC: " << unidadeControle->getPC() << endl;
                unidadeControle->executarInstrucao();
                cout << "Instrucao executada" << endl;
                cout << "PC: " << unidadeControle->getPC() << endl << endl;
                continue;
            }
            telaAtual = escolha;
        }else if(telaAtual == 1){
            escolha = telaMemoriaDeDados();

            if(escolha == 1){
                alterarMemoria(dados);
            }else if(escolha == 2){
                unidadeControle->getMemoriaDeDados()->imprimir();
                cout << endl;
            }else{
                telaAtual = 0;
            }
        }else if(telaAtual == 2){
            escolha = telaRegistradores();

            if(escolha == 1){
                alterarRegistrador(registradores);
            }else if(escolha == 2){
                unidadeControle->getBancoDeRegistradores()->imprimir();
                cout << endl;
            }else{
                telaAtual = 0;
            }
        }
    }


    return 0;
}