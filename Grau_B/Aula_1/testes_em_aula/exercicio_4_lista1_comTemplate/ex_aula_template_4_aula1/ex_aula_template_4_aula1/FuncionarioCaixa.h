#pragma once
#include "Calculadora.h"

template<typename Type>
class FuncionarioCaixa {

private:
    string nome;
    Calculadora<Type> calculadora;
    string endereco;

public:
    FuncionarioCaixa();
    FuncionarioCaixa(string nome, Calculadora<Type> calculadora, string endereco);
    ~FuncionarioCaixa();

    string getNome();
    void setNome(string nome);

    Calculadora<Type> getCalculadora();
    void setCalculadora(Calculadora<Type> calculadora);

    string getEndereco();
    void setEndereco(string endereco);

    Type  somarFC(Type a, Type b);

    Type subtrairFC(Type a, Type b);

    Type multiplicarFC(Type a, Type b);

    Type dividirFC(Type a, Type b);

    Type eleva_ao_quadradoFC(Type a);

    Type eleva_ao_cuboFC(Type a);
};

template<typename Type>
FuncionarioCaixa<Type>::FuncionarioCaixa() {}

template<typename Type>
FuncionarioCaixa<Type> ::FuncionarioCaixa(string nome, Calculadora<Type> calculadora, string endereco) {
    this->nome = nome;
    this->calculadora = calculadora;
	this->endereco = endereco;
}

template<typename Type>
FuncionarioCaixa<Type>::~FuncionarioCaixa() {}

template<typename Type>
string FuncionarioCaixa<Type>::getNome() {
    return this->nome;
}

template<typename Type>
void FuncionarioCaixa<Type>::setNome(string nome) {
    this->nome = nome;
}

template<typename Type>
Calculadora<Type> FuncionarioCaixa<Type>::getCalculadora() {
    return this->calculadora;
}

template<typename Type>
void FuncionarioCaixa<Type>::setCalculadora(Calculadora<Type> calculadora) {
    this->calculadora = calculadora;
}

template<typename Type>
string FuncionarioCaixa<Type>::getEndereco() {
    return this->endereco;
}

template<typename Type>
void FuncionarioCaixa<Type>::setEndereco(string endereco) {
    this->endereco = endereco;
}

template<typename Type>
Type FuncionarioCaixa<Type>::somarFC(Type a, Type b) {
    return calculadora.somar(a, b);
}

template<typename Type>
Type FuncionarioCaixa<Type>::subtrairFC(Type a, Type b) {
    return calculadora.subtrair(a, b);
}

template<typename Type>
Type FuncionarioCaixa<Type>::multiplicarFC(Type a, Type b) {
    return calculadora.multiplicar(a, b);
}

template<typename Type>
Type FuncionarioCaixa<Type>::dividirFC(Type a, Type b) {
    return calculadora.dividir(a, b);
}

template<typename Type>
Type FuncionarioCaixa<Type>::eleva_ao_quadradoFC(Type a) {
    return calculadora.eleva_ao_quadrado(a);
}

template<typename Type>
Type FuncionarioCaixa<Type>::eleva_ao_cuboFC(Type a) {
    return calculadora.eleva_ao_cubo(a);
}
