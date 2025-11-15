#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template<class Type>
class Calculadora {
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

    Type somar(Type valorA, Type valorB);
    Type subtrair(Type valorA, Type valorB);
    Type multiplicar(Type valorA, Type valorB);
    Type dividir(Type valorA, Type valorB);
    Type eleva_ao_quadrado(Type valorA);
    Type eleva_ao_cubo(Type valorA);

    void imprime_info();
};

template<class Type>
Calculadora<Type>::Calculadora() {}

template<class Type>
Calculadora<Type>::Calculadora(string cor, Type memoria) {
    this->cor = cor;
    this->memoria = memoria;
}

template<class Type>
Calculadora<Type>::~Calculadora() {}

template<class Type>
Type Calculadora<Type> ::getMemoria() {
    return this->memoria;
}

template<class Type>
void Calculadora<Type> ::setMemoria(Type memoria) {
    this->memoria = memoria;
}

template<class Type>
string Calculadora<Type> ::getCor() {
    return this->cor;
}

template<class Type>
void Calculadora<Type> ::setCor(string cor) {
    this->cor = cor;
}

template<class Type>
Type Calculadora<Type> ::somar(Type a, Type b) {
    return a + b;
}
template<class Type>
Type Calculadora<Type> ::subtrair(Type a, Type b) {
    return a - b;
}
template<class Type>
Type Calculadora<Type> ::multiplicar(Type a, Type b) {
    return a * b;
}
template<class Type>
Type Calculadora<Type> ::dividir(Type a, Type b) {
    if (b == 0) {
        cerr << "Erro: Divisao por zero!" << endl;
        return Type(); // Retorna o valor padrão do tipo Type
    }
    return a / b;
}

template<class Type>
Type Calculadora<Type> ::eleva_ao_quadrado(Type a) {
    return pow(a, 2);
}

template<class Type>
Type Calculadora<Type> ::eleva_ao_cubo(Type a) {
    return pow(a, 3);
}

template<class Type>
void Calculadora<Type> ::imprime_info() {
    cout << "Cor da calculadora: " << this->cor << endl;
    cout << "Memoria da calculadora: " << this->memoria << endl;
}