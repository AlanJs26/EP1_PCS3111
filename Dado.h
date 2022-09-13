#ifndef DADO_h
#define DADO_h

class Dado
{
private:
    int valor;
public:
    Dado(int valor);
    virtual ~Dado();
    int getValor();
    void imprimir();
};


#endif 