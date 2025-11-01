#include "calculadora.hpp"

template<class Type>
Calculadora<Type>::Calculadora(){}

template<class Type>
Calculadora<Type>::Calculadora(string cor, Type memoria){
    this->cor = cor;
    this->memoria = memoria;
}

template<class Type>
Calculadora<Type>::~Calculadora(){}

template<class Type>
Type Calculadora<Type> 