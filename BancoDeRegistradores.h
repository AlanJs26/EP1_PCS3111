#ifndef BANCODEREGISTRADORES_h
#define BANCODEREGISTRADORES_h

#define QUANTIDADE_REGISTRADORES 32

class BancoDeRegistradores {
private:
    int registradores[QUANTIDADE_REGISTRADORES];
    void resetaRegistradores(); 
public:
    BancoDeRegistradores();
    virtual ~BancoDeRegistradores();
    virtual int getValor(int registrador);
    virtual void setValor(int registrador, int valor);
    virtual void imprimir();
};

#endif