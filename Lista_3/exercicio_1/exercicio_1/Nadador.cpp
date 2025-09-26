#include "Nadador.h"
#include <iostream>

Nadador::Nadador(const std::string& nome, int idade, const std::string& categoria)
    : Atleta(nome, idade), categoria(categoria) {
}

std::string Nadador::getCategoria() const {
    return categoria;
}

void Nadador::imprime_info() const {
    Atleta::imprime_info();
    std::cout << "Categoria: " << categoria << std::endl;
}