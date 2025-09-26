#include "Corredor.h"
#include <iostream>

Corredor::Corredor(const std::string& nome, int idade, double peso, const std::string& nomeCompeticao, int dia, int mes, int ano)
    : Atleta(nome, idade), peso(peso), competicao(nomeCompeticao, dia, mes, ano) {
}

double Corredor::getPeso() const {
    return peso;
}

Competicao Corredor::getCompeticao() const {
    return competicao;
}

void Corredor::imprime_competicao() const {
    std::cout << "Competicao: " << competicao.getNome() << std::endl;
    std::cout << "Data: ";
    competicao.getData().imprime_data();
}

void Corredor::imprime_info() const {
    Atleta::imprime_info();
    std::cout << "Peso: " << peso << " kg" << std::endl;
    imprime_competicao();
}