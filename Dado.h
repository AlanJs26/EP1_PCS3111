#ifndef DADO_h
#define DADO_h

class Dado {
private:
    int valor;
public:
    Dado(int valor);
    virtual ~Dado();
    virtual int getValor();
    virtual void imprimir();
};

#endif 