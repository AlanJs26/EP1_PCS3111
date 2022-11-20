#include "UnidadeDeControle.h"
#include "MemoriaRAM.h"
#include "ESMapeadaNaMemoria.h"
#include "Teclado.h"
#include "TecladoDeChar.h"
#include "Monitor.h"
#include "MonitorDeChar.h"
#include "GerenciadorDeMemoria.h"

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

void alterarRegistrador(BancoDeRegistradores* registradores){
    int antigoRegistrador, novoValor;

    cout << "Registrador a ser alterado: ";
    cin >> antigoRegistrador;
    cout << endl << "Novo valor: ";
    cin >> novoValor;
    cout << endl;
    
    registradores->setValor(antigoRegistrador, novoValor);
}

void Load(MemoriaRAM* memoriaRam) {
    GerenciadorDeMemoria* gerenciador = new GerenciadorDeMemoria();

    cout << "Arquivo origem: ";

    string arquivo;

    cin >> arquivo;

    cout << endl;

    try{
        gerenciador->load(arquivo, memoriaRam);
    }catch(exception* e){
        cout << "Erro: " << e->what() << endl;
        delete e;
    }
}

void Dump(MemoriaRAM* memoriaRam) {
    GerenciadorDeMemoria* gerenciador = new GerenciadorDeMemoria();

    cout << "Arquivo destino: ";

    string arquivo;

    cin >> arquivo;

    cout << endl;

    try{
        gerenciador->dump(arquivo, memoriaRam);
    }catch(exception* e){
        cout << "Erro: " << e->what() << endl;
        delete e;
    }
}


int telaMemoria(){
    int escolha = 0;
    cout << "Memoria" << endl;
    cout << "1) Alterar valor" << endl;
    cout << "2) Imprimir" << endl;
    cout << "0) Voltar" << endl;
    cout << "Escolha uma opcao: ";

    cin >> escolha;
    
    cout << endl;

    return escolha;
}

void alterarMemoria(ESMapeadaNaMemoria* dados){
    int posicao, novoValor;
    cout << "Posicao a ser alterada: ";
    cin >> posicao;
    cout << "Novo valor: ";
    cin >> novoValor;
    cout << endl;

    Dado* novoDado = new Dado(novoValor);
    dados->escrever(posicao, novoDado);
}

int telaEmuladorMips(){
    int escolha = 0;
    cout << "Emulador de MIPS" << endl;
    cout << "1) Memoria de Dados" << endl;
    cout << "2) Registradores" << endl;
    cout << "3) Executar proxima instrucao" << endl;
    cout << "4) Executar ate PC = 0" << endl;
    cout << "5) Load" << endl;
    cout << "6) Dump" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opcao: ";

    cin >> escolha;

    cout << endl;

    return escolha;
}



int main()
{
    BancoDeRegistradores *registradores = new BancoDeRegistradores;
    MemoriaRAM *memoriaRam = new MemoriaRAM(64);

    vector<Dispositivo*> dispositivos;
    ESMapeadaNaMemoria *esMapeadaNaMemoria = new ESMapeadaNaMemoria(memoriaRam, &dispositivos);

    esMapeadaNaMemoria->adicionar(new Teclado());
    esMapeadaNaMemoria->adicionar(new TecladoDeChar());
    esMapeadaNaMemoria->adicionar(new Monitor());
    esMapeadaNaMemoria->adicionar(new MonitorDeChar());

    UnidadeDeControle *unidadeControle = new UnidadeDeControle(registradores, esMapeadaNaMemoria);


    int telaAtual = 0;
    int escolha;
    while (true)
    {
        if (telaAtual == 0)
        {
            escolha = telaEmuladorMips();

            if (escolha == 0)
            {
                break;
            }
            if (escolha == 3)
            {
                cout << "PC: " << unidadeControle->getPC() << endl;
                unidadeControle->executarInstrucao();
                cout << "Instrucao executada" << endl;
                cout << "PC: " << unidadeControle->getPC() << endl
                     << endl;
                continue;
            }
            else if (escolha == 4)
            {
                try
                {
                    
                    do{
                        unidadeControle->executarInstrucao();
                    }while (unidadeControle->getPC() != 0);
                    cout << endl;
                }
                catch (exception *e)
                {
                    cout << "Erro: " << e->what() << endl;
                    delete e;
                }
                continue;
            }
            else if (escolha == 5)
            {
                Load(memoriaRam);
                continue;
            }
            else if (escolha == 6)
            {
                Dump(memoriaRam);
                continue;
            }

            telaAtual = escolha;
        }
        else if (telaAtual == 1)
        {
            escolha = telaMemoria();

            if (escolha == 1)
            {
                alterarMemoria(esMapeadaNaMemoria);
            }
            else if (escolha == 2)
            {
                esMapeadaNaMemoria->imprimir();
                cout << endl;
            }
            else
            {
                telaAtual = 0;
            }
        }
        else if (telaAtual == 2)
        {
            escolha = telaRegistradores();

            if (escolha == 1)
            {
                alterarRegistrador(registradores);
            }
            else if (escolha == 2)
            {
                unidadeControle->getBancoDeRegistradores()->imprimir();
                cout << endl;
            }
            else
            {
                telaAtual = 0;
            }
        }
    }

    return 0;
}