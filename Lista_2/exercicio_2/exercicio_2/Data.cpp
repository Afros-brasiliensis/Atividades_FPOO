#include "Data.h"
#include <iostream>

Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}

void Data::imprime() const {
    std::cout << dia << "/" << mes << "/" << ano;
}