#include "Data.h"
#include <iomanip>
#include <iostream>

Data::Data(int dia, int mes, int ano)
    : dia(dia), mes(mes), ano(ano) {
}

int Data::getDia() const {
    return dia;
}

int Data::getMes() const {
    return mes;
}

int Data::getAno() const {
    return ano;
}

void Data::imprime_data() const {
    std::cout << std::setfill('0') << std::setw(2) << dia << "/"
        << std::setfill('0') << std::setw(2) << mes << "/"
        << ano << std::endl;
}