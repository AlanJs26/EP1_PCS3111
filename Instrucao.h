#ifndef INSTRUCAO_h
#define INSTRUCAO_h
#include "Dado.h"

class Instrucao : public Dado {
private:
    int origem1;
    int origem2;
    int destino;
    int imediato;
    int funcao;
    Instrucao(int opcode, int origem1, int origem2, int destino, int imediato, int funcao);
public:
    static const int LW = 35;
    static const int SW = 43;
    static const int J = 2;
    static const int BNE = 5;
    static const int BEQ = 4;
    static const int TIPO_R = 0;
    static const int FUNCAO_ADD = 32;
    static const int FUNCAO_SUB = 34;
    static const int FUNCAO_MULT = 24;
    static const int FUNCAO_DIV = 26;

    static Instrucao* criarLW(int destino, int imediato);
    static Instrucao* criarSW(int destino, int imediato);
    static Instrucao* criarJ(int imediato);
    static Instrucao* criarBNE(int origem1, int origem2, int imediato);
    static Instrucao* criarBEQ(int origem1, int origem2, int imediato);
    static Instrucao* criarADD(int destino, int origem1, int origem2);
    static Instrucao* criarSUB(int destino, int origem1, int origem2);
    static Instrucao* criarMULT(int origem1, int origem2);
    static Instrucao* criarDIV(int origem1, int origem2);

    virtual ~Instrucao();
    virtual int getOpcode();
    virtual int getOrigem1();
    virtual int getOrigem2();
    virtual int getDestino();
    virtual int getImediato();
    virtual int getFuncao();

    void imprimir(); 


};
// 64
// J 15
// D 72
// D 101
// D 108
// D 108
// D 111
// D 44
// D 32
// D 87
// D 111
// D 114
// D 108
// D 100
// D 33
// D 10
// LW 2 1
// SW 2 67
// LW 2 2
// SW 2 67
// LW 2 3
// SW 2 67
// LW 2 4
// SW 2 67
// LW 2 5
// SW 2 67
// LW 2 6
// SW 2 67
// LW 2 7
// SW 2 67
// LW 2 8
// SW 2 67
// LW 2 9
// SW 2 67
// LW 2 10
// SW 2 67
// LW 2 11
// SW 2 67
// LW 2 12
// SW 2 67
// LW 2 13
// SW 2 67
// LW 2 14
// SW 2 67
// J 0
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -
// -


#endif 