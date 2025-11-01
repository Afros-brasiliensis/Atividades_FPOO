#include <iostream>
#include <string>

using namespace std;

template<class Type>

class Calculadora{
    private:
        string cor;
        Type memoria;

    public:

    Calculadora();
    Calculadora(string cor, Type memoria);
    ~Calculadora();

    void setCor(string cor);
    void setMemoria(Type memoria);
    string getCor();
    Type getMemoria();

    void somar(Type valorA, Type valorB);
    void subtrair(Type valorA, Type valorB);
    void multiplicar(Type valorA, Type valorB);
    void dividir(Type valorA, Type valorB);
    void eleva_ao_quadrado(Type valorA, Type valorB);
    void eleva_ao_cubo(Type valorA, Type valorB);
    
    void imprime_info();
}